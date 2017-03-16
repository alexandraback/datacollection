import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class bullseyelarge {
	  
	public static int T;
	
	public static long r;
	public static long t;
	
	public static long calRingNum()
	{
		long res = 0L;
		
		double k = Math.sqrt((2.0*r-1.0)*(2.0*r-1.0)/16.0+t/2.0)-(2.0*r-1.0)/4.0;
		
		res = (long)k - 5L;
		long bound = res+7L;
		long i = res;
		for(i=res; i <= bound; i++)
		{
			if( 2*i*i+(2*r-1)*i > t)
				break;
		}
		
		res = i-1;
		return res;
	}
	
	public static void main(String[] s) throws IOException
	{
		  //BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
				File file = new File("A-large.in");
				BufferedReader input = new BufferedReader(new FileReader(file));
				
				File outfile = new File("A-large-RA.out");
				
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
