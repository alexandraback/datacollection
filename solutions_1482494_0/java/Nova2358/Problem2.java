package gcj2012round1;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

import utils.FileTool;

public class Problem2 {

	/**
	 * @param args
	 */
	static int caseNum;
	static int one[],two[];
	static int n;
	static int[] outputs;
	
	static void read() throws IOException {
		Scanner ss = new Scanner(new File("in2.txt"));
		// ss.next("[0-9]");
		caseNum = ss.nextInt();
		outputs = new int[caseNum];
		for (int caseIndex = 0; caseIndex < caseNum; caseIndex++) {
			n = ss.nextInt();
			one = new int[n];
			two = new int[n];
			for(int i = 0; i < n;i++)	{
				one[i] = ss.nextInt();
				two[i] = ss.nextInt();
			}
			solve(caseIndex);
		}
	}
	
	static void solve(int caseIndex) {
		ArrayList<Task> t1 = new ArrayList<Task>();
		ArrayList<Task> t2 = new ArrayList<Task>();
		for(int i = 0;i<n;i++)	{
			Task t = new Task(i,one[i],1);
			t1.add(t);
			t = new Task(i,two[i],2);
			t2.add(t);
			
		}
		Collections.sort(t1);
		Collections.sort(t2);
		int currentValue = 0;
		int count = 0;
		while(!t2.isEmpty())	{
			if(currentValue >= t2.get(0).require)	{
				count += 1;
				currentValue += t2.get(0).value;
				for(int i =0;i<t1.size();i++){
					if(t1.get(i).index==t2.get(0).index)	{
						t1.remove(i);
					}
				}
				t2.remove(0);
			}
			else{
				if(t1.isEmpty() || currentValue < t1.get(0).require)	{
					count = -1;
					break;
				}
				int index = -1;
				int max= Integer.MIN_VALUE;
				for(int i = 0; i < t1.size();i++){
					if(t1.get(i).require > currentValue)
						break;
					if(two[t1.get(i).index] > max)	{
						max = two[t1.get(i).index];
						index = i;
					}
				}
				count += 1;
				currentValue += 1;
				for(int i =0;i<t2.size();i++){
					if(t2.get(i).index==t1.get(index).index)	{
						t2.get(i).value = 1;
					}
				}
				t1.remove(index);
				
			}
		}
		outputs[caseIndex] = count;
	}
	
	static void output() throws IOException {
		ArrayList<String> contents = new ArrayList<String>();

		for (int i = 0; i < outputs.length; i++) {
			String s = "Case #" + (i + 1) + ": ";
			if (outputs[i] != -1)
				s += outputs[i];
			else
				s += "Too Bad";
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
class Task	implements Comparable<Task>{
	
	public int index;
	public int require;
	public int value;
	public Task(int index,int require, int value)	{
		this.index = index;
		this.require = require;
		this.value = value;
		
	}
	@Override
	public int compareTo(Task arg0) {
		// TODO Auto-generated method stub
		if(require < arg0.require)
			return -1;
		else if(require == arg0.require )
			return 0;
		return 1;
		
	}
}
