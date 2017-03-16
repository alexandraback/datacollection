import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CountingSheep {
	public static String inPath = "/Users/guojunshi/Downloads/A-large.in.txt";
	public static String outPath = "/Users/guojunshi/Downloads/A-large.out.txt";

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new FileReader(inPath));
		BufferedWriter out = new BufferedWriter(new FileWriter(outPath));
		int t = Integer.parseInt(in.readLine());
		for (int i = 0; i < t; i++) {
			long result = lastNumber(Integer.parseInt(in.readLine()));
			if (result == -1) {
				out.write("Case #" + (i + 1) + ": INSOMNIA");
				out.newLine();
			} else {
				out.write("Case #" + (i + 1) + ": " + result);
				out.newLine();
			}
		}
		in.close();
		out.close();
	}

	public static long lastNumber(int num) {
		if (num == 0) {
			return -1;
		}
		boolean exist[] = new boolean[10];
		long count = 0, number = num;
		while (true) {
			count += countingFigure(number, exist);
			if (count == 10) {
				return number;
			}
			number += num;
		}
	}

	public static int countingFigure(long num, boolean[] exist) {
		int figure, ret = 0;
		while (num > 0) {
			figure = (int) (num % 10);
			num /= 10;
			if (exist[figure] == false) {
				exist[figure] = true;
				ret++;
			}
		}
		return ret;
	}

}
