import static java.util.Arrays.deepToString;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class QA {

	public static void main(String[] args) throws Exception 
	{
		new QA().run();
		
	}
	
	void run() throws Exception 
	{
		//Scanner sc = new Scanner(System.in);
		
		NumberFormat formatter = new DecimalFormat("#0.000000");
		
		
		//debug(formatter.format(i));
		//Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		FileWriter fstream = new FileWriter("out.in");
		BufferedWriter out = new BufferedWriter(fstream);

		int ntest = Integer.valueOf(sc.nextLine());
		
		for(int test=1;test<=ntest;++test) 
		{
			int readNum = sc.nextInt();
			int total = sc.nextInt();
			float[] acc = new float[readNum];
			for(int i=0; i<readNum; i++)
			{
				acc[i] = sc.nextFloat();
			}
			
			double res0 = calculateSol1(readNum, total, acc);
			double res1 = calculateSol2(readNum, total, acc);
			double res2 = calculateSol3(readNum, total, acc);
			
			double res = Math.min(res0, res1);
			res = Math.min(res, res2);
			debug(res);
			out.write("Case #" + test + ": ");
			out.write(formatter.format(res));
			out.write("\n");
		}
		out.close();
		sc.close();
	
	}
	
	double calculateSol1(int readNum, int total, float[] acc)
	{
		double res = 0;
		
		//right case
		int numRight = total - readNum + 1;
		int numWrong = numRight + total + 1;
		
		float correctRate = 1;
		
		for(int i=0; i<readNum; i++)
		{
			correctRate = correctRate * acc[i];
		}
		
		res = correctRate * numRight + (1-correctRate) * numWrong;
		
		return res;
	}
	
	double calculateSol2(int readNum, int total, float[] acc)
	{
		double res = total * 5;
		
		int typeBackNum = readNum;
		while(typeBackNum > 0)
		{
			float currentRes = 0;
			int numRight = typeBackNum + total - (readNum - typeBackNum) + 1;
			int numWrong = numRight + total + 1;
			
			float correctRate = 1;
			
			if(typeBackNum == readNum)
			{
				correctRate = 0;
			}
			
			for(int i=0; i<readNum-typeBackNum; i++)
			{
				correctRate = correctRate * acc[i];
			}
			
			currentRes = correctRate * numRight + (1-correctRate) * numWrong;
			
			if(currentRes < res) res = currentRes;
			typeBackNum --;
		}
		
		return res;
	}
	
	double calculateSol3(int readNum, int total, float[] acc)
	{
		double res = total + 2;
		
		
		
		return res;
	}
	
	
	void debug(Object...os) 
	{
		System.err.println(deepToString(os));
	} 
	
	void debugArray(Object[]...os) 
	{
		System.err.println(deepToString(os));
	} 
}
