package edu.nitin.codejam.round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;

public class EqualSums {

	static ArrayList<Long> numbers = new ArrayList<Long>();
	static HashMap<Long,HashSet<String>> map = new HashMap<Long,HashSet<String>>();
	static BufferedReader br = null;
	static BufferedWriter bw = null;
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	private static boolean addMap(ArrayList<Long> out) throws IOException	{
		long sum = 0;
		StringBuilder str = new StringBuilder();
		for(Long l: out)	{
			sum += l;
			str.append(l+" ");
		}
		if(map.get(new Long(sum)) != null)	{
			HashSet<String> set = map.get(sum);
			HashSet<Long> oldSet = new HashSet<Long>();
			HashSet<Long> newSet = new HashSet<Long>();
			for(String s: str.toString().split(" "))	{
				if(s.length() > 0)
					newSet.add(Long.parseLong(s));
			}
			//System.out.println("Sum: "+sum);
			
			for(String s: set)	{
				//System.out.println("old: "+s);
				for(String s1: s.toString().split(" "))	{
					if(s1.length() > 0)
						oldSet.add(Long.parseLong(s1));
				}
				HashSet<Long> intersection = new HashSet<Long>(newSet);
				intersection.retainAll(oldSet);
				if(intersection.size() == 0){
					System.out.println("Sum: "+sum);
					//System.out.println("old: "+s);
					//System.out.println("new: "+ str);
					bw.write(s+"\n");
					bw.write(str+"\n");
					return true;
				}
			}
			System.out.println("Str: "+ str);
		}
		else	{
			HashSet<String> set = new HashSet<String>();
			set.add(str.toString());
			map.put(sum, set);
		}
		return false;	
	}
	private static boolean doCombine(Long[] in, ArrayList<Long> out, int length, int level) throws IOException
	{	
		for(int i=level;i<length;i++)
		{
			out.add(in[i]);
			
			boolean status = addMap(out);
			if(status)
				return true;
			
			if(i < length -1)
			{
				status = doCombine(in,out,length,i+1);
				if(status)
					return true;
				
			}
			out.remove(out.size()-1);
		}
		return false;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		File fin = new File("src/files/b1.txt");
		File fout = new File("src/files/b2.txt");
		
		try {
			br = new BufferedReader(new FileReader(fin));
			bw = new BufferedWriter(new FileWriter(fout));
			long num = Integer.parseInt(br.readLine());
			for(int k=1;k<=num;k++)
			{
				bw.write("Case #"+k+":");
				bw.write("\n");
				
				String text = br.readLine();
				String[] splits = text.split(" ");
				int count = splits.length - 1;
				for(int var = 1; var <= count; var++){
					numbers.add(Long.parseLong(splits[var]));
				}
				
				int length = count;
				ArrayList<Long> out = new ArrayList<Long>();
				Long[] in = new Long[count]; 
				numbers.toArray(in);
				
				if(!doCombine(in, out, length, 0))
					bw.write("Impossible\n");
				numbers.clear();
				map.clear();
			}
			bw.flush();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
	}

}
