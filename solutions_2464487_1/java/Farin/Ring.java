import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Ring
{

	public void Execute(String aFileName)
	{

		Scanner in;
		PrintWriter out;
		try
		{
			in = new Scanner(new FileReader(aFileName));
			out = new PrintWriter("D:\\GoogleJam\\rin1.in");
			int n = Integer.parseInt(in.nextLine());
			for (int i = 1; i <= n; i++)
			{
				String R = in.next();
				String t = in.next();
				String s = "Case #" + i + ": ";
				s = s + Process(R + "", t);
				out.println(s);

			}
			out.flush();
		}
		catch (Exception e)
		{

		}

		// for (int i = 0; i < r.size(); i++)
		// System.out.println(r.get(i).toString());
	}

	SquareRootOfBigIntegerExample	sq	= new SquareRootOfBigIntegerExample();

	BigInteger Process(String sR, String st)
	{
		System.out.println("Start");
		BigInteger p1 = new BigInteger("0");
		BigInteger R = new BigInteger(sR);
		BigInteger t = new BigInteger(st);
		BigInteger one = new BigInteger("1");
		BigInteger two = new BigInteger("2");
		BigInteger four = new BigInteger("4");
		BigInteger eight = new BigInteger("8");
		p1 = (R.add(R).subtract(one)).multiply(R.add(R).subtract(one)).add(
				eight.multiply(t));
		BigInteger tt= sq.find(p1);
		BigInteger b = tt.subtract(R.multiply(two).subtract(one));

		return b.divide(four);

	}

	BigInteger Process3(String sR, String st)
	{
		System.out.println("Start");
		BigInteger beta = new BigInteger("1");
		BigInteger R = new BigInteger(sR);
		BigInteger t = new BigInteger(st);
		BigInteger Sum = new BigInteger("0");
		boolean cond = true;
		BigInteger two = new BigInteger("2");
		BigInteger one = new BigInteger("1");
		BigInteger cnt = new BigInteger("0");
		while (cond)
		{
			Sum = Sum.add(R.add(beta).multiply(two).subtract(one));
			beta = beta.add(two);
			if (t.compareTo(Sum) == -1)
			{
				cond = false;
			}
			else
			{
				cnt.add(one);
			}

		}

		return cnt;
	}

	int Process2(String sR, String st)
	{
		System.out.println("hhhh");
		boolean cond = true;
		BigInteger R = new BigInteger(sR);
		BigInteger t = new BigInteger(st);
		BigInteger w = R;
		BigInteger one = new BigInteger("1");
		BigInteger b = R.add(one);
		BigInteger g = new BigInteger("0");
		int cnt = 0;
		BigInteger zero = new BigInteger("0");
		while (cond)
		{
			BigInteger con = Consume(b, w);
			g = t.subtract(con);
			if (g.compareTo(zero) == -1)
				cond = false;
			else
			{
				t = t.subtract(con);
				b = b.add(one).add(one);
				w = w.add(one).add(one);
				cnt++;
			}
		}

		return cnt;
	}

	public BigInteger Consume(BigInteger B, BigInteger W)
	{
		BigInteger m = new BigInteger("0");
		m = B.multiply(B).subtract(W.multiply(W));
		return m;
	}

}
