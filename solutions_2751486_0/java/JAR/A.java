package com.codejam.round1C2013;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws Exception{
		A a = new A();
		a.process("A-sample.in");
		a.process("A-small-attempt0.in");
		//a.process("A-large-practice.in");
	}
	void process(String fileName) throws Exception
	{
		Scanner scanner = new Scanner(new File("data/" + fileName));
		FileWriter fw = new FileWriter(new File("output/" + fileName + ".out"));
		int line = scanner.nextInt();
		scanner.nextLine();
		for(int i=0;i<line;i++)
		{
			String[] l1 = scanner.nextLine().split(" ");
			long result = solve(l1[0],Integer.parseInt(l1[1]));
			String o = "Case #" + (i+1) + ": " + result + "\n";
			fw.write(o);
			System.out.print(o);
		}
		scanner.close();
		fw.close();
	}
	public long solve(String s,int n)
	{
		long total = 0;
		for(int i=0;i<s.length();i++)
		{
			int count = 0;
			for(int j=i;j<s.length();j++)
			{
				char c = s.charAt(j);
				if(c == 'a' || c=='i' || c=='e' || c=='o' || c == 'u')
				{
					count=0;
					continue;
				}
				count++;
				if(count >= n)
				{
					total+= s.length() - j;
					break;
				}
			}
			
		}
		return total;
	}
}
