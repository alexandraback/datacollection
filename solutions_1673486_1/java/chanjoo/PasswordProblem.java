package codejam;

public class PasswordProblem extends Solver {

	public static void main(String...args) {
		PasswordProblem solver = new PasswordProblem();
//		solver.solveSample();
//		solver.solveSmall(0);
		solver.solveLarge();
	}
	
	public PasswordProblem() {
		super('A');
	}
	
	@Override
	public String evaluate() {
		int typed, total = 0;
		float[] probs;
		
		typed = in.nextInt();
		total = in.nextInt();
		probs = new float[typed];
		
		for(int i=0; i<typed; i++) {
			probs[i] = in.nextFloat();
		}
		
		float result = 1 + total + 1;
		
		for(int bs=0; bs<=typed; bs++) {
			typed -= bs;
			float correct_prob = 1f;
			for(int i=0; i<typed; i++) {
				correct_prob *= probs[i];
			}
			int correct_stroke = bs + (total - typed) + 1;
			float exp = correct_stroke * correct_prob;
			
			float wrong_prob = 1f - correct_prob;
			int wrong_stroke = bs + (total - typed + 1) + total + 1;
			
			exp += wrong_stroke * wrong_prob;
			
			if(exp<result) result = exp;
		}
		
		return String.format("%.06f", result);
	}

}
