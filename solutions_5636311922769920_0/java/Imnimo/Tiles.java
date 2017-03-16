import java.io.File;
import java.util.Scanner;


public class Tiles {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("D-small-attempt0.in"));
		int numCases = Integer.parseInt(s.nextLine());
		
		for(int c = 1;c<=numCases;c++) {
			String line = s.nextLine();
			String[] items = line.split("\\s+");
			int k = Integer.parseInt(items[0]);
			System.out.print("Case #" + c +":");
			for(int i = 1;i<=k;i++) {
				System.out.print(" " + i);
			}
			System.out.println();
		}
		
	}
}
