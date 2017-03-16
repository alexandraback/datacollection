import java.io.*;
import java.math.*;
class cJQ3_2
{
	public static void main (String args[])	throws IOException
	{
		File file =new File("sub1.txt");
		File file1 =new File("C-large.in");
		file.createNewFile();
		FileWriter writer =new FileWriter(file);
		int inc=1;
		try (BufferedReader br = new BufferedReader(new FileReader(file1))) {
		String line;
		char ar[][]=new char[5][5];
		int ar1[][]=new int [5][5];
		ar[1][1]='h';ar[1][2]='i';ar[1][3]='j';ar[1][4]='k';ar[2][1]='i';ar[2][2]='h';ar[2][3]='k';ar[2][4]='j';ar[3][1]='j';ar[3][2]='k';ar[3][3]='h';ar[3][4]='i';ar[4][1]='k';ar[4][2]='j';ar[4][3]='i';ar[4][4]='h';
		ar1[1][1]=1;ar1[1][2]=1;ar1[1][3]=1;ar1[1][4]=1;ar1[2][1]=1;ar1[2][2]=-1;ar1[2][3]=1;ar1[2][4]=-1;ar1[3][1]=1;ar1[3][2]=-1;ar1[3][3]=-1;ar1[3][4]=1;ar1[4][1]=1;ar1[4][2]=1;ar1[4][3]=-1;ar1[4][4]=-1;
		boolean var=false;
		while ((line = br.readLine()) != null) 
		{
       		if(inc==1)
			{inc+=1;}
			else
			{
				String inp[]=line.split(" ");
				long l=(long)Double.parseDouble(inp[0]);
				long x=(long)Double.parseDouble(inp[1]);
				String str=br.readLine();String pr="";int cr[]=new int[5];
				char cVar=str.charAt(0);int v1=0,v2=0,mi=1;cr[((int)cVar)-103]=1;
				for(int i=1; i<l; i++)
				{
					
					v1=((int)cVar)-103;
					v2=((int)str.charAt((int)i))-103;
					cr[v2]=1;
					mi=mi*ar1[v1][v2];
					cVar=ar[v1][v2];
				}
				int sum=cr[2]+cr[3]+cr[4];char rep=str.charAt(0);
				if(l==1 )
				{
					pr="NO";
				}
				else if(chkB(sum,str,rep,str.charAt(1),l))
				{
					int d=(int)l/2;
					if((d*x)>=6)
					{
						x=x*d;
						if(x%2==0)
						{
							if(x%4==0)
							{
								pr="NO";
							}
							else
							{
								pr="YES";
							}
						}
						else
						{
							pr="NO";
						}
					}
					else
					{
						pr="NO";
					}
				}
				else if(cVar=='h')
				{
					if(mi==-1)
					{
						pr=x%2==0?"NO":"YES";
					}
					else
					{
						pr="NO";
					}
				}
				else
				{
					if(x%2==0)
					{
						if(x%4==0)
						{
							pr="NO";
						}
						else
						{
							pr="YES";
						}
					}
					else
					{
						pr="NO";
					}
				}
				
				writer.write("Case #"+(inc-1)+": "+pr+"\n");
				inc++;
			}
		}
		writer.flush();
		writer.close();
		}
	}
	public static boolean chkB(int sum, String str,char rep,char rep1,long l)
	{
		if(sum==2 && (str.length()%2==0) )
		{		
				for(int j=0; j<l;j+=2)
				{
					if(rep!=str.charAt(j) || rep1!=str.charAt(j+1))
					{
						return false;
					}
				}
		}
		else
		{
			return false;
		}
		return true;
	}
	
}