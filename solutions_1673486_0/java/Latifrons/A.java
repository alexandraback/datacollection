import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {	
	static String in = "1s.in";
	static String out = "1s.out";
	
	public static double pi(double[] a,int start,int end){
		double p = 1;
		for (int i = start; i < end;i++){
			p *=a[i];
		}
		return p;
	}
	
	public static String handle(){
		//solution place holder
		int A = s.nextInt();
		int B = s.nextInt();
		double[] p = new double[A];
		for (int i = 0 ; i < A ; i++){
			p[i]=s.nextDouble();
		}
//		//1
//		double ex1=0;
//		{
//			double prob = pi(p,0,p.length);
//			ex1 = (B-A+1)*prob +(2*B-A+2)*(1-prob);
//		}
//		//2
		double ex2 = Double.MAX_VALUE;
		{
			for (int i = 0;i <= A;i++){
				double prob = pi(p,0,p.length-i);
				double ex = (B-A+2*i+1)*prob + (2*B-A+2*i+2)*(1-prob);
				if (ex2 > ex){
					ex2 = ex;
				}
			}
		}
		//3
		if (ex2 > B+2){
			ex2 = B + 2;
		}
		
		return Double.toString(ex2);
	}
	
	public static void init(){}
	static Scanner s;
	static FileWriter fw;
	public static void main(String[] args) throws IOException{
		s = new Scanner(new FileInputStream(in));
		fw = new FileWriter(out);
		
		init();
		
		int lines = s.nextInt();
		for (int i = 1 ; i <= lines ;i++){
			long start = System.currentTimeMillis();
			String result = handle();
			String output = String.format("Case #%d: %s\n", i,result);
			fw.write(output);
			System.out.printf("%3d %s",(System.currentTimeMillis()-start)/1000,output);
		}
		
		fw.close();
	}
}
