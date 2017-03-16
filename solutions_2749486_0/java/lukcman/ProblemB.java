import java.io.*;
import java.util.*;

public class ProblemB {
	InputReader in; PrintWriter out;
	int T;
	void solve() {
		int x = in.nextInt();
		int y = in.nextInt();
		for (int i = 0; i < Math.abs(x); i++)
		{
			if (x > 0)
				out.print("WE");
			else
				out.print("EW");
		}
		for (int i = 0; i < Math.abs(y); i++)
		{
			if (y > 0)
				out.print("SN");
			else
				out.print("NS");
		}
		out.println();
	}
	
	ProblemB(){
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
		new ProblemB();
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