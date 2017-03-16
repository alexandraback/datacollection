import java.io.*;
import java.math.*;
class cJQ4
{
	public static void main (String args[])	throws IOException
	{
		File file =new File("sub.txt");
		File file1 =new File("read.txt");
		file.createNewFile();
		FileWriter writer =new FileWriter(file);
		int inc=1;int ar[][]=new int[3][7];
		ar[1][1]=1;ar[2][1]=1;ar[1][2]=1;ar[2][2]=2;ar[1][3]=2;ar[2][3]=3;ar[1][4]=3;ar[2][4]=4;ar[1][5]=3;ar[2][5]=5;ar[1][6]=4;ar[2][6]=6;
		try (BufferedReader br = new BufferedReader(new FileReader(file1))) {
		String line;
		while ((line = br.readLine()) != null) 
		{
       		if(inc==1)
			{inc+=1;}
			else
			{
				String inp[]=line.split(" ");
				int n=Integer.parseInt(inp[0]);
				int x=Integer.parseInt(inp[1]);
				int y=Integer.parseInt(inp[2]);
				int chk=1,chk1=1;String pr="";
				if(n<=6)
				{
						if((x>=ar[1][n] && y>=ar[2][n]) ||(y>=ar[1][n] && x>=ar[2][n]) )
						{
							//chk=n>=x?n%x:x%n;
							//chk1=n>=y?n%y:y%n;
							if(x%n==0 || y%n==0)
							{
								pr="GABRIEL";
							}
							else
							{
								pr="RICHARD";
							}
						}	
						else
						{
							pr="RICHARD";
						}
				}
				else
				{
					pr="RICHARD";
				}
				
				writer.write("Case #"+(inc-1)+": "+pr+"\n");
				inc++;
			}
		}
		writer.flush();
		writer.close();
		}
	}
	
}