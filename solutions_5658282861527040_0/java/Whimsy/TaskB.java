import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;


public class TaskB {
	Scanner in = new Scanner(System.in);
	PrintWriter out = null;
	
	public TaskB() {
		try {
			in = new Scanner(new File("B-small-attempt1.in"));
			out = new PrintWriter("B.out");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		

	}
	public static void main(String[] args) {
		new TaskB().solve();
	}
	private void solve() {
		int testCase = in.nextInt();
		//System.out.println(testCase);
		
		for (int i = 0;i<testCase;++i){
			//System.out.println(i);
			work(i+1);
		}
		out.close();
	}
	private void work(int test) {
		
		int A = in.nextInt();
		int B = in.nextInt();
		int K = in.nextInt();
		
		int ans = 0;
		for (int i = 0;i<A;++i){
			for (int j = 0;j<B;++j){
				if ( (i & j) < K){
					++ans;
				}
			}
		}
		//System.out.println(test);
		
		
		out.printf("Case #%d: ", test);
		out.printf("%d\n",ans);
	}
}
