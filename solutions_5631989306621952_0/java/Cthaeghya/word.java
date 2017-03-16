import java.util.*;
import java.io.*;

class word {

    public static void main (String[] args) {

	Scanner in = new Scanner(System.in);

	int count = in.nextInt();
	String blank = in.nextLine();
	for (int l = 0; l < count; l++) {

	    String text = in.nextLine();
	    String output = solve(text, "");

	    System.out.println("Case #" + (l+1) + ": " + output);


	}

    }

    public static String solve (String input, String output) {
	if (input.length() == 0)
	    return output;
	String newInput = input.substring(1);
	String newOutput;
	if (output.length() == 0 || output.charAt(0) < input.charAt(0))
	    newOutput = input.charAt(0) + output;
	else if (output.charAt(0) > input.charAt(0))
	    newOutput = output + input.charAt(0);
	else {
	    int location = 0;
	    newOutput = output + input.charAt(0);
	    while (location < output.length()) {
		if (output.charAt(location) < input.charAt(0)) {
		    newOutput = input.charAt(0) + output;
		    location = output.length();
		} else if (output.charAt(location) > input.charAt(0)) {
		    location = output.length();
		} else {
		    location++;
		}
	    }
	}
	return solve(newInput, newOutput);
	
    }

}
