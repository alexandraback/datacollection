package codejam2012.round1B;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;


public class Problem1C {
	private static String dir=System.getProperty("user.dir") + "/io/R1B2012/";

	static String problemLetter= "C";
//	static String fname= problemLetter + "-test";
		static String fname= problemLetter + "-small-attempt0";
	//	static String fname= problemLetter + "-large";

	private static ArrayList<ArrayList<Long>> getSubsets(
			ArrayList<Long> set) {

		ArrayList<ArrayList<Long>> subsetCollection = new ArrayList<ArrayList<Long>>();

		if (set.size() == 0) {
			subsetCollection.add(new ArrayList<Long>());
		} else {
			ArrayList<Long> reducedSet = new ArrayList<Long>();

			reducedSet.addAll(set);

			long first = reducedSet.remove(0);
			ArrayList<ArrayList<Long>> subsets = getSubsets(reducedSet);
			subsetCollection.addAll(subsets);

			subsets = getSubsets(reducedSet);

			for (ArrayList<Long> subset : subsets) {
				subset.add(0, first);
			}

			subsetCollection.addAll(subsets);
		}

		return subsetCollection;
	}
	
	public void test(Scanner input, PrintWriter out, int testCase) {
		int n=input.nextInt();
		long num[]=new long[n];
		ArrayList<Long> nums=new ArrayList<Long>();
		long sum=0;
		for(int i=0;i<n;i++) {
			num[i]=input.nextLong();
			nums.add(num[i]);
			sum+=num[i];

		}
		System.out.println("num=" + Arrays.toString(num) + " sum=" +sum);
		Collections.sort(nums);
		
		ArrayList<ArrayList<Long>> subSets = getSubsets(nums); 
		System.out.println("subsets.size()=" + subSets.size() );
		
		ArrayList<Long> results=new ArrayList<Long>();
		
		Long r=null;
		for(ArrayList<Long> sub : subSets ) {
			r=sum(sub);
			if(results.contains(r)) {
				break;
			} 
			else
				results.add(r);
		}
		System.out.println(r);
		
		ArrayList<Long> subA=new ArrayList<Long>();
		ArrayList<Long> subB=new ArrayList<Long>();
		for(ArrayList<Long> sub : subSets ) {
			long aa=sum(sub);
			
			if(aa==r) {
				if(subA.size()==0)
					subA=sub;
				else {
					subB=sub;
					break;
				}
			}
		}
		System.out.println("subA=" + subA);
		System.out.println("subB=" + subB);
		
		StringBuffer sb=new StringBuffer();
		sb.append("\n");
		for(Long l : subA) {
			sb.append(l);
			sb.append(" ");
		}
		sb.append("\n");
		for(Long l : subB) {
			sb.append(l);
			sb.append(" ");
		}
			

		String resultCase = "Case #" + (testCase+1) + ": " + sb.toString();
		System.err.println(resultCase);
		out.println(resultCase);
	}


	private long sum(ArrayList<Long> sub) {
		long res=0;
		for(Long l: sub)
			res+=l;
		return res;
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

				long start=System.currentTimeMillis();
				for(int i=0 ; i < testCases ; i++)
					test(input,out,i);
				System.out.println("Elapsed:" + (System.currentTimeMillis() - start ) +"ms");
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
		Locale.setDefault(new Locale("en"));
		Problem1C template = new Problem1C();
		template.run();
	}


}

