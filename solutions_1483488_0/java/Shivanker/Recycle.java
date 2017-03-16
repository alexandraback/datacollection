import java.util.LinkedList;
import java.util.Scanner;


public class Recycle {

	private static int[] total(int r)	{
		int i=1, t=10;
		while(r/t > 0)	{
			i++;
			t*=10;
		}
		return new int[] {i,t/10};
	}
	
	private static int pow(int c)	{
		int t=1;
		while(c-->0)
			t*=10;
		return t;
	}
	
	private static int recycle(int r, int c /* peechhe se, 1 based*/)	{
		int k = pow(c), t=total(r)[0];
		int a = r/k;
		int b = (r%k) * pow(t-c);
		return a+b;
	}
	
	public static void main(String[] args) {
		Scanner c = new Scanner(System.in);
		int t = c.nextInt();
		for(int w=1; w<=t; ++w)	{
			System.out.print("Case #"+w+": ");
			int cnt = 0;
			int A = c.nextInt();
			int B = c.nextInt();
			int tmp[] = total(A);
			int tot = tmp[0];
			
			for(int i=Math.max(A, 10); i <=B; ++i )	{
				int in = i/tmp[1];
				int pow = 1;
				LinkedList<Integer> l = new LinkedList<Integer>();
				for(int j=1; j<tot; ++j, pow*=10)	{
					int cth = (i/pow)%10;
					
					if(cth >= in)	{
						int r = recycle(i,j);
						if(r > i && r<=B && !l.contains(r))	{
							cnt++;
							l.add(r);
							//System.out.println("("+i+","+r+")");
						}
					}
				}
			}
			System.out.println(cnt);
		}

	}

}
