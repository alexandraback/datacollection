import java.io.*;
import java.util.*;
import java.math.*;
/** @author Samuel Ahn */

public class A {
    public static void main(String args[]) throws Exception {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for (int i = 1; i <= T; i++) {
	    int A = in.nextInt(); // typed
	    int B = in.nextInt(); // total
	    boolean flag = true;
	    double[] array = new double[A];
	    double mult = 1.0;
	    for (int j = 0; j < A; j++) {
		array[j] = in.nextDouble();
		mult *= array[j];
	    }
	    //System.out.println(mult);
	    double backspace = 0.0;
	    for (int j = A; j > 0; j--) {
		if (array[j - 1] < (1 - array[j - 1])) {
		    backspace++;
		} else {
		    break;
		}
	    }
	    //System.out.println(backspace);
	    double sum;
	    if (backspace == 0) {
		double temp = (B - A)/(B + 1.0);
		//System.out.println(temp);
		if (mult > temp) {
		    sum = mult*(B - A + 1.0) + (1.0 - mult)*(2.0*B - A + 2.0);
		} else {
		    sum = B + 2.0;
		}
	    } else if (backspace == A) {
		sum = B - A + 1.0 + 2.0*A;

	    } else {
		double temp = (B - A)/(B + 1.0);
		//System.out.println(temp);
		if (mult > temp) {
		    temp = mult*(B - A + 1.0) + (1.0 - mult)*(2.0*B - A + 2.0);
		} else {
		    temp = B + 2.0;
		}
		mult = 1.0;
		for (int j = 0; j < backspace; j++) {
		    mult *= array[A - j - 1];
		}
		sum = (1.0 - mult)*(B - A + 2.0*backspace + 1.0) + mult*(2.0*B - A + 2.0*backspace + 2.0);
		if (temp < sum) {
		    sum = temp;
		}
	    }

	    System.out.printf("Case #%d: %f\n", i, sum);
	}
    }
}
