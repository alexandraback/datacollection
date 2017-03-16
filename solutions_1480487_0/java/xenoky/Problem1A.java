package codejam2012.round1B;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;




public class Problem1A {

	private static String dir=System.getProperty("user.dir") + "/io/R1B2012/";

	static String problemLetter= "A";
	//	static String fname= problemLetter + "-test";
	static String fname= problemLetter + "-small-attempt2";
	//	static String fname= problemLetter + "-large";
	DecimalFormat df = new DecimalFormat("#.######");



	public void test(Scanner input, PrintWriter out, int testCase) {
		int n=input.nextInt();
		List<Integer> voti=new ArrayList<Integer>();
		int sum=0;
		for(int i=0;i<n;i++)  {
			int current=input.nextInt();
			voti.add(current) ;
			sum+=current;
		}
		List<Integer> isZero=new ArrayList<Integer>();
		
		List<Double> resultList=new ArrayList<Double>();
		
		double result[]=risolvi(voti,sum,isZero);
		for(int i=0;i<result.length;i++)
			resultList.add(result[i]);

		boolean uZero=false;
		for(int i=0;i<n;i++)  {
			if(result[i]<0) {
				uZero=true;
				isZero.add(i);
			}
		}
		
		
		if(uZero) {
			resultList=new ArrayList<Double>();
			System.out.println("isZero=" + isZero);
			List<Integer> voti2=new ArrayList<Integer>();
			
			for(int i=0;i<n;i++)  {
				if(!isZero.contains(i))
					voti2.add(voti.get(i));	
			}
			n=voti2.size();
			System.out.println("new voti=" + voti2 + " isZero=" + isZero);
//			sum=0;
//			for(int i=0;i<voti2.size();i++)
//				sum+=voti2.get(i);
			System.out.println("new sum=" + sum);
			result=risolvi(voti2,sum,isZero);
			
			
			
			for(int i=0;i<n;i++) {
				resultList.add(result[i]);
			}
			for(Integer i : isZero) {
				resultList.add(i,0.0);
			}
			System.out.println("resultList=" +resultList);
		}

		//		System.out.println("result=" + Arrays.toString( result));
		//		if(uZero) {
		//			
		//			
		//			equalPerc = 1.0 / (c*1.0);
		//			
		//			System.out.println("---------------voti2=" + Arrays.toString(voti2) + " equalPerc=" + equalPerc + " sum=" +sum + " newn=" + c);
		//			double scoredEqual2[]=new double[n];
		//			double sumScoredEqual2=0;
		//			for(int i=0;i<n;i++)  {
		//				scoredEqual2[i]=voti2[i]*1.0+sum*equalPerc;
		//				sumScoredEqual2+=scoredEqual2[i];
		//			}
		//			System.out.println("scoredEqual2=" + Arrays.toString(scoredEqual2) + " sumScoredEqual=" + sumScoredEqual2);
		//			double mean2=sumScoredEqual2 / (n*1.0);
		//			System.out.println("mean2=" + mean2);
		//			
		//			for(int i=0;i<n;i++)  {
		//				result[i]=((mean2-voti[i])/(sum*1.0))*100;
		//			}
		//			System.out.println("result=" + Arrays.toString( result));
		//		}


		double sumOfResult=0;
		for(Double d: resultList)  {
			sumOfResult+=d;
		}
		System.out.println("SumOfResult=" + sumOfResult );

		StringBuffer sb=new StringBuffer();
		for(Double d: resultList)  {

			sb.append(df.format(d) );
			sb.append(" ");
		}


		String resultCase = "Case #" + (testCase+1) + ": " +sb.toString();
		System.out.println(resultCase);
		out.println(resultCase);
	}


	private double[] risolvi(List<Integer> voti, int sum, List<Integer> isZero) {
		int n=voti.size();
		double equalPerc = 1.0 / (n*1.0);

		System.out.println("voti=" + voti + " equalPerc=" + equalPerc + " sum=" +sum);
		double scoredEqual[]=new double[n];
		double sumScoredEqual=0;
		for(int i=0;i<n;i++)  {
			scoredEqual[i]=voti.get(i)*1.0+sum*equalPerc;
			sumScoredEqual+=scoredEqual[i];
		}
		System.out.println("scoredEqual=" + Arrays.toString(scoredEqual) + " sumScoredEqual=" + sumScoredEqual);
		double mean=sumScoredEqual / (n*1.0);
		System.out.println("mean=" + mean);

		boolean uZero=false;
		int c=0;

		double result[]=new double[n];
		for(int i=0;i<n;i++)  {
				if(sum==0) {
					result[i]=0;
					System.out.println("-------------sum=0");
				}
					
				else
					result[i]=((mean-voti.get(i))/(sum*1.0))*100;
		}
		System.out.println("result="+Arrays.toString(result));
		return result;
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
		Problem1A template = new Problem1A();
		template.run();
	}


}
