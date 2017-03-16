import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class assignmentB
{
	//private static String filename = "test";
	private static String filename = "B-small-attempt3";

	private static boolean debug = false;

	private static int caseindex = 1;

	public static void main(String[] args) throws Exception
	{
		if (debug)
			System.out.println("Start out buffer");

		BufferedWriter out = new BufferedWriter(new FileWriter(filename + ".out"));
		BufferedReader in = new BufferedReader(new FileReader(filename + ".in"));

		performAtStart();

		readFile(in, out);

		out.close();
		in.close();
	}

	public static void writeToFile(BufferedWriter out, String s)
	{
		try
		{
			if (debug == true)
			{
				String write = "Case #" + caseindex + ": " + s;
				System.out.println("write: " + write);
				out.write(write);
			}
			else
				out.write("Case #" + caseindex + ": " + s);
			out.newLine();
			caseindex++;
		}
		catch (Exception e)
		{
		}
	}

	public static void readFile(BufferedReader in, BufferedWriter out)
	{
		try
		{
			String str;
			//skip first
			in.readLine();
			while ((str = in.readLine()) != null)
			{
				if (debug == true)
					System.out.println("read: " + str);
				writeToFile(out, performAction(str.split(" ")));
			}
		}
		catch (IOException e)
		{
		}
	}

	public static void performAtStart()
	{

	}

	public static String performAction(String[] parm)
	{
		int x = Integer.parseInt(parm[0]);
		int y = Integer.parseInt(parm[1]);

		return works(0, 0, x, y);
	}

	public static int getDir(int x, int y, int dx, int dy)
	{
		int diffx = dx - x;
		int diffy = dy - y;
		if (Math.abs(diffy) > Math.abs(diffx))
			if (diffy > 0)
				return 1;
			else
				return 3;
		else if (diffx > 0)
			return 0;
		else
			return 2;
	}

	public static String works(int x, int y, int dx, int dy)
	{

		int diff;
		int step = 1;
		int count = 1;
		int dir = getDir(x, y, dx, dy);
		//if (true)
		//return dir + "";
		String res = "";

		while (x != dx || y != dy)
		{
			if (dir == 0)
			{
				diff = Math.abs(dx - x);
				int newdiffx = Math.abs(dx - (x + step));
				if (newdiffx <= diff)
				{
					x += step;
					step += count;
					count++;
					res += "E";
					continue;
				}
			}

			if (dir == 2)
			{
				diff = Math.abs(dx - x);
				int newdiffx = Math.abs(dx - (x - step));
				if (newdiffx <= diff)
				{
					x -= step;
					step += count;
					count++;
					res += "W";
					continue;
				}
			}

			if (dir == 1)
			{
				diff = Math.abs(dy - y);
				int newdiffx = Math.abs(dy - (y + step));
				if (newdiffx <= diff)
				{
					y += step;
					step += count;
					count++;
					res += "N";
					continue;
				}
			}

			if (dir == 3)
			{
				diff = Math.abs(dy - y);
				int newdiffx = Math.abs(dy - (y - step));
				if (newdiffx <= diff)
				{
					y -= step;
					step += count;
					count++;
					res += "S";
					continue;
				}
			}
			dir = getDir(x, y, dx, dy);
			count = 1;
			step = 1;
		}
		return res;
	}
}
