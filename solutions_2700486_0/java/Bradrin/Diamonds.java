import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Diamonds {
	
	static int dim = 500;
	static int[][] array = new int[dim][dim];
	
	public static void preprocess() {
		array[0][0] = 1;
		for (int i = 1; i < dim; i++) {
			array[i][0] = 1;
			array[i][i] = 1;
			for (int j = 1; j < i; j++) {
				array[i][j] = array[i-1][j-1] + array[i-1][j];
			}
		}
		
	}
	
	public void solve(Scanner scan, PrintWriter out) {
		int n = scan.nextInt();
		int x = scan.nextInt();
		int y = scan.nextInt();
		if ((x + y) % 2 != 0) {
			System.out.println(0);
			out.println(0);
			return;
		}
		int line = (Math.abs(x)+y)/2;
		int val = 2*line*line + 3*line + 1;
		int temp = line-1;
		temp = 2*temp*temp + 3*temp + 1;
		if (n >= val) {
			System.out.println(1.0);
			out.println(1.0);
			return;
		}
		if (n <= temp) {
			System.out.println(0.0);
			out.println(0.0);
			return;
		}
		n -= temp;
		int max = line*2;
		if (y == max && n < 2*max +1) {
			System.out.println(0.0);
			out.println(0.0);
			return;
		}
		if (n >= max + y + 1) {
			System.out.println(1.0);
			out.println(1.0);
			return;
		}
		if (n < y) {
			System.out.println(0.0);
			out.println(0.0);
			return;
		}
		double prob = Math.pow(0.5, n);
		int total = 0;
		for (int i = y+1; i <= n; i++) {
			total += array[n][i];
		}
		System.out.println(prob*total);
		out.println(prob*total);
	}		
	
	public static void main(String[] args) throws Exception {
		preprocess();
        Scanner scan = new Scanner(new FileReader("input.in"));
        PrintWriter out = new PrintWriter("output.txt");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new Diamonds().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}