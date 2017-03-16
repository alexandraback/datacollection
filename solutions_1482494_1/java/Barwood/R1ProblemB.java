import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class R1ProblemB {
	public static final boolean Debug = true;
	
	public static void main(String[] args) {
		try {
			//Configuration variables
			final String round = "R1";
			final char problem = 'B';
			final boolean isSmall = false;
			final int attempt = 0;
			
			//Setup of input and output streams
			String filename = "C:/Users/Ben Harwood/Desktop/CodeJam/" + round + "/" + problem;
			if (isSmall) {
				filename += "-small";
				if (attempt >= 0) filename += "-attempt" + attempt;
			}
			else filename += "-large";
			BufferedReader input = new BufferedReader(new FileReader(filename + ".in"));
			BufferedWriter output = new BufferedWriter(new FileWriter(filename + ".out"));
			
			//Parse input
			int lines = Integer.parseInt(input.readLine());
			for (int i = 0; i < lines; i++) {
				String out = ProcessInput(input, i);
				out = "Case #" + (i + 1) + ": " + out.trim();
				if (Debug) System.out.println(out);
				output.append(out);
				if (i < lines - 1) output.append("\n");
			}
			input.close();
			output.close();
		}
		catch (Exception e) {
			System.err.println(e.getMessage());
			e.printStackTrace();
		}
	}
	
	public static String ProcessInput(BufferedReader input, int caseNo) throws Exception {
		String in = input.readLine();
		if (Debug) System.out.println("Input#" + (caseNo + 1) + ": " + in);
		String out = "";
		//Code goes here...
		int levels = Integer.parseInt(in);
		int[][] stars = new int[levels][2];
		int[] done = new int[levels];
		for (int i = 0; i < levels; i++) {
			in = input.readLine();
			String[] starString = in.split(" ");
			stars[i][0] = Integer.parseInt(starString[0]);
			stars[i][1] = Integer.parseInt(starString[1]);
			done[i] = 0;
		}
		int count = 0;
		int starCount = 0;
		//Solve
		boolean playing  = true;
		while (playing) {
			ArrayList<Integer> canPlay = new ArrayList<Integer>();
			ArrayList<Integer> canFinish = new ArrayList<Integer>();
			for (int i = 0; i < levels; i++) {
				switch (done[i]) {
				case 0:
					if (stars[i][0] <= starCount) canPlay.add(i);
				case 1:
					if (stars[i][1] <= starCount) canFinish.add(i);
					break;
				}
			}
			if (canFinish.size() > 0) {
				for (Integer level : canFinish) {
					starCount += 2 - done[level];
					done[level] = 2;
					count++;
				}
			}
			else if (canPlay.size() > 0) {
				int max = -1;
				int dif = 0;
				for (Integer level : canPlay) {
					int currentDif = stars[level][1] - stars[level][0];
					if (currentDif > dif) {
						max = level;
						dif = currentDif;
					}
				}
				if (max > -1) {
					starCount ++;
					done[max] = 1;
					count++;
				}
			}
			else playing = false;
		}
		if (starCount == 2 * levels) out += count;
		else out = "Too Bad";
		return out;
	}
}
