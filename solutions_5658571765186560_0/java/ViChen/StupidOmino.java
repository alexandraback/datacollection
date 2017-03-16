import java.io.*;
import java.util.*;

class StupidOmino {
  int X, R, C;
  public static void main (String [] args) throws IOException {
	StupidOmino solver = new StupidOmino();
	solver.solveProblem();
  }
  public void solveProblem() throws IOException {
	BufferedReader f = new BufferedReader(new FileReader("Ominous.in"));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("OminousNew.out")));

	int T = Integer.parseInt(f.readLine());

	for(int t = 0; t < T; t++) {
	  StringTokenizer st = new StringTokenizer(f.readLine());
	  X = Integer.parseInt(st.nextToken());
	  R = Integer.parseInt(st.nextToken());
	  C = Integer.parseInt(st.nextToken());
	  if(R*C % X != 0) {
		out.println("Case #" + (t+1) + ": RICHARD");
		continue;
	  }
	  if(X==1) {
		out.println("Case #" + (t+1) + ": GABRIEL");
		continue;
	  }
	  if(X==2) {
		out.println("Case #" + (t+1) + ": GABRIEL");
	  }
	  if(X==3) {
		if((R==1 && C==3) || (R==3 && C==1)) {
		  out.println("Case #" + (t+1) + ": RICHARD");
		}
		else {
		  out.println("Case #" + (t+1) + ": GABRIEL");
		}
	  }
	  if(X==4) {
		if((R==2 && C==2) || (R==2 && C==4) || (R==4 && C==2) || (R==4 && C==1) || (R==1 && C==4)) {
		  out.println("Case #" + (t+1) + ": RICHARD");
		}
		else {
		  out.println("Case #" + (t+1) + ": GABRIEL");
		}
	  }
	}
	f.close();
	out.close();
	System.exit(0);
  }
}
