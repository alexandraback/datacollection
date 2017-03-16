import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;


public class Problem1 {
	
	static double x;
	static int ind = 0;
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for(int i = 1; i<= numCases; i++) {
			x = 0;
			int n = scan.nextInt();
			Contestant[] cs = new Contestant[n];
			TreeSet<Contestant> ts = new TreeSet<Contestant>();
			for(int j = 0; j < n; j++) {
				cs[j] = new Contestant(scan.nextDouble());
				ts.add(cs[j]);
				x+= cs[j].score;
			}
			doFractions(ts);
			System.out.print("Case #" + i + ": ");
			for(int j = 0; j < n; j++) {
				System.out.print(cs[j].fraction*100 + " ");
			}
			System.out.println(); //Add answer
		}
	}
	
	public static void doFractions(TreeSet<Contestant> cs) {
		
		double a = 0;
		ArrayList<Contestant> processed = new ArrayList<Contestant>();
		Contestant first = cs.pollFirst();
		double currS = first.current();
		processed.add(first);
		
		while(!cs.isEmpty()) {
			Contestant current = cs.pollFirst();
			//System.err.println("Old score: " + currS);
			double newS = current.current();
			//System.err.println("Score: " + newS);
			double need = (newS - currS)/x;
			//System.err.println("Need: " + need);
			if(need*processed.size() + a > 1) break;
			a+=need*processed.size();
			for(Contestant c:processed) {
				c.fraction += need;
			}
			processed.add(current);
			currS = newS;
		}
		double left = 1-a;
		double toAdd = left/processed.size();
		for(Contestant c:processed) {
			c.fraction+=toAdd;
		}
		
		
	}
	
	private static class Contestant implements Comparable<Contestant> {
		double score;
		int index;
		double fraction;
		
		
		public Contestant(double score) {
			this.score = score;
			fraction = 0;
			index = ind++;
		}
		
		
		@Override
		public int compareTo(Contestant c) {
			if(score - c.score < 0) {
				return -1;
			} else if (score - c.score > 0) {
				return 1;
			}
			return index - c.index;
		}
	
		public boolean equals(Contestant c) {
			return false;
		}
		
		public double current() {
			return fraction * x + score;
		}
		
		
	}

}
