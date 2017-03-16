/*
 * 
 * To compile: javac <filename>.java
 * To run: java <filename> <input_file> > <output_file>
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B
{

	private Set<Pair> set;

	private int X, Y;

	public B(int X, int Y)
	{
		this.X = X;
		this.Y = Y;

		set = new HashSet<Pair>();
	}

	private Set<Pair> bfs(Set<Pair> set, int count, String ans)
	{
		Set<Pair> ret = new HashSet<Pair>(set.size() * 4);
		for (Pair p : set)
		{
			String way = p.way;
			ret.add(new Pair(p.x + count, p.y, way + 'E'));
			ret.add(new Pair(p.x, p.y + count, way + 'N'));
			ret.add(new Pair(p.x - count, p.y, way + 'W'));
			ret.add(new Pair(p.x, p.y - count, way + 'S'));
		}

		return ret;
	}

	public String solve()
	{

		Set<Pair> set = new HashSet<Pair>();
		set.add(new Pair(0, 0, ""));
		for (int i = 1; i <= 500; i++)
		{
			set = bfs(set, i, "");

			for (Pair p : set)
			{
				if (p.x == X && p.y == Y)
					return p.way;
			}
		}

		return null;
	}

	public static void main(String[] args)
	{
		if (args.length != 1)
		{
			System.err.println("Run it with 1 command line argument i.e. filename of input file");
		}
		File file = new File(args[0]);
		Scanner scan = null;
		try
		{
			scan = new Scanner(file);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File not found");
			e.printStackTrace();
		}

		int T = scan.nextInt();

		for (int i = 0; i < T; i++)
		{
			int X = scan.nextInt();
			int Y = scan.nextInt();

			B b = new B(X, Y);
			System.out.println("Case #" + (i + 1) + ": " + b.solve());
		}
	}
}
