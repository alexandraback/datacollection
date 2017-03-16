import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class DeceitfulWar {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new FileReader("war.txt"));
		
		int tests = scanner.nextInt();
		for(int i = 1; i <= tests; i++) {
			int N = scanner.nextInt();
			naomiBlocks = new double[N];
			kenBlocks = new double[N];
			for(int j = 0; j < N; j++) {
				naomiBlocks[j] = scanner.nextDouble();
			}
			for(int j = 0; j < N; j++) {
				kenBlocks[j] = scanner.nextDouble();
			}
			
			System.out.println("Case #" + i + ": " + getDeceitfulWarScore() + " " + getWarScore());
		}
		
		scanner.close();
		System.exit(0);
	}
	
	private static double[] naomiBlocks;
	private static double[] kenBlocks;
	
	
	private static int getDeceitfulWarScore() {
		Ken ken = new Ken();
		Naomi naomi = new Naomi();
		
		int naomiPoints = 0;
		while(!ken.blocks.isEmpty()) {
			//Find smallest she can win with
			int smallestIndex = -1;
			for(int i = 0; i < naomi.blocks.size(); i++) {
				if(naomi.blocks.get(i) > ken.blocks.get(0)) {
					smallestIndex = i;
					break;
				}
			}
			
			if(smallestIndex == -1) {
				break;
			}
		
			naomiPoints++;
			double n = naomi.blocks.remove(smallestIndex);
			double k = ken.blocks.remove(0);
		}
		
		return naomiPoints;
	}
	
	private static int getWarScore() {
		Ken ken = new Ken();
		Naomi naomi = new Naomi();
		
		//The optimal strategy for Naomi can be modelled using a greedy algorithm
		//that takes the maximal loss for Ken in value difference or the minimal
		//gain for naomi
		//
		//I'm using a lame O(n^2) alg here...
		int naomiPoints = 0;
		while(!ken.blocks.isEmpty()) {
			//maximal loss
			double utility = Double.MIN_VALUE;
			int idx = -1;
			for(int i = 0; i < naomi.blocks.size(); i++) {
				double n = naomi.blocks.get(i);
				double k = ken.simulatePlay(n);
				double tmpUtility;
				if(n > k) {
					tmpUtility = 1 - (n - k);
				} else {
					tmpUtility = k - n;
				}
				
				if(tmpUtility > utility) {
					utility = tmpUtility;
					idx = i;
				}
			}
			
			
			double n = naomi.blocks.remove(idx);
			double k = ken.playBlock(n);
			
			if(n > k) {
				naomiPoints++;
			}
		}
		
		
		
		return naomiPoints;
	}
	
	/**
	 * Ken tries to play War optimally. I define optimally as:
	 * 
	 * if possible to win a round, play the smallest possible winner
	 * if not possible, play smallest. 
	 * 
	 * @author Andrew
	 *
	 */
	public static class Ken {
		
		public List<Double> blocks = new ArrayList<Double>();
		
		public Ken() {
			for(int i = 0; i < kenBlocks.length; i++) {
				blocks.add(kenBlocks[i]);
			}
			Collections.sort(blocks);
		}
		
		public double playBlock(double opponent) {
			//First check if there is a big enough block
			if(blocks.get(blocks.size() - 1) < opponent) {
				//Nope! Play the smallest
				return blocks.remove(0);
			}
			
			int lastBlockIndex = blocks.size() - 1;
			for(int i = lastBlockIndex - 1; i >= 0; i--) {
				if(blocks.get(i) < opponent) {
					break;
				}
				lastBlockIndex--;
			}
			
			return blocks.remove(lastBlockIndex);
		}
		
		public double simulatePlay(double opponent) {
			//First check if there is a big enough block
			if(blocks.get(blocks.size() - 1) < opponent) {
				//Nope! Play the smallest
				return blocks.get(0);
			}
			
			int lastBlockIndex = blocks.size() - 1;
			for(int i = lastBlockIndex - 1; i >= 0; i--) {
				if(blocks.get(i) < opponent) {
					break;
				}
				lastBlockIndex--;
			}
			
			return blocks.get(lastBlockIndex);
		}
	}
	
	public static class Naomi {
		public List<Double> blocks = new ArrayList<Double>();
		
		public Naomi() {
			for(int i = 0; i < naomiBlocks.length; i++) {
				blocks.add(naomiBlocks[i]);
			}
			Collections.sort(blocks);
		}
		
	}

}
