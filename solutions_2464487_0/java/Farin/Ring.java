import java.io.FileReader;
import java.io.PrintWriter;
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
				Integer R = Integer.parseInt(in.next());
				Integer t = Integer.parseInt(in.next());
				String s = "Case #" + i + ": ";
				s = s + Process(R, t);
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

	int Process(double R, double t)
	{
		System.out.println("hhhh");
		boolean cond = true;
		double w = R;
		double b = R + 1;
		int cnt = 0;
		while (cond)
		{
			double con = Consume(b, w);
			if (con > t)
				cond = false;
			else
			{
				t = t - con;
				b = b + 2;
				w = w + 2;
				cnt++;
			}
		}

		return cnt;
	}

	public double Consume(double B, double W)
	{
		double m = 0;
		m = B * B - W * W;
		return m;
	}

}
