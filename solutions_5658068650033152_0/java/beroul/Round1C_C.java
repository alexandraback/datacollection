import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;


public class Round1C_C {


	String round="Round_1C";
	String exercice="C";

	// global var
	int N,M,K;
	
	void log(Object s) {
		System.out.println(s);
	}
	
	void info(String s) {
		System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}

	class Composite implements Comparable<Composite>{
		int stones;
		int enclosed;
		String name;
		
		Composite(int stones, int enclosed,String name) {
			this.stones = stones;
			this.enclosed = enclosed;
			this.name=name;
		}
		
		// on veut d'abord classer par stones
		// et ensuite par enclosed
		
		public int compareTo(Composite X){
			if (stones!=X.stones)
					return (stones-X.stones);
			return enclosed-X.enclosed;
		}
		
	}
	
	String solve(){
		
		
		if ((M<=2)|| (N<=2))
			return ""+K;
		
		ArrayList<Composite> sol=new ArrayList<Composite>();
		sol.add(new Composite(K,K,"myself"));
		
		
		// plusieurs options
		// le carré plein
		// le carré sans les coiins
		// la coupure horizontale
		// la coupur verticale
		int x,y,stones,enclosed;
		for (int i=1;i<N;i++)
			for (int j=1;j<M;j++) {
				if (K<i*j) {
					sol.add(new Composite(i-1+j+i-1+j-1,K,"case 1"+i+" "+j));
				} 
				if (K==i*j)
					sol.add(new Composite(i+j+i+j-2,K,"case 2"+i+" "+j));
			}
		
		for (int i=3;i<=N;i++){
			for (int j=3;j<=M;j++) {
				
				x=i-2;
				y=j-2;
				stones=2*(x+y);
				enclosed=stones+x*y; 
				sol.add(new Composite(stones,enclosed,"case 3 "+i+" "+j));
				// ensuite les 4 coins
				sol.add(new Composite(stones+1,enclosed+1,"case 4 "+i+" "+j));
				sol.add(new Composite(stones+2,enclosed+2,"case 5 "+i+" "+j));
				sol.add(new Composite(stones+3,enclosed+3,"case 6 "+i+" "+j));
				sol.add(new Composite(stones+4,enclosed+4,"case 7 "+i+" "+j));
			}
		}
	
		
		
		
		Collections.sort(sol);
		for (int i=0;i<sol.size();i++){
			Composite C=sol.get(i);
			if (C.enclosed>=K) {
				return ""+C.stones;
			}
		}
		
		return "Bug";
		}



	void process() throws Exception {

	//	File inputFile=new File(round+"/test_"+exercice+".in");
	//	PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");
	

			File inputFile=new File(round+"/"+exercice+"-small-attempt3.in");
			PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt3.out","UTF-8");

		
	//	File inputFile=new File(round+"/"+exercice+"-large.in");
	//	PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");

		

		for (int t=1;t<=T;t++) {
	
			// do Something
			N=scanner.nextInt();
			M=scanner.nextInt();
			K=scanner.nextInt();
			
			/*
			for (int i=0;i<N;i++){
			
			}
			*/	
			log(N+" "+M+" "+K);
			String ss=""+solve();
		
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);
			
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		Round1C_C J=new Round1C_C();
		J.process();
	}


}

