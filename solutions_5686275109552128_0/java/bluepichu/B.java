import java.io.*;
import java.math.*;
import java.util.*;

public class B{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.print("Case #" + t + ": ");
			
			int d = nextInt(br);
			StringTokenizer st = getst(br);
			
			int[] diners = new int[d];
			
			for(int i = 0; i < d; i++){
				diners[i] = nextInt(st);
			}
			
			int min = 1000000000;
			
			for(int i = 1; i <= 1000; i++){
				int sp = 0;
				for(int j = 0; j < d; j++){
					sp += (diners[j]-1)/i;
				}
				min = Math.min(min, sp + i);
			}
			
			pw.println(min);
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