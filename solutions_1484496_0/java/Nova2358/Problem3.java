package round2;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

import utils.FileTool;

public class Problem3 {

	/**
	 * @param args
	 */
	static int caseNum, n;
	static long[] nums;
	static String[] outputs;
	
	static void read() throws IOException {
		Scanner ss = new Scanner(new File("in.txt"));
		// ss.next("[0-9]");
		caseNum = ss.nextInt();
		outputs = new String[caseNum];
		for (int caseIndex = 0; caseIndex < caseNum; caseIndex++) {
			 n = ss.nextInt();
			 nums = new long[n];
			 for(int i = 0; i < n; i++){
				 nums[i] = ss.nextLong();
			 }
			solve(caseIndex);
		}
	}
	
	static void solve(int caseIndex) {
		Arrays.sort(nums);
		ArrayList<Long> list = new ArrayList<Long>();
		for(int i = 0; i < nums.length;i++)	{
			list.add(nums[i]);
		}
		boolean found = false;
		String out = "";
		int count = 0;
		while(!found)	{
			count += 1;
			Collections.shuffle(list);
			HashMap<Long,Integer> map = new HashMap<Long,Integer>();
			long sum = 0;
			for(int i = 0; i < list.size();i++)	{
				sum += list.get(i);
				if(sum %2 ==0 && map.containsKey(sum/2)){
					found = true;
					int j = map.get(sum/2);
					for(int k = 0; k <=j; k++){
						out += list.get(k) +" ";
					}
					out += "\r\n";
					for(int k = j+1;k<=i;k++)	{
						out += list.get(k) +" ";
					}
					break;
				}
				else {
					//sum += list.get(i);
					map.put(sum, i);
				}
			}
			map.clear();
		}
		System.out.println(count + " times.");
		outputs[caseIndex] = out;
	}
	boolean isSum(long[] a)	{
		
		return true;
	}
	
	static void output() throws IOException {
		ArrayList<String> contents = new ArrayList<String>();

		for (int i = 0; i < outputs.length; i++) {
			String s = "Case #" + (i + 1) + ": \n";
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
