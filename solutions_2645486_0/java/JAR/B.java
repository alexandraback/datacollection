package com.codejam.round1A2013;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws Exception{
		B a = new B();
		//a.process("B-sample.in");
		a.process("B-small-attempt0.in");
		//a.process("B-large-practice.in");
	}
	void process(String fileName) throws Exception
	{
		Scanner scanner = new Scanner(new File("data/" + fileName));
		FileWriter fw = new FileWriter(new File("output/" + fileName + ".out"));
		int line = scanner.nextInt();
		scanner.nextLine();
		for(int i=0;i<line;i++)
		{
			 E = scanner.nextLong();
			 R = scanner.nextLong();
			 N = scanner.nextLong();
			
			scanner.nextLine();
			v = new long[(int)N];
			for(int j=0;j<N;j++)
				v[j] = scanner.nextLong();
			long result = solve();
			String o = "Case #" + (i+1) + ": " + result + "\n";
			fw.write(o);
			System.out.print(o);
		}
		scanner.close();
		fw.close();
	}
	long E,R,N;
	long[] v;
	public long solve()
	{
		mg = 0;
		solve(E,0,0);
		return mg;
	}
	long mg;
	public void solve(long e,long g,int index)
	{
		if(g > mg)
			mg = g;
		if(e <= 0)
			return;
		if(index >=N)
			return;
		if(e > E)
			e = E;
		for(int i=0;i<=e;i++)
		{
			solve(e-i+ R,g+ v[index]* i,index+1);
		}
	}
}
