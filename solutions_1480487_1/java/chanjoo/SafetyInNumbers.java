package codejam;

import java.util.Scanner;

public class SafetyInNumbers extends Solver {

	public static void main(String...args) {
		SafetyInNumbers solver = new SafetyInNumbers();
//		solver.solveSample();
//		solver.solveSmall(1);
		solver.solveLarge();
	}
	
	public SafetyInNumbers() {
		super('A');
	}
	
	int contestants;
	int[] scores;
	boolean[] targets;
	int sum;
	int bsum;
	double avg;
	
	@Override
	public void read(Scanner in) {
		contestants = in.nextInt();
		scores = new int[contestants];
		targets = new boolean[contestants];
		avg = bsum = sum = 0;
		for(int i=0; i<contestants; i++) {
			scores[i] = in.nextInt();
			sum += scores[i];
		}
		bsum = sum;
		avg = (sum+bsum)/(double) contestants;
	}
	
	@Override
	public String evaluate() {
		sum = 0;
		int targetcount = 0;
		for(int i=0; i<contestants; i++) {
			if(avg<scores[i]) {
				targets[i] = false;
			} else {
				sum+=scores[i];
				targets[i] = true;
				targetcount++;
			}
		}
		
		avg = (sum+bsum)/(double) targetcount;
		
		StringBuilder buf = null;
		for(int i=0; i<contestants; i++) {
			double per = avg - scores[i];
			if(targets[i]) {
				per = per/bsum * 100;
			} else {
				per = 0;
			}
			if(buf==null) buf = new StringBuilder();
			else buf.append(" ");
			buf.append(String.format("%6f", per));
		}
		return buf.toString();
	}
	
}
