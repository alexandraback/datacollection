import java.util.AbstractList;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Task2a extends AbstractTask {

	public Task2a() {
		super("A-large.in");
	}

	double best;
	private ArrayList<Double> probabilities;
	
	@Override
	protected void compute() {
		for (String s: cases) {
			Scanner scan = new Scanner(s);
			int alreadyTyped = scan.nextInt();
			int totalLetters = scan.nextInt();
			probabilities = new ArrayList<Double>();
			while (scan.hasNext())
				probabilities.add(scan.nextDouble());
			Double immediateCancel = 2.0 + totalLetters;
			best = immediateCancel;
			goThrough(alreadyTyped, totalLetters);
			result.add("" + best);
		}
	}

	private void goThrough(int a, int b) {
		double chanceWorking = 1.0;
		for (int i = 1; i <= a; i++) {
			int stepsWorking = a - i + b - i + 1;
			int stepsFailing = stepsWorking + b + 1;
			chanceWorking *= probabilities.get(i-1);
			double average = stepsWorking*chanceWorking + stepsFailing*(1 - chanceWorking);
			if (average < best)
				best = average;
		}
	}

	public static void main(String[] args) {
		new Task2a();
	}
}
