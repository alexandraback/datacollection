
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = Files.newBufferedReader(Paths.get("C-small-attempt0.in", args), Charset.defaultCharset());
		System.setOut(new PrintStream(Files.newOutputStream(Paths.get("output.out"))));

		final int CASES = Integer.parseInt(br.readLine());
		String line;

		for (int cs = 0; cs < CASES; cs++)
		{
			line = br.readLine();
			final int TRIBES = Integer.parseInt(line);
			//final int space = line.indexOf(' ');
			//final int A = Integer.parseInt(line.substring(0, space));
			//final int B = Integer.parseInt(line.substring(space + 1));

			PriorityQueue<Tribe> tribes = new PriorityQueue<>(TRIBES);

			for (int i = 0; i < TRIBES; i++)
				tribes.add(loadTribe(br.readLine()));


			printStatus(cs + 1, tribes);
			//br.readLine();
		}
	}

	private static void printStatus(int dataCase, PriorityQueue<Tribe> tribes)
	{
		Wall wall = new Wall();
		int day = 0;
		int count = 0;
		while (!tribes.isEmpty())
		{
			Tribe curr = tribes.remove();
			if (day != curr.nextAttack)
			{
				day = curr.nextAttack;
				wall.newDay();
			}

			if (wall.attacked(curr))
				count++;

			if (curr.attack())
				tribes.add(curr);
		}

		//String msg = null;
		printMessage(dataCase, new Integer(count).toString());
	}

	public static void printMessage(int dataCase, String message)
	{
		System.out.println("Case #" + dataCase + ": " + message);
	}

	private static Tribe loadTribe(String line)
	{
		StringTokenizer st = new StringTokenizer(line, " ");
		return new Tribe(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
	}

	private static class Tribe implements Comparable<Tribe>
	{
		int position = Wall.LEN / 2;
		int nextAttack;
		int nAttacks;
		final int west;
		final int east;
		int stren;
		final int deltaD;
		final int deltaP;
		final int deltaS;

		public Tribe(int nextAttack, int nAttacks, int west, int east, int stren, int deltaD, int deltaP, int deltaS)
		{
			this.nextAttack = nextAttack;
			this.nAttacks = nAttacks;
			this.west = west;
			this.east = east;
			this.stren = stren;
			this.deltaD = deltaD;
			this.deltaP = deltaP;
			this.deltaS = deltaS;
		}

		public boolean attack()
		{
			position += deltaP;
			nextAttack += deltaD;
			nAttacks--;
			stren += deltaS;

			return nAttacks > 0 && stren > 0;
		}

		@Override
		public int compareTo(Tribe o)
		{
			return nextAttack - o.nextAttack;
		}
	}

	private static class Wall
	{
		public static final int LEN = 2048;
		int[] today = new int[LEN];
		int[] tomorrow = new int[LEN];

		public void newDay()
		{
			int[] tmp = today;
			today = tomorrow;
			tomorrow = tmp;
			System.arraycopy(today, 0, tomorrow, 0, LEN);
		}

		public boolean attacked(Tribe t)
		{
			boolean succ = false;
			for (int i = t.position + t.west; i < t.position + t.east; i++)
				if (today[i] < t.stren)
				{
					succ = true;
					if (tomorrow[i] < t.stren)
						tomorrow[i] = t.stren;
				}
//			System.err.println("attacked by "+t.stren+" at "+(t.position + t.west - 1024)+" to "+(t.position + t.east - 1024)+" succ "+succ +" day "+t.nextAttack);
			return succ;
		}
	}
}