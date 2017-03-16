import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("input.txt"));
		File write = new File("output.txt");
		FileWriter fWriter = new FileWriter(write);
		
		int nb = sc.nextInt();
		int n = sc.nextInt();
		int j = sc.nextInt();

		fWriter.write("Case #1: \n");
		for(int i = 0 ; i < j ; i++)
		{
			String output = "1";
			String right = Integer.toBinaryString(i);
			for(int k = 0 ; k < (n-2)-right.length()*2 ; k+=2)
			{
				output += "00";
			}
			for(int k = 0 ; k < right.length() ; k++)
			{
				if(right.charAt(k) == '1')
				{
					output += "11";
				}
				else
				{
					output += "00";
				}
			}
			output += "1";
			fWriter.write(output+" 3 4 5 6 7 8 9 10 11\n");
			
			System.out.println("Case #"+(i+1)+": "+output);
		}
		fWriter.flush();
		fWriter.close();
		sc.close();
	}
	/*public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("input.txt"));
		File write = new File("output.txt");
		FileWriter fWriter = new FileWriter(write);
		
		int nb = sc.nextInt();	
		sc.nextLine();
		for(int i = 0 ; i < nb ; i++)
		{
			String s = sc.nextLine();
			int sum = 0;
			boolean[] pancakes = new boolean[s.length()+1];
			pancakes[s.length()] = true;
			for(int j = 0 ; j < s.length() ; j++)
			{
				pancakes[j] = (s.charAt(j) == '+');
			}
			
			for(int j = 0 ; j < pancakes.length-1 ; j++)
			{
				if(pancakes[j] != pancakes[j+1])
					sum++;
			}
			
			fWriter.write("Case #"+(i+1)+": "+sum+"\n");
			
			System.out.println("Case #"+(i+1)+": "+sum);
		}
		fWriter.flush();
		fWriter.close();
		sc.close();
	}*/
	
	/*public static void addDigits(boolean[] seen, int nb)
	{
		while(nb > 0)
		{
			seen[nb%10] = true;
			nb /= 10;
		}
	}
	
	public static boolean test(boolean[] seen)
	{
		boolean toReturn = true;
		for(boolean b : seen)
			toReturn &= b;
		return toReturn;
	}
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("input.txt"));
		File write = new File("output.txt");
		FileWriter fWriter = new FileWriter(write);
		
		int nb = sc.nextInt();
		
		for(int i = 0 ; i < nb ; i++)
		{
			int test = sc.nextInt();
			System.out.println(test);
			boolean[] seen = new boolean[10];
			for(int j = 0 ; j < seen.length ; j++)
			{
				seen[j] = false;
			}
			int nbToAdd = 0;
			if(test == 0)
			{
				fWriter.write("Case #"+(i+1)+": INSOMNIA\n");
			}
			else
			{
				while(!test(seen))
				{
					nbToAdd += test;
					addDigits(seen, nbToAdd);
				}
				fWriter.write("Case #"+(i+1)+": "+nbToAdd+"\n");
			}
		}
		fWriter.flush();
		fWriter.close();
		sc.close();
	}*/
}
