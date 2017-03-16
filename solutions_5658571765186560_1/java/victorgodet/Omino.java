import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class Omino {
	
	public static boolean filled(int x, int r, int c)
	{
		if(x >= 7 || (int)((x+1)/2) > Math.min(r, c) || r*c % x != 0)
			return false;
		
		/*
		int zeros = (int)(c/2) * (int)((r+1)/2) + (int)((c+1)/2)*(int)(r/2);
		int ones = r*c - zeros;
		*/
		
		if(Math.min(r, c) == 2)
		{
			if(x == 4)
				return false;
		}
		

		if(Math.min(r, c) == 3)
		{
			if(x == 5 && Math.max(r,c) == 5)
				return false;
			if(x == 6)
				return false;
				
		}
			
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
		
		
		
		int t = scan.nextInt();
		
		int x, r, c;
		
		for(int i = 0; i < t; i++)
		{ 	
			System.out.println("Case #" + (i+1));
			
			x = scan.nextInt();
			r = scan.nextInt();
			c = scan.nextInt();
			
			try {
				if(filled(x, r, c))
					out.write("Case #"+(i+1)+": GABRIEL\n");
				else
					out.write("Case #"+(i+1)+": RICHARD\n");
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
