import java.util.Scanner;

public class Program
{
	static final int RANGE = 50;
	static Board board;
	static double dist;

	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(new java.io.FileReader("in"));
		int t = in.nextInt();

		for (int test = 0; test < t; test++)
		{
			board = new Board(in.nextInt(), in.nextInt());
			dist = in.nextInt();
			for (int r = 0; r < board.height; r++)
			{
				String str = in.next();
				for (int c = 0; c < board.width; c++)
				{
					char ch = str.charAt(c);
					int tile;
					if (ch == '.') tile = 0;
					else if (ch == '#') tile = 1;
					else tile = 2;

					board.set(r, c, tile);
				}
			}

			int count = 0;
			for (int dR = -RANGE; dR <= RANGE; dR++)
			{
				for (int dC = -RANGE; dC <= RANGE; dC++)
				{
					if (Calc.gcd(dR, dC) == 1)
					{
						boolean hit = ray(dR, dC);
						if (hit) count++;
					}
				}
			}
			System.out.println("Case #" + (test + 1) + ": " + count);
		}
	}

	static boolean ray(int dR, int dC)
	{
		Point p = board.player.clone();
		Point v = new Point(new Fraction(dR, 1), new Fraction(dC, 1));
		double d = 0;

		while (d <= dist)
		{
			Point nP = board.reflect(p, v);
			if (nP == null) return false;

			double addD = nP.distance(p);
			if (board.hitsPlayer(p, nP) && d + nP.distance(board.player) <= dist)
			{
				return true;
			}
			p = nP;
			d += addD;
		}
		return false;
	}
}
