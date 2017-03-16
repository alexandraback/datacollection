package ProblemA;

import java.io.IOException;
import java.util.LinkedList;

import utils.InputReader;

public class SolverA {
	public static void main(String[] args) throws IOException {
		LinkedList<String> input = InputReader.read("C:/Users/Danielle/Desktop/A-small-attempt0.in");
		int num = Integer.parseInt(input.removeFirst());
		int i = 1;
		while(i <= num && !input.isEmpty()) {
			String[] split = input.removeFirst().split(" ");
			int typed = Integer.parseInt(split[0]);
			int total = Integer.parseInt(split[1]);
			double[] probabilities = new double[typed];
			split = input.removeFirst().split(" ");
			for (int k = 0; k < typed; k++) probabilities[k] = Double.parseDouble(split[k]);
			
			double smallest = total + 2;
			for (int k = 0; k < typed; k++){
				int inpsCorrect = total-typed+1+2*k;
				int inpsIncorrect = inpsCorrect+total+1;
				double chanceCorrect = 1;
				for (int j = 0; j < typed-k; j++){
					chanceCorrect *= probabilities[j];
				}
				double cur = chanceCorrect*inpsCorrect + (1-chanceCorrect)*inpsIncorrect;
				if (cur < smallest) smallest = cur;
			}
			System.out.println("Case #"+(i++)+": "+smallest);
		}
	}
}
