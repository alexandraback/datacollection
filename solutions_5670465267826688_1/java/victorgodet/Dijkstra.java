import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class Dijkstra {
	
	/*
	
	  1 => 0
	 -1 => 1
	  i => 2
	 -i => 3
	  j => 4
	 -j => 5
	  k => 6
	 -k => 7
	 */
	
	public static boolean possible(int[] seq, int[][] table)
	{
		
		int res = seq[0], l = seq.length;
		
		for(int i = 1; i < l; i++)
			res = table[res][seq[i]];

		if(res != 1)
			return false;
		
		int value = seq[0], first;
		for(first = 0; first < l-2; first++)
		{
			if(value == 2)
				break;
			value = table[value][seq[first+1]];
		}
		
		if(first == l-2)
			return false;
		
		int second;
		value = seq[first+1];
		for(second = first + 1; second < l-1; second++)
		{
			if(value == 4)
				break;
			value = table[value][seq[second+1]];
		}

		if(second == l-1)
			return false;
		
		return true;
	}
	 

	public static void main(String[] args)
	{
		
		Scanner scan = new Scanner(System.in);
		try {
			scan = new Scanner(new FileReader("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			scan.close();
			return;
		}
		
		Writer out = null;
		
		try {
			out = new BufferedWriter(new OutputStreamWriter(
	              new FileOutputStream("output.txt"), "utf-8"));
		}
		
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		
		int[][] table = new int[8][8];
		
		
		
		
		for(int i = 0; i < 8; i++)
		{
			table[i][0] = i;
			table[0][i] = i;
		}
		
		for(int i = 2; i < 8; i++)
		{
			table[i][1] = (i % 2 == 0) ? i + 1 : i - 1;
			table[1][i] = table[i][1];
		}
		
		table[1][1] = 0;
		
		for(int i = 2; i < 8; i++)
			table[i][i] = 1;
		
		for(int i = 1; i < 4; i++)
		{
			table[2*i][2*i+1] = 0;
			table[2*i+1][2*i] = 0;
		}
		
		table[2][4] = 6;
		table[2][5] = 7;
		table[2][6] = 5;
		table[2][7] = 4;
		table[4][2] = 7;
		table[4][3] = 6;
		table[4][6] = 2;
		table[4][7] = 3;
		table[6][2] = 4;
		table[6][3] = 5;
		table[6][4] = 3;
		table[6][5] = 2;
		
		
		for(int i = 1; i < 4; i++)
			for(int j = 2; j < 8; j++)
				if(j != 2*i && j != 2*i + 1)
					table[2*i+1][j] = table[2*i][j] + ((table[2*i][j] % 2 == 0) ? 1 : - 1);
		/*
		
		
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				String s = "";
				switch(table[i][j])
				{
				case 0:
					s = " 1";
					break;
				case 1:
					s = "-1";
					break;
				case 2:
					s = " i";
					break;
				case 3:
					s = "-i";
					break;
				case 4:
					s = " j";
					break;
				case 5:
					s = "-j";
					break;
				case 6:
					s = " k";
					break;
				case 7:
					s = "-k";
					break;
				
				}
				System.out.print(s + " ");
			}
			System.out.println();
		}
		
		*/
		
		
		int t = scan.nextInt();
		
		int l; 
		long x;
		int x_reduced;
		
		for(int i = 0; i < t; i++)
		{
			System.out.println("Case #" + (i+1));
			
			l = scan.nextInt();
			x = scan.nextLong();
						
			System.out.println("x = " + x + " | l = "+ l);
			
			x_reduced = (int)(Math.min(x, (x % 12) + 12));
					
			String sequence = scan.next();
			
			int[] seq = new int[l*x_reduced];
			
			for(int j = 0; j < l; j++)
				for(int k = 0; k < x_reduced; k++)
					seq[j+k*l] = 2*( (int)(sequence.charAt(j)) - (int)('i') + 1);
				
			try {
			if(possible(seq, table))
				out.write("Case #"+(i+1)+": YES\n");
			else
				out.write("Case #"+(i+1)+": NO\n");
			}
			catch ( IOException e ) {
	            e.printStackTrace();
	        }
		}
		
		
		
		try {
		out.close();
		}
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		scan.close();
		
	}



}
