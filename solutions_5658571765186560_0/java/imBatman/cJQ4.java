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
		int inc=1;
		try (BufferedReader br = new BufferedReader(new FileReader(file1))) {
		String line;
		while ((line = br.readLine()) != null) 
		{
       		if(inc==1)
			{inc+=1;}
			else
			{
				int ar[][][]=new int [5][5][5];
				for(int i=0; i<5; i++)
				{
					for(int j=0; j<5; j++)
					{
						ar[i][j][1]=1;
					}
				}
				ar[1][2][2]=1;ar[2][2][2]=1;ar[1][4][2]=1;ar[2][4][2]=1;ar[4][4][2]=1;ar[2][3][2]=1;ar[2][3][3]=1;ar[3][4][2]=1;ar[3][3][3]=1;ar[3][4][3]=1;ar[4][4][4]=1;ar[3][4][4]=1;
				String inp[]=line.split(" ");
				int n=Integer.parseInt(inp[0]);
				int x=Integer.parseInt(inp[1]);
				int y=Integer.parseInt(inp[2]);
				int lo=x<=y?x:y;
				int hi=x>=y?x:y;
				String pr=ar[lo][hi][n]==1?"GABRIEL":"RICHARD";
				writer.write("Case #"+(inc-1)+": "+pr+"\n");
				inc++;
			}
		}
		writer.flush();
		writer.close();
		}
	}
	
}