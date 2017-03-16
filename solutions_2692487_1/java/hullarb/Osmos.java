import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;


public class Osmos {


	/**
	 * @author Bela Hullar
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader input = new BufferedReader(new FileReader(args[0]));
		OutputStreamWriter out = new OutputStreamWriter(new FileOutputStream(args[0].contains("in")?args[0].replace("in", "out"):args[0] + ".out"));
		int testCases = Integer.parseInt(input.readLine());
		for(int i = 0; i < testCases; i++) {
			String line = input.readLine();
			int A = Integer.parseInt(line.split(" ")[0]);
			int numOfMotes = Integer.parseInt(line.split(" ")[1]);
			int[] motes = new int[numOfMotes];
			String[] tokens = input.readLine().split(" ");
			for(int j = 0; j < numOfMotes; j++)
			    motes[j] = Integer.parseInt(tokens[j]);
			out.write("Case #" + (i + 1) + ": " + solve(A, motes) + "\n");
		}
		out.close();
		input.close();
	}

	private static int solve(long a, int[] motes) {
	    if(a == 1)
		return motes.length;	
	    Arrays.sort(motes);
	    int start = 0;
	    for(;start < motes.length; start++)
		if(a > motes[start])
		    a += motes[start];
		else
		    break;
	    if(start == motes.length)
		return 0;
	    int[] additions = addMissing(a, motes, start);    
	    return reduce(additions);
	}

	private static int reduce(int[] additions) {
	    int sum = 0;
	    for(int i = additions.length -1; i > -1; i--) {
		sum += additions[i];
		if(sum > additions.length - i) 
		    return  additions.length - i + reduce(Arrays.copyOf(additions, i));
	    }
	    return sum;
	}

	private static int[] addMissing(long a, int[] motes, int start) {
	    int[] additions = new int[motes.length - start];
	    for(int i = start; i < motes.length; i++) {
		while(a <= motes[i]) {
		    a += a -1;
		    additions[i - start]++;
		}
		a += motes[i];
	    }
	    return additions;
	}

}
