import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Andrey Rechitsky (arechitsky@gmail.com)
 */
public class Main {
	public static void main(String[] args) {
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
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    static long MOD = 1000000007;
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        String [] set = new String[n];
        for (int i = 0; i < n; i++) {
            set[i] = in.next();
        }
        long ans = getAns(set);
        out.printLine(String.format("Case #%d: %d", testNumber, ans));
    }
    private long getAns(String []set){
        ArrayList<String> set2 = new ArrayList<String>();
        for (int i = 0; i < set.length; i++) {
            StringBuilder stringBuilder = new StringBuilder();
            char cur = set[i].charAt(0);
            stringBuilder.append(cur);
            for (int j = 1; j < set[i].length(); j++) {
                if (set[i].charAt(j)==cur) continue;
                cur = set[i].charAt(j);
                stringBuilder.append(cur);
            }
            set2.add(stringBuilder.toString());
        }
        ArrayList<Integer> [] start= new ArrayList [26], end = new  ArrayList[26],
                middle = new ArrayList[26], whole = new ArrayList[26];
        for (int i = 0; i < 26; i++) {
            start[i] = new ArrayList<Integer>();
            end[i] = new ArrayList<Integer>();
            middle[i] = new ArrayList<Integer>();
            whole[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < set2.size(); i++) {
            String s = set2.get(i);
            if (s.length()==1) {
                whole[s.charAt(0)-'a'].add(i);
                continue;
            }
            start[s.charAt(0)-'a'].add(i);
            end[s.charAt(s.length()-1)-'a'].add(i);
            for (int j = 1; j < s.length()-1; j++) {
                middle[s.charAt(j)-'a'].add(i);
            }
        }
        boolean [] last = new boolean [set2.size()];
        Arrays.fill(last, true);
        long res = 1;
        for (int i = 0; i < 26; i++) {
            if (start[i].size()>1) return 0;
            if (end[i].size()>1) return 0;
            if (middle[i].size()>1) return 0;
            if (middle[i].size()==1 && (start[i].size()==1 || end[i].size()==1 || whole[i].size()>0))
                return 0;
            if (middle[i].size()>0) continue;
            if (whole[i].size()>0){
                res*=fact(whole[i].size());
                res%=MOD;
                for(int j:whole[i]){
                    last[j] = false;
                }
                if (start[i].size()==0 && end[i].size()==0)
                    last[whole[i].get(0)] = true;
            }
            if (start[i].size()==1 && end[i].size()==1){
                last[end[i].get(0)] = false;
            }
        }
        int blocks = 0;
        for (int i = 0; i < last.length; i++) {
            blocks+=last[i]?1:0;
        }
        res *= fact(blocks);
        res %= MOD;

        boolean []checked = new boolean[set2.size()];
        for (int i = 0; i < set2.size(); i++) {
            if (checked[i]) continue;
            checked[i] = true;
            if(set2.get(i).length()==1) continue;
            int j = i;
            while (start[set2.get(j).charAt(set2.get(j).length()-1)-'a'].size()>0)
            {
                if (set2.get(j).charAt(set2.get(j).length()-1)==set2.get(i).charAt(0)) return 0;
                checked[j] = true;
                j = start[set2.get(j).charAt(set2.get(j).length()-1)-'a'].get(0);
            }
        }
        return res;
    }

    private long fact(long x){
        if (x<2) return 1;
        long res = 1;
        for (int i = 2; i <= x; i++) {
            res*=i;
            res%=MOD;
        }
        return res;
    }
}

class FastScanner {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;

    public FastScanner(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String next() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            if (Character.isValidCodePoint(c))
                res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\t' || isEOL(c);
    }

    public static boolean isEOL(int c) {
        return c == '\n' || c == '\r' || c == -1;
    }

    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}

class FastPrinter {
    private final PrintWriter writer;

    public FastPrinter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public FastPrinter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void close() {
        writer.close();
    }

    public void printLine(String s) {
        writer.println(s);
    }

    }

