package com.codejam.round1A2013;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws Exception{
		A a = new A();
		//a.process("A-sample.in");
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
			long r = scanner.nextLong();
			long t = scanner.nextLong();
			long result = solve(r,t);
			String o = "Case #" + (i+1) + ": " + result + "\n";
			fw.write(o);
			System.out.print(o);
		}
		scanner.close();
		fw.close();
	}
	public long solve(long r,long t)
	{
		long count = 0;
		long cr = r;
		long nr = r + 1;
		while(t > 0)
		{
			
			long paintNeeded = (nr * nr - cr * cr);
			if(paintNeeded > t)
				break;
			count++;
			t -= paintNeeded;
			cr += 2;
			nr += 2;
		}
		return count;
	}
}
