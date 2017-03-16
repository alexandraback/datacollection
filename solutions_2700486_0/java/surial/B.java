import java.util.Scanner;


public class B {
	private static Scanner sc;
	
	public static void main(String[] args) {
		build();
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %f\n", i + 1, exec());
	}
	
	private static int EXAC_LIMIT = 101;
	private static double facs[] = new double[EXAC_LIMIT];
	
	public static double exec() {
		int n = sc.nextInt();
		int x = Math.abs(sc.nextInt());
		int y = sc.nextInt();
		if (n == 0) return 0;
		int m;
		for (m = 1; m < 1000; m++) {
			if (m2z[m] <= n) continue;
			m--;
			break;
		}
		int z = m2z[m];
		int d = n - z;
		
		// Option 1: Spot is not even.
		if ((x + y) % 1 == 1) {
			return 0.0;
		}
		
		// Option 2: Spot is entirely within body of mountain.
		if ((x + y) <= 2*m -1) {
			return 1.0;
		}
		
		// Option 2a: d is 0, so if option 2 didn't score, then odds are 0.
		if (d == 0) return 0.0;
		
		// Option 3: Spot is entirely outside both the body and the flank of the mountain.
		if ((x + y) > 2*m + 1) {
			return 0.0;
		}
		
		// Option 3a: Spot is on the exact top.
		if (x == 0) return 0.0;
		
		// Option 4: Even if the coin flips go as badly as possible, the spot is still covered.
		int numberOfDiamondsThatAreGuaranteedToGoCorrectly = d - (2*m);
		if (numberOfDiamondsThatAreGuaranteedToGoCorrectly >= (y + 1)) {
			return 1.0;
		}
		
		// Option 5: Given d coin flips, what are the odds that y of them come up heads?
		// This is the binomial distribution.
		if (d >= EXAC_LIMIT) return approxBinomial(d, y + 1);
		return exactBinomial(d, y + 1);
	}
	
	private static double fac(int n) {
		return facs[n];
	}
	
	private static double exactBinomial(int flips, int expected) {
		double odds = 0.5;
		double p = 0;
		double ff = fac(flips);
		double pp = Math.pow(odds, flips);
		for (int i = expected; i <= flips; i++) {
			p += (ff / ((fac(i)*fac(flips-i)))) * pp;
		}
		return p;
	}
	
	private static double erf(double z) {
		double t = 1.0 / (1.0 + 0.5 * Math.abs(z));
		// Horner's
		double ans = 1 - t * Math.exp(-z * z - 1.26551223 + 
				t * ( 1.00002368 +
				t * ( 0.37409196 + 
				t * ( 0.09678418 + 
				t * (-0.18628806 + 
				t * ( 0.27886807 + 
				t * (-1.13520398 + 
				t * ( 1.48851587 + 
				t * (-0.82215223 + 
				t * ( 0.17087277))))))))));
		if (z >= 0) return ans;
		return -ans;
	}
	
	private static double approxBinomial(int flips, int expected) {
		return 1 - approxBinomial0(expected - 1, flips);
	}
	
	private static double approxBinomial0(int expected, int flips) {
		double u = 0.5 * flips;
		double o = Math.pow(u * 0.5, 0.5);
		return 0.5 * (1 + erf((expected - u) / (Math.sqrt(2) * o)));
	}
	
	static int[] m2z = new int[1000];
	
	// General observation: if X + Y is odd, then the odds are 0.0, because a diamond couldn'tp ossibly land in that configuration.
	
	
	// There are certain stable states; if X or more than X diamonds fall, then this 'mountain' of diamonds will always form and it'll always be
	// exactly where the first Z diamonds fall, where Z is the size of this particular mountain shape.
	
	// This method builds a table which links minimum X sizes (if at least X diamonds fall, then this mountain will exist) to the shape of the mountain.
	
	// Thus, any place inside the minimum known mountain is a 1.0 odds. Any place outside the flanks of that mountain is 0.0 odds. Any place exactly on the
	// flank of this mountain is the interesting case. To calculate odds, we consider that we will now throw D coins, where D is the difference between
	// N and the maximum smaller mountain which has Z diamonds in it. In order for our spot to get a diamond, calculate how many diamonds have to slide down
	// your flank's side of the mountain to score a hit. Now doublecheck that if you throw all diamonds down the wrong flank until that flank is full and
	// then you still get to your chosen spot the odds are still 1.0. If not, the odds are the chances that of D coin flips, D0 of them come up heads.
	
	// This fully answers the question and will easily complete in time given the stated limits.
	
	// Z(1) = 1
	// Z(x+1) = Z(x) + 4x + 1
	// A spot is within the body of mountain M if X+Y is even and M or smaller.
	// A spot is on the flank if X+Y is M+2. It is 0.0 odds if X+Y is more than that.
	// The number of coins that have to have to come up your way is Y.
	// The odds will be 1.0 if D-M is equal to or larger than Y.
	// The 'range' of mountain 1 
	static void build() {
		m2z[1] = 1;
		for (int i = 1; i < 999; i++) {
			m2z[i + 1] = m2z[i] + 4*i + 1;
		}
		
		facs[0] = 1;
		facs[1] = 1;
		for (int i = 2 ; i < EXAC_LIMIT; i++) {
			facs[i] = facs[i-1] * i;
		}
	}
}
