import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class Lawn {
	private static int nextIntLine(Scanner in) {
		return Integer.parseInt(in.nextLine());
	}

	public static void main(String[] args) throws FileNotFoundException {
		File f = new File("output.out");
		f.delete();
		PrintStream out = new PrintStream(f);
//		PrintStream out = System.out;

		Scanner in = new Scanner(new File("input2.in"));
		int numCases = nextIntLine(in);
//		for(;;)System.out.println("\""+in.nextLine()+"\"");
		for(int i = 0; i < numCases; ++i) {
			out.printf("Case #%d: %s\n", i+1, getAnswer(in));
		}
		
		out.close();
		in.close();
	}

	private static String getAnswer(Scanner in) {
		int height = in.nextInt();
		int width = in.nextInt();
		int[][] pattern = new int[height][width];
		TreeSet<Integer> availHeights = new TreeSet<Integer>();

		for(int y = 0; y < height; ++y) {
			for(int x = 0; x < width; ++x) {
				int gh = in.nextInt();
				pattern[y][x] = gh;
				availHeights.add(gh);
//				System.out.print(gh + " ");
			}
//			System.out.println();
		}
		in.nextLine();
		
		//System.out.println(Arrays.toString(availHeights.toArray()));

		return (testPattern(pattern, availHeights)) ? "YES" : "NO";
	}

	private static boolean testPattern(int[][] pattern, TreeSet<Integer> availHeights) {
		if(pattern.length == 1 || pattern[0].length == 1) return true;
		if(availHeights.size() < 2) return true;

		int grass = availHeights.pollFirst();
		if(!formsStraightLines(pattern, grass))
			return false;

		int newLow = availHeights.first();
		for(int y = 0; y < pattern.length; ++y) {
			for(int x = 0; x < pattern[y].length; ++x) {
				if(pattern[y][x] == grass) pattern[y][x] = newLow;
			}
		}
		
		return testPattern(pattern, availHeights);
	}

	private static boolean formsStraightLines(int[][] pattern, int grass) {
		boolean[] vertLines = new boolean[pattern[0].length];
		boolean[] horzLines = new boolean[pattern.length];

		for(int i = 0; i < vertLines.length; ++i)
			vertLines[i] = true;
		
		for(int i = 0; i < horzLines.length; ++i)
			horzLines[i] = true;

		for(int y = 0; y < pattern.length; ++y) {
			for(int x = 0; x < pattern[y].length; ++x) {
				if(pattern[y][x] != grass) {
					vertLines[x] = false;
					horzLines[y] = false;
				}
			}
		}
		
		for(int y = 0; y < pattern.length; ++y) {
			for(int x = 0; x < pattern[y].length; ++x) {
				//if(pattern[y][x] == grass) System.out.printf("%d %d %b %b %d\n", y, x, vertLines[x], horzLines[y], grass);
				if(pattern[y][x] == grass && !(vertLines[x] || horzLines[y]))
					return false;
			}
		}
		
		return true;
		
		
		
		
//		// test upper edge
//		boolean topLine = true;
//		for(int x = 0; x < pattern[0].length; x++) {
//			if(pattern[0][x] != grass) topLine = false;
//
//			if(pattern[0][x] == grass && pattern[1][x] != grass) {
//				boolean leftOK = (x == 0 || pattern[0][x-1] == grass);
//				boolean rightOK = (x == pattern[0].length || pattern[0][x+1] == grass);
//				if(!leftOK || !rightOK) return false;
//			}
//		}
//		
//		// test bottom edge
//		int botY = pattern.length-1;
//		boolean bottomLine = true;
//		for(int x = 0; x < pattern[botY].length; x++) {
//			if(pattern[botY][x] != grass) bottomLine = false;
//
//			if(pattern[botY][x] == grass && pattern[botY-1][x] != grass) {
//				boolean leftOK = (x == 0 || pattern[botY][x-1] == grass);
//				boolean rightOK = (x == pattern[botY].length || pattern[botY][x+1] == grass);
//				if(!leftOK || !rightOK) return false;
//			}
//		}
//		
//		// test left edge
//		boolean leftLine = true;
//		for(int y = 0; y < pattern.length; y++) {
//			if(pattern[y][0] != grass) leftLine = false;
//
//			if(pattern[y][0] == grass && pattern[y][1] != grass) {
//				boolean upOK = (y == 0 || pattern[y-1][0] == grass);
//				boolean downOK = (y == pattern.length || pattern[y+1][0] == grass);
//				if(!upOK || !downOK) return false;
//			}
//		}
//		
//		// test right edge
//		int rightX = pattern[0].length-1;
//		boolean rightLine = true;
//		for(int y = 0; y < pattern.length; y++) {
//			if(pattern[y][rightX] != grass) rightLine = false;
//
//			if(pattern[y][rightX] == grass && pattern[y][rightX-1] != grass) {
//				boolean upOK = (y == 0 || pattern[y-1][rightX] == grass);
//				boolean downOK = (y == pattern.length || pattern[y+1][rightX] == grass);
//				if(!upOK || !downOK) return false;
//			}
//		}
//		
//		// test corners
//		if(pattern[0][0] == grass && !(topLine || leftLine)) return false;
//		if(pattern[botY][0] == grass && !(leftLine || bottomLine)) return false;
//		if(pattern[0][rightX] == grass && !(topLine || rightLine)) return false;
//		if(pattern[botY][rightX] == grass && !(bottomLine || rightLine)) return false;
//
//		// test middle tiles
//		for(int y = 1; y < pattern.length-1; ++y) {
//			for(int x = 1; x < pattern[y].length-1; ++x) {
//				if(pattern[y][x] == grass &&
//					(!testUpDown(pattern, y, x) ||
//					 !testLeftRight(pattern[y], x)))
//				{
//					return false;
//				}
//			}
//		}
//		
//		return true;
	}

	private static boolean testLeftRight(int[] patternY, int x) {
		if(patternY[x] != patternY[x-1] || patternY[x] != patternY[x-1]) return false;
		return true;
	}

	private static boolean testUpDown(int[][] pattern, int y, int x) {
		if(pattern[y][x] != pattern[y-1][x] || pattern[y][x] != pattern[y+1][x]) return false;
		return true;
	}
}
