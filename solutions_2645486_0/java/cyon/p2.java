import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p2 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	private static final int v[]=new int[11];
	private static int E = 0;
	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int e=Integer.parseInt(st.nextToken());
		E = e;
		int r=Integer.parseInt(st.nextToken());
		int n=Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		Arrays.fill(v,0);
		for(int i=0;i<n;i++)
			v[i]=Integer.parseInt(st.nextToken());
		
		int maxi=go(0,0,e,r,n);
		return Integer.toString(maxi);
	}

	private static int go(int a, int j, int e, int r, int n) {
		//debug(a,j,e,r,n);
		if(a==n) return j;
		int maxi = 0;
		for(int i=0;i<=e;i++) {
			maxi=Math.max(maxi, go(a+1,j+v[a]*i,Math.max(0, Math.min(e-i+r,E)),r,n));
		}
		return maxi;
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