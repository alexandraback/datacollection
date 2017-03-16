import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class ProblemA {

	int solve (int init, int[] input) {

		List<Integer> motes = new ArrayList<Integer>();
		for (int i: input) motes.add(i);
		Collections.sort(motes);
		
		//System.out.println(init);
		//System.out.println(motes);
		return solveRec(init, motes, 0, 0);
	}
	
	
	int solveRec (int init, List<Integer> motes, int index, int steps) {
		if (index>=motes.size())
			return steps;
		
		int total = init;
		int mote = motes.get(index);
		if (mote<total)
			return solveRec(total+mote, motes, index+1, steps);
		else {
			int removalSteps = solveRec(init, motes, index+1, steps+1);
			int additionSteps = 0;
			if (init-1==0)
				additionSteps = Integer.MAX_VALUE;
			else
				additionSteps = solveRec(init+init-1, motes, index, steps+1);
			return Math.min(removalSteps, additionSteps);
		}
		
		
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("src/A-small-attempt1.in"));
//		Scanner sc = new Scanner(new File("src/A-sample.in"));

		ProblemA a = new ProblemA();
		
		/*int input[] = new int[4];
		input[0] = 16;
		input[1] = 16;
		input[2] = 16;
		input[3] = 16;
		System.out.println(a.solve(5, input));
		
		*/
		
		int T = sc.nextInt();
		for (int t=1; t<=T; t++) {
			int init = sc.nextInt();
			int sz = sc.nextInt();
			int input[] = new int[sz];
			for (int i=0; i<sz; i++)
				input[i] = sc.nextInt();

			//if (t==4)
			System.out.println("Case #"+t+": "+a.solve(init, input));
		}
		
	}

}
