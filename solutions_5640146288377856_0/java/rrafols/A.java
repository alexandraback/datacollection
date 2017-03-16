import java.io.File;
import java.util.Scanner;


public class A {
	public static void main(String args[]) {
        new A().solveAll();
    }
	
	public void solveAll() {
		Scanner sc = new Scanner(System.in);
		
//		try {
//    		sc = new Scanner(new File("bin/i.txt"));
//    	} catch(Exception e) {}	

		int numTestCases = sc.nextInt(); sc.nextLine();
		for(int i = 0; i < numTestCases; i++) {
			
			int R = sc.nextInt();
			int C = sc.nextInt();
			int W = sc.nextInt(); sc.nextLine();
			
			System.out.println("Case #" + (i + 1) + ": " + solve(R, C, W));
		}
	}
	
	public int solve(int R, int C, int W) {
		if(W == 1) return C * R;
		else {
			int moves = (C/W) * R - 1;
			if(C % W == 0) {
				moves += W;
			} else {
				moves += W + 1;
			}
			return moves;
		}
	}	
}
