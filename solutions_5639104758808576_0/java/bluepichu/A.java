import java.io.*;
import java.math.*;
import java.util.*;

public class A{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.print("Case #" + t + ": ");
			
			StringTokenizer st = getst(br);
			
			int n = nextInt(st);
			String chrs = st.nextToken();
			int[] s = new int[n+1];
			
			for(int i = 0; i <= n; i++){
				s[i] = chrs.charAt(i) - 48;
			}
			
			int cnt = 0;
			int ans = 0;
			
			for(int i = 0; i <= n; i++){
				if(cnt < i && s[i] > 0){
					ans += i - cnt;
					cnt = i;
				}
				cnt += s[i];
			}
			
			pw.println(ans);
		}
		
		br.close();
		pw.close();
	}
	
	public static int nextInt(BufferedReader br) throws Exception{
		return Integer.parseInt(br.readLine());
	}
	
	public static int nextInt(StringTokenizer st) throws Exception{
		return Integer.parseInt(st.nextToken());
	}
	
	public static StringTokenizer getst(BufferedReader br) throws Exception{
		return new StringTokenizer(br.readLine(), " ");
	}
}