package shb.test.codejam.k14;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import shb.test.codejam.JamInputReader;

public class War {
	private JamInputReader jam;
	private StringBuffer out;

	public static void main(String[] args) throws IOException {
//		War problem = new War("war-sample.in");
		War problem = new War("D-small-attempt0.in");

		int tests = problem.jam.readInt();
		for (int t = 1; t <= tests; t++) {
			problem.solve(t);
		}
		problem.printResults();
	}

	private void solve(int t) {
		int size = jam.readInt();
		BigDecimal[] naomy = jam.readBigDecimalArray(size);
		BigDecimal[] ken = jam.readBigDecimalArray(size);

		int warScore = playWar(naomy, ken);
		int deceitScore = playDeceitWar(naomy, ken);
		
		if (t > 1) {
			out.append("\n");
		}
		out.append("Case #"+t+": " + deceitScore + " " + warScore);
	}

	private int playDeceitWar(BigDecimal[] naomy, BigDecimal[] ken) {
		//best case, she wins it all
		int won = 0; 
		
		int games = naomy.length;
		
		Arrays.sort(naomy, Collections.reverseOrder());
		Arrays.sort(ken, Collections.reverseOrder());
		
		List<BigDecimal> naomyList = new ArrayList<BigDecimal>(Arrays.asList(naomy));
		List<BigDecimal> kenList =  new ArrayList<BigDecimal>(Arrays.asList(ken));
		
		while (games > 0) {
			if (naomyList.get(naomyList.size() - 1).compareTo(kenList.get(kenList.size() - 1)) < 0) {
				//offer loser pieces
				naomyList.remove(naomyList.size()-1);
				kenList.remove(kenList.get(0));
			} else if (naomyList.get(naomyList.size() - 1).compareTo(kenList.get(kenList.size() - 1)) > 0) {
				//naomy's worst is better than ken's worst, take it
				naomyList.remove(naomyList.size()-1);
				kenList.remove(kenList.size() - 1);
				won++;
			}
			games--;
		}
		
		
		return won;
	}

	private int playWar(BigDecimal[] naomy, BigDecimal[] ken) {
		// naomy plays her best piece, ken plays better if available, otherwise
		// plays lowest piece
		int won = 0;
		Arrays.sort(naomy, Collections.reverseOrder());
		Arrays.sort(ken, Collections.reverseOrder());
	
		List<BigDecimal> naomyList = new ArrayList<BigDecimal>(Arrays.asList(naomy));
		List<BigDecimal> kenList =  new ArrayList<BigDecimal>(Arrays.asList(ken));
		
		for (BigDecimal naomyPiece : naomyList) {
			//get ken's piece
			BigDecimal kenPiece = null;
			for (BigDecimal piece : kenList) {
				if (piece.compareTo(naomyPiece) > 0) {
					kenPiece = piece;
				}
			}
			if (null == kenPiece) {
				kenPiece = kenList.get(kenList.size() - 1); //smallest element
			}

			kenList.remove(kenPiece);
			
			if (naomyPiece.compareTo(kenPiece) > 0) {
				won++;
			}
		}
		
		return won;
	}


	private void printResults() throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter("war.out"));
		writer.append(out.toString());
		writer.close();
	}

	public War(String filename) throws FileNotFoundException {
		jam = new JamInputReader(filename);
		out = new StringBuffer();
	}

}
