
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;

public class GCJ_Fractiles_v2 {

	void log(long[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}

	void log(double[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}

	void log(int[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}
	void log(Object[] X){
		int L=X.length;
		for (int i=0;i<L;i++){
			logWln(X[i]+" ");
		}
		log("");
	}


	void log(Object o){
		logWln(o+"\n");
	}

	void logWln(Object o){
		System.out.print(o);
		//	outputWln(o);

	}
	void info(Object o){
		System.out.println(o);
		//output(o);
	}

	long shift(long x,long max,int K,int C,int shift){
		int c=C;
		long res=0;
		while (c>0){
			//log("x:"+x);
			max/=K;
			res+=((x/max+shift)%K)*max;
			x%=max;
			c--;
		}
		return res;

	}


	String solveStrange(int K,int C,int S){
		ArrayList<Long> list=solveBiz(K,C,S);
		if (list==null)
			return "IMPOSSIBLE";
		String res="";
		for (long x:list)
			res+=(x+1)+" ";
		return res;
	}
	


	ArrayList<Long> solveBiz(int K,int C,int S){
		long KC=1;
		for (int x=0;x<C;x++)
			KC*=K;
		ArrayList<Long> res=new ArrayList<Long>();
		if (S==K){
			for (int i=0;i<K;i++)
				res.add((long)(i));
			return res;
		}
		int n=K/C;
		if (n*C<K)
			n++;
		if (S<n){
			return null;
		}
		long y=K-3;
		long p=y*y+5*y+5;
		res.add(p);
		for (int u=1;u<n;u++)
			res.add(shift(p,KC,K,C,K-(u*C)%K));
		
		
		return res;
	}

	
	// Global vars
	StringTokenizer st;
	BufferedReader in;
	BufferedWriter out;



	void process() throws Exception {
		Locale.setDefault(Locale.US);


		//check(7,3);

		//File inputFile=new File("B-large.in");
		File inputFile=new File("D.in");



		//		PrintWriter outputFile= new PrintWriter("B-large.out","UTF-8");
		PrintWriter outputFile= new PrintWriter("D.out","UTF-8");



		Scanner sc=new Scanner(inputFile);
		sc.useLocale(Locale.US);





		int T=sc.nextInt();
		for (int t=1;t<=T;t++){
			int K=sc.nextInt();
			int C=sc.nextInt();
			int S=sc.nextInt();
			String s=solveStrange(K,C,S);
			System.out.println("Case #"+t+": "+s);
			outputFile.println("Case #"+t+": "+s);

		}



		sc.close();
		outputFile.close();


	}



	public static void main(String[] args) throws Exception {
		GCJ_Fractiles_v2 J=new GCJ_Fractiles_v2();

		J.process();


	}






}
