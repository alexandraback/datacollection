package Round1C;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class A {

	public static void main(String[] args) throws IOException{
		Scanner k = new Scanner(System.in);
		
		int T = k.nextInt(); k.nextLine();
		
		String[] solution = new String[T];
		
		for (int x = 1; x <= T; x++)
		{
			
			
			String name = k.next(); int sublength = k.nextInt(); k.nextLine();
			
			char[] letter = name.toCharArray();
			boolean[] consonant = new boolean[letter.length];
			
			for (int y = 0; y < letter.length; y++)
			{
				if (letter[y] == 'a' ||letter[y] == 'e' ||letter[y] == 'i' ||letter[y] == 'o' ||
						letter[y] == 'u')
				{
					//vowel
					consonant[y] = true;
				}
			}
			
				int[] values = new int[consonant.length];
				int count = 0;
				int countV = 1;
				
				for (int y = 0; y < consonant.length - 1; y++)
				{
					if (consonant[y] == consonant[y+1])
					{
						if (y + 2 == consonant.length)
						{
							if (consonant[y] == consonant[y+1])
							{
								countV++;
								values[count] = countV;
								count++;
							}
							else
							{
								values[count] = countV;
								count++;
								values[count] = 1;
								count++;
							}
						}
						else	
							countV++;
					}		
					else
					{
						values[count] = countV;
						countV = 1;
						count++;
					}
						
				}
				
				int[] numbers = new int[count];
				for (int y = 0; y < numbers.length; y++)
				{
					numbers[y] = values[y];
					//System.out.println(numbers[y]);
				}
				
				int sum = 0;
				
				int m = 0, b = 0, a = 0;

					int[] mPlaces = new int[numbers.length];
					
					if (consonant[0])
					{
						for (int y = 0; y < numbers.length; y++)
						{
							if (y % 2 == 1 && numbers[y] >= sublength)
							{
								mPlaces[m] = y;
								m++;
							}
						}
					}
					else
					{
						for (int y = 0; y < numbers.length; y++)
						{
							if (y % 2 == 0 && numbers[y] >= sublength)
							{
								
								mPlaces[m] = y;
								m++;
							}
						}
					}
					
					
					int[] newMPlaces = new int[m];

					for (int y = 0; y < newMPlaces.length; y++)
					{
						newMPlaces[y] = mPlaces[y];
					}
					
					int[] newNumber = new int[m+2];
					if (m > 0)
					{
					if (mPlaces[0] == 0)
						b = 0;
					else
					{
						for (int y = 0; y < mPlaces[0]; y++)
						{
							b = b + numbers[y];
						}
					}
					
					if (newMPlaces[newMPlaces.length-1] == numbers.length -1)
						a = 0;
					else
					{
						for (int y = mPlaces[m-1]; y < numbers.length; y++)
						{
							if (y != mPlaces[m - 1])
								a = a + numbers[y];
						}
					}
					}
					
					
				int n = name.length() - sublength;
				
				System.out.println("Before: " + b);
				System.out.println("After: " + a);
				System.out.println("M: " + m);
				System.out.println("N: " + n);
				
				long number = m*(n+1) - ((m-1)*(a+b+1));
				
				String ans = "Case #" + x + ": " + number;
				solution[x-1] = ans;
			}
		printOutAnswers(solution);
		}
	public static void printOutAnswers(String[] solution) throws IOException
	{
		//print out caseStorer and write to a file
		PrintWriter out = new PrintWriter(new FileWriter("/Users/davidlong"+
		"/Desktop/javaoutputs/A.txt"));
		
		for (int x = 0; x < solution.length; x++)
		{
			out.println(solution[x]);
			System.out.println(solution[x]);
		}
		
		out.close();
	}
	}

