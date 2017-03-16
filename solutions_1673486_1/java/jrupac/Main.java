import java.util.Scanner;

public class Main {
    static Scanner in;

    private static double solve(int A, int B) {
        double[] probs = new double[A];
        double[] outcomes = new double[A + 2];
        double p;

        for (int i = 0; i < A; i++) {
            probs[i] = in.nextDouble();
        }
       
		double[] pcache = new double[A + 1];
		pcache[A] = 1.0;
		
		for (int i = A-1; i >= 0; i--) {
			pcache[i] = pcache[i+1] * probs[A-i-1];
		}

        for (int i = 0; i <= A; i++) {
			p = pcache[i];

            outcomes[i] = p * (i + (B - A + i) + 1) + (1.0 - p) * (i + (B - A + i) + 1 + B + 1);
        }

        outcomes[A + 1] = 1 + B + 1;

        double min = B + 2;
        for (double oo : outcomes) {
			if (oo < min) {
				min = oo;
			}
        }

        return min;
    }

    public static void main(String args[]) {
        in = new Scanner(System.in);

        int N = in.nextInt();

        for (int i = 0; i < N; i++) {
            System.out.println("Case #" + (i+1) + ": " + 
                               solve(in.nextInt(), in.nextInt()));
        }
    }
}
