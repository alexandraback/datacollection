import java.text.*;
import java.io.*;
import java.util.*;
import java.lang.Math;

public class A
{
	public static void main(String[] args) throws Exception
	{
		DecimalFormat df = new DecimalFormat("0.000000");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String str;
		String[] ss;
		
		int T = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= T; t++) {
			System.out.print("Case #" + t + ": ");
			
			str = br.readLine();
			ss = str.split(" ");
			int A = Integer.parseInt(ss[0]);
			int B = Integer.parseInt(ss[1]);
			
			str = br.readLine();
			ss = str.split(" ");
			
			double[] arr = new double[A];
			
			for(int i = 0; i < A; i++) {
				arr[i] = Double.parseDouble(ss[i]);
			}
			
			double ans1, ans2, ans3;
			
			double p1 = 1;
			for(int i = 0; i < A; i++) {
				p1 *= arr[i];
			}
			ans1 = p1 * (B-A + 1) + (1 - p1) * (2*B-A + 2);
			
			ans3 = 2 + B;
			
			double[] a2 = new double[A];
			
			double prob = 1;
			for(int i = 0; i < A; i++) {
				prob *= arr[i];
				
				a2[i] = prob * (A-(i+1) + B-(i+1) + 1) + (1 - prob) * (A-(i+1) + 2*B - (i+1) + 2);
				
			}
			//System.out.println();
			ans2 = ans1;
			for(int i = 0; i < A; i++) {
				//System.out.println("a2 " + i + ": " + a2[i]);
				if(a2[i] < ans2) {
					ans2 = a2[i];
				}
			}
			//System.out.println("ans1: " + ans1);
			//System.out.println("ans3: " + ans3);
			
			double result = ans1;
			if(ans2 < result) result = ans2;
			if(ans3 < result) result = ans3;
			
			System.out.println(df.format(result));
		}
		
	}
}