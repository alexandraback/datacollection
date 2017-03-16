import java.util.Scanner;


public class prob1 {

	public static void main(String[] args) {
		Scanner c = new Scanner(System.in);
		int t = c.nextInt();
		for(int j=1; j<=t; j++)	{
			System.out.print("Case #"+j+": ");
			int n = c.nextInt(), x=0;
			int p[] = new int[n];
			for(int i=0; i<n; ++i)
				x += (p[i] = c.nextInt());
			for(int i=0; i<n; ++i)	{
				for(double v = 0.0000001; v<=1;)	{
					/*if(v>=0.3333333)	{
						int foo=0;
						System.out.print("foo"+foo);
					}*/
					double m = (double)p[i]+(double)x*v, _v = 1-v;
					int k=-1;
					while(++k < n)
						if(k!=i && p[k] < m)	{
							_v -= (m-p[k])/(double)x;
							if(_v < 0)
								break;
						}
					if(k<n)	{
						long r = (long)(100000000*v);
						long g = r/1000000;
						System.out.printf("%f ",100*v);
						break;
					}
					else if((v=v+0.0000001)>1)	{
						System.out.print("100.0 ");
						break;
					}
				}
			}
			System.out.println();	
		}

	}

}
