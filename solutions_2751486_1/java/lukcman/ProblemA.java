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
		long ans = 0;
		int[] a = new int[1000001];
		
		if (!isVowel(s.charAt(0)))
			a[0] = 1;
		for (int i = 1; i < len; i++)
			if (!isVowel(s.charAt(i)))
				a[i] = a[i - 1] + 1;
			else
				a[i] = 0;
		
		int i = 0, j = i + n - 1;
		while (i < len && j < len)
		{
			while ((j - i + 1 < n || a[j] < n) && j < len)
				j++;
//			out.println("i == " + i + " j == " + j);
			ans += len - j;
			i++;
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