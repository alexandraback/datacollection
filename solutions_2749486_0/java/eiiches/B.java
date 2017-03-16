package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.TreeSet;

public class B 
{
	public String solve(final int x, final int y) {
		final StringBuilder builder = new StringBuilder();
		
		int cx = 0, cy = 0;
		int nextJump = 1;
		
		while (cy != y || cx != x) {
			if (x - cx >= nextJump && x - cx > 0) {
				cx += nextJump;
				nextJump += 1;
				builder.append('E');
			} else if (cx - x >= nextJump && cx - x > 0) {
				cx -= nextJump;
				nextJump += 1;
				builder.append('W');
			} else if (x - cx < nextJump && x - cx > 0) {
				cx += 1;
				nextJump += 2;
				builder.append("WE");
			} else if (cx - x < nextJump && cx - x > 0) {
				cx -= 1;
				nextJump += 2;
				builder.append("EW");
			}
			
			if (y - cy >= nextJump && y - cy > 0) {
				cy += nextJump;
				nextJump += 1;
				builder.append('N');
			} else if (cy - y >= nextJump && cy - y > 0) {
				cy -= nextJump;
				nextJump += 1;
				builder.append('S');
			} else if (y - cy < nextJump && y - cy > 0) {
				cy += 1;
				nextJump += 2;
				builder.append("SN");
			} else if (cy - y < nextJump && cy - y > 0) {
				cy -= 1;
				nextJump += 2;
				builder.append("NS");
			}
		}
		
		return builder.toString();
	}

	public static void main( String[] args ) throws NumberFormatException, IOException
	
	{
		
		final B b = new B();
		final BufferedReader reader = new BufferedReader(new FileReader(new File(args[0])));
		final int T = Integer.valueOf(reader.readLine());
		for (int i = 0; i < T; ++i) {
			final String[] columns = reader.readLine().split(" ");
			final int x = Integer.valueOf(columns[0]);
			final int y = Integer.valueOf(columns[1]);
			final String value = b.solve(x, y);
			System.out.printf("Case #%d: %s%n", i + 1, value);
		}
	}
}
