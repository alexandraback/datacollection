import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;


public class Round1C_A {


	String round="Round_1C";
	String exercice="A";

	// global var
	int N;
	int P,Q;
	String S;
	
	void log(Object s) {
		System.out.println(s);
	}
	
	void info(String s) {
		System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}
	
	int pgcd(int a,int b){
		////log("pgcd "+a+" "+b);
		if (b>a)
			return pgcd(b,a);
		if (b==0) {
		//	//log("pgcd >>> "+a);
			return a;
		}
		return pgcd(b,a%b);
	}
		
	String solveSmall(){
		int L=S.length();
		int i=0;
		while (S.charAt(i)!='/')
				i++;
		String s1=S.substring(0,i);
		String s2=S.substring(i+1);
		P=Integer.parseInt(s1);
		Q=Integer.parseInt(s2);
		int Z=pgcd(P,Q);
		P=P/Z;
		Q=Q/Z;
		//log(P);
		//log(Q);
		int q=Q;
		
		if (q%2!=0)
			return "impossible";
		int gene=0;
		while (q%2==0){
			gene++;
			q=q/2;
		}
		if ((q!=1)||(gene>40))
			return "impossible";
		int n=1;
		int cur=2;
		
		//log((P*cur)+" "+Q);
		while (P*cur<Q) {
			n++;
			cur=cur*2;
		}
		return ""+n;
	}



	void process() throws Exception {

	//	File inputFile=new File(round+"/test_"+exercice+".in");
	//	PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");
	

			File inputFile=new File(round+"/"+exercice+"-small-attempt1.in");
			PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt1.out","UTF-8");

		
	//	File inputFile=new File(round+"/"+exercice+"-large.in");
	//	PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");

	

		for (int t=1;t<=T;t++) {
	
			// do Something
			S=scanner.next();
			
			
			/*
			for (int i=0;i<N;i++){
			
			}
			*/	
			
			String ss=""+solveSmall();
		
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);
			
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		Round1C_A J=new Round1C_A();
		J.process();
	}


}

