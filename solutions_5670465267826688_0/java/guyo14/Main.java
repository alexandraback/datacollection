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
			String line2 = null;
			total = Integer.parseInt(line);

			Main a = new Main();

			while (null != (line = br.readLine()) && null != (line2 = br.readLine())) {
				String result = a.operate(complete + 1, a.parse(line, line2));
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

	public int[] parse(String line, String line2) {
		String values[] = line.split(" ");
		int repeat = Integer.parseInt(values[1]);
		int length = line2.length();
		int[] result = new int[repeat * length];
		int k = 0;
		for (int i = 0; i < repeat; i++) {
			for (int j = 0; j < length; j++) {
				result[k++] = getCode(line2.charAt(j));
			}
		}
		return result;
	}

	public String operate(int number, int[] array) {
		int length = array.length;
		if (3 <= length) {
			int[] i_val = {0, 0};
			for (int i = 0; i < length - 2; i++) {
				i_val = by(i_val, array[i]);
				if (1 == i_val[0] && i_val[1] % 2 == 0) {
					int[] j_val = {0, 0};
					for (int j = i + 1; j < length - 1; j++) {
						j_val = by(j_val, array[j]);
						if (2 == j_val[0] && j_val[1] % 2 == 0) {
							int[] k_val = {0, 0};
							for (int k = j + 1; k < length; k++) {
								k_val = by(k_val, array[k]);
							}
							if (3 == k_val[0] && k_val[1] % 2 == 0) {
								return "Case #" + String.valueOf(number) + ": YES";
							}
						}
					}
				}
			}
		}
		return "Case #" + String.valueOf(number) + ": NO";
	}

	private int[][] values = {
		{0, 0},
		{1, 0},
		{2, 0},
		{3, 0},

		{1, 0},
		{0, 1},
		{3, 0},
		{2, 1},

		{2, 0},
		{3, 1},
		{0, 1},
		{1, 0},

		{3, 0},
		{2, 0},
		{1, 1},
		{0, 1}
	};
	private int getCode(char value) {
		switch(value) {
			case '1':
			return 0;
			case 'i':
			return 1;
			case 'j':
			return 2;
			case 'k':
			return 3;
		} 
		return -1;
	}
	private int[] by(int[] val, int other) {
		int[] tmp = values[val[0] * 4 + other];
		val[0] = tmp[0];
		val[1] += tmp[1];
		return val;
	}
}