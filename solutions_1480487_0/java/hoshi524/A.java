import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {
	static FileWriter out;
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
		out=new FileWriter("out.txt");
		int T=sc.nextInt();
		for(int t=1;t<=T;t++){
			int n=sc.nextInt();
			int buf[]=new int[n],sum=0;
			for(int i=0;i<n;i++){
				buf[i]=sc.nextInt();
				sum+=buf[i];
			}
			boolean flag[]=new boolean[n];
			int n2=n,sum2=0;
			for(int i=0;i<n;i++){
				if(sum*2<=buf[i]*n){
					flag[i]=true;
					n2--;
					sum2+=buf[i];
				}
			}
			String str="";
			for(int i=0;i<n;i++){
				if(i!=0)
					str+=" ";
				if(flag[i])
					str+="0";
				else
					str+=String.format("%.6f", ((double)(sum*2-sum2-buf[i]*n2)/(double)(sum*n2))*100.0);
			}
			output("Case #"+t+": "+str);
		}
		out.close();
	}
	
	static void output(String str) throws IOException{
		out.write(str+"\n");
		System.out.println(str);
	}
}
