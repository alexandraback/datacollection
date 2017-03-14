import java.io.*;
import java.util.*;
import java.math.*;

class D
{
	private static final boolean DEBUG_ON = true;
	private static final boolean ECHO_ON = true;

	private static BufferedReader input;
	private static BufferedWriter output;

	private static final int INF = Integer.MAX_VALUE / 2;
	private static final int MOD = 10007;

	private static int H, W, D;

	public static int gcd(int n, int m) {return (0 == m) ? (n) : gcd(m, n % m);}

	public static void main(String[] args)
	{
		try
		{
			input = new BufferedReader(new FileReader(args[0]  + ".in"));
			output = new BufferedWriter(new FileWriter(args[0] + ".out"));

			String line = input.readLine();
			int testcases = getInt(line, 0);

			for (int testcase = 1; testcase <= testcases; testcase++)
			{
				char[][] real = getCharMatrix(input);

				int R0 = (D + H - 3) / (H - 2); int R = 2 * R0 + 1; R = (H - 2) * R + (R + 1);
				int C0 = (D + W - 3) / (W - 2); int C = 2 * C0 + 1; C = (W - 2) * C + (C + 1);
				char[][] virtual = new char[R][C];

				int row = -1, col = -1;

				for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
				{
					char c = virtual[R0 * (H - 1) + i][C0 * (W - 1) + j] = real[i][j];
					if ('X' == c)
					{
						row = R0 * (H - 1) + i;
						col = C0 * (W - 1) + j;
					}
				}

				for (int i = 0; i < H; i++)
				{
					int lastMirror = C0 * (W - 1);
					for (int j = lastMirror - 1; j >= 0; j--)
					{
						char c = virtual[R0 * (H - 1) + i][j] = virtual[R0 * (H - 1) + i][lastMirror + (lastMirror - j)];
						if ('#' == c) {lastMirror = j;}
					}
				}

				for (int i = 0; i < H; i++)
				{
					int lastMirror = (C0 + 1) * (W - 1);
					for (int j = lastMirror + 1; j < C; j++)
					{
						char c = virtual[R0 * (H - 1) + i][j] = virtual[R0 * (H - 1) + i][lastMirror - (j - lastMirror)];
						if ('#' == c) {lastMirror = j;}
					}
				}

				for (int j = 0; j < C; j++)
				{
					int lastMirror = R0 * (H - 1);
					for (int i = lastMirror - 1; i >= 0; i--)
					{
						char c = virtual[i][j] = virtual[lastMirror + (lastMirror - i)][j];
						if ('#' == c) {lastMirror = i;}
					}
				}

				for (int j = 0; j < C; j++)
				{
					int lastMirror = (R0 + 1) * (H - 1);
					for (int i = lastMirror + 1; i < R; i++)
					{
						char c = virtual[i][j] = virtual[lastMirror - (i - lastMirror)][j];
						if ('#' == c) {lastMirror = i;}
					}
				}

				for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if ('X' == virtual[i][j])
				{
					int diffX = Math.abs(i - row);
					int mod = diffX % (2 * (H - 1));
					int delta = diffX / (2 * (H - 1));
					if (0 == mod) {diffX -= 2 * delta;} else {diffX -= (2 * delta + 1);}

					int diffY = Math.abs(j - col);
					mod = diffY % (2 * (W - 1));
					delta = diffY / (2 * (W - 1));
					if (0 == mod) {diffY -= 2 * delta;} else {diffY -= (2 * delta + 1);}

					if ((diffX * diffX) + (diffY * diffY) <= (D * D))
					{
						virtual[i][j] = 'O';
					}
				}
				virtual[row][col] = 'X';

				for (int j = col - 1; j >= 0; j--)
				{
					if ('O' == virtual[row][j])
					{
						for (int jj = j - 1; jj >= 0; jj--)
						{
							if ('O' == virtual[row][jj]) {virtual[row][jj] = 'X';}
						}
					}
				}

				for (int j = col + 1; j < C; j++)
				{
					if ('O' == virtual[row][j])
					{
						for (int jj = j + 1; jj < C; jj++)
						{
							if ('O' == virtual[row][jj]) {virtual[row][jj] = 'X';}
						}
					}
				}

				for (int i = row - 1; i >= 0; i--)
				{
					if ('O' == virtual[i][col])
					{
						for (int ii = i - 1; ii >= 0; ii--)
						{
							if ('O' == virtual[ii][col]) {virtual[ii][col] = 'X';}
						}
					}
				}

				for (int i = row + 1; i < R; i++)
				{
					if ('O' == virtual[i][col])
					{
						for (int ii = i + 1; ii < R; ii++)
						{
							if ('O' == virtual[ii][col]) {virtual[ii][col] = 'X';}
						}
					}
				}

				for (int i = row - 1; i >= 0; i--) for (int j = 0; j < C; j++) if ('O' == virtual[i][j])
				{
					int diffX = Math.abs(i - row);
					int mod = diffX % (2 * (H - 1));
					int delta = diffX / (2 * (H - 1));
					if (0 == mod) {diffX -= 2 * delta;} else {diffX -= (2 * delta + 1);}

					int diffY = Math.abs(j - col);
					mod = diffY % (2 * (W - 1));
					delta = diffY / (2 * (W - 1));
					if (0 == mod) {diffY -= 2 * delta;} else {diffY -= (2 * delta + 1);}

					int gcd = gcd(Math.abs(diffX), Math.abs(diffY));
					diffX /= gcd; diffY /= gcd;
					int k = gcd + 1;

					int kDiffX = k * diffX;
					int kDiffY = k * diffY;

					int ii = (i > row) ? (i + 1) : (i - 1);
	 				int diffXX = gcd * diffX;
					while (0 <= ii && ii< R)
					{
						if ('#' != virtual[ii][j]) {diffXX++;}
						if (diffXX == kDiffX) {break;}
						if (ii > row) {ii++;} else {ii--;}
					}

					int jj = (j > col) ? (j + 1) : (j - 1);
					int diffYY = gcd * diffY;
					while (0 <= jj && jj < C)
					{
						if ('#' != virtual[i][jj]) {diffYY++;}
						if (diffYY == kDiffY) {break;}
						if (jj > col) {jj++;} else {jj--;}
					}

					while (0 <= ii && ii< R && 0 <= jj && jj < C)
					{
						if ('O' == virtual[ii][jj]) {virtual[ii][jj] = 'X';}
						k++;
						kDiffX = k * diffX;
						kDiffY = k * diffY;

						if (ii > row) {ii++;} else {ii--;}
						while (0 <= ii && ii< R)
						{
							if ('#' != virtual[ii][j]) {diffXX++;}
							if (diffXX == kDiffX) {break;}
							if (ii > row) {ii++;} else {ii--;}
						}

						if (jj > col) {jj++;} else {jj--;}
						while (0 <= jj && jj < C)
						{
							if ('#' != virtual[i][jj]) {diffYY++;}
							if (diffYY == kDiffY) {break;}
							if (jj > col) {jj++;} else {jj--;}
						}
					}
				}

				for (int i = row + 1; i < R; i++) for (int j = 0; j < C; j++) if ('O' == virtual[i][j])
				{
					int diffX = Math.abs(i - row);
					int mod = diffX % (2 * (H - 1));
					int delta = diffX / (2 * (H - 1));
					if (0 == mod) {diffX -= 2 * delta;} else {diffX -= (2 * delta + 1);}

					int diffY = Math.abs(j - col);
					mod = diffY % (2 * (W - 1));
					delta = diffY / (2 * (W - 1));
					if (0 == mod) {diffY -= 2 * delta;} else {diffY -= (2 * delta + 1);}

					int gcd = gcd(Math.abs(diffX), Math.abs(diffY));
					diffX /= gcd; diffY /= gcd;
					int k = gcd + 1;

					int kDiffX = k * diffX;
					int kDiffY = k * diffY;

					int ii = (i > row) ? (i + 1) : (i - 1);
	 				int diffXX = gcd * diffX;
					while (0 <= ii && ii< R)
					{
						if ('#' != virtual[ii][j]) {diffXX++;}
						if (diffXX == kDiffX) {break;}
						if (ii > row) {ii++;} else {ii--;}
					}

					int jj = (j > col) ? (j + 1) : (j - 1);
					int diffYY = gcd * diffY;
					while (0 <= jj && jj < C)
					{
						if ('#' != virtual[i][jj]) {diffYY++;}
						if (diffYY == kDiffY) {break;}
						if (jj > col) {jj++;} else {jj--;}
					}

					while (0 <= ii && ii< R && 0 <= jj && jj < C)
					{
						if ('O' == virtual[ii][jj]) {virtual[ii][jj] = 'X';}
						k++;
						kDiffX = k * diffX;
						kDiffY = k * diffY;

						if (ii > row) {ii++;} else {ii--;}
						while (0 <= ii && ii< R)
						{
							if ('#' != virtual[ii][j]) {diffXX++;}
							if (diffXX == kDiffX) {break;}
							if (ii > row) {ii++;} else {ii--;}
						}

						if (jj > col) {jj++;} else {jj--;}
						while (0 <= jj && jj < C)
						{
							if ('#' != virtual[i][jj]) {diffYY++;}
							if (diffYY == kDiffY) {break;}
							if (jj > col) {jj++;} else {jj--;}
						}
					}
				}

//				debug(virtual);

				long count = 0;
				for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if ('O' == virtual[i][j]) {count++;}

				String result = "Case #" + testcase + ": " + count;
				output(result);
			}

			input.close();
			output.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static int getInt(String line, int index) {return Integer.parseInt(getString(line, index));}
	public static long getLong(String line, int index) {return Long.parseLong(getString(line, index));}
	public static double getDouble(String line, int index) {return Double.parseDouble(getString(line, index));}
	public static String getString(String line, int index)
	{
		line = line.trim();
		while (index > 0) {line = line.substring(line.indexOf(' ') + 1); index--;}

		if ((-1) == line.indexOf(' ')) {return line;}
		else {return line.substring(0, line.indexOf(' '));}
	}

	public static int[] getIntArray(String line)
	{
		String[] strings = getStringArray(line);
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Integer.parseInt(strings[i]);}
		return numbers;
	}
	public static long[] getLongArray(String line)
	{
		String[] strings = getStringArray(line);
		long[] numbers = new long[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Long.parseLong(strings[i]);}
		return numbers;
	}
	public static double[] getDoubleArray(String line)
	{
		String[] strings = getStringArray(line);
		double[] numbers = new double[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Double.parseDouble(strings[i]);}
		return numbers;
	}
	public static String[] getStringArray(String line) {return line.trim().split("(\\s)+", 0);}

	public static int[] getIntArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		int[] numbers = new int[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Integer.parseInt(strings[i - begin]);}
		return numbers;
	}
	public static long[] getLongArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		long[] numbers = new long[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Long.parseLong(strings[i - begin]);}
		return numbers;
	}
	public static double[] getDoubleArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		double[] numbers = new double[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Double.parseDouble(strings[i - begin]);}
		return numbers;
	}
	public static String[] getStringArray(String line, int begin, int end)
	{
		String[] lines = line.trim().split("(\\s)+", 0);
		String[] results = new String[end - begin];
		for (int i = begin; i < end; i++) {results[i - begin] = lines[i];}
		return results;
	}

	public static char[][] getCharMatrix(BufferedReader input) throws Exception
	{
		String line = input.readLine();
		H = getInt(line, 0);
		W = getInt(line, 1);
		D = getInt(line, 2);
		char[][] matrix = new char[H][W];
		for (int i = 0; i < H; i++)
		{
			line = input.readLine();
			for (int j = 0; j < W; j++) {matrix[i][j] = line.charAt(j);}
		}
		return matrix;
	}
	public static int[][] getIntMatrix(BufferedReader input) throws Exception
	{
		String line = input.readLine();
		int R = getInt(line, 0);
		int C = getInt(line, 1);
		int[][] matrix = new int[R][C];
		for (int i = 0; i < R; i++)
		{
			line = input.readLine();
			for (int j = 0; j < C; j++) {matrix[i][j] = getInt(line, j);}
		}
		return matrix;
	}

	public static boolean[][] newBooleanMatrix(int R, int C, boolean value)
	{
		boolean[][] matrix = new boolean[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static char[][] newCharMatrix(int R, int C, char value)
	{
		char[][] matrix = new char[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static int[][] newIntMatrix(int R, int C, int value)
	{
		int[][] matrix = new int[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static long[][] newLongMatrix(int R, int C, long value)
	{
		long[][] matrix = new long[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static double[][] newDoubleMatrix(int R, int C, double value)
	{
		double[][] matrix = new double[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}

	public static void output(String s) throws Exception
	{
		if (ECHO_ON) {System.out.println(s);}
		output.write(s);
		output.newLine();
	}

	public static String toKey(boolean[] array)
	{
		StringBuffer buffer = new StringBuffer(array.length + ",");
		for (int i = 0; i < array.length / 16; i++)
		{
			char c = 0;
			for (int j = 0; j < 16; j++)
			{
				c <<= 1; if (array[i * 16 + j]) {c += 1;}
			}
			buffer.append(c + "");
		}
		char c = 0;
		for (int j = 0; j < (array.length % 16); j++)
		{
			c <<= 1; if (array[(array.length / 16) * 16 + j]) {c += 1;}
		}
		buffer.append(c + "");
		return buffer.toString();
	}
	public static String toKey(int[] array, int bit)
	{
		StringBuffer buffer = new StringBuffer(array.length + ",");
		if (bit > 16)
		{
			for (int i = 0; i < array.length; i++)
			{
				char c1 = (char)(array[i] >> 16);
				char c2 = (char)(array[i] & 0xFFFF);
				buffer.append("" + c1 + c2);
			}
		}
		else
		{
			int n = 16 / bit;
			for (int i = 0; i < array.length / n; i++)
			{
				char c = 0;
				for (int j = 0; j < n; j++)
				{
					c <<= bit; c += array[i * n + j];
				}
				buffer.append(c + "");
			}
			char c = 0;
			for (int j = 0; j < (array.length % n); j++)
			{
				c <<= bit; c += array[(array.length / n) * n + j];
			}
			buffer.append(c + "");
		}
		return buffer.toString();
	}

	public static void debug(String s)
	{if (DEBUG_ON) {System.out.println(s);}}
	public static void debug(String s0, double l0)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0);}}
	public static void debug(String s0, double l0, String s1, double l1)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2)
	{if (DEBUG_ON) {	System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2, String s3, double l3)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2+"; "+s3+" = "+l3);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2, String s3, double l3, String s4, double l4)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2+"; "+s3+" = "+l3+"; "+s4+" = "+l4);}}

	public static void debug(boolean[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(boolean[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append((array[i] == true ? "1" : "0") + separator);}
			buffer.append((array[array.length - 1] == true) ? "1" : "0");
			System.out.println(buffer.toString());
		}
	}
	public static void debug(boolean[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(boolean[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}

	public static void debug(char[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(char[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append(array[i] + separator);}
			buffer.append(array[array.length - 1]);
			System.out.println(buffer.toString());
		}
	}
	public static void debug(char[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(char[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}

	public static void debug(int[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(int[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append(array[i] + separator);}
			buffer.append(array[array.length - 1]);
			System.out.println(buffer.toString());
		}
	}
	public static void debug(int[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(int[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}
}
