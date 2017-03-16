import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	
	int T;
	int t = 1; 
	String[] out;
	
	public A() throws FileNotFoundException  {
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		T = sc.nextInt();
		sc.nextLine();
		out = new String[T];
		
		while(sc.hasNext()){
			int a = sc.nextInt();
			int b = sc.nextInt();
			double[] p = new double[a];
			sc.nextLine();
			for(int i = 0; i<a; i++){
				String n = sc.next();
				p[i] = Double.parseDouble(n);
			}
			calcOut(a, b,p);
			t++;
		}
		PrintWriter pw = new PrintWriter(new File("out"));
		for(String s : out){
			pw.println(s);
		}
		pw.close();
	}
	
	//A = Already typed
	//B = total chars
	public void calcOut(int A, int B,double[] p){
		Double[] ans = new Double[4];
		 ans[0] = (double)(B + 2);
		 ans[1] = calcProb(A, B, p, 1);
		 ans[2] = calcProb(A-1, B, p,2);
		 ans[3] = calcProb(A-2,B,p,3);
		 
		 double fin = ans[0];
		 for(int i = 0; i<ans.length; i++){
			 if(ans[i]<fin){
				 fin = ans[i];
			 }
		 }
		
		
		out[t-1] = "Case #"+t+": "+fin ;
	}
	
	public double calcProb(int A, int B , double[] p, int init){
		double KT = 1;
		for(int i = 0; i<A; i++){
			KT*=p[i];
		}
		double rest = 1-KT;
		return (B-A + init) * KT + rest * ((B-A + init) + B +1);
	}
	
	public static void main(String[] args) {
		try {
			new A();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
