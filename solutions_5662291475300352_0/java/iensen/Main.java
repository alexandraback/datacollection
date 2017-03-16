import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.FileOutputStream;
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
        int G = in.nextInt();
        ArrayList<Integer> D = new ArrayList<Integer>();
        ArrayList<Integer> M = new ArrayList<Integer>();
        for(int i =0; i< G;i++) {
            int Ds = in.nextInt();// start
            int H = in.nextInt(); // hikers
            int t = in.nextInt(); // time
            for(int j=0;j<H;j++) {
                D.add(Ds);
                M.add(t+j);
            }
        }
        if(D.size()>2) {
            out.println("ERROR");
            return;
        }
        if(D.size()<=1) {
            out.println("Case #"+testNumber+": 0");
        } else {
                // follow the slower hiker
                double startSLow = -1;
                double startFast = -1;
            double speedMin =-1;
            double speedMax = -1;

            if(M.get(0) > M.get(1)) {
                startSLow = D.get(0);
                speedMin = M.get(0);
                speedMax = M.get(1);
                startFast = D.get(1);
            } else {

                    startSLow = D.get(1);
                    speedMin = M.get(1);
                    speedMax = M.get(0);
                    startFast = D.get(0);
                }
                if(speedMax == speedMin) {
                    out.println("Case #" + testNumber+": "+ 0);
                    return;
                }
                int bestCount = 1;
                // follow the slow hiker
                double time = speedMin*(360 - startSLow)/360.0;
                // how many times faster hiker will reacch 360?
                double time1 = time -  speedMax*(360 - startFast)/360.0;

                int count = (int)Math.floor((time1+1e-9)/((speedMax)));
                if(count<0)
                    count = 0;
                bestCount = Math.min(count,bestCount);
                // follow the fast hiker
                time = speedMax*(360 - startFast)/360.0;
               // will the slow hiker have time to go out?
              double leftDegree = 360 - startSLow;
               double timeNeeded = speedMin * leftDegree/360.0;
               if(timeNeeded < time-1e-9)
                   bestCount = 0;
              out.println("Case #" + testNumber+": "+ bestCount);

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

