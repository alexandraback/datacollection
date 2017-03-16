package y2015.Round1C;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Scanner;

public class ProbB {

	private static Reader in;
	private static PrintWriter out;	
	public static final String NAME = "A-small-practice.in";		
	public static final String OUTNAME = "output.out";
	
	public static boolean canSolve(int num, int curCoin, ArrayList<Integer> coins) {
		if (num < 0) {
			return false;
		}
		if (num == 0) {
			return true;
		} else {
			if (curCoin >= coins.size()) {
				return false;
			}
			return canSolve(num - coins.get(curCoin), curCoin+1, coins) || canSolve(num, curCoin+1, coins);
		}
	}
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader(NAME));
		BufferedWriter bw = new BufferedWriter(new FileWriter(OUTNAME));
		
		String output = "";
		int cases = Integer.valueOf(sc.nextLine());
		for (int c = 1; c <= cases; c++) {
			output += "Case #" + c + ": ";
			
			int C = sc.nextInt();
			int D = sc.nextInt();
			int V = sc.nextInt();
			
			sc.nextLine();
			ArrayList<Integer> coins = new ArrayList<Integer>();
			for (int i = 0; i < D; i++) {
				coins.add(sc.nextInt());
			}
			
			int needed = 0;
			int[] upTo = new int[V+1];
			for (int i = 1; i <= V; i++) {
				upTo[i] = i;
				boolean set = false;
				if (! canSolve(i, 0, coins)) {
					for (int j = 0; j < coins.size(); j++) {
						if (coins.get(j) <= upTo[i]) {
							upTo[i] = upTo[i] - coins.get(j);
						}
					}
					if (upTo[i] > 0) {
						coins.add(i);
						needed++;
					}
				}
			}
			
			output += needed + "\n";
			
			if (sc.hasNext()) sc.nextLine();
		}		
		bw.write(output);
		bw.close();
	}
	
}
