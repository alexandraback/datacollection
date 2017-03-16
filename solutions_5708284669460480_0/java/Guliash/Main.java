import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Artem Gilmudinov
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("B-small-attempt.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    char[] chars;
    ArrayList<String> possible;
    int k, l, s;
    public void solve(int testNumber, Reader in, PrintWriter out) {
        int T = in.ni();
        for(int t = 1; t <= T; t++) {
            k = in.ni(); l = in.ni(); s = in.ni();
            String keyboard = in.rl();
            String target = in.rl();
            HashSet<Character> charsSet = new HashSet<>();
            for(int i = 0; i < k; i++) {
                charsSet.add(keyboard.charAt(i));
            }
            chars = new char[charsSet.size()];
            int iter = 0;
            for(Character ch : charsSet) {
                chars[iter++] = ch;
            }
            possible = new ArrayList<>();
            dfs("");
            int[] freq = new int[26];
            for(int i = 0; i < keyboard.length(); i++) {
                freq[keyboard.charAt(i) - 'A']++;
            }
            ArrayList<Integer> occur = new ArrayList<>();
            for(int i = 0; i < possible.size(); i++) {
                String str = possible.get(i);
                int cnt = 0;
                for(int j = 0; j <= s - l; j++) {
                    boolean isFine = true;
                    for(int z = j; z < j + l; z++) {
                        if(target.charAt(z - j) != str.charAt(z)) {
                            isFine = false;
                        }
                    }
                    if(isFine) {
                        cnt++;
                    }
                }
                occur.add(cnt);
            }
            int max = 0;
            for(int i = 0; i < occur.size(); i++) {
                max = Math.max(occur.get(i), max);
            }
            double expected = 0.0;
            for(int i = 0; i < possible.size(); i++) {
                double prob = 1;
                String str = possible.get(i);
                for(int j = 0; j < s; j++) {
                    prob *= (1.0 * freq[str.charAt(j) - 'A'] / k);
                }
                expected += (prob * (max - occur.get(i)));
            }
            out.println(String.format("Case #%d: %f", t, expected));
        }
    }

    public void dfs(String cur) {
        if(cur.length() == s) {
            possible.add(cur);
            return;
        }
        for(int i = 0; i < chars.length; i++) {
            dfs(cur + chars[i]);
        }
    }
}

class Reader {
    private BufferedReader in;
    private StringTokenizer st = new StringTokenizer("");
    private String delim = " ";

    public Reader(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
    }

    public String next() {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(rl());
        }
        return st.nextToken(delim);
    }

    public String rl() {
        try {
            return in.readLine();
        } catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    public int ni() {
        return Integer.parseInt(next());
    }

}

