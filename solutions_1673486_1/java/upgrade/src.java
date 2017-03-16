import java.util.*;
import java.io.*;
import java.text.*;

public class Q {
	
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		PrintStream out = new PrintStream("output.txt");
		
		int num = in.nextInt();
		in.nextLine();
		double[] ps = new double[100001];
		double[] psagg = new double[100001];
		for (int i=0;i<num;++i) {
			int a = in.nextInt();
			int b = in.nextInt();	
			psagg[0]=1;
			for (int j=0;j<a;++j) {
				ps[j+1]=in.nextDouble();
				psagg[j+1]=psagg[j]*ps[j+1];
			}
			double min = b+2;
			for (int j=a;j>0;--j) {
				min=Math.min(min, (a-j+b-j+1) + (b+1)*(1-psagg[j]));
			}
			
			StringBuilder builder = new StringBuilder("Case #" +(i+1)+": ");
			
			builder.append(String.format("%.6f", min));
			System.out.println(builder.toString());
			out.println(builder.toString());
		}
		
		in.close();
		out.close();
	}	
}
