import java.io.*;
import java.util.*;

public class ProbB {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        ProbB p = new ProbB();
        p.solveAll();
    }
    int tests = 0;
    Scanner in;
    BufferedWriter out;
    public ProbB() throws FileNotFoundException, IOException {
        out = new BufferedWriter(new FileWriter("b.out"));
        in = new Scanner(new File("b.in"));
        tests = in.nextInt();
        //in.nextLine();
        //System.out.println(tests);
    }

    public void solveAll() throws IOException {
        for(int i = 0; i < tests; i++) {
            solve(i+1);
        }
        out.close();
        in.close();
    }
    public void solve(int casenr) throws IOException {
		//System.out.println();
        String line = in.nextLine();
        out.write("Case #"+casenr+": ");
		//solve 
		int n;
		n = in.nextInt();
		int l1[] = new int[n];
		int l2[] = new int[n];
		boolean u1[] = new boolean[n];
		boolean u2[] = new boolean[n];
		int ratings = 0;
		for(int i = 0; i < n; i++) {
			l1[i] = in.nextInt();
			l2[i] = in.nextInt();
			u1[i] = u2[i] = false;
		}
		
		int res = 0;
		boolean error = false;
		while(ratings < n*2 && !error) {
			boolean choosed = false;
			int choice = 0;
			int choicel = 0;
			for(int i = 0; i < n; i++) {
				int l = 0;
				if(l2[i] <= ratings && !u2[i]) {
					l = 2;
				} else if(l1[i] <= ratings && !u1[i]) {
					l = 1;
				}
				if(l > choicel) {
					choicel = l;
					choice = i;
					choosed = true;
				} else if(l == choicel && choosed && l2[choice] < l2[i]) {
					if((l == 1 && !u1[i]) || l == 2 && !u2[i]) {
					choicel = l;
					choice = i;
					}
				}
			}
			if(choicel == 0) {
				error = true;
			} else {
				if(choicel == 1) {
					//System.out.println("l1 - "+choice+" "+ratings);
					ratings += 1;
					u1[choice] = true;
				} else {
					//System.out.println("l2 - "+choice+" "+ratings);
					ratings++;
					if(!u1[choice]) {
						ratings++;
						u1[choice] = true;
					}
					u2[choice] = true;
				}
				res++;
			}
		}
		if(!error)
			out.write(new Integer(res).toString());
		else
			out.write("Too Bad");
		//endsolve
        out.write('\n');
    }
}