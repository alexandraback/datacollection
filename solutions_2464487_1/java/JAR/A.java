package com.codejam.round1A2013;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws Exception{
		A a = new A();
		//a.process("A-sample.in");
		//a.process("A-small-attempt0.in");
		a.process("A-large.in");
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
			double t = scanner.nextDouble();
			double result = solve(r,t);
			
			String o = "Case #" + (i+1) + ": " + (long)result + "\n";
			fw.write(o);
			System.out.print(o);
		}
		scanner.close();
		fw.close();
	}
	public double solve(long r,double t)
	{
		double count = 0;
		double cr = r;
		double nr = r + 1;
		
		while(true)
		{
			count = count+100;
			double value = count * (2*count -1 + 2 * r);
			if(value == t)
				return count;
			if(value > t)
				break;
		}
		long c1 = (long)count;
		while(count > 0)
		{
			double value = count * (2*count -1 + 2 * r);
			if(value == t)
				return count;
			if(value < t)
				return count;
			count--;
		}
		return count;
/*		while(t > 0)
		{
			
			double paintNeeded = (nr * nr - cr * cr);
			if(paintNeeded > t)
				break;
			count++;
			t -= paintNeeded;
			cr += 2;
			nr += 2;
		}*/
		//return count;
	}
}
