package ProblemD;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
	    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    in.nextLine();
	    int[][] cases = new int[t][3];
	    for (int i = 0; i < t; i++) {
	      for (int j=0; j<3; j++) {
	      	cases[i][j] = in.nextInt();
	      }
      	in.nextLine();
	    }
	    for (int i=0; i<t; i++) {
	   	 ArrayList<Long> solutions = new ArrayList<>();
   		 int branches = cases[i][0];
   		 int depth = cases[i][1];
   		 int checks = cases[i][2];
	   	 if (Math.pow(checks, depth) >= branches) {
	   		 long path = 0;
	   		 for (int j = 0; j < Math.ceil((float)branches/(float)depth); j++) {
	   			 long pos = 0;
	   			 for (int k = depth - 1; k >= 0 ; k--) {
	   				 long pow = 1;
	   				 for (int l=0; l<k; l++) pow*=branches;
	   				 pos += path * pow;
	   				 if(path < branches - 1) path++;
	   			 }
		   		 solutions.add(pos + 1);
	   		 }
	   	 }
	   	 String output = String.format("Case #%d: %s", (i+1), solutions.size()==0 ? "IMPOSSIBLE" : Arrays.toString(solutions.toArray()).replaceAll(", "," ").replaceAll("[\\[\\]]",""));
	   	 System.out.println(output);
	    }
	    in.close();
	}

}
