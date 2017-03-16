import java.io.*;
import java.util.*;

class StandingOvation {
  public static void main (String [] args) throws IOException {
	StandingOvation solver = new StandingOvation();
	solver.solveProblem();
  }
  public void solveProblem() throws IOException {
	BufferedReader f = new BufferedReader(new FileReader("StandingOvation.in"));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("StandingOvation.out")));
	
	int T = Integer.parseInt(f.readLine());
	
	for(int x = 0; x < T; x++) {
	  String line = f.readLine();
	  StringTokenizer st = new StringTokenizer(line);
	  int Smax = Integer.parseInt(st.nextToken());
	  int[] audience = new int[Smax + 1];
	  String digits = st.nextToken();
	  for(int i = 0; i < audience.length; i++) {
		audience[i] = Integer.parseInt(digits.substring(i, i+1));
	  }
	  
	  int numStanding = audience[0];
	  int friends = 0;
	  for(int i = 1; i < audience.length; i++) {
		if(i > numStanding && audience[i] != 0) {
		  friends += (i - numStanding);
		  numStanding = i;
		}
		numStanding += audience[i];
	  }
	  out.println("Case #" + (x+1) + ": " + friends);
	}
	
	f.close();
	out.close();
	System.exit(0);
  }
}
