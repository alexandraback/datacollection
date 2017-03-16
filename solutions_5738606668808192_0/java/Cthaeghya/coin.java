import java.util.*;
import java.io.*;

public class coin {

    public static void main (String[] args) {

	Scanner in = new Scanner(System.in);

	int count = in.nextInt();
	for (int l = 0; l < count; l++) {

	    int n = in.nextInt();
	    int j = in.nextInt();

	    if (n % 2 != 0) {
		
		System.out.println("Case #" + (l+1) + ": Only works for even N");
	    
	    } else {
		
		System.out.println("Case #" + (l+1) + ":");

		for (int i = 0; i < j; i++) {
		    if (i < power(2,(n/2) - 2)) {
			
			System.out.print("1");
			printBinary(i, (n/2)-2);
			System.out.print("11");
			printBinary(i, (n/2)-2);
			System.out.print("1");
		    
			for (int k = 2; k <= 10; k++) {
			    System.out.print(" ");
			    System.out.print(1L + power(k, n/2));
			}

			System.out.println("");

		    }
		}
	    }

	}

    }

    public static long power (long k, int n) {
	if (n < 1)
	    return 1;
	return (k * power(k, n-1));
    }

    public static void printBinary (int number, int length) {
	if (number < 1) {
	    for (int i = 0; i < length; i++)
		System.out.print("0");
	} else {
	    printBinary(number/2, length-1);
	    System.out.print(number%2);
	}
    }

}
