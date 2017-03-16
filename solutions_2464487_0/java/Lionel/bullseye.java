import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class bullseye {
	  
	public static int T;
	
	public static long r;
	public static long t;
	
	public static long calRingNum()
	{
		long res = 0L;
		
		long m = t;
		long base = r;
		while(true)
		{
			double next = 2*base+1;
			if(next <= m)
			{
				m -= next;
				base+=2;
			}
			else
				break;
			res++;
		}
		
		return res;
	}
	
	public static void main(String[] s) throws IOException
	{
		//BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
				File file = new File("A-small-attempt0.in");
				BufferedReader input = new BufferedReader(new FileReader(file));
				
				File outfile = new File("A-small-attempt0.out");
				
				if(!outfile.exists())
					file.createNewFile();
				
				FileWriter fw = new FileWriter(outfile.getAbsoluteFile());
				BufferedWriter bw = new BufferedWriter(fw);
				
				String line = input.readLine();
				
				T = Integer.parseInt(line);
				
				for(int i=0; i< T; i++)
				{
					line = input.readLine();
					
					String[] split = line.split(" ");
					
					r = Long.parseLong(split[0]);
					t = Long.parseLong(split[1]);
					 
					long result = calRingNum();
					String decstr = new Long(result).toString();
					
					 String outstr = "Case #"+ new Integer(i+1).toString()+": ";
					 
					 bw.write(outstr+decstr+"\n");
					 //System.out.println(outstr+decstr);
				}
				
				input.close();
				bw.close();
	}
}
