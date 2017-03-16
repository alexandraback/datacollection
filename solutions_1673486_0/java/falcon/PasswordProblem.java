package gcj.r1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;

public class PasswordProblem 
{
	public double getExpected(int A,int B,double[] probCorrect)
	{
		double allRight=1.0;
		for(int i=0;i<A;++i)
			allRight*=probCorrect[i];
		double ret=Double.MAX_VALUE;
		//keep typing
		double r1=(allRight*(B-A+1))+((1.0-allRight)*((2*B)+2-A));
		ret=Math.min(ret,r1);
		//press enter right away
		double r4=B+2;
		ret=Math.min(ret,r4);
		
		for(int numBkSpace=1;numBkSpace<=A;++numBkSpace)
		{
			int totalTyped=A-numBkSpace;
			double allRightSoFar=1.0;
			for(int i=0;i<totalTyped;++i)
				allRightSoFar*=probCorrect[i];
			double r=allRightSoFar*(numBkSpace+B-totalTyped+1);
			r+=((1.0-allRightSoFar)*(numBkSpace+B-totalTyped+1+B+1));
			ret=Math.min(ret,r);			
		}
		return ret;
	}
	

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception  
	{
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		PasswordProblem obj=new PasswordProblem();		
		for(int t=1;t<=T;++t)
		{
			String[] t1=br.readLine().trim().split(" ");
			String[] t2=br.readLine().trim().split(" ");
			int A=Integer.valueOf(t1[0]);
			int B=Integer.valueOf(t1[1]);
			double[] probCorrect=new double[A];
			for(int i=0;i<A;++i)
				probCorrect[i]=Double.valueOf(t2[i]);
			double ret=obj.getExpected(A, B, probCorrect);
			System.out.println("Case #"+t+": "+new BigDecimal(String.valueOf(ret)).setScale(6, BigDecimal.ROUND_HALF_UP));
		}
		
		br.close();

	}

}
