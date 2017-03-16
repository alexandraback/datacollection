import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TaskB {

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	int n;
	int[] a;
	int e;
	int r;
	
	public int ff( int x, int j){
		int ans=0;
		if (j == n){
			return 0;
		}
		for ( int i = 0; i <= x; i++){
			int y = a[j]*i+ff(Math.min(x-i+r,e),j+1);
			if (y>ans){
				ans = y;
			}
		}
		return ans;
	}

	void run() throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		String s1 = br.readLine();
		st = new StringTokenizer(s1);
		int t = Integer.parseInt(st.nextToken());
		for (int i1 = 1; i1 <= t; i1++) {
			out.print("Case #" + i1 + ": ");
			s1 = br.readLine();
			st = new StringTokenizer(s1);
			e = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			a = new int[n];
			s1 = br.readLine();
			st = new StringTokenizer(s1);
			for (int i = 0; i < n; i++) {
				a[i] = Integer.parseInt(st.nextToken());
			}
			out.println(ff(e,0));
			
		}

		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new TaskB().run();
	}

}