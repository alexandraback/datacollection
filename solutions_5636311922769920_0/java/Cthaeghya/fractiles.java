import java.util.*;
import java.io.*;
import java.math.*;

public class fractiles {

    public static void main (String[] args) {

	Scanner in = new Scanner(System.in);

	int count = in.nextInt();
	for (int l = 0; l < count; l++) {

	    int k = in.nextInt();
	    int c = in.nextInt();
	    if (c > k)
		c = k;
	    int s = in.nextInt();

	    if (c*s < k) {
		System.out.println("Case #" + (l+1) + ": IMPOSSIBLE");
	    } else {

		System.out.print("Case #" + (l+1) + ":");

		BigInteger module = BigInteger.valueOf(k).pow(c);

		for (int i = 0; i < k/c; i++) {
		    BigInteger val = BigInteger.valueOf(0);
		    for (int j = 0; j < c; j++) {
			val = val.multiply(BigInteger.valueOf(k));
			val = val.add(BigInteger.valueOf(i*c+j));
		    }
		    val = val.add(BigInteger.valueOf(1));
		    System.out.print(" " + val.toString());
		}

		if (k%c != 0) {
		    int i = k/c;
		    BigInteger val = BigInteger.valueOf(0);
		    for (int j = 0; j < c; j++) {
			val = val.multiply(BigInteger.valueOf(k));
			val = val.add(BigInteger.valueOf(Math.min(i*c+j, k-1)));
		    }
		    val = val.add(BigInteger.valueOf(1));
		    System.out.print(" " + val.toString());
		}

		System.out.println();

	    }

	}

    }

}
