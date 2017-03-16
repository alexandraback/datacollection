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
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int L = in.nextInt();
        int X = in.nextInt();
        String t = in.nextToken();
        StringBuilder s = new StringBuilder();
        for(int i=0;i<X;i++) {
           s.append(t);
        }

        String rs = s.toString();
        Letter Rproducts[] = new Letter[rs.length()];
        Rproducts[rs.length()-1] = new Letter(rs.charAt(rs.length()-1));
        for(int i=rs.length()-2;i>=0;i--) {
            Rproducts[i] = new Letter(rs.charAt(i)).multiply(Rproducts[i+1]);
        }

        Letter lp = new Letter(1,false);
        boolean ok = false;
        out: for(int l = 0; l < rs.length()-2;l++) {
            lp = lp.multiply(new Letter(rs.charAt(l)));
            if(lp.id == 2 && lp.negative == false) {
                Letter mp = new Letter(1, false);
                for(int m = l+1;m<rs.length()-1;m++) {
                    mp = mp.multiply(new Letter(rs.charAt(m)));
                    if(mp.negative == false && mp.id == 3 && Rproducts[m+1].id == 4 && Rproducts[m+1].negative == false) {
                        ok = true;
                        break out;
                    }
                }
            }

        }
        out.println("Case #"+testNumber+": "+(ok?"YES":"NO"));
    }
}

class Letter {
    int id;
    boolean negative = false;
    private int getId(char c) {
        switch (c) {
            case 'i': return 2;
            case 'j': return 3;
            case 'k': return 4;
        }
        return -1;
    }

    public Letter(char c) {
        this.id = getId(c);
    }


    public Letter(int id, boolean negative) {
        this.id = id;
        this.negative = negative;
    }


    public Letter multiply(Letter c) {
        int id1 = 0;
        if(this.id ==1 && c.id == 1)
            id1 = 1;
        if(this.id ==1 && c.id == 2)
            id1 = 2;
        if(this.id ==1 && c.id == 3)
            id1 = 3;
        if(this.id ==1 && c.id == 4)
            id1 = 4;


        if(this.id ==2 && c.id == 1)
            id1 = 2;
        if(this.id ==3 && c.id == 1)
            id1 = 3;
        if(this.id ==4 && c.id == 1)
            id1 = 4;

        if(this.id == 2 && c.id == 2)
            id1 = -1;

        if(this.id == 3 && c.id == 2)
            id1 = -4;

        if(this.id == 4 && c.id == 2)
            id1 = 3;



        if(this.id == 2 && c.id == 3)
            id1 = 4;

        if(this.id == 3 && c.id == 3)
            id1 = -1;

        if(this.id == 4 && c.id == 3)
            id1 = -2;


        if(this.id == 2 && c.id == 4)
            id1 = -3;

        if(this.id == 3 && c.id == 4)
            id1 = 2;

        if(this.id == 4 && c.id == 4)
            id1 = -1;

        boolean negative = this.negative ^ c.negative;
        if(id1<0) {
            id1 = Math.abs(id1);
            negative = !negative;
        }

        return new Letter(id1, negative);
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

