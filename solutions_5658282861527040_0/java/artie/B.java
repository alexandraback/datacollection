import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class B {

	public static void main(String[] args) throws Exception {
		new B().run();
	}
	
	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int res = 0;
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++)
					if ((i & j) < c)
						res++;
			pw.printf("Case #%d: %d\n", t, res);
		}		
		pw.close();
		sc.close();
	}

}
