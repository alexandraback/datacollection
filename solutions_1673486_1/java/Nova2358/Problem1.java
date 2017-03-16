package gcj2012round1;

import java.io.File;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import utils.FileTool;

public class Problem1 {

	/**
	 * @param args
	 */
	static int A,B,caseNum;
	static int[] prob;
	static double[] outputs;
	 
	static void read() throws IOException {
		Scanner ss = new Scanner(new File("in.txt"));
		// ss.next("[0-9]");
		caseNum = ss.nextInt();
		outputs = new double[caseNum];
		for (int caseIndex = 0; caseIndex < caseNum; caseIndex++) {
			A = ss.nextInt();
			B = ss.nextInt();
			prob = new int[A];
			for(int i = 0; i < A; i++)	{
				double t = ss.nextDouble();
				prob[i] = (int) (t*10);
			}
			solve(caseIndex);
		}
	}
	
	static void solveLarge(int caseIndex) {
		
		double exp1 = 0;
		double exp2 = B+2;
		double[] expB = new double[A];
		BigInteger[] expBI = new BigInteger[A];
		for(int i = 0; i < A;i++){
			expBI[i] = new BigInteger("0");
		}
		BigInteger base = new BigInteger(1+"");
		BigInteger ten = new BigInteger(10+"");
		BigInteger prod = new BigInteger("1");
		BigInteger sum = new BigInteger("0");
		for(int i = 0; i < A;i++){
			base.multiply(ten);
			BigInteger p = prod.multiply(new BigInteger((10-prob[i])+""));
			sum = sum.multiply(ten);
			
			for(int j = 0; j < A;j++)	{
				int t1 = 0;
				if(A - i <= j){
					t1 = 2*j + B - A +1;
				}
				else {
					t1 = 2*j + B - A +1 + B + 1;
				}
				expBI[j].add(sum.multiply(new BigInteger(t1+""))); 
			}
			
			prod = prod.multiply(new BigInteger(prob[i]+""));
		}
		//exp1 = prod.multiply(new BigInteger((B-A+1)+""));
		
	}
	static void solve(int index){
		double exp1 = 0;
		double exp2 = B+2;
		double[] expB = new double[A+1];
		double prod = 1.0;
		for(int i = 0; i < A;i++){
			double p = prod*(10.0-prob[i])/10;
			//System.out.println("p:" + p);
			for(int j = 0; j <= A;j++)	{
				int t1 = 0;
				if(A - j <= i){
					t1 = 2*j + B - A +1;
				}
				else {
					t1 = 2*j + B - A +1 + B + 1;
				}
				expB[j] += p*t1;
			}
			//System.out.println("exB" + Arrays.toString(expB));
			prod*=prob[i]/10.0;
		}
		for(int j = 0; j <= A;j++)	{
			int t1 = 2*j + B - A +1;
			expB[j] += prod*t1;
		}
		System.out.println(prod);
		exp1 = prod*(B-A+1) + (1-prod)*(B-A+1+B+1);
		System.out.println(exp1 + " " + exp2);
		System.out.println(Arrays.toString(expB));
		double min = Double.MAX_VALUE;
		min = Math.min(exp1, exp2);
		for(int j = 0; j <= A;j++)	{
			min = Math.min(min,expB[j]);
		}
		outputs[index] = min;
	}
	
	static void output() throws IOException {
		ArrayList<String> contents = new ArrayList<String>();

		for (int i = 0; i < outputs.length; i++) {
			String s = "Case #" + (i + 1) + ": ";
			//if (outputs[i] != -1)
				s += outputs[i];
			//else
				//s += "IMPOSSIBLE";
			contents.add(s);
			System.out.println(s);
		}
		FileTool.outputFile("out.txt", contents);
	}
	
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		read();
		output();
	}

}
