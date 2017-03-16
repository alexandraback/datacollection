using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Q1
{
	class Program
	{
		static void Main(string[] args)
		{
			string[] aLines = File.ReadAllLines(args[0]);

			int nLineCount = System.Convert.ToInt32(aLines[0]);

			Dictionary<char, char> CharMappings = new Dictionary<char, char>();

			CharMappings['y'] = 'a';
			CharMappings['n'] = 'b';
			CharMappings['f'] = 'c';
			CharMappings['i'] = 'd';
			CharMappings['c'] = 'e';
			CharMappings['w'] = 'f';
			CharMappings['l'] = 'g';
			CharMappings['b'] = 'h';
			CharMappings['k'] = 'i';
			CharMappings['u'] = 'j';
			CharMappings['o'] = 'k';
			CharMappings['m'] = 'l';
			CharMappings['x'] = 'm';
			CharMappings['s'] = 'n';
			CharMappings['e'] = 'o';
			CharMappings['v'] = 'p';
			CharMappings['z'] = 'q';
			CharMappings['p'] = 'r';
			CharMappings['d'] = 's';
			CharMappings['r'] = 't';
			CharMappings['j'] = 'u';
			CharMappings['g'] = 'v';
			CharMappings['t'] = 'w';
			CharMappings['h'] = 'x';
			CharMappings['a'] = 'y';
			CharMappings['q'] = 'z';
			CharMappings[' '] = ' ';

			for (int nLine = 1; nLine <= nLineCount; nLine++)
			{
				string strLine = aLines[nLine];
				string strOutLine = "Case #" + nLine + ": ";

				for (int nChar = 0; nChar < strLine.Length; nChar++)
				{
					char cInChar = strLine[nChar];

					char cOutChar = CharMappings[cInChar];
					strOutLine += cOutChar;
				}

				Console.WriteLine(strOutLine);
			}
		}
	}
}
