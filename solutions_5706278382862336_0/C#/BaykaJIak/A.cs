using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

class Program {
	long p;
	long q;
	long gen;
	
	bool imp;
	
	void Solve() {
		var a = p;
		var b = q;
		long c = 0;
		do {
			c = b % a;
			b = a;
			a = c;
			
		} while (c != 0);
		
		p = p / b;
		q = q / b;
		
		a = q;
		
		while (a % 2 == 0) {
			a = a / 2;
		}
		
		if (a != 1) {
			imp = true;
			return;
		}
		
		gen = 1;
		
		while (p * 2 < q) {
			gen++;
			q = q / 2;
		}
	}

	public static void Main(string[] args)
	{
		var t = ReadInt();
		
		foreach (var index in Enumerable.Range(1, t)) {
			var program = new Program();
			var pq = Console.ReadLine().Split('/');
			program.p = ParseLong(pq[0]);
			program.q = ParseLong(pq[1]);
			program.Solve();
			WriteCase(index, program.imp ? "impossible" :  program.gen.ToString());
		}
	}
	
	public static void WriteCase(int caseIndex, string result = null) {
		Console.WriteLine(Format("Case #{0}: {1}", caseIndex, result));
	}
	
	public static void Write(string line) {
		Console.WriteLine(line);
	}
	
	public static string Format(string format, params object[] parameters) {
		return string.Format(CultureInfo.InstalledUICulture, format, parameters);
	}
	
	public static double ReadDouble(string number) {
		return double.Parse(number, CultureInfo.InvariantCulture);
	}
	
	public static int ReadInt() {
		return ParseInt(Console.ReadLine());
	}
	
	public static int ParseInt(string number) {
		return int.Parse(number);
	}
	
	public static long ParseLong(string number) {
		return long.Parse(number);
	}
		
	public static List<List<string>> ReadMatrix(int rows) {
		return Enumerable.Range(0, rows)
			.Select(index => ReadRow())
			.ToList();
	}
	
	public static List<string> ReadRow() {
		return Console.ReadLine().Split(' ').ToList();
	}
}
