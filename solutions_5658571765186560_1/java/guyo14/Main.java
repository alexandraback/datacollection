import java.io.*;
import java.util.List;
import java.util.ArrayList;

class Main {

	public static void main(String[] args) {
		File input = null;
		FileReader fr = null;
		BufferedReader br = null;

		File output = null;
		FileWriter fw = null;
		PrintWriter pw = null;

		int total = 0;
		int complete = 0;

		try {
			input = new File(args[0]);
			fr = new FileReader(input);
			br = new BufferedReader(fr);

			output = new File(args[1]);
			fw = new FileWriter(output);
			pw = new PrintWriter(fw);

			String line = br.readLine();
			total = Integer.parseInt(line);

			while (null != (line = br.readLine())) {
				String result = operate(complete + 1, parse(line));
				pw.println(result);
				complete++;

			}
		} catch(IOException e) {
			e.printStackTrace();
		} catch(Exception e2) {
			e2.printStackTrace();
		}finally {
			try {
				if (null != fw) {
					fw.close();
				}
			} catch(IOException e) {
				e.printStackTrace();
			}
			try {
				if (null != fw) {
					fw.close();
				}
			} catch(IOException e) {
				e.printStackTrace();
			}
			System.out.println(String.valueOf(complete) + " of " + String.valueOf(total));
		}
	}

	private static int[] parse(String line) {
		String words[] = line.split(" ");
		int result[] = {
			Integer.parseInt(words[0]),
			Integer.parseInt(words[1]),
			Integer.parseInt(words[2])
		};
		return result;
	}

	private static String operate(int number, int values[]) {
		int x = values[0];
		int r = values[1];
		int c = values[2];
		String winner = "RICHARD";
		if (7 > x) {
			int grid = r * c;
			if (grid % x == 0)  {
				if (2 >= x) {
					winner = "GABRIEL";
				} else if(grid != x) {
					if (3 == x) {
						if (1 < r && 1 < c) {
							winner = "GABRIEL";
						}
					} else if (4 == x) {
						if (2 < r && 2 < c) {
							winner = "GABRIEL";
						}
					} else if (5 == x) {
						if (2 < r && 2 < c && 15 < grid) {
							winner = "GABRIEL";
						}
					} else {
						if (3 < r && 3 < c) {
							winner = "GABRIEL";
						}
					}
				}
			}
		}
		return "Case #" + String.valueOf(number) + ": " + winner;
	}

}