package gcj;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

/*
 * Problem B. Pogo
Confused? Read the quick-start guide.
Small input
10 points	
Solve B-small
You may try multiple times, with penalties for wrong submissions.
Large input
25 points	
You must solve the small input first.
You have 8 minutes to solve 1 input file. (Judged after contest.)
Problem

You have just got the best gift ever, a Pogo stick. The pogo stick is something you use to jump off the ground while standing on it. 

This Pogo stick is a special one: the first jump will move you a distance of 1 unit, the second jump will move you 2 units, the third jump will move you 3 units and so on. You can jump in only four directions using this stick: north (increasing y), south (decreasing y), east (increasing x) or west (decreasing x). 

Now you want to play a game in your backyard, which we model as an infinite plane. You are standing with your stick in at point (0, 0) and you want to go to point (X, Y). 

The point (X, Y) will never be (0, 0), and it will always be reachable from your starting point. 

Check the output section carefully, because the required outputs for the small and large datasets are not the same.

Input

The first line of the input gives the number of test cases, T. T test cases follow, one per line. Each line consists of 2 integers separated by a single space, X and Y, the coordinates of the point you want to reach.

Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is a string represents the directions of the moves, for example if you are going to move north then south then east then west, this string should be NSEW.

For the small dataset, the output is considered correct if it does not take more than 500 moves to reach the destination in each test case. 

For the large dataset, the output is considered correct if it reaches the destination point in the minimum possible number of moves. 

If there are multiple correct solutions, print any of them.

Limits

Small dataset

1 ² T ² 50.
0 ² |X|, |Y| ² 100.

Large dataset

1 ² T ² 100.
0 ² |X|, |Y| ² 106.

Sample


Input 
 	
Output 
 
2
3 4
-3 4
Case #1: ENWSEN
Case #2: ENSWN

The output for the first sample test case will not be considered correct if it is in the large dataset, because the number of moves is not the minimum. WNSEN would be a correct output for this test case if it were in the large dataset.
 */
public class GCJ2013r1CqB {
	public static void main(String[] args) throws Exception {
		final String FILE_DIR = "/Users/jhorwitz/Downloads/";
		File inFile = new File(FILE_DIR + "B-small-attempt0.in");
		File outFile = new File(FILE_DIR + "gcj2013R1C-qB-s0.txt");
		Writer w = new FileWriter(outFile);
		Scanner s = new Scanner(inFile);

		int T = s.nextInt();
		for (int t = 1; t <= T; ++t) {
			int X = s.nextInt();
			int Y = s.nextInt();
			output(w, t, solve(X,Y));
		}
		s.close();
		w.close();
	}

	private static String solve(int X, int Y) {
		StringBuilder retVal = new StringBuilder();

		char east = (X < 0) ? 'W' : 'E';
		char north = (Y < 0) ? 'S' : 'N';
		char west = (X < 0) ? 'E' : 'W';
		char south = (Y < 0) ? 'N' : 'S';
		X = Math.abs(X);
		Y = Math.abs(Y);
		// now we the problem in quadrant I

		int nextJumpLength = 1;
		while (nextJumpLength <= X) {
			retVal.append(east);
			X -= nextJumpLength;

			++nextJumpLength;
		}
		while (nextJumpLength <= Y) {
			retVal.append(north);
			Y -= nextJumpLength;

			++nextJumpLength;
		}
		while (X > 0) {
			retVal.append(west).append(east);
			--X;

			nextJumpLength += 2;
		}
		while (Y > 0) {
			retVal.append(south).append(north);
			--Y;

			nextJumpLength += 2;
		}

		return retVal.toString();
	}

	public static void output(Writer w, int t, String s) throws IOException {
		w.write("Case #" + t + ": " + s + "\n");
		System.out.println("Case #" + t + ": " + s);
	}
}