import java.util.*;
import java.io.*;
public class C {
	static int tc,r,c,m;
	static char[][] mat;
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("C-small-attempt3.in"));
		PrintWriter out = new PrintWriter(new File("C.out"));
		tc = i(in.nextLine());
		for(int i = 0; i < tc; i++)
		{
			out.printf("Case #%d: \n",i+1);
			StringTokenizer st = new StringTokenizer(in.nextLine());
			r = i(st.nextToken());
			c = i(st.nextToken());
			m = i(st.nextToken());
			mat = new char[r][c];			
			boolean imp = false;
			for(int j = 0; j < r; j++) Arrays.fill(mat[j],'*');
			
			int rem = r*c-m;
			//System.out.printf("%d %d\n",i+1,rem);		
			if(rem==1);
			else if(r==1)
				for(int j = 1; j < rem; j++)
					mat[0][j]='.';
			else if(c==1)
				for(int j = 1; j < rem; j++)
					mat[j][0]='.';
			else if(rem>1 && rem < 4 || rem == 5 || rem == 7) {out.println("Impossible"); imp = true;}
			else if(r==2)
			{
				if(rem==2 || rem%2==1){ out.println("Impossible"); imp = true;}
				else 
					for(int j = 0; j < rem/2; j++)
						mat[0][j]=mat[1][j] = '.';
			}
			else if(c==2)
			{
				if(rem==2 || rem%2==1) {out.println("Impossible"); imp = true;}
				else 
					for(int j = 0; j < rem/2; j++)
						mat[j][0]=mat[j][1] = '.';
			}
			else
			{
				
					if(rem== 4) 
						mat[0][0]=mat[0][1]=mat[1][1]=mat[1][0] = '.';
					else if(rem==6)
						mat[0][0]=mat[0][1]=mat[1][1]=mat[1][0] = mat[2][0] = mat[2][1]= '.';
					else 
					{
						mat[0][0]=mat[0][1]=mat[1][1]=mat[1][0]=mat[2][0]=mat[2][1]=mat[0][2]=mat[1][2]='.';
						int rem2 = rem - 8;
						//System.out.println(i+1+" "+rem2);
						for(int j = 3; j < r && rem2>=2; j++)
						{
							mat[j][0]=mat[j][1]='.';
							rem2-=2;
						}
						for(int j = 3; j < c && rem2 >=2; j++)
						{
							mat[0][j]=mat[1][j]='.';
							rem2-=2;
						}
						outer:
						for(int j = 2; j < r; j++)
							for(int k = 2; k < c; k++)
							{
								if(rem2<=0) break outer;
								mat[j][k]='.';
								rem2--;
							}
							
					}
				
			}
			
			mat[0][0] = 'c';
			if(!imp)
			{
				for(int j = 0; j < r; j++)
				{
					for(int k = 0; k < c; k++)
					{
						out.print(mat[j][k]);
					}
					out.println();
				}
			}
			
		}
		out.close();
		System.exit(0);
	}
	static int i(String s)
	{
		return Integer.parseInt(s);
	}
}
