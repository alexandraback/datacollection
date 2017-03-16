import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class Round1B_Problem1 {
	
	 public static int getReverseInt(int value) 
	 {

		    int resultNumber = 0;
		    for(int i = value; i !=0; i /= 10) {
		        resultNumber = resultNumber * 10 + i % 10;
		    }
		    return resultNumber;        
		}
	 

	public static int minCount(int n)
	{
		char[] digitsAsChars = String.valueOf(n).toCharArray();
		int length = digitsAsChars.length;
		int m = n;
	
		if(digitsAsChars[length-1] == '0')
		{
			int rec = 1;
			for(int i = 1; i < length; i++)
				if(digitsAsChars[length-i] == '0')
					rec *=10;
			m = n - rec+1;
		}
		
		if(m == 1)
			return minCountB(n);

		return Math.min(minCountB(getReverseInt(m))+1, minCountB(n));
	}
	
	public static int minCountB(int n)
	{
		if(n <= 20)
			return n;
				
		char[] digitsAsChars = String.valueOf(n).toCharArray();
		int length = digitsAsChars.length;
		
		if(digitsAsChars[length-1] == '0')
			return 1+minCount(n-1);

			
		int dec = (int)(Math.pow(10,length-1));
		int first = (int)(digitsAsChars[0])-(int)('0');
		int remain = n- first*dec;
		
		if(first == 1)
			return minCountB(dec)+remain;
		
		//System.out.println("n:"+n+" | dec:"+dec+" | f:"+first+" | r:"+remain);
		
		return minCountB(dec) + first + remain;

	}
	
	public static void main(String[] args)
	{
		System.out.println(minCount(100));
		Scanner s = new Scanner(System.in);
		try {
			s = new Scanner(new FileReader("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			s.close();
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
		
		
		
		int t = s.nextInt();
		
		int n;
	
		for(int i = 0; i < t; i++)
		{ 	
			//System.out.println("Case #" + (i+1));
	
			n = s.nextInt();
			try {
				out.write("Case #"+(i+1)+": "+ minCount(n) + "\n");
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
		
		s.close();
		
	}

}
