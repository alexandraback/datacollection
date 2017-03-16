import java.util.*;
import java.io.*;

public class sheep {

    public static void main (String[] args) {

	Scanner in = new Scanner(System.in);

	int count = in.nextInt();
	for (int l = 0; l < count; l++) {

	    long n = in.nextLong();

	    if (n == 0) {
		System.out.println("Case #" + (l+1) + ": INSOMNIA");
	    } else {
		boolean[] list = new boolean[10];
		for (int i = 0; i < 10; i++)
		    list[i] = false;
		long number = n;
		augment(list, number);
		while (!check(list)) {
		    number += n;
		    augment(list, number);
		}
		System.out.println("Case #" + (l+1) + ": " + number);
	    }

	}

    }

    private static boolean[] augment (boolean[] list, long number) {
	if (number <= 0)
	    return list;
	int value = (int) (number%10L);
	list[value] = true;
	return augment(list, number/10);
    }

    private static boolean check (boolean[] list) {
	for (int i = 0; i < list.length; i++) {
	    if (list[i] == false)
		return false;
	}
	return true;
    }

}
