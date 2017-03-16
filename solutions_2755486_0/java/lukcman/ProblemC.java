import java.io.*;
import java.util.*;

public class ProblemC {
	InputReader in; PrintWriter out;
	int T;
	
	int N;
	int[] d, n, w, e, s;
	int[] dd, dp, ds;
	
	final int WS = 2001;
	int ND = 0;
	Set<Integer> days;
	int[] wall = new int[WS];
	int[] nWall = new int[WS];
	
	int ans = 0;
	
	void attackDaily(int day)
	{
		for (int tribe = 0; tribe < N; tribe++)
		{
			if (day < d[tribe] || (day - d[tribe]) % dd[tribe] != 0)
				continue;
			int attackNum = (day - d[tribe]) / dd[tribe];
			if (attackNum >= n[tribe])
				continue;
			
//			out.println("tribe " + tribe + " attackNum " + attackNum + " on day " + day);

			int curW = w[tribe] + dp[tribe] * attackNum;
			int curE = e[tribe] + dp[tribe] * attackNum;
			int curS = s[tribe] + ds[tribe] * attackNum;
			
			boolean successAttack = false;
			for (int x = curW; x < curE; x++)
			{
				if (wall[x] < curS)
				{
					successAttack = true;
					nWall[x] = Math.max(nWall[x], curS);
				}
			}
			
			if (successAttack)
				ans++;
		}
		
		for (int x = 0; x < WS; x++)
			wall[x] = nWall[x];
	}
	
	void solve() {
		N = in.nextInt();
		d = new int[N]; n = new int[N];
		w = new int[N]; e = new int[N];
		s = new int[N];
		
		dd = new int[N]; dp = new int[N]; ds = new int[N];
		
		ans = 0;
		Arrays.fill(wall, 0);
		Arrays.fill(nWall, 0);
		days = new TreeSet<Integer>();
		
		for (int i = 0; i < N; i++)
		{
			d[i] = in.nextInt(); n[i] = in.nextInt();
			w[i] = in.nextInt(); e[i] = in.nextInt();
			s[i] = in.nextInt();
			
			dd[i] = in.nextInt(); dp[i] = in.nextInt(); ds[i] = in.nextInt();
			
			w[i] += 1000; e[i] += 1000;
			
			for (int j = 0; j < n[i]; j++)
				days.add(d[i] + j * dd[i]);
			
		}
		
	
		for (int day : days)
			attackDaily(day);
		
		out.println(ans);
	}
	
	ProblemC(){
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
			System.out.println(t);
			
			out.print("Case #" + t + ": ");
			solve();			
		}
		out.close();
	}
	public static void main(String[] args){
		new ProblemC();
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