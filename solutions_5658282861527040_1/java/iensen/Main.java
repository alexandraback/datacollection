import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    long[][][][] solved;
    long solve(int bit, int less1, int less2, int lessK,int maxBit,int A,int B,int K) {
        if(bit>=maxBit) {
            if(less1 ==1 && less2 ==1 && lessK ==1)
                return 1;
            else return 0;
        }
         if(solved[bit][less1][less2][lessK]!=-1)
             return solved[bit][less1][less2][lessK];


         long ans = 0;
         for(int bit1 = 0;bit1<=1;bit1++)
             for(int bit2 = 0;bit2<=1;bit2++) {
                 // can never be greater
                 if(less1==0 && bit1> (BitUtils.getBit(A,maxBit-bit-1)?1:0)
                     || less2 == 0 && bit2>(BitUtils.getBit(B,maxBit-bit-1)?1:0)
                     || lessK ==0 && (bit1&bit2) > (BitUtils.getBit(K,maxBit-bit-1)?1:0)  )
                     continue;

                 int newLess1 = (less1==1 || bit1 < (BitUtils.getBit(A,maxBit-bit-1)?1:0))?1:0;
                 int newLess2 = (less2==1 || bit2 < (BitUtils.getBit(B,maxBit-bit-1)?1 :0))?1:0;
                 int newLessK = (lessK==1 || (bit1&bit2)  < (BitUtils.getBit(K,maxBit-bit-1)?1:0))?1:0;
                 ans += solve(bit+1,newLess1,newLess2,newLessK,maxBit,A,B,K);

             }
        return solved[bit][less1][less2][lessK] = ans;

    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int A = in.nextInt(),B=in.nextInt(),K=in.nextInt();
        int maxBit = Math.max(Integer.toBinaryString(A).length(), Integer.toBinaryString(B).length());
        maxBit = Math.max(maxBit, Integer.toBinaryString(K).length());
        solved = new long[maxBit][2][2][2];
        for(int i=0;i<maxBit;i++) {
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    for(int h=0;h<2;h++) {
                        solved[i][j][k][h] = -1;
                    }
        }
        out.println("Case #"+testNumber+": "+solve(0,0,0,0,maxBit,A,B,K));

    }
}

class BitUtils
{

    public static boolean getBit(long number,int bitIdx) {
        return (number & (1l << bitIdx))>0;
    }

}

class InputReader {

    private InputStream stream;
    int curCharIndex = 0;
    int charsInBuf = 0;
     byte buf[] = new byte[16*1024];

    public InputReader(InputStream stream) {
        this.stream = stream;
    }


    public int readChar() {

        if (curCharIndex >= charsInBuf) {
            curCharIndex = 0;
            try {
                charsInBuf = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (charsInBuf <= 0)
                return -1;
        }
        return buf[curCharIndex++];
    }


    public int nextInt() {

        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        int sign = 1;
        if (c == '-') {
            c = readChar();
            sign = -1;

        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        return sign * res;
    }


    public String nextToken() {
        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        return res.toString();
    }

    /*
    * For the purpose of compatibilty with Chelper Chrome extension
     */

    public String next() {
        return nextToken();
    }


    private boolean isWhitespace(int c) {
        return  c==' ' || c=='\n'|| c=='\r' || c=='\t';
    }
}


