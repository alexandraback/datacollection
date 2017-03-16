/*
 * Created by SharpDevelop.
 * User: santi
 * Date: 2014.04.12.
 * Time: 8:05
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;

namespace CookieFarm
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

				string[] Numbers = file.ReadLine().Split(' ');
				
				
				Double Cost = Double.Parse(Numbers[0], System.Globalization.CultureInfo.InvariantCulture);
				Double Farm = Double.Parse(Numbers[1], System.Globalization.CultureInfo.InvariantCulture);
				Double X    = Double.Parse(Numbers[2], System.Globalization.CultureInfo.InvariantCulture);
				
				Double n = Math.Ceiling( (X*Farm - 2*Cost - Cost*Farm)/(Cost*Farm) );
				
				if ( n < 0 ) n = 0;
				Double time = 0;
				
				for ( int i = 0; i<n; i++)
				{
					time += Cost/(2+i*Farm);
				}
				time += X/(2+n*Farm);
				outfile.WriteLine(String.Format(System.Globalization.CultureInfo.InvariantCulture, "Case #{0}: {1:0.0000000}", counter+1, time));
				
			}
			
			file.Close();
			outfile.Close();
			/*Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);*/
		}
	}
}