/*
 * This code is meant to run under the Java Runtime Environment, version 1.7 or
 * later.
 */

package qualification.d;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main0 {
	
	// This is used to work around the inability of Eclipse to use a file as
	// System.in when running a program.
	private static final String IN_FILE_NAME = "input.txt";

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE_NAME)));
		
		int numCases = in.nextInt();
		
		for (int i = 1; i <= numCases; i++) {
			int n = in.nextInt();
			double[] p0Blocks = new double[n];
			for (int j = 0; j < n; j++) {
				p0Blocks[j] = in.nextDouble();
			}
			double[] p1Blocks = new double[n];
			for (int j = 0; j < n; j++) {
				p1Blocks[j] = in.nextDouble();
			}
			
			int[] result = solve(n, p0Blocks, p1Blocks);
			System.out.println(String.format("Case #%s: %s %s", i, result[0],
				result[1]));
		}
		
		in.close();
	}
	
	// Returns two values: p0's max score in Deceitful War, and p0's max score
	// in War.
	private static int[] solve(int n, double[] p0Blocks, double[] p1Blocks) {
		Arrays.sort(p0Blocks);
		Arrays.sort(p1Blocks);
		
		int deceitfulWarResult = solveDeceitfulWar(n, p0Blocks, p1Blocks);
		int warResult = solveWar(n, p0Blocks, p1Blocks);
		
		int[] result = {deceitfulWarResult, warResult};
		return result;
	}
	
	// Assumes p0Blocks and p1Blocks are sorted.
	private static int solveDeceitfulWar(int n, double[] p0Blocks,
		double[] p1Blocks)
	{
		// Convert p1Blocks to a list, for removal support.
		List<Double> p1BlocksList = new ArrayList<Double>(n);
		for (int i = 0; i < n; i++) {
			p1BlocksList.add(p1Blocks[i]);
		}
		
		int p0Score = 0;
		
		// P0 will play blocks from small to large.
		
		for (int i = 0; i < n; i++) {
			double nextP0Block = p0Blocks[i];
			
			// If P1 has a block of less value than P0's, P0 can score a point
			// by making P1 play its smallest block.  (Can't make P1 play a
			// losing block other than its smallest one.)
			int searchResultIndex = -(Collections.binarySearch(p1BlocksList, nextP0Block) + 1);
			if (searchResultIndex != 0) {
				p0Score++;
				p1BlocksList.remove(0);
			}
			
			// Otherwise, P0 is guaranteed to lose this round, and will simply
			// make P1 discard its largest block.
			else {
				p1BlocksList.remove(p1BlocksList.size()-1);
			}
		}
		
		return p0Score;
	}
	
	// Assumes p0Blocks and p1Blocks are sorted.
	private static int solveWar(int n, double[] p0Blocks, double[] p1Blocks) {
		// Convert p1Blocks to a list, for removal support.
		List<Double> p1BlocksList = new ArrayList<Double>(n);
		for (int i = 0; i < n; i++) {
			p1BlocksList.add(p1Blocks[i]);
		}
		
		int p0Score = 0;
		
		// P0 will play blocks from small to large.  (The order of P0's moves
		// does not matter.)
		
		for (int i = 0; i < n; i++) {
			double nextP0Block = p0Blocks[i];
			int searchResultIndex = -(Collections.binarySearch(p1BlocksList, nextP0Block) + 1);
			if (searchResultIndex == p1BlocksList.size()) {
				p0Score++;
				p1BlocksList.remove(0);
			}
			else {
				p1BlocksList.remove(searchResultIndex);
			}
		}
		
		return p0Score;
	}
}