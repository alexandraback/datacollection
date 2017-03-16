package codejam2012.round1A;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class ProblemB {
	private static String dir=System.getProperty("user.dir") + "/io/R1A2012/";

	static String problemLetter= "B";
//	static String fname= problemLetter + "-test";
		static String fname= problemLetter + "-small-attempt6";
	//		static String fname= problemLetter + "-large";

	public class MyComparator implements Comparator<Pair> {

		@Override
		public int compare(Pair arg0, Pair arg1) {

			return arg0.b-arg1.b;
		}


	}

	class Pair implements Comparable<Pair>{
		public int a;
		public int b;
		public int indice;


		public Pair(int a, int b, int indice) {
			super();
			this.a = a;
			this.b = b;
			this.indice=indice;
		}


		@Override
		public int compareTo(Pair o) {
			int result=a-o.a;
			if(result==0)
				return o.b-b;
			else
				return result;

		}


		@Override
		public String toString() {
			return "Pair [a=" + a + ", b=" + b + ", indice=" + indice + "]";
		}




	}
	public void test(Scanner input, PrintWriter out, int testCase) {
		int levels=input.nextInt();
		System.out.println("levels=" + levels);
		List<Pair> lista= new ArrayList<ProblemB.Pair>();
		List<Pair> lista2= new ArrayList<ProblemB.Pair>();
		for(int i=0;i<levels;i++) {
			int a=input.nextInt();
			int b=input.nextInt();
			lista.add(new Pair(a,b,i));
			lista2.add(new Pair(a,b,i));


		}

		Collections.sort(lista,  new MyComparator() );
		Collections.reverse(lista);
		System.out.println(lista);
		Collections.sort(lista2, new MyComparator() );
		System.out.println(lista2);

		int myStar=0;
		int completed=0;
		int played=0;
		boolean tooBad=false;
		List<Integer> solved= new ArrayList<Integer>();
		List<Integer> solvedOneStar= new ArrayList<Integer>();

		while(completed<levels) {
			boolean solvedCiclo=false;
			for(Pair current : lista2) {
				if(!solvedCiclo) {
					if(!solved.contains(current.indice) ) {
						if(current.b<=myStar) {
							System.out.println("Choosed " + current.indice + " for 2 star");
							completed++;
							played++;
							solved.add(current.indice);

							if(solvedOneStar.contains(current.indice)) {
								myStar+=1;
							} else {
								myStar+=2;
							}
							solvedCiclo=true;
						} 
					}
				}
			}

			for(Pair current : lista) {
				if(!solvedCiclo) {
					if(!solved.contains(current.indice) && !solvedOneStar.contains(current.indice) ) {
						
						if(current.a<=myStar) {
							System.out.println("Choosed " + current.indice + " for 1 star");
							solvedOneStar.add(current.indice);
							myStar+=1;
							solvedCiclo=true;
							played++;
						} 
					}
				}
			}
			if(!solvedCiclo)
			{
				tooBad=true;
				break;
			}
			System.out.println("Completed=" + completed);
		}
		String resultCase;
		if(tooBad)
			resultCase= "Case #" + (testCase+1) + ": " + "Too Bad";
		else
			resultCase= "Case #" + (testCase+1) + ": " + played;
		System.out.println(resultCase);
		out.println(resultCase);
	}


	public void run() {
		try {
			String inputPath = dir + fname;

			Scanner input =new Scanner(new File(inputPath + ".in"));
			FileWriter outFile = new FileWriter(inputPath + ".out");
			PrintWriter out = new PrintWriter(outFile);
			try {		
				int testCases = input.nextInt();
				input.nextLine();

				for(int i=0 ; i < testCases ; i++)
					test(input,out,i);
			}
			finally {
				input.close();
				out.close();
			}
		}
		catch (IOException ex){
			ex.printStackTrace();
		}
	}

	public static void main(String[] args) {
		ProblemB template = new ProblemB();
		template.run();
	}


}
