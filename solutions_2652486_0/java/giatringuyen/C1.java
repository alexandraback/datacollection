import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class C1 {
	public static void main (String[] args) throws Exception {
		Scanner sc = new Scanner (new File("C-small-1-attempt2.in"));
		FileWriter fstream = new FileWriter("C-small-1-attempt2-out.txt");
		BufferedWriter out = new BufferedWriter(fstream);
//		Scanner sc = new Scanner (System.in);
		sc.nextLine();
		sc.nextLine();
		
		int R = 100;
		int M = 5;
		int K = 7;
		
		out.write("Case #1:\n");
		for (int t = 1; t <= R; ++t) {
			Set<Integer> set = new HashSet<Integer>();
			for (int i = 0; i < K; ++i) {
				set.add(sc.nextInt());
			}
			
			boolean done = false;
			outer:
			for (int x = 1; x <= M; ++x)
				for (int y = 1; y <= M; ++y)
					for (int z = 1; z <= M; ++z) {
						Set<Integer> tmpSet = new HashSet<Integer>();
						for (int k : set)
							tmpSet.add(k);
						tmpSet.remove(1);
						tmpSet.remove(x); tmpSet.remove(y); tmpSet.remove(z);
						tmpSet.remove(x*y); tmpSet.remove(y*z); tmpSet.remove(z*z);
						tmpSet.remove(x*y*z);
						if (tmpSet.isEmpty()) {
							done = true;
//							System.out.println("" + x + y + z);
							out.write("" + x + y + z + "\n");
							break outer;
						}
					}
			
			if (!done)
//				System.out.println("111");
				out.write("111\n");
		}
		
		out.close();
	}
}
