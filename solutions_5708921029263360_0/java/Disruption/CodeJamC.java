import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class CodeJamC {

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new BufferedReader(new FileReader("C-small-attempt0.in")));
		try {
			int testCases = input.nextInt();
			for (int i = 1; i <= testCases; i++) {
				solveTestCase(input, i);
			}
		} finally {
			input.close();
		}
	}

	private static void solveTestCase(Scanner input, int numCase) {
		int jackets = input.nextInt();
		int pants = input.nextInt();
		int shirts = input.nextInt();
		
		int maxPairs = input.nextInt();
		
		Map<Pair, Integer> pairs = new HashMap<>();
		List<Combination> combinations = new ArrayList<>();
		// Choose jackets as base so we only have to care about pants-shirts pairs later
		for (int i = 0; i < jackets; i++) {
			int currentJacket = i + 1;
			// We iterate over the pants
			
			for (int j = 0; j < pants; j++) {
				int currentPants = j + 1;
				// We iterate over shirts
				for (int k = 0; k < shirts; k++) {
					int currentShirt = k + 1;
					Pair jacketPantsPair = new Pair(currentJacket, currentPants, 0);
					Pair jacketShirtPair = new Pair(currentJacket, 0, currentShirt);
					Pair shirtPantsPair = new Pair(0, currentPants, currentShirt);
					
					if (checkOrAddPair(jacketPantsPair, pairs, maxPairs) 
							&& checkOrAddPair(jacketShirtPair, pairs, maxPairs) 
							&&checkOrAddPair(shirtPantsPair, pairs, maxPairs)) {
						combinations.add(new Combination(currentJacket, currentPants, currentShirt));
					}
				}
			}
		}
		
		// Since jackets is the smaller we will use it as generator
		
		System.out.println("Case #" + numCase + ": " + combinations.size());
		for (Combination combination : combinations) {
			System.out.println(combination);
		}
	}


	
	private static boolean checkOrAddPair(Pair pair, Map<Pair, Integer> pairs, int maxPairs) {
		if (pairs.containsKey(pair)) {
			Integer count = pairs.get(pair);
			if (count == maxPairs) {
				return false;
			}
			
			pairs.put(pair, count + 1);
		} else {
			pairs.put(pair, 1);
		}
		return true;
	}



	public static class Combination {
		int jacket;
		int pant;
		int shirts;
		
		public Combination(int currentJacket, int currentPants, int currentShirt) {
			this.jacket = currentJacket;
			this.pant = currentPants;
			this.shirts = currentShirt;
		}
		
		@Override
		public String toString() {
			return jacket + " " + pant + " " + shirts;
		}
	}
	
	public static class Pair {
		int jeans;
		int shirts;
		int jackets;
		
		public Pair(int jackets, int jeans, int shirts) {
			this.jeans = jeans;
			this.shirts = shirts;
			this.jackets = jackets;
		}
		
		@Override
		public boolean equals(Object obj) {
			Pair other = (Pair) obj;
			return jeans == other.jeans && shirts == other.shirts && jackets == other.jackets;
		}
		
		@Override
		public int hashCode() {
			return 31 * jeans + 31 * 31 * shirts + 31 * 31 * 31 * jackets;
		}

		@Override
		public String toString() {
			return jackets + " " + jeans + " " + shirts;
		}
	}
	
}
