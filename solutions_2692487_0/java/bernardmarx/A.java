import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	static int a, n;
	static int[] m, cu;
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("A.in"));
		StringBuffer buf = new StringBuffer();
		int t = Integer.parseInt(reader.readLine());
		StringTokenizer st;
		for (int c = 1; c <= t; c++) {
			st = new StringTokenizer(reader.readLine());
			a = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			m = new int[n];
			cu = new int[n];
			st = new StringTokenizer(reader.readLine());
			for (int i = 0; i < n; i++) {
				m[i] = Integer.parseInt(st.nextToken());
			}
			buf.append("Case #"+c+": "+solve()+"\n");
		}
		System.setOut(new PrintStream("A.out"));
		System.out.print(buf);
	}
	
	static int solve(){
		if (a==1) return n;
		Arrays.sort(m);
		int act = a;
		for (int i = 0; i < n; i++) {
			if (i == 0) cu[i]=0;
			else cu[i]=cu[i-1];
			while(m[i]>=act){
				act=2*act-1;
				cu[i]++;
			}
			act += m[i];
		}
		int min = n;
		for (int i = 0; i < n; i++) {
			min = Math.min(min, (n-i-1) + cu[i]);
		}
		return min;
	}
}
