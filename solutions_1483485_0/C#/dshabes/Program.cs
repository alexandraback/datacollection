using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2012Q
{
	class Program
	{
		static readonly IDictionary<char,char> map = new Dictionary<char, char>()
		{
			{'a', 'y'},
			{'b', 'h'},
			{'c', 'e'},
			{'d', 's'},
			{'e', 'o'},
			{'f', 'c'},
			{'g', 'v'},
			{'h', 'x'},
			{'i', 'd'},
			{'j', 'u'},
			{'k', 'i'},
			{'l', 'g'},
			{'m', 'l'},
			{'n', 'b'},
			{'o', 'k'},
			{'p', 'r'},
			{'q', 'z'},
			{'r', 't'},
			{'s', 'n'},
			{'t', 'w'},
			{'u', 'j'},
			{'v', 'p'},
			{'w', 'f'},
			{'x', 'm'},
			{'y', 'a'},
			{'z', 'q'},
			{' ', ' '},
		}; 

		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var i = 0; i < testCount; i++)
				Console.WriteLine("Case #{0}: {1}", i+1, new string(Console.ReadLine().Select(c => map[c]).ToArray()));
		}
	}
}
