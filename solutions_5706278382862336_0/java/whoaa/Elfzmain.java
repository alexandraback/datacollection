package elfz;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Elfzmain {
	public static void main(String[] args) {

		try {
			Scanner s = new Scanner(new File("/Users/mamud/Desktop/A-small-attempt0.in"));
			
			int num_test = s.nextInt();
			s.nextLine();
			int x = 0;
			while (++x <= num_test)
			{
				Long[] r = read(s);
				System.out.print("Case #" + x + ": ");
				System.out.println(solve(r));
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}
	
	public static boolean possibility(Long[] longs, int gen)
	{
		long x,y = longs[0],z = longs[1];
		for (x = 0; x < 40 - gen; x++) y*= 2;
		Double chk = ((double)y) / ((double)z);
		if (Math.abs( Math.round(chk) - chk  ) < 0.0001 ) return true;
		return false;
	}

	public static String solve(Long[] r)
	{
		long x = r[0], y=r[1];
		int g = 0;
		while(++g > 0)
		{
			x*= 2;
			if (x - y >= 0)
			{
				if (possibility(new Long[]{ (x - y),  y}, g)) 
					return String.valueOf(g);
			}
			if (g > 40) break;
		}
		return "impossible";
	}
	
	public static Long[] read(Scanner kbd) {

		Long num = (long) -1, denom = (long) -1;

		String s = kbd.nextLine();

		// tokens are the strings before and after "/"
		StringTokenizer stok = new StringTokenizer(s, "/");
		num = Long.parseLong(stok.nextToken());
		denom = Long.parseLong(stok.nextToken());

		return new Long[] { num, denom };

	}// end main

}
