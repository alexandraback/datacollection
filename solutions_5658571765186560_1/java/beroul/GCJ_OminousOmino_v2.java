import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.StringTokenizer;



class GCJ_OminousOmino_v2 {

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


	// Global vars
	StringTokenizer st;
	BufferedReader in;
	BufferedWriter out;
	
	String RIC="RICHARD";
	String GAB="GABRIEL";
	
	String solve(int X,int R,int C){
		// on va travailler avec R<=C (le petit)
		if (R>C)
			return solve(X,C,R);
		if (X==1)
			return GAB;
		if ((R*C)%X!=0)
			return RIC;
		if (X==2){
				return GAB;
		}
		if (X==3){
			if (R==1)
				return RIC;
			else
				return GAB;
		}
		if (X==4){
			// on plante les 1x
			// on plante tous les 2x, grace à
			//    ###
			//    .#.
			//
			// les 3x4 ? ok
			if (R<=2)
				return RIC;
			return GAB;
		}
		if (X==5){
			// bloque à 5x1 5x2 et 5x3, et ok au delà
			// bloque x1 et x2 
			// mais il faut vérifier 3x10 et 3x15
			// 3x10 est ok. Donc 3x15 & cie 
			
			// ATTENTION ON TRAITE MAL LE CAS DES MULTIPLES
			if (R<=2)
				return RIC;
			if (R==3 && C==5)
				return RIC;
			return GAB;
		}
		if (X==6){
			// bloque aussi 1x et 2x 
			// bloque 3x 
			// à cause de
			//  .##
			//  .#.
			//  ##.
			//  #..
			
			if (R<=3)
				return RIC;
			return GAB;
		}
		// au delà on peut mettre un trou, donc c'est foutu pour GAB
		return RIC;
	}
	
	void process() throws Exception {
		Locale.setDefault(Locale.US);




		//File inputFile=new File("D-large.in");
		File inputFile=new File("D-large.in");
		
		

		//		PrintWriter outputFile= new PrintWriter("D-large.out","UTF-8");
		PrintWriter outputFile= new PrintWriter("D-large.out","UTF-8");


		Scanner sc=new Scanner(inputFile);
		sc.useLocale(Locale.US);

		long startTime,endTime;
		
		
		int T=sc.nextInt();
		for (int t=1;t<=T;t++){
			
			int X=sc.nextInt();
			int R=sc.nextInt();
			int C=sc.nextInt();
			String ss=solve(X,R,C);
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);


		}



		sc.close();
		outputFile.close();


	}



	public static void main(String[] args) throws Exception {
		GCJ_OminousOmino_v2 J=new GCJ_OminousOmino_v2();

		J.process();


	}




}