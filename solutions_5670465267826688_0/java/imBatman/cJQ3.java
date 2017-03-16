import java.io.*;
import java.math.*;
class cJQ3
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
				int l=Integer.parseInt(inp[0]);
				int x=Integer.parseInt(inp[1]);
				String ijk=br.readLine();
				int v1=0,v2=0;int mi=1;
				String str="";	String pr="";char cVar;
				if((l*x)<3)
				{
					pr="NO";
				}
				else
				{
					for(int i=0; i<x; i++)
					{
						str=str+ijk;
					}
					l=l*x;
					//System.out.println(str);
					cVar=str.charAt(0);
					for(int j=0; j<l-2;j++)
					{
						//System.out.println(cVar+" "+j);
						if(cVar=='i' && mi==1)
						{
							//System.out.println(j+"j");
							var=findj(str,j,ar,ar1,l);
							
							if(var)
							{break;}
						}
						
							var=false;
							v1=((int)cVar)-103;
							v2=((int)str.charAt(j+1))-103;
							mi=mi*ar1[v1][v2];
							cVar=ar[v1][v2];
					}
				if(var)
				{
					pr="YES";
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
	public static boolean findj(String str, int pos,char ar[][],int ar1[][],int l)
	{
		char cVar=str.charAt(pos+1);int mi=1;boolean var=false;int v1=0,v2=0;
		for(int j=pos+1; j<l-1;j++)
		{
			//System.out.println(j+" "+cVar+" "+mi);
			if(cVar=='j' && mi==1)
			{
				//System.out.println(j+"k");
				var=findk(str,j,ar,ar1,l);
				
				if(var)
				{break;}
			}
			
				var=false;
				v1=((int)cVar)-103;
				v2=((int)str.charAt(j+1))-103;
				mi=mi*ar1[v1][v2];
				cVar=ar[v1][v2];
			
		}
		return var;
	}
	public static boolean findk(String str, int pos,char ar[][],int ar1[][],int l)
	{
		char cVar=str.charAt(pos+1);int v1=0,v2=0;int mi=1;boolean var=false;
		
		for(int j=pos+1; j<l-1;j++)
		{
			v1=((int)cVar)-103;
			v2=((int)str.charAt(j+1))-103;
			mi=mi*ar1[v1][v2];
			cVar=ar[v1][v2];
		}
		//System.out.println(cVar+"c"+mi);
		if(cVar=='k' && mi==1)
		{
			var=true;//System.out.println("k");
		}
		else
		{
			var=false;
		}
		return var;
	}
}