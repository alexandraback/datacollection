import java.io.*;
import java.util.*;

public class ProbA {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        ProbA p = new ProbA();
        p.solveAll();
    }
    int tests = 0;
    Scanner in;
    BufferedWriter out;
    public ProbA() throws FileNotFoundException, IOException {
        out = new BufferedWriter(new FileWriter("a.out"));
        in = new Scanner(new File("a.in"));
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
        String line = in.nextLine();
        out.write("Case #"+casenr+": ");
		//solve 
		int a, b;
		a = in.nextInt();
		b = in.nextInt();
		double min = b+2.0;
		double corr = 1.0;
		for(int i = 1; i <= a; i++) {
			double tmp = in.nextDouble();
			corr = corr * tmp;
			int need = (a-i)*2+b-a+1;
			double exp = corr * need + (1-corr)*(need+b+1);
			if(exp < min) {
				//System.out.println("i: "+i+" "+exp+" "+need);
				min = exp;
			}
		}
		out.write(new Double(min).toString());
		//endsolve
        out.write('\n');
    }
}