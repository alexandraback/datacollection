import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;


public class sub {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	public static String next() throws Exception {
		while (true) {
			if (st.hasMoreTokens())
				return st.nextToken();
			String s = br.readLine();
			if (s == null)
				return null;
			st = new StringTokenizer(s);
		}
	}
	public static int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	public static void main(String[] args) throws Exception {
		 int T = nextInt();
		 for(int it = 1 ; it <= T; it++){
			 
			 int n = nextInt();
			 int [] num = new int[n];
			 int sum = 0;
			 for(int i = 0 ; i < n ; i ++){
				 num[i] = nextInt() ;
				 sum += num[i];
			 }
			 String res = "" ;
			 System.out.print("Case #" + it +  ": ");
			 for(int i = 0 ; i < n ; i ++){
				 int curSum = sum - num[i];
				 double x = (curSum+sum) / (double)(n-1) - num[i];
				 double y = sum/(double)(n-1) + sum;
				 x = x/y;
				 x = x*100.0f;
				 if(x<0.0f) x= 0.0f;
				 if(i == n-1)
					 System.out.printf("%.6f",x);
				 else
					 System.out.printf("%.6f ",x);
			 }
			 System.out.println();
		 }
		 
		 
	}
}
