import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.FileInputStream;
import java.io.File;
import java.util.Queue;
import java.util.LinkedList;
import java.io.FilenameFilter;
import java.util.Collection;
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
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    int getNumber(int [] ar) {
        int ans = 0;
        int mult = 1;
        for(int i =0;i<ar.length;i++) {
            ans +=ar[i]*mult;
            mult*=10;
        }
        return ans;
    }
    ArrayList<Integer> getAllPermutations(int n) {
        int ct = 0;
        int n1 = n;
        while(n>0) {
            ++ct;
            n/=10;
        }
        n = n1;
        int [] ar = new int[ct];
        int idx = 0;
        while(n>0) {
            ar[idx++]= n%10;
            n/=10;
        }

        ArrayList<Integer> ans = new ArrayList<Integer>();
        ans.add(n);
        ArrayUtils.reverse(ar);
        ans.add(getNumber(ar));
        return ans;

    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        HashMap<Integer,Integer> distance = new HashMap<Integer, Integer>();
        distance.put(1,1);

        Queue<Integer> q = new LinkedList<Integer>();
        q.add(1);

        while(!q.isEmpty()) {
            int val = q.poll();
            int d = distance.get(val);
            ArrayList<Integer> cands = getAllPermutations(val);
            cands.add(val+1);

            for(Integer c: cands) {
                if(!distance.containsKey(c)) {
                    distance.put(c,d+1);
                    q.add(c);
                }
            }
            if(distance.containsKey(n)) {
                out.println("Case #"+testNumber+": "+distance.get(n));
                break;
            }

        }
    }
}

class ArrayUtils
{


    public static void reverse(int []a)
     {
      for(int i = 0; i < a.length/2; i++)
      {
        int temp = a[i];
        a[i] = a[a.length - i - 1];
        a[a.length - i - 1] = temp;
      }
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

    public void putCharBack(int c) {
        buf[--curCharIndex] = (byte) c;
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
        if( c != -1) putCharBack(c);
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
        if( c != -1) putCharBack(c);
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

