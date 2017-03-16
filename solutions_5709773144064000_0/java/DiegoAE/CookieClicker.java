import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class CookieClicker {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			double C = sc.nextDouble();
			double F = sc.nextDouble();
			double X = sc.nextDouble();
			double ans = Double.MAX_VALUE;
			double sum = 0.0;
			for(int i = 0;  true; i++){
				double t = X / (2 + F*i);
				ans = Math.min(ans, sum + t);
				sum += (C / (2 + i*F));
				if (sum > (X/2.0) || sum > ans)
					break;
			}
			String cad = String.format("Case #%d: %.9f", c, ans);
			cad = cad.replace(",", ".");
			System.out.println(cad);
		}
	}

}
