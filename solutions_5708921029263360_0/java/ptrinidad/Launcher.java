package commons;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Launcher {

	public static void main(String[] args) throws IOException {
		File inFile = new File("C-small-attempt1.in");
	    File outFile = new File("C-small-attempt1.out");
	    Scanner in = new Scanner(inFile);
	    BufferedWriter out = new BufferedWriter(new FileWriter(outFile));
	    int testCases = in.nextInt();
	    for(int t=1;t<=testCases;t++){
	    	Problem problem = processLine(in);
	    	Result result = problem.execute();

	        out.write("Case #" + t + ": " + result + "\n");
	    }
	    in.close();
	    out.close();

	}

	private static Problem processLine(Scanner in) {
		int nJackets = in.nextInt();
		int nPants = in.nextInt();
		int nShirts = in.nextInt();
		int nPairRepeat = in.nextInt();
		
		return new Problem(nJackets,nPants,nShirts,nPairRepeat);
	}



}
