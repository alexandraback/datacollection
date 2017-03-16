
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;



class Main{
	public static void main(String arg0[])throws IOException{
		BufferedReader f = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
		DecimalFormat df=new DecimalFormat("0.000000");
		df.setRoundingMode(RoundingMode.HALF_UP);
		Scanner in=new Scanner(f);
		int cin=in.nextInt();
		for (int ci=0;ci<cin;ci++){
			int a=in.nextInt();
			int b=in.nextInt();
			double gan[]=new double[a];
			double dp[]=new double[a+1];
			double dps[]=new double[a+1];
			for (int i=0;i<a;i++){
				gan[i]=in.nextDouble();
			}
			//double dpf[]=new double[a];
			dp[0]=b+a+1;
			dps[0]=1;
			for (int i=1;i<=a;i++){
				dps[i]=dps[i-1]*gan[i-1];
				double ss=dps[i];
				dp[i]=ss*(b+a-i*2+1)+(1-ss)*(b+a-i*2+1+b+1);
				
			}
			double min=b+2;
			for (int i=0;i<=a;i++){
				min=min<dp[i]?min:dp[i];
			}
			out.println("Case #"+(ci+1)+": "+df.format(min));
		}
		   out.close();          
		   System.exit(0);  
	}
}