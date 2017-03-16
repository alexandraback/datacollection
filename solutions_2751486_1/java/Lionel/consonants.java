import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class consonants {
	  
	public static int t;
	
	static class range
	{
		public long start;
		public long end;
		public long len;
		
		public range(long s, long e)
		{
			start = s;
			end = e;
			len = e-s+1;
		}
	}
	
	public static boolean isCon(char a)
	{
		if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
			return false;
		return true;
	}
	
	public static long findCon(String s, int n)
	{
		long curc = 0;
		long sum = 0;
		
		ArrayList<range> ar = new ArrayList<range>();
		
		for(int i=0; i< s.length(); i++)
		{
			if(isCon(s.charAt(i)))
				curc++;
			else
			{
				if(curc >= n)
				{
					ar.add(new range(i-curc, i-1));
				}
				curc = 0;
			}	
		}
		
		if(curc >= n)
		{
			ar.add(new range(s.length()-curc, s.length()-1));
		}
		
		for(int i=0; i< ar.size(); i++)
		{
			range tmp = ar.get(i);
			long base =  (long)(tmp.len-n+1)*(long)(2*s.length()-2*tmp.end+tmp.len-n)/2L;  //(tmp.len-n+1)*(s.length()-tmp.end);
			sum += base;
			long base2 = (long)(tmp.len-n)+(long)(s.length()-tmp.end);
			if(i > 0)
			{
				range tmp2 = ar.get(i-1);
				sum +=  (long)(tmp.start-tmp2.end-1+n-1)*base2;  //    (tmp.start-(tmp2.end-tmp2.len+2))*base2;
			}
			else
			{
				sum += tmp.start*base2;
			}
		}
		return sum;
	}
	
	public static void main(String[] s) throws IOException
	{
		//BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
				File file = new File("1C\\A-large.in");
				BufferedReader input = new BufferedReader(new FileReader(file));
				
				File outfile = new File("1C\\A-large-1.out");
				
				if(!outfile.exists())
					file.createNewFile();
				
				FileWriter fw = new FileWriter(outfile.getAbsoluteFile());
				BufferedWriter bw = new BufferedWriter(fw);
				
				String line = input.readLine();
				
				t = Integer.parseInt(line);
				
				for(int i=0; i< t; i++)
				{ 
					line = input.readLine();
					String[] split = line.split(" ");
					
					String ss = split[0];
					int n = Integer.parseInt(split[1]);
					
					 String outstr = "Case #"+ new Integer(i+1).toString()+": ";
					 String decstr = new Long(findCon(ss, n)).toString();
					 System.out.println(outstr+decstr);
					 bw.write(outstr+decstr+"\n");
				}
				
				input.close();
				bw.close();
	}
}
