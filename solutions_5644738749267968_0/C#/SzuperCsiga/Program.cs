/*
 * Created by SharpDevelop.
 * User: santi
 * Date: 2014.04.12.
 * Time: 10:00
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;

namespace War
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
				int KovekSzama = 0;
				int ResultWar = 0;
				int ResultDeceitfulWar = 0;
				
				KovekSzama = Int32.Parse(file.ReadLine());
				Double[] Naomi = new Double[KovekSzama];
				Double[] Ken   = new Double[KovekSzama];
				
				string[] NumbersNaomi = file.ReadLine().Split(' ');
				string[] NumbersKen = file.ReadLine().Split(' ');
				bool[] Used = new bool[KovekSzama];
				
				for ( int i = 0; i<KovekSzama; i++)
				{
					Used[i] = false;
					Naomi[i] = Double.Parse(NumbersNaomi[i], System.Globalization.CultureInfo.InvariantCulture);
					Ken[i] = Double.Parse(NumbersKen[i], System.Globalization.CultureInfo.InvariantCulture);
				}

				/*Normal War result*/
				/*for ( int ChooseNaomi = 0; ChooseNaomi<KovekSzama; ChooseNaomi++)
				{
					Double KenWeight = FeltMinKer(Ken, Used, Naomi[ChooseNaomi]);
					if (KenWeight <  Naomi[ChooseNaomi]) ResultWar++;
				}*/
				
				
				BubbleSort(Ken);
				BubbleSort(Naomi);
				int actualPlace = 0;
				for ( int i = 0; i<KovekSzama; i++)
				{
					if (Ken[i] > Naomi[actualPlace] )
					{
						actualPlace++;
						ResultWar++;
					}
				}
				
				/*Modified War result*/
				actualPlace = 0;
				for ( int i = 0; i<KovekSzama; i++)
				{
					if (Naomi[i] > Ken[actualPlace] )
					{
						actualPlace++;
						ResultDeceitfulWar++;
					}
				}
				
				outfile.WriteLine(String.Format("Case #{0}: {1} {2}", counter+1, ResultDeceitfulWar, KovekSzama-ResultWar));

			}
			
			file.Close();
			outfile.Close();
			//Console.Write("Press any key to continue . . . ");
			//Console.ReadKey(true);
		}
		
		public static void BubbleSort(Double[] Numbers)
		{
			for ( int i = 0 ; i<Numbers.Length-1;  i++)
			{
				for ( int j = 0; j<Numbers.Length-1-i; j++)
				{
					if ( Numbers[j]>Numbers[j+1] )
					{
						Double temp  = Numbers[j];
						Numbers[j]   = Numbers[j+1];
						Numbers[j+1] = temp;
					}
				}
			}
		}
		
		/*public static Double FeltMinKer(Double[] KenNumber, bool[] Used, Double NaomiMass)
		{
			Double KenMass = 2;
			int    placeKen = 0;
			Double MinMass = 0;
			int    placeMin = 0;
			
			for ( int i = 0; i<KenNumber.Length; i++)
			{
				if ( !Used[i])
				{
					if ( (KenNumber[i] > NaomiMass) && (KenMass > KenNumber[i]) )
					{
						KenMass  = KenNumber[i];
						placeKen = i;
					}
					if ( MinMass > KenNumber[i] )
					{
						MinMass  = KenNumber[i];
						placeMin = i;
					}
				}
			}
			
			if (KenMass < 2)
			{
				Used[placeKen] = true;
				return KenMass;
			}
			else
			{
				Used[placeMin] = true;
				return MinMass;
			}
		}*/
		
		/*public static void PrintData(Double[] Naomi, Double[] Ken, int KovekSzama, System.IO.StreamWriter outfile)
		{
			outfile.Write("Naomi before sort: ");
			for ( int i = 0; i<KovekSzama ; i++ )
			{
				outfile.Write(String.Format(System.Globalization.CultureInfo.InvariantCulture, "{0:0.###} ", Naomi[i]));
			}
			outfile.WriteLine();
			outfile.Write("Ken before sort  : ");
			for ( int i = 0; i<KovekSzama ; i++ )
			{
				outfile.Write(String.Format(System.Globalization.CultureInfo.InvariantCulture, "{0:0.###} ", Ken[i]));
			}
			outfile.WriteLine();
			
			BubbleSort(Ken);
			BubbleSort(Naomi);
			outfile.Write("Naomi after sort : ");
			for ( int i = 0; i<KovekSzama ; i++ )
			{
				outfile.Write(String.Format(System.Globalization.CultureInfo.InvariantCulture, "{0:0.###} ", Naomi[i]));
			}
			outfile.WriteLine();
			outfile.Write("Ken after sort   : ");
			for ( int i = 0; i<KovekSzama ; i++ )
			{
				outfile.Write(String.Format(System.Globalization.CultureInfo.InvariantCulture, "{0:0.###} ", Ken[i]));
			}
			outfile.WriteLine();
		}
		*/
	}
}