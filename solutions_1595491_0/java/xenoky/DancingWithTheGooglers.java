package codejam2012.qualification;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class DancingWithTheGooglers {
	static String dir="/home/casatta/Scaricati/";
//	static String dir="data/";
	
	static String fname="B-small-attempt0.in";
//	static String fname="DancingWithTheGooglers";
	
	
	public void test(Scanner input, PrintWriter out, Long i) {
		int n=input.nextInt();
		int surprising=input.nextInt();
		int p=input.nextInt();
		
		int max=p*3;
		int notSurprising=max-2;
		int isSurprising=max-4;
		int count=0;
		int current;
		
		System.out.println("n=" + n + " surprising=" + surprising + " p=" + p );
		System.out.println("max=" + max + " notSurprising=" + notSurprising + " isSurprising=" + isSurprising );
		
		
		for(int j=0;j<n;j++) {
			current=input.nextInt();
			System.out.print(" " + current);
			if(current>=notSurprising)
				count++;
			else if(current>=isSurprising && surprising>0 && current>=p) {
				count++;
				surprising--;
			}
		}
		
		
		
		
		System.out.println();
		
		String result = "Case #" + (i+1) + ": " +count;
		out.println(result);
		System.out.println(result);
		System.out.println();
	}
	
	
	public void run() {
			
		
		try {
			String inputPath = dir + fname;

			Scanner input =new Scanner(new File(inputPath));
			FileWriter outFile = new FileWriter(inputPath + ".out");
			PrintWriter out = new PrintWriter(outFile);
			try {		
				Long testCases = input.nextLong();
				input.nextLine();

				for(Long i=0L ; i < testCases ; i++)
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
		DancingWithTheGooglers template = new DancingWithTheGooglers();
		template.run();
	}
	

}
