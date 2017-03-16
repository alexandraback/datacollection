import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class TaskD {
//	Scanner in = new Scanner(System.in);
//	PrintStream out = System.out;

	public static void main(String[] args) throws FileNotFoundException {
		new TaskD().solve();
	}

	private void solve() throws FileNotFoundException {
		Scanner in = new Scanner(new File("D-small-attempt0.in"));
		PrintWriter out = new PrintWriter("taskD.out");
		int testCase = in.nextInt();
		for (int ii = 0; ii < testCase; ++ii) {
			out.printf("Case #%d: ",ii+1);
			int n = in.nextInt();
			double [] a = new double[n];
			double [] b = new double[n];
			for (int i = 0; i < n; ++i) {
				a[i] = in.nextDouble();

			}
			TreeSet<Double> tree = new TreeSet<Double>();
			for (int i = 0; i < n; ++i) {
				b[i] = in.nextDouble();
				tree.add(b[i]);
			}
			int ans = 0;
			for (int i = 0;i<n;++i){
				Double got = tree.floor(a[i]);
				if (got!=null){
					++ans;
					tree.remove(got);
				}
			
			}
			int ans2 = 0;
			tree.clear();
			for (int i = 0; i < n; ++i) {
	
				tree.add(a[i]);
			}
			
			for (int i = 0;i<n;++i){
				Double got = tree.floor(b[i]);
				if (got!=null){
					
					tree.remove(got);
				} else {
					++ans2;
				}
			
			}
			
			out.println(ans+" "+ans2);
			
			
		}
		out.close();
		in.close();
	}
}
