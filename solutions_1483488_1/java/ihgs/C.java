package qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;

import common.FileTranslatorBasis;

public class C {

	final static int[] digitNum = { 9, 99, 999, 9999, 99999, 999999, 9999999 };
	int low;
	int high;

	int pow = 1;

	public C(String low, String high) {

		for (int i = 0; i < low.length() - 1; i++) {
			pow = 10 * pow;
		}
		this.low = Integer.parseInt(low);
		this.high = Integer.parseInt(high);
	}

	long count;
	int[] map = new int[2000001];

	public void initMap() {
		int[] tmp = { 1, 11, 111, 1111, 11111, 111111, 1111111, 2, 22, 222,
				2222, 22222, 222222, 3, 33, 333, 3333, 33333, 333333, 4, 44,
				444, 4444, 44444, 444444, 5, 55, 555, 5555, 55555, 555555, 6,
				66, 666, 6666, 66666, 666666, 7, 77, 777, 7777, 77777, 777777,
				8, 88, 888, 8888, 88888, 888888, 9, 99, 999, 9999, 99999,
				999999, };
		for (int i : tmp) {
			map[i] = -1;
		}
	}

	/**
	 * 
	 * @param in
	 */
	private void parse(int in) {
		int pair = 1;

		if (map[in] == -1) {
			return;
		}
		map[in]=-1;
		String inStr = String.valueOf(in);
		char[] chars = inStr.toCharArray();
		for (int i = 0; i < chars.length - 1; i++) {
			in = (in - (chars[i] - 48) * pow) * 10 + (chars[i] - 48);
			if (valid(in)) {
				if (map[in] != -1) {
					pair++;
					map[in] = -1;
				}
			}
		}
		count += pair * (pair - 1) / 2;
	}

	public long count() {
		for (int i = low; i <= high; i++) {
			parse(i);
		}
		return count;
	}

	private boolean valid(int t) {
		return t >= low && t <= high;
	}

	public static void main(String[] args) throws FileNotFoundException {

		System.setOut(new PrintStream(new File("output.txt")));

//		String fname = "sample.txt";
//		String fname = "C-small-attempt0.in.txt";
		String fname = "C-large.in.txt";
		FileTranslatorBasis ftb = FileTranslatorBasis.getInstance(fname);

		int num = ftb.getNumOfCase();
		for (int i = 0; i < num; i++) {
			String[] input = ftb.getStrDataArray();
			C c = new C(input[0],input[1]);
			System.out.println("Case #" + Integer.toString(i + 1) + ": "
					+ String.valueOf(c.count()));

		}

	
	}
}
