/*
 * Created by SharpDevelop.
 * User: UX31
 * Date: 12.04.2014
 * Time: 12:11
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace problem
{
	class Program
	{
		public static void Main(string[] args)
		{
			var t = int.Parse(Console.ReadLine());
			
			foreach (var index in Enumerable.Range(1, t)) {
				var n = int.Parse(Console.ReadLine());
				var a = ReadArray(Console.ReadLine());
				var b = ReadArray(Console.ReadLine());
				var r = Solve(n, a, b);
				Console.WriteLine(string.Format(CultureInfo.InstalledUICulture, "Case #{0}: {1} {2}", index, r.Item1, r.Item2));
			}
		}
		
		public static List<double> ReadArray(string numbers) {
			return numbers.Split(' ').Select(Read).ToList();
		}
		
		public static double Read(string number) {
			return double.Parse(number, CultureInfo.InvariantCulture);
		}
		
		public static Tuple<int, int> Solve(int n, List<double> a, List<double> b) {
			a.Sort();
			b.Sort();
			
			int ai = 0, bi = 0;
				
			while (ai < n && bi < n) {
				if (a[ai] < b[bi]) {
					ai++;
				}
				
				bi++;
			}
			
			var r2 = n - ai;
			
			ai = bi = n - 1;
			
			while (ai >= 0 && bi >= 0) {
				if (a[ai] > b[bi]) {
					ai--;
				}
				
				bi--;
			}
			
			var r1 = n - ai - 1;
			
			return Tuple.Create(r1, r2);
		}
	}
}