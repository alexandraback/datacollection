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
		public static char[][] Solve(int r, int c, int m) {
			var rr = r;
			var cc = c;
			var mm = m;
			
			while (Math.Min(rr, cc) <= mm) {
				if (rr < cc) {
					mm -= rr;
					cc--;
				} else {
					mm -= cc;
					rr--;
				}
			}
			
			if (rr > 1 && cc > 1 && (rr - 2) * (cc - 2) < mm) {
				return null;
			}
			
			var matrix = new char[r][];
			
			for (var ri = 0; ri < r; ri++) {
				matrix[ri] = new char[c];
				for (var ci = 0; ci < c; ci++) {
					matrix[ri][ci] = ri < rr && ci < cc ? '.' : '*';
				}
			}
			
			matrix[0][0] = 'c';
			
			{
				var ri = rr - 1;
				var ci = cc - 1;
				
				while (mm > 0 && ci > 1) {
					matrix[ri][ci] = '*';
					ci--;
					mm--;
				}
				
				if (mm > 0) {
//					if (rr - 2 < 2) {
//						return null;
//					}
					
					matrix[rr - 2][cc - 1] = '*';
				}
			}
			
			if (r > 1 && matrix[1][0] == '*' || c > 1 && matrix[0][1] == '*') {
				if (m + 1 < r * c) {
					return null;
				}
			}
			
			return matrix;
		}

		public static void Main(string[] args)
		{
			var t = ReadInt();
			
			foreach (var index in Enumerable.Range(1, t)) {
				var a = ReadRow();
				var r = ParseInt(a[0]);
				var c = ParseInt(a[1]);
				var m = ParseInt(a[2]);
				
				WriteCase(index);
				var matrix = Solve(r, c, m);
				
				if (matrix == null) {
					Write("Impossible");
				} else {
					foreach (var row in matrix) {
						Write(new String(row));
					}
				}
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
			
		public static List<List<string>> ReadMatrix(int rows) {
			return Enumerable.Range(0, rows)
				.Select(index => ReadRow())
				.ToList();
		}
		
		public static List<string> ReadRow() {
			return Console.ReadLine().Split(' ').ToList();
		}
	}
}