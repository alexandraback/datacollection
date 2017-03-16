import java.io.*;
import java.util.List;
import java.util.ArrayList;

class Main {

	private static int max;
	private static int[] values;

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
				if (parse(line)) {
					String result = operate(complete + 1);
					pw.println(result);
					complete++;
				}
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

	private static boolean parse(String line) {
		String words[] = line.split(" ");
		max = Integer.parseInt(words[0]);
		String chars[] = words[1].split("");
		values = new int[chars.length];
		int i = 0;
		for (String value : chars) {
			values[i++] = Integer.parseInt(value);
		}
		return true;
	}

	private static String operate(int number) {
		int persons = 0;
		int missing = 0;
		for (int i = 0; i <= max; i++) {
			int needy = 0;
			if (values[i] != 0 && persons < i) {
				needy = i - persons;
				missing += needy;
			}
			persons += values[i] + needy;
		}
		return "Case #" + String.valueOf(number) + ": " + String.valueOf(missing);
	}

}