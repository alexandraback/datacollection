import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.Date;

public class Main {

	public boolean solve(int X, int R, int C) {
		int grids = R * C;
		switch (X) {
		case 1:
			return true;
		case 2:
			return grids % 2 == 0;
		case 3:
			if (grids % 3 == 0) {
				return R != 1 && C != 1;
			}
			break;
		case 4:
			if (grids >= 12 && grids % 4 == 0) {
				return R >= 3 && C >= 3;
			}
			break;
		case 5:
			if (grids >= 15 && grids % 5 == 0) {
				return R >= 3 && C >= 3;
			}
			break;
		case 6:
			if (grids >= 24 && grids % 6 == 0) {
				return R >= 4 && C >= 4;
			}
		}
		return false;
	}

	public Main() throws Exception {

		String userDir = System.getProperty("user.dir");
		FileWriter fWriter = new FileWriter(new File(userDir + "\\result.txt"));

		BufferedReader reader = new BufferedReader(new FileReader(userDir
				+ "\\input.in"));
		// BufferedReader reader = new BufferedReader(new
		// InputStreamReader(System.in));

		final Date now = new Date();
		int count = Integer.parseInt(reader.readLine());
		StringBuilder content = new StringBuilder();
		for (int i = 0; i < count; i++) {

			String line = reader.readLine();
			String[] segs = line.split(" ");
			int X = Integer.parseInt(segs[0]);
			int R = Integer.parseInt(segs[1]);
			int C = Integer.parseInt(segs[2]);

			boolean result = solve(X, R, C);
			content.append("Case #").append(i + 1).append(": ")
					.append(result ? "GABRIEL" : "RICHARD").append("\r\n");
			// System.out.println(i);
		}

		// System.out.print(new Date().getTime() - now.getTime());

		fWriter.write(content.toString());
		fWriter.flush();
		fWriter.close();
	}

	public static void main(String[] args) {
		try {
			new Main();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
