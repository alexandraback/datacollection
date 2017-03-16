import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class classMain {
	public static void main(String[] args)
	{
		int n, j;
		Scanner pin = new Scanner (new BufferedInputStream(System.in));
		while(pin.hasNext())
		{
			int nCase = pin.nextInt();
			for(int nT = 1; nT <= nCase; nT++)
			{
				n = pin.nextInt();
				j = pin.nextInt();
				solver sol = new solver();
				System.out.println("Case #" + nT + ":");
				sol.Solve(n, j);
			}
		}
		pin.close();
	}
}


class solver{
	public int isPrime(BigInteger x)
	{
		for(int i = 2; i < 1000; i++)
		{
			if( BigInteger.ZERO == x.mod(BigInteger.valueOf(i)) )
			{
				return i;
			}
		}
		return 0;
	}
	
	public void Solve(int len, int num)
	{
		//	System.out.println("len = " + len);
			
			BigInteger pre = BigInteger.valueOf(2);
			pre = pre.pow(len - 1);
			pre = pre.add(BigInteger.valueOf(1));
		//	System.out.println("pre = " + pre);
			
			int cert = 50;
			BigInteger cal, cur = pre;
			cur = cur.add(BigInteger.valueOf(-2));
			int lim = 1 << (len - 2);
			int cnt = 0;
			for(int i = 0; i < lim; i++)
			{
				cur = cur.add(BigInteger.valueOf(2));
				if(isPrime(cur) > 0)//如果二进制是合数
				{
					boolean flag = true;
					String bin = cur.toString(2);
					for(int j = 3; j <= 10; j++)
					{
						cal = new BigInteger(bin, j);
						if(0 == isPrime(cal))//如果j进制是质数
						{
							flag = false;
							break;
						}
					}
					if(flag)
					{
						cnt++;
						System.out.print(cur.toString(2));

						for(int j = 2; j <= 10; j++)
						{
							cal = new BigInteger(bin, j);
							System.out.print(" " + isPrime(cal));
						//	System.out.print(" " + isPrime(cal) + "(" + cal + ")");
						}
						System.out.println("");
						if(cnt >= num) return ;
				//		System.out.println("num(" + cnt + "):" + cur.toString(2));
					}
				}
			}
		//	System.out.println("pre = " + pre + "  cur = " + cur);
	}
}