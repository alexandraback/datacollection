import java.util.*;
import java.io.*;

public class Dijk
{
	static int[][] prod = {
		{0,  0,  0,  0,  0},
		{0,  1,  2,  3,  4},
		{0,  2, -1,  4, -3},
		{0,  3, -4, -1,  2},
		{0,  4,  3, -2, -1}};
	
	static int prod(int a, int b)
	{
		return sign(a*b)*prod[Math.abs(a)][Math.abs(b)];
	}
	
	static int sign(int a)
	{
		return a>0?1:-1;
	}
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		
		String[] dat;
		String seq;
		boolean negone;
		int l, p;
		long x, iloc, kloc;
		int numRuns=Integer.parseInt(in.readLine());
		for (int run=1; run<=numRuns; run++)
		{
			dat=in.readLine().split(" ");
			l=Integer.parseInt(dat[0]);
			x=Long.parseLong(dat[1]);
			p=1;
			seq=in.readLine();
			negone=true;
			iloc=-1;
			kloc=Long.MAX_VALUE;
			for (int i=0; negone && i<4; i++)
			{
				for (int j=0; negone && j<l; j++)
				{
					if (iloc<0 && p==2) // i
						iloc=i*l+j;
					else if (p==4) // k
					{
						if (iloc<0)
							kloc=Math.min(kloc, (4+i)*l+j);
						else
							kloc=Math.min(kloc, i*l+j);
					}
//System.out.print(p+" ");
					
					if (j==0 && i==(x%4) && p!=-1) // -1
						negone=false;
					p=prod(p, seq.charAt(j)-'i'+2);
				}
			}
//System.out.println();
//System.out.println(negone +" "+ iloc +" "+ kloc +" "+ l +" "+ x);
			System.out.print("Case #"+run+": ");
			System.out.println((negone && 0<=iloc && iloc<l*x && kloc<l*x)?"YES":"NO");
		}
	}
}