/*
 * Created by SharpDevelop.
 * User: santi
 * Date: 2014.04.12.
 * Time: 15:29
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;

namespace Mine
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
				string[] Datas = file.ReadLine().Split(' ');
				int numR      = Int32.Parse(Datas[0]);
				int numC      = Int32.Parse(Datas[1]);
				int numMines  = Int32.Parse(Datas[2]);
				bool Possible  = false;
				bool Reverse  = false;
				char[,] table;
					
				
				//int teszt = numR*numC - numMines;
				//outfile.WriteLine(String.Format("numR: {0}, numC: {1}, numMines: {2} #{3}:  not mines {4}", numR, numC, numMines, counter+1, teszt));
				
				if ( numMines == 0 )
				{
					table = new char[numR, numC];
					for ( int i = 0; i < numR; i++)
						for ( int j = 0; j < numC; j++)
							table[i, j] = '.';
					table[0, 0] = 'c';
					Possible = true;
				}
				else if (numR*numC - numMines == 1)
				{
					table = new char[numR, numC];
					for ( int i = 0; i < numR; i++)
						for ( int j = 0; j < numC; j++)
							table[i, j] = '*';
					table[0, 0] = 'c';
					Possible = true;
				}

				else if ( numMines == 1)
				{
					table = new char[numR, numC];
					if ( (numR > 2 && numC > 2) || ( numR == 1) ||  ( numC == 1) )
					{
						for ( int i = 0; i < numR; i++)
							for ( int j = 0; j < numC; j++)
								table[i, j] = '.';
						table[0, 0] = 'c';
						table[numR-1, numC-1] = '*';
						Possible = true;
					}
					else
					{
						Possible = false;
					}
				}
				else if (numR == 1)
				{
					table = new char[numR, numC];
					if(numMines < numC)
					{
						Possible = true;
						for ( int i = 0; i<numC; i++) table[0, i] = '.';
						table[0,0] = 'c';
						for ( int i = 0; i < numMines; i++) table[0, numC-1-i] = '*';
					}
					else
					{
						Possible = false;
					}
				}
				else if (numC == 1)
				{
					table = new char[numR, numC];
					if(numMines < numR)
					{
						Possible = true;
						for ( int i = 0; i<numR; i++) table[i, 0] = '.';
						table[0,0] = 'c';
						for ( int i = 0; i < numMines; i++) table[ numR-1-i, 0] = '*';
					}
					else
					{
						Possible = false;
					}
				}
				else
				{
					if (numR < numC) //swap
					{
						int tmp = numR;
						numR = numC;
						numC = tmp;
						Reverse = true;
					}
					table = new char[numR, numC];
					Possible = SearchSolution(numR, numC, table, numMines, outfile);
				}
				
				outfile.WriteLine(String.Format("Case #{0}:", counter+1));
				
				if ( Possible )
				{
					if (!Reverse)
					{
						for ( int i = 0; i < numR; i++)
						{
							for ( int j = 0; j < numC; j++)
							{
								if (j < numC - 1) outfile.Write(String.Format("{0}", table[i, j]));
								else outfile.WriteLine(String.Format("{0}", table[i, j]));
							}
						}
					}
					else
					{
						for ( int i = 0; i < numC; i++)
						{
							for ( int j = 0; j < numR; j++)
							{
								if (j < numR - 1) outfile.Write(String.Format("{0}", table[j, i]));
								else outfile.WriteLine(String.Format("{0}", table[j, i]));
							}
						}
					}
					
				}
				else
				{
					//outfile.WriteLine(String.Format("Case #{0}:", counter+1));
					//int teszt = numR*numC - numMines;
					//outfile.WriteLine(String.Format("numR: {0}, numC: {1}, numMines: {2} #{3}:  not mines {4}", numR, numC, numMines, counter+1, teszt));
					outfile.WriteLine("Impossible");
				}

			}
			
			file.Close();
			outfile.Close();
			//Console.Write("Press any key to continue . . . ");
			//Console.ReadKey(true);
		}
		
		public static bool SearchSolution(int numR, int numC, char[,] table, int numMines, 	System.IO.StreamWriter outfile )
		{
			
			int notMines = numR*numC - numMines;
			int testI = 0;
			int testJ = 0;
			int remain = 0;
			bool possible = false;
			
			if (numR == 2 || numC == 2)
			{
				if ( ( numMines % 2 == 0 ) && ((numR * numC - numMines) >= 4) )
				{
					for ( int i = 0; i < numR; i++)
						for ( int j = 0; j < numC; j++)
							table[i, j] = '.';
					
					if (numR == 2)
					{
						for ( int i = 0; i<numMines/2; i++)
						{
							table[0, i] = '*';
							table[1, i] = '*';
						}
					}
					else
					{
						for ( int i = 0; i<numMines/2; i++)
						{
							table[i, 0] = '*';
							table[i, 1] = '*';
						}
					}
					table[numR - 1, numC -1] = 'c';
					
					return true;
				}
				return false;
			}
			
			if (numR == 3 && numC > 3 && numMines == 3)
			{
				for ( int i = 0; i < numR; i++)
					for ( int j = 0; j < numC; j++)
						table[i, j] = '.';
				table[0, 0] = 'c';
				
				table[0, numC-1] = '*';
				table[1, numC-1] = '*';
				table[2, numC-1] = '*';
				return true;
			}
			
			if (numC == 3 && numR > 3 && numMines == 3)
			{
				for ( int i = 0; i < numR; i++)
					for ( int j = 0; j < numC; j++)
						table[i, j] = '.';
				table[0, 0] = 'c';
				
				table[numR-1, 0] = '*';
				table[numR-1, 1] = '*';
				table[numR-1, 2] = '*';
				return true;
			}
			
			if ( numR >=5 && numC == 3 && numMines == 4)
			{
				for ( int i = 0; i<numR; i++)
					for( int j = 0; j < numC; j++)
						table[i, j] = '.';
				table[0, 0] = '*';
				table[0, 1] = '*';
				table[0, 2] = '*';
				table[1, 0] = '*';
				table[numR-1, numC-1] = 'c';
				return true;
			}
			

			/*less mines then larger side*/
			if ( numMines < numR)
			{
				if ( numR == 3 && numC == 3 && numMines == 2) return false;
				for ( int i = 0; i<numR; i++)
					for( int j = 0; j < numC; j++)
						table[i, j] = '.';
				table[numR-1, 0] = 'c';
				for ( int i = 0; i < numMines && i < numR-2; i++)
				{
					table[i, numC-1] = '*';
				}
				if (numMines == numR-1)
				{
					table[0, numC-2] = '*';
					if (numC-2 == 1) return false;
				}
				return true;
			}
			
			for ( testI = numR; testI > 1 && !possible; testI--)
			{
				testJ = notMines / testI;
				if ( testJ > 1 )
				{
					remain = notMines - (testJ * testI);
					if ( remain == 0 ||remain > 1) possible = true;
				}
			}
			testI++;
				
			if ( possible )
			{
				for( int i = 0; i<numR; i++)
				{
					for ( int j = 0; j < numC; j++)
					{
						if ( i < testI && j < testJ) table[i, j ] = '.';
						else table[i, j] = '*';
					}
				}
				if ( testI + 1 < numR - 1) for ( int i = 0; i<remain; i++) table[testI, i] = '.';
				else for ( int i = 0; i<remain; i++) table[i, testJ] = '.';
			
				table[0, 0] = 'c';
			}
			
			return possible;
		}
	}
}