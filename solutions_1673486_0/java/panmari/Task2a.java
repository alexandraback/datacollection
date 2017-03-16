import java.util.AbstractList;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Task2a extends AbstractTask {

	public Task2a() {
		super("A-small-attempt0.in");
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
		System.out.println(result);
	}

	private void goThrough(int a, int b) {
		for (int i = 1; i <= a; i++) {
			int stepsWorking = a - i + b - i + 1;
			int stepsFailing = stepsWorking + b + 1;
			double chanceWorking = multiplyAll(i);
			double average = stepsWorking*chanceWorking + stepsFailing*(1 - chanceWorking);
			if (average < best)
				best = average;
		}
	}
	private Double multiplyAll(int end) {
		List<Double> probs = probabilities.subList(0, end);
		Double result = 1.0;
		for (Double prob: probs)
			result *= prob;
		return result;
	}

	public static void main(String[] args) {
		new Task2a();
	}
}
