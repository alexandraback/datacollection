import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class ProblemA {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A-small-attempt2.in"));
//		Scanner sc = new Scanner(new File("A-large-1.in"));
//		Scanner sc = new Scanner(new File("A-large-2.in"));
//		Scanner sc = new Scanner(new File("A.in"));
		int cases = sc.nextInt();
		int count = 1;
		
		while(cases --> 0) {
			String line = sc.next();
			String[] elems = line.split("/");
			int p = Integer.parseInt(elems[0]);
			int q = Integer.parseInt(elems[1]);
			int result = 0;
			boolean found  = false;
			int i = 0;
			
			for(i = 0; i < 40 && !found; i++) {
//				System.out.println(p + "/" + q);
				if(q%2 != 0) {
					break;
				}
				if(p/(q/2) >= 1) {
					result++;
					found = true;
				} else {
					q = q/2;
					result++;
				}	
			}
			
			for(int j = i; j < 40; j++) {
//				System.out.println(p + "/" + q);
				if(q == 1)
					break;
				if(q%2 != 0) {
					found = false;
					break;
				}
				if(p/(q/2) >= 1) {
					q = q/2;
					p = p - q;
				} else {
					q = q/2;
				}
			}

			if(found)
				System.out.println("Case #" + count + ": " + result);
			else
				System.out.println("Case #" + count + ": impossible");
			
			count++;
		}
		
		sc.close();
	}
}
