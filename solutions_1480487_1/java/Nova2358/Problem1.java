package round2;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import utils.FileTool;

public class Problem1 {

	/**
	 * @param args
	 */
	static int caseNum, n;
	static double[] scores;
	static String[] outputs;
	static double epsi = 0.000000001;
	static double sum = 0;
	static void read() throws IOException {
		Scanner ss = new Scanner(new File("in.txt"));
		// ss.next("[0-9]");
		caseNum = ss.nextInt();
		//System.out.println(caseNum +" ");
		outputs = new String[caseNum];
		for (int caseIndex = 0; caseIndex < caseNum; caseIndex++) {
			n = ss.nextInt();
			System.out.println(n+"");
			scores = new double [n];
			sum = 0;
			for(int i = 0; i < n; i++)	{
				scores[i] = ss.nextDouble();
				sum += scores[i];
			}
			System.out.println(sum);
			solve(caseIndex);
		}
	}
	
	static void solve(int caseIndex) {
		System.out.println(caseIndex + " ");
		String out = "";
		for(int i = 0; i < n;i++)	{
			out+=get(i)+" ";
		}
		outputs[caseIndex] = out;
	}
	static double get(int i )	{
		double high = 1.0,low=0.0,mid = 0;
		while(high - low > epsi)	{
			mid = (high+low)/2;
			double s = scores[i]+ sum*mid;
			double ts = 0;
			for(int j = 0; j < n;j++)	{
				if( i == j )
					continue;
				if(scores[j] >= s){
					continue;
				}
				else {
					ts += (s - scores[j])/sum;
				}
			}
			if(ts + mid > 1.0)	{
				high = mid;
			}
			else {
				low = mid;
			}
			System.out.println(low + " " + high + " " + mid);
		}
		return mid*100;
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
