import java.io.*;
import java.util.*;

class StupidDijkstra {
  // i = 2, j = 3, k = 4
  int times[][] = { {0,0,0,0,0},
	  {0,1,2,3,4},
	  {0,2,-1,4,-3},
	  {0,3,-4,-1,2},
	  {0,4,3,-2,-1}  
  };

  public static void main (String [] args) throws IOException {
	StupidDijkstra solver = new StupidDijkstra();
	solver.solveProblem();
  }
  public void solveProblem() throws IOException {
	BufferedReader f = new BufferedReader(new FileReader("Dijkstra.in"));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Dijkstra.out")));

	int T = Integer.parseInt(f.readLine());

	for(int t = 0; t < T; t++) {
	  StringTokenizer st = new StringTokenizer(f.readLine());
	  int L = Integer.parseInt(st.nextToken());
	  int X = Integer.parseInt(st.nextToken());
	  String ijk = f.readLine();
	  
	  int totalBit = 1;
	  int sign = 1;

	  boolean goti = false;
	  boolean gotj = false;
	  boolean gotk = false;
	  for(int x = 0; x < X; x++ ) {
		for(int i = 0; i < L; i++) {
		  int nextBit = bitToInt(ijk.substring(i, i+1));
		  totalBit = times[totalBit][nextBit];
		  if(totalBit < 0) {
			sign *= -1;
			totalBit *= -1;
		  }
		  if(!goti && totalBit == 2 && sign == 1) {
			goti = true;
			totalBit = 1;
			sign = 1;
		  }
		  else if(goti && !gotj && totalBit == 3 && sign == 1) {
			gotj = true;
			totalBit = 1;
			sign = 1;
		  }
		}
	  }
	  
	  if(totalBit == 4 && sign == 1) {
		gotk = true;
	  }
	  
	  if(goti && gotj && gotk) {
		out.println("Case #" + (t+1) + ": " + "YES");
	  }
	  else {
		out.println("Case #" + (t+1) + ": " + "NO");
	  }
	}

	f.close();
	out.close();
	System.exit(0);
  }

  public int bitToInt(String bit) {

	if(bit.equals("1"))
	  return 1;
	if(bit.equals("i"))
	  return 2;
	if(bit.equals("j"))
	  return 3;
	if(bit.equals("k"))
	  return 4;
	return 0;
  }
}
