import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	private static Scanner sc;
	private static PrintWriter out;
	
	private static int x,y, step;
	private static ArrayList<Character> a;
	
	public static void main(String args[]) throws FileNotFoundException {
		sc = new Scanner(new File("b.in"));
		out = new PrintWriter(new File("b.out"));
		
		int t = sc.nextInt();
		
		for (int i = 1; i <= t; i++) {
			int dx = sc.nextInt();
			int dy = sc.nextInt();
			
			a = new ArrayList();
			


			step = 1;
			
			out.print("Case #" + i + ": ");
			
			while (dx != 0 || dy != 0) {
				System.out.println(dx +" " + dy);
				if (dx == 0) {
					if (dy - step < 0) {
						dy += step; 
						a.add('S');
					} else {
						dy -= step;
						a.add('N');
					}
					
				} else {
					if (dx - step < 0) {
						dx += step; 
						a.add('W');
					} else {
						dx -= step;
						a.add('E');
					}
				}
				step++;
				
			}
			
			for (int k = 0; k < a.size(); k++) out.print(a.get(k));
			out.println();
		}
			
	
		sc.close();
		out.close();
	}
	
}
