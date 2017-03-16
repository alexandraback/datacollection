import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

public class A {
	static FileWriter out;
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
		out=new FileWriter("out.txt");
		int T=sc.nextInt();
		for(int t=1;t<=T;t++){
			int a=sc.nextInt(),b=sc.nextInt();
			double enter=b+2.0,kaku=1.0,ans=Double.MAX_VALUE;
			for(int i=1;i<=a;i++){
				kaku*=sc.nextDouble();
				double tmp=kaku*((b-a+1)+(a-i)*2)+(1.0-kaku)*(((b-a+1)+(a-i)*2)+b+1);
				ans=Math.min(ans, tmp);
			}
			DecimalFormat df=new DecimalFormat();
			df.setMaximumFractionDigits(6);
	        df.setMinimumFractionDigits(6);
			output("Case #"+t+": "+df.format(Math.min(ans, enter)));
		}
		out.close();
	}
	
	static void output(String str) throws IOException{
		out.write(str+"\n");
		System.out.println(str);
	}
}
