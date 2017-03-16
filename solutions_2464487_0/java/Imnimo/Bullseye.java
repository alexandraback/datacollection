import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Bullseye {
	public static void main(String[] args) throws FileNotFoundException {

		Scanner s = new Scanner(new File("input.txt"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int c = 1;c<=numCases;c++) {
			String line = s.nextLine();
			String[] items = line.split(" ");
			int rad = Integer.parseInt(items[0]);
			int paint = Integer.parseInt(items[1]);
			int result = solve(rad,paint);
			System.out.println("Case #" + c + ": " + result);
		}
	}
	public static int solve(int rad,int paint) {
		int total = 0;
		int count = 0;
		while(total<=paint) {
			int spent = (rad+1)*(rad+1) - rad*rad;
			total+=spent;
			rad+=2;
			count++;
		}
		return (count-1);
	}
}
