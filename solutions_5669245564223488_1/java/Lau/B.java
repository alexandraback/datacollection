import java.math.BigInteger;
import java.util.Scanner;

public class B {
    
    static BigInteger modulo = BigInteger.valueOf(1000000007);

    static BigInteger factorial(int n) {
	if (n < 2)
	    return BigInteger.ONE;
	return BigInteger.valueOf(n).multiply(factorial(n - 1)).mod(modulo);
    }

    static int solve(Scanner in) {
	int N = in.nextInt();
	int[] begin = new int[26];
	int[] inner = new int[26];
	int[] end = new int[26];
	int[] pure = new int[26];
	for (int i = 0; i < N; i++) {
	    String car = in.next();
	    boolean isPure = true;
	    char prevLetter = car.charAt(0);
	    for (int j = 1; j < car.length(); j++) {
		if (car.charAt(j) != prevLetter) {
		    if (!isPure)
			inner[prevLetter-'a']++;
		    isPure = false;
		    prevLetter = car.charAt(j);
		}
	    }
	    if (isPure)
		pure[prevLetter - 'a']++;
	    else {
		    begin[car.charAt(0) - 'a']++;
		    end[car.charAt(car.length() - 1) - 'a']++;
	    }
	}
	int nblocks = 0;
	for (int i = 0; i < 26; i++) {
	    if (begin[i] > 1 || end[i] > 1)
		return 0;
	    if (begin[i] + pure[i] + end[i] > 0 && inner[i] > 0)
		return 0;
	    if (begin[i] > 0 && end[i] == 0)
		nblocks++;
	    if (pure[i] > 0 && begin[i] + end[i] == 0)
		nblocks++;
	}
	if (nblocks == 0)
	    return 0;
	BigInteger res = BigInteger.ONE;
	res = res.multiply(factorial(nblocks)).mod(modulo);
	for (int i = 0; i < 26; i++)
	    res = res.multiply(factorial(pure[i])).mod(modulo);
	return res.intValue();

    }

    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for (int cas = 1; cas <= T; cas++)
	    System.out.println("Case #" + cas + ": " + solve(in));
    }

}
