import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class CookieClickerAlpha {


	String round="Qualification";
	String exercice="B";

	// global var
	double C,F,X;

	void log(String s) {
		System.out.println(s);
	}
	
	void info(String s) {
		//System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}

	

	String solve(){
		double rate=2;
		double count=0;
		double t1;
		double t2;
		double t=0;
		double target;
		double nextStep;
		info("C="+C+" F="+F+" X="+X);
		while (count<X) {
			t1=(double)(X-count)/(double)rate;
			boolean ok=true;
			while ((count>=C)&&ok) {
				t2=(double)(X-count+C)/(double)(rate+F);
				if (t2<t1){
					count-=C;
					rate+=F;
				}
				else
					ok=false;
			}
			if (count>=C)
				nextStep=X;
			else
				nextStep=Math.min(C,X);
			double dt=(double)(nextStep-count)/(double)rate;
			t=t+dt;
			count=nextStep;
			info("Running "+dt+" to reach "+count);
		}
		return ""+t;
	}




	void process() throws Exception {

		//File inputFile=new File(round+"/test_"+exercice+".in");
		//PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");


			File inputFile=new File(round+"/"+exercice+"-small-attempt0.in");
			PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt0.out","UTF-8");
		//File inputFile=new File(round+"/"+exercice+"-large-practice.in");
		//PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large-practice.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");



		for (int t=1;t<=T;t++) {
			C=scanner.nextDouble();	
			F=scanner.nextDouble();	
			
			X=scanner.nextDouble();	
				
			
	
			String ss=""+solve();
			System.out.println("Case #"+t+": "+ss);

			outputFile.println("Case #"+t+": "+ss);
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		CookieClickerAlpha J=new CookieClickerAlpha();
		J.process();
	}


}

