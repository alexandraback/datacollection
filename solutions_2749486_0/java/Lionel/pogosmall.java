import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class pogosmall {
	  
	public static int t;
	
	public static String findPogo(int x, int y)
	{
		String s = new String();
		
		if(x > 0)
		{
			while(x > 0)
			{
				s += "WE";
				x--;
			}
		}
		else
		{
			while(x < 0)
			{
				s += "EW";
				x++;
			}
		}
		
		if(y > 0)
		{
			while(y > 0)
			{
				s += "SN";
				y--;
			}
		}
		else
		{
			while(y < 0)
			{
				s += "NS";
				y++;
			}
		}
		
		return s;
	}
	
	public static void main(String[] s) throws IOException
	{
		//BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
				File file = new File("1C\\B-small-attempt0.in");
				BufferedReader input = new BufferedReader(new FileReader(file));
				
				File outfile = new File("1C\\B-small0.out");
				
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
					
					int x = Integer.parseInt(split[0]);
					int y = Integer.parseInt(split[1]);
					
					String decstr = findPogo(x, y);
					
					 String outstr = "Case #"+ new Integer(i+1).toString()+": ";
					 //assert(Math.abs(Double.parseDouble(decstr)-result) <= 1e-6);
					 
					 System.out.println(outstr+decstr);
					 bw.write(outstr+decstr+"\n");
				}
				
				input.close();
				bw.close();
	}
}
