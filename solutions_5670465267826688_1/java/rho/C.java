import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class quat
{
	char c;
	int s;
	char[][] mlt = {{'1','i','j','k'},
					{'i','1','k','j'},
					{'j','k','1','i'},
					{'k','j','i','1'}};

	int[][] sgn = {{ 1, 1, 1, 1},
				   { 1,-1, 1,-1},
				   { 1,-1,-1, 1},
				   { 1, 1,-1,-1}};

	
	public quat(char C, int S)
	{
		c=C;
		s=S;
	}
	
	void mult(quat q)
	{
		int idx1=(c=='1')?0:(c-'h');
		int idx2=(q.c=='1')?0:(q.c-'h');
		s*=q.s*sgn[idx1][idx2];
		c=mlt[idx1][idx2];
	}

	void mult(char C, int S)
	{
		int idx1=(c=='1')?0:(c-'h');
		int idx2=(C=='1')?0:(C-'h');
		s*=S*sgn[idx1][idx2];
		c=mlt[idx1][idx2];
	}
	
	void div(char C, int S)
	{
		if(C=='1')
			mult(C, S);
		else
			mult(C, -S);
	}

	@Override
	public String toString() {
		return (s<0?'-':' ')+""+c;
	}
}

public class C {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C.in"));
		int numT = sc.nextInt();
		for(int test=1; test<=numT; ++test)
		{
			long L = sc.nextLong(), X=sc.nextLong();
			char[] arr = sc.next().toCharArray();
			//System.out.println(arr);
			quat Q = new quat('1', 1);
			quat T = new quat('1', 1);
			for(int i=0; i<L; ++i)
				T.mult(arr[i], 1);
			
			long used=0;
			int Idx=-1, Jdx=-1;
			
			I:	for(int l=0; l<4; l++)
				for(int i=0; i<L; ++i)
				{
					Q.mult(arr[i], 1);
					if(Q.c=='i' && Q.s==1)
					{
						//done i
						used+=l+1;
						Idx=i+1;
						break I;
					}
				}
				
				if(Idx<0) //not i
				{
					System.out.printf("Case #%d: NO\n", test);
					continue;
				}
				
				
				Q = new quat('1', 1);
				for(int i=Idx; i<L; ++i)
				{
					Q.mult(arr[i], 1);
					if(Q.c=='j' && Q.s==1)
					{
						//done j
						Jdx=i+1;
						break;
					}
				}
				
				if(!(Q.c=='j' && Q.s==1))
				{				
			J:	for(int l=0; l<4; l++)
				for(int i=0; i<L; ++i)
				{
					Q.mult(arr[i], 1);
					if(Q.c=='j' && Q.s==1)
					{
						//done i
						used+=l+1;
						Jdx=i+1;
						break J;
					}
				}
				}
				
				if(Jdx<0) //not j
				{
					System.out.printf("Case #%d: NO\n", test);
					continue;
				}
				
				Q = new quat('1', 1);
				for(int i=Jdx; i<L; ++i)
				{
					Q.mult(arr[i], 1);
				}
				
				if(used>X) //cant do it
				{
					System.out.printf("Case #%d: NO\n", test);
					continue;
				}
				else
				{
					while((used%4)!=(X%4))
					{
						Q.mult(T);
						++used;
					}
					if(Q.c=='k' && Q.s==1) //done
						System.out.printf("Case #%d: YES\n", test);
					else
						System.out.printf("Case #%d: NO\n", test);
				}
				
				
		}
	}
	
}
