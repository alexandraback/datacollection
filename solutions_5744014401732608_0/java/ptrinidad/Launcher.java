package commons;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Launcher {

	public static void main(String[] args) throws IOException {
		File inFile = new File("B-small-attempt0.in");
	    File outFile = new File("B-small-attempt0.out");
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
		int nBuildings = in.nextInt();
		int nPaths = in.nextInt();
		
		return new Problem(nBuildings,nPaths);
	}



}
