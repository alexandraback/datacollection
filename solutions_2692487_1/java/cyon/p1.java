
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p1 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	private static final int MAX=101;
	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a=Integer.parseInt(st.nextToken());
		int n=Integer.parseInt(st.nextToken());
		int mt[]=new int[n];
		int c[]=new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			mt[i]=Integer.parseInt(st.nextToken());
		}
		if(a==1) {
			return "" + n;
		}
		Arrays.sort(mt);
		int cnt=0;
		long sum=a;
		int i=0;
		for(i=0;i<n;i++) {
			if(sum > mt[i]) {
				sum=sum+mt[i];
			}
			else {
				while(sum <= mt[i]) {
					sum=2*sum-1;
					cnt++;
				}
				sum=sum+mt[i];
			}
			c[i]=cnt;
		}
		debug(sum);
		//debug(c);
		//debug(mt);
		cnt = Math.min(cnt, n);
		for(i=0;i<n;i++) {
			//debug(c[i]+(n-i-1));
			cnt = Math.min(cnt, c[i]+(n-i-1));
		}
		//debug(c);
		for(i=0;i<n;i++) {
			//debug(c[i]+(n-i-1));
			c[i] = c[i]+(n-i-1);
		}
		//debug(sum);
		//debug(mt);
		//debug(c);
		return "";//Integer.toString(cnt);
	}

	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
}
