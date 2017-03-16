import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class HikingDeer {
	static String filename = "C-small-1-attempt0";
	static Scanner sc;
	
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream(filename + ".in"));
		System.setOut(new PrintStream(filename + ".out"));
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int casee = 1 ; casee<=t ; casee++){
			System.out.print("Case #" + casee + ": ");
			System.out.println(solve());
		}
	}
	public static long solve(){
		int n = sc.nextInt();
		ArrayList<Hiker> hikers = new ArrayList<Hiker>();
		for(int i = 0; i < n; i++){
			int d = sc.nextInt();
			int h = sc.nextInt();
			int m = sc.nextInt();
			for(int j = 0; j < h; j++){
				hikers.add(new Hiker( (((double)(360-d))/360)*(m+j) , m+j));
			}
		}
		Collections.sort(hikers);
		return calculate(hikers);
	}
	
	private static long calculate(ArrayList<Hiker> hikers) {
		long best = Long.MAX_VALUE;
		for(int i = 0; i < hikers.size(); i++){
			long val = i;
			for(int j = i+1; j < hikers.size(); j++){
				val+= Math.floor((hikers.get(i).firstRound-hikers.get(j).firstRound)/hikers.get(j).roundTime);
			}
			best = Math.min(best, val);
		}
		
		return best;
	}

	static class Hiker implements Comparable<Hiker>{
		double firstRound;
		double roundTime;
		Hiker(double firstRound, double roundTime){
			this.firstRound = firstRound;
			this.roundTime = roundTime;
		}
		@Override
		public int compareTo(Hiker h) {
			return Double.compare(h.firstRound, this.firstRound);
		}
	}
}
