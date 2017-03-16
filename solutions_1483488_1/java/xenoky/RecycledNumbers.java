package codejam2012.qualification;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class RecycledNumbers {
		static String dir="/home/casatta/Scaricati/";
//	static String dir="data/";

	//	static String fname="B-large.in";
//	static String fname="C-small-attempt0.in";
	static String fname="C-large.in";
//	static String fname="RecycledNumbers";


	public void test(Scanner input, PrintWriter out, Long i) {
		int a=input.nextInt();
		int b=input.nextInt();

		int count=0;

		for(int j=a;j<=b;j++) {
			count=count+countGoodRecycled(j, b);

		}

		String result = "Case #" + (i+1) + ": " +count;
		out.println(result);
		System.out.println(result);
		System.out.println();
	}

	int countGoodRecycled(int val,int maxVal) {
		String valString=""+val;
		int length=valString.length();
		Set<Integer> results=new HashSet<Integer>();

		for(int i=length-1;i>0;i--) {
			if(valString.charAt(i)!='0') {
				String after =valString.substring(i);
				String before=valString.substring(0,i);
				int inverse=Integer.parseInt( after+before );
				if(inverse<=maxVal && val<inverse) {
//					System.out.println(val + "=" + inverse);
					results.add(inverse);
					
				}
			}

		}

		return results.size();

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
				long start=System.currentTimeMillis();
				for(Long i=0L ; i < testCases ; i++)
					test(input,out,i);
				System.out.println("elapsed:" + (System.currentTimeMillis()-start) );
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
		RecycledNumbers template = new RecycledNumbers();
		template.run();
	}


}
