import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws IOException {
		new A();
	}
	
	public A() throws IOException {
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A-small.txt"));
		int amountOfTasks = in.nextInt();
		for (int task = 0; task < amountOfTasks; task++) {
			System.out.println("Case: #" + (task+1));
			
			String name = in.next();
			int n = in.nextInt();
			
			int total = 0;
			
			for (int i = 0; i < (name.length() - n + 1); i++) {
				for (int j = (i+n); j <= name.length(); j++) {
					if (opeenvolgend(n, name.substring(i, j))) total++;
				}
			}
			
			out.write("Case #" + (task+1) + ": " + total);
			out.newLine();
		}
		in.close();
		out.close();
	}
	
	private boolean opeenvolgend(int n, String name) {
		int length = 0;
		for (int i = 0; i < name.length(); i++) {
			if (name.charAt(i) != 'a' && name.charAt(i) != 'e' && name.charAt(i) != 'i' && name.charAt(i) != 'u' && name.charAt(i) != 'o')
				length ++;
			else
				length = 0;
			if (length == n) return true;
		}
		return false;
	}
}