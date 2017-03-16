// Java Shell by Matthew Savage

import java.io.*;
import java.math.*;
import java.util.*;

public class D{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			int n = nextInt(br);
			double[] a = new double[n];
			double[] b = new double[n];
			
			StringTokenizer sa = getst(br);
			StringTokenizer sb = getst(br);
			
			for(int i = 0; i < n; i++){
				a[i] = Double.parseDouble(sa.nextToken());
				b[i] = Double.parseDouble(sb.nextToken());
			}
			
			Arrays.sort(a);
			Arrays.sort(b);
			
			pw.print("Case #" + t + ": ");
			
			int pb = 0;
			int offset = 0;
			
			for(int i = 0; i < n; i++){
				while(pb < n && b[pb] < a[i]){
					pb++;
				}
				if(pb + offset - 1 < i){
					offset = i - pb + 1;
				}
				//pw.println(i + " " + pb + " " + offset);
			}
			
			pw.print((n - offset) + " ");
			
			int high = n-1;
			int low = 0;
			int pts = 0;
			
			for(int i = n-1; i >= 0; i--){
				if(b[high] > a[i]){
					high--;
				} else {
					pts++;
					low++;
				}
			}
			
			pw.println(pts);
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