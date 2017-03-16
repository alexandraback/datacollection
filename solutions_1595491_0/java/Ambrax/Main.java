import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Result {
	public boolean possible;
	public int newSurprises;
	
	public Result(int sur) {
		possible = false;
		newSurprises = sur;
	}
	
	public Result(boolean pos, int sur) {
		possible = pos;
		newSurprises = sur;
	}
}

class Input {
	int numCases;
	int numSurprises;
	int minScore;
	int [] sums;
	
	public Input(String line) {
		String [] arr = line.split(" ");
		numCases = Integer.parseInt(arr[0]);
		sums = new int[numCases];
		
		numSurprises = Integer.parseInt(arr[1]);
		minScore = Integer.parseInt(arr[2]);
		
		int j=3;
		for(int i=0;i<numCases;i++) {
			sums[i] = Integer.parseInt(arr[j]);
			j++;
		}
	}
	
	public Result CheckSatisfaction(int sum, int minScore, int surprises) {
		int quotient = sum/3;
		int rem = sum%3;
		
		if(quotient >= minScore) return new Result(true, surprises);
		
		// doesnt satisfy as is, try to use the remainder
		if(rem > 0) {
			if(quotient+1 >= minScore) return new Result(true, surprises);
			
			// even a 1 doesnt satisfy - we will have to use up surprises if we a bigger remainder
			if(rem == 2 && surprises > 0 && quotient+2 >= minScore)
				return new Result(true, surprises-1);
		} else if(rem == 0 && surprises > 0) {
			// no remainder, and doesnt satisfy, try to readjust
			// readjust for 1 if possible
			if(quotient >= 1 && quotient+1 >= minScore) return new Result(true, surprises-1);
		}
		
		//default
		return new Result(surprises);
	}
	
	public int Solve() {
		int count=0;
		int workingSurprises = numSurprises;
		for(int i=0;i<numCases;i++) {
			Result r = CheckSatisfaction(sums[i], minScore, workingSurprises);
			if(r.possible) {
				workingSurprises = r.newSurprises;
				count++;
			}
		}
		return count;
	}
}

public class Main {
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		// Setup console
		BufferedReader c = new BufferedReader(new InputStreamReader(System.in));
		
		// Read number of test cases
		int numCases = Integer.parseInt(c.readLine());
		// Input
		Input [] testCases = new Input[numCases];
		for(int i=0;i<numCases;i++) {
			testCases[i] = new Input(c.readLine());
		}
		// Solve
		for(int i=0;i<numCases;i++) {
			int soln = testCases[i].Solve();
			System.out.println("Case #" + (i+1) + ": " + soln);
		}
	}
}

