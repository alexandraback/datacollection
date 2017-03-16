import java.io.*;
import java.math.*;
import java.util.*;

public class D{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.print("Case #" + t + ": ");
			
			StringTokenizer st = getst(br);
			
			int n = nextInt(st);
			int r = nextInt(st);
			int c = nextInt(st);
			
			int l = Math.max(r, c);
			int s = Math.min(r, c);
			
			if(s < (n+1)/2 || n >= 7 || (r*c)%n != 0){
				pw.println("RICHARD");
				continue;
			}
			
			if(n < 2*s-1){
				pw.println("GABRIEL");
				continue;
			}
			
			boolean ok = false;
			
			for(int i = 0; i < n-s; i++){
				ok = true;
				for(int j = 0; j < l; j++){
					if(j*s - i >= 0 && (l-j-1)*s - (n-s-i) >= 0 && (j*s - i)%n == 0){
						ok = false;
						break;
					}
				}
				if(ok){
					break;
				}
			}
			
			if(ok){
				pw.println("RICHARD");
			} else {
				pw.println("GABRIEL");
			}
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