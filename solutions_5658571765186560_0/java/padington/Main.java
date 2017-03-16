import java.io.FileInputStream;
import java.io.InputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author padington
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "D-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("d.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        final int X = in.nextInt();
        final int R = in.nextInt();
        final int C = in.nextInt();
        boolean richardWin;

        if (R * C % X != 0 || X > Math.max(R, C)) {
            richardWin = true;
        } else if(X == 1) {
            richardWin = false;
        } else if (X == 2) {
            richardWin = R * C % 2 == 1;
        } else if (X == 3) {
            richardWin = R * C == 3;
        } else {
            richardWin = R * C < 9;
        }

        out.println(String.format("Case #%d: %s", testNumber, richardWin ? "RICHARD" : "GABRIEL"));
    }
}

