/*
 * Created by SharpDevelop.
 * User: santi
 * Date: 2013.04.27.
 * Time: 3:06
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;

namespace Pogo
{
	class Program
	{
		public static void Main(string[] args)
		{
			int darabszam = 0;
			string line;

			// Read the file and display it line by line.
			System.IO.StreamReader file = new System.IO.StreamReader(args[0]);
			//System.IO.StreamReader file = new System.IO.StreamReader("input.txt");
			System.IO.StreamWriter outfile = new System.IO.StreamWriter("result.out");
			
			line = file.ReadLine();
			darabszam = Int32.Parse(line);
			
			for (int counter = 0; counter < darabszam; counter++)
			{
				string[] words = file.ReadLine().Split(' ');
				
				int coordX = Convert.ToInt32(words[0]);
				int coordY = Convert.ToInt32(words[1]);

				
				//System.Console.WriteLine("Case #{0}: {1}", counter+1, GetDirection(coordX, coordY));
				outfile.WriteLine("Case #{0}: {1}", counter+1, GetDirection(coordX, coordY));
			}
			file.Close();
			outfile.Close();
			// Suspend the screen.
            //outfile.Close();
            //System.Console.ReadLine();
		}
		
		public static String GetDirection(int coordX, int coordY)
		{
			int lepes =  1;
			string x_lepes;
			string x_lepes2;
			string y_lepes;
			string y_lepes2;
			string eredmeny = "";
			
			int x = 0;
			int y = 0;
			if (coordX>0) 
			{
				x_lepes = "E";
				x_lepes2 = "WE";
			}
			else{
				x_lepes = "W";
				x_lepes2 = "EW";
			}
			
			if (coordY>0) 
			{
				y_lepes = "N";
				y_lepes2 = "SN";
			}
			else 
			{
				y_lepes = "S";
				y_lepes2 = "NS";
			}
			while ( Math.Abs(coordX) >= x + lepes)
			{
				eredmeny += x_lepes;
				x += lepes;
				//System.Console.WriteLine("erdemeny: {0}, x: {1}, y: {2}, lepes: {3}", eredmeny, x, y, lepes);
				lepes++;
			}
			
			for (int i = 0; i< Math.Abs(coordX) - x; i++)
			{
				eredmeny += x_lepes2;
				//System.Console.WriteLine("erdemeny: {0}, x: {1}, y: {2}, lepes: {3}", eredmeny, x, y, lepes);
				lepes += 2;
			}
			
			while ( Math.Abs(coordY) >= y + lepes)
			{
				eredmeny += y_lepes;
				y += lepes;
				//System.Console.WriteLine("erdemeny: {0}, x: {1}, y: {2}, lepes: {3}", eredmeny, x, y, lepes);
				lepes++;
			}
			
			for (int i = 0; i< Math.Abs(coordY) - y; i++)
			{
				eredmeny += y_lepes2;
				//System.Console.WriteLine("erdemeny: {0}, x: {1}, y: {2}, lepes: {3}", eredmeny, x, y, lepes);
				//lepes += lepes+2;
			}

			return eredmeny;
		}
	}
}


