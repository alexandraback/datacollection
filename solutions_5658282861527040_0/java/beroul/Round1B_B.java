import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;


public class Round1B_B {


	String round="Round_1B";
	String exercice="B";

	// global var
	int A,B,K;
	
	void log(Object s) {
		System.out.println(s);
	}
	
	void info(String s) {
		System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}

		
	String solve_bourrin(){
		int count=0;
		for (int X=0;X<A;X++)
			for (int Y=0;Y<B;Y++) {
				if ((X & Y)<K)
					count++;
			}
		
	return ""+count;
}


	void process() throws Exception {

	//	File inputFile=new File(round+"/test_"+exercice+".in");
	//	PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");
	

			File inputFile=new File(round+"/"+exercice+"-small-attempt0.in");
			PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt0.out","UTF-8");

		
	//	File inputFile=new File(round+"/"+exercice+"-large.in");
	//	PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");

		

		for (int t=1;t<=T;t++) {
	
			// do Something
			
			A=scanner.nextInt();
			B=scanner.nextInt();
			K=scanner.nextInt();
			
			
			/*
			for (int i=0;i<N;i++){
			
			}
			*/	
			
			String ss=""+solve_bourrin();
		
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);
			
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		Round1B_B J=new Round1B_B();
		J.process();
	}


}

