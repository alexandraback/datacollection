import java.io.*;
import java.util.*;
class Source1 
{
	public static void main(String[] args) throws IOException 
	{
		String s,word,buffer;
		String[][] board;

		FileReader input = new FileReader("B-small.in");
		Scanner in = new Scanner(input);
		File file = new File("B-small.out");
		BufferedWriter out = new BufferedWriter(new FileWriter(file));

		s = in.nextLine();
		int count= Integer.parseInt(s);

		int i=1;
		 while (in.hasNext())
		{

			 out.write("Case #"+(i++)+": ");

			
				if(in.hasNext())s = in. nextLine();

				String[] sp = s.split(" ");

				int [] list = new int[sp.length]; 
				for (int x=0;x<sp.length;x++ )
				{
					list[x]= Integer.parseInt(sp[x]);

				}

				boolean[][] result =slide(i-1,list);
				if(result!=null)
				{
					out.write("POSSIBLE");
					out.newLine();

					for (int x=0;x<list[0];x++ )
					{
						for (int j=0;j<list[0];j++ )
						{
							if(result[x][j])
							{
								out.write("1");
							}
							else
							{
								out.write("0");
							}
						}
						out.newLine();
					}

				}
				else
				{
					out.write("IMPOSSIBLE");
					out.newLine();
				}


		}


		 out.close();
	}
	public static boolean[][] slide(int cases,int[] list)
	{
		int B=list[0];
		int M=list[1];
		
		boolean[][] result =new boolean[B][B];

		if(M==0)
		{
			return result;
		}
			

		if(M<B)
		{
			result[0][B-1]=true;
			M--;
				for(int j=1;j<B-1;j++ )
				{
					if(M>0)
					{
						result[0][j]=true;
						result[j][B-1]=true;
						M--;
					}
				}

		}
		else
		{
			result[0][B-1]=true;
			M--;

				for(int j=1;j<B-1;j++ )
				{
					if(M>0)
					{
						result[0][j]=true;
						M--;
					}
				}

				for(int i=1;i<B-1;i++ )
				{
						result[i][B-1]=true;
				}		

			/////
				for(int i=1;i<B-1;i++ )
				{
					for(int j=i+1;j<B-1;j++ )
					{
						if(M>0)
						{
						result[i][j]=true;
						M=M-numpath(i,j,result,B);
						}
						
					}

				}
			



		}


		if(M>0)
		{
			return null;
		}
		else
		{
			if(M==-1)
			{
				result[0][B-1]=false;
				M--;
			}
			else if(M<0)
			{
				int remain = M*-1;
				//System.out.println(remain);
				for(int i=0;i<B-1;i++)
				{
					for(int j=0;j<B;j++)
					{
						if(result[i][j]&&numpath(i,j,result,B)==remain)
						{
							result[i][j]=false;
							//System.out.println(cases+"    "+i+" "+j);
							i=B;
							break;
						}
					}
				}

			}


		}



		return result;
	}

	public static int numpath(int x,int y,boolean[][] result,int B)
	{
		int num=0;
		for(int i=0;i<B;i++)
		{
			if(result[i][x])
			{
				num++;
			}
		}
		return num;

	}

}
