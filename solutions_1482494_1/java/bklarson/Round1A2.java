import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;


public class Round1A2 {
	private static BufferedReader r;
	private static PrintStream outFile;
	private static PrintStream out = new PrintStream(new OutputStream() {
		@Override
		public void write(int b) throws IOException {
			System.out.write(b);
			outFile.write(b);
		}
	});

	public static void main(String[] args) throws IOException {
		File f = new File("/home/blarson/input");
		r = new BufferedReader(new FileReader(f));
		outFile = new PrintStream(new FileOutputStream(new File("/home/blarson/output")));
		final int numCases = readInt();
		
		for(int i = 0; i < numCases; i++) {
			out.print("Case #" + (i+1) + ": ");

			solve();
			
			out.println();
		}
		
		out.close();
	}
	
	static int[][] levels;
	static int numLevels;
	static int numStars;
	
	private static void solve() throws IOException {
		numLevels = readInt();
		levels = new int[numLevels][2];
		numStars = 0;
		int numGames = 0;
		int bestLevel = -1;
		for(int i = 0; i < numLevels; i++) {
			levels[i] = readIntArray(2);
		}
		while(numStars < numLevels * 2) {
			bestLevel = findBestLevel();
			if(bestLevel == -1) {
				out.print("Too Bad");
				return;
			}
			if(numStars >= levels[bestLevel][1]) {
				if(levels[bestLevel][0] == -1) {
					numStars++;
				} else {
					numStars += 2;
				}
				levels[bestLevel][1] = -1;
				levels[bestLevel][0] = -1;
			} else {
				levels[bestLevel][0] = -1;
				numStars += 1;
			}
			numGames++;
		}
		out.print(numGames);
	}

	private static int findBestLevel() {
		int bestLevel = -1;
		int highestTwoStar = -1;
		for(int i = 0; i < numLevels; i++) {
			if(levels[i][1] == -1) {
				continue;
			}
			if(levels[i][1] <= numStars) {
				return i;
			}
			if(levels[i][0] <= numStars && levels[i][0] != -1) {
				if(levels[i][1] > highestTwoStar) {
					bestLevel = i;
					highestTwoStar = levels[i][1];
				}
			}
		}
		return bestLevel;
	}

	private static int[] readIntArray(int maxItems) throws IOException {
		int[] array = new int[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for(int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = new Integer(data[i]);
		}
		return array;
	}

	private static int readInt() throws IOException {
		String line = r.readLine().trim();
		return new Integer(line);
	}

}