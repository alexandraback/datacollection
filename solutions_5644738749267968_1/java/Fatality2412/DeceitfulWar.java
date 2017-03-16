import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class DeceitfulWar {
	
public static void main(String[] args) throws IOException{
		
		String fileIn = "C:/Users/Valentin/workspace/GoogleCodeJamQualif/src/D-large.in";
		String fileOut = "C:/Users/Valentin/workspace/GoogleCodeJamQualif/src/test.out";
		System.setIn(new FileInputStream(fileIn));
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		System.setOut(new PrintStream(fileOut));
		
		String line;
		int testCase = 1;
		int i = 1;
		int blocksRemaining = 0;
		
		List<Double> naomiBlocks = new ArrayList<>();
		List<Double> kenBlocks = new ArrayList<>();
		
		boolean firstLine = true;
		while ((line = stdin.readLine()) != null && line.length() != 0) {
			String[] input = line.split(" ");
			if (firstLine) {
				firstLine = false;
				continue; 
			}
			switch (i) {
				case 1: blocksRemaining = Integer.parseInt(input[0]);;
						break;
				case 2: for (String elem : input) {
							naomiBlocks.add(Double.parseDouble(elem));
						};
						break;
				case 3: for (String elem : input) {
							kenBlocks.add(Double.parseDouble(elem));
						};
						break;
			}
			if (i == 3) {
				Collections.sort(naomiBlocks);
				Collections.sort(kenBlocks);
				calculate(blocksRemaining, naomiBlocks, kenBlocks, testCase);
				testCase++;
				i = 1;
				naomiBlocks = new ArrayList<>();
				kenBlocks = new ArrayList<>();
				continue;
			}
			i++;
		}
		
		
	}

private static void calculate(int blocksRemaining, List<Double> naomiBlocks,
		List<Double> kenBlocks, int testCase) {
	int z = resultWar(blocksRemaining, naomiBlocks, kenBlocks);
	int y = resultDeceitfulWar(blocksRemaining, naomiBlocks, kenBlocks);
	System.out.println("Case #" + testCase + ": " + y + " " + z);
}

private static int resultDeceitfulWar(int blocksRemaining,
		List<Double> naomiBlocks, List<Double> kenBlocks) {
	List<Double> remainingNaomi = new ArrayList<>(naomiBlocks);
	List<Double> remainingKen = new ArrayList<>(kenBlocks);
	int naomiPoints = 0;
	
	while (blocksRemaining != 0) {
		if (needSacrifice(remainingNaomi, remainingKen)) {
			remainingKen.remove(blocksRemaining - 1);
			remainingNaomi.remove(0);
			blocksRemaining--;
		}
		else {
			naomiPoints += blocksRemaining;
			blocksRemaining = 0;
		}
	}
	return naomiPoints;
}

private static boolean needSacrifice(List<Double> remainingNaomi,
		List<Double> remainingKen) {
	for (int i = 0; i < remainingKen.size(); i++) {
		if (remainingKen.get(i) > remainingNaomi.get(i)) {
			return true;
		}
	}
	return false;
}

private static int resultWar(int blocksRemaining, List<Double> naomiBlocks,
		List<Double> kenBlocks) {
	List<Double> remainingNaomi = new ArrayList<>(naomiBlocks);
	List<Double> remainingKen = new ArrayList<>(kenBlocks);
	int naomiPoints = 0;
	
	while (blocksRemaining != 0) {
		//If max naomi > max ken
		if (remainingNaomi.get(blocksRemaining - 1) > remainingKen.get(blocksRemaining - 1)) {
			naomiPoints++;
			remainingNaomi.remove(blocksRemaining - 1);
			remainingKen.remove(0);
		}
		else {
			int kenIndex = findKenBestToRemove(remainingNaomi.get(blocksRemaining - 1), remainingKen);
			remainingNaomi.remove(blocksRemaining - 1);
			remainingKen.remove(kenIndex);
		}
		blocksRemaining--;
	}
	
	return naomiPoints;
}

private static int findKenBestToRemove(Double naomiNb, List<Double> kenBlocks) {
	int position = -Collections.binarySearch(kenBlocks, naomiNb) - 1;
	return position;
}


}
