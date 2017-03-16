/*
 * Created by SharpDevelop.
 * User: UX31
 * Date: 12.04.2014
 * Time: 12:11
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
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
				var line = Console.ReadLine();
				var parts = line.Split(' ');
				var seconds = Solve(Read(parts[0]), Read(parts[1]), Read(parts[2]));
				Console.WriteLine(string.Format(CultureInfo.InstalledUICulture, "Case #{0}: {1:0.0000000}", index, seconds));
			}
		}
		
		public static double Read(string number) {
			return double.Parse(number, CultureInfo.InvariantCulture);
		}
		
		public static double Solve(double c, double f, double x) {
			double s = 0;
			double ff = 2;
			
			while (x/ff > x/(ff + f) + c/ff) {
				s += c/ff;
				ff += f;
			}
			
			s += x/ff;
			
			return s;
		}
	}
}