import java.io.*;
import java.util.*;

public class ProblemA {
	InputReader in; PrintWriter out;
	int T;
	boolean isVowel(char c)
	{
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
	void solve() {
		String s = in.next();
		int n = in.nextInt();
		int len = s.length();
		int ans = 0;
		for (int i = 0; i < len; i++)
			for (int j = i + n - 1; j < len; j++)
			{
				boolean ok = false;
				int cur = 0;
				for (int k = i; k <= j; k++)
				{
					if (!isVowel(s.charAt(k)))
						cur++;
					else
						cur = 0;
					if (cur >= n)
						ok = true;
				}
				if (ok)
					ans++;
			}
		out.println(ans);
	}
	
	ProblemA(){
		boolean oj = System.getProperty("ONLINE_JUDGE") != null;
		try {
			if (oj) {
				in = new InputReader(System.in);
				out = new PrintWriter(System.out);
			}
			else {
				Writer w = new FileWriter("output.txt");
				in = new InputReader(new FileReader("input.txt"));
				out = new PrintWriter(w);
			}
		} catch(Exception e) {
			throw new RuntimeException(e);
		}
		T = in.nextInt();
		for (int t = 1; t <= T; t++)
		{
			out.print("Case #" + t + ": ");
			solve();			
		}
		out.close();
	}
	public static void main(String[] args){
		new ProblemA();
	}
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }
    
    public InputReader(FileReader fr) {
    	reader = new BufferedReader(fr);
    	tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }
    public long nextLong() {
    	return Long.parseLong(next());
    }
    public double nextDouble() {
    	return Double.parseDouble(next());
    }

}