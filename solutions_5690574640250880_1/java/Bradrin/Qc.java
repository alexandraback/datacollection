import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Qc {
	
	public void print(Scanner scan, PrintWriter out, int rows, int cols, int rowsFilled, int colsFilled, int rowExtra, int colExtra, boolean flip) {
		if (flip) {
			int temp = rows;
			rows = cols;
			cols = temp;
			temp = rowsFilled;
			rowsFilled = colsFilled;
			colsFilled = temp;
			temp = rowExtra;
			rowExtra = colExtra;
			colExtra = temp;
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i == 0 && j == 0) {
					System.out.print("c");
					out.print("c");
				} else if (i < rowsFilled && j < colsFilled) {
					System.out.print(".");
					out.print(".");
				} else if (i == rowsFilled && j < rowExtra) {
					System.out.print(".");
					out.print(".");
				} else if (j == colsFilled && i < colExtra){
					System.out.print(".");
					out.print(".");
				} else {
					System.out.print("*");
					out.print("*");
				}
			}
			System.out.println();
			out.println();
		}
	}
	
	public void printSpecial(Scanner scan, PrintWriter out, int rows, int cols) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i == 0 && j == 0) {
					System.out.print("c");
					out.print("c");
				} else if (i < rows-2) {
					System.out.print(".");
					out.print(".");
				} else if (i == rows-2 && j < cols-1) {
					System.out.print(".");
					out.print(".");
				} else if (i == rows-1 && j < 2) {
					System.out.print(".");
					out.print(".");
				} else {
					System.out.print("*");
					out.print("*");
				}
			}
			System.out.println();
			out.println();
		}
	}
	
	public void solve(Scanner scan, PrintWriter out) {
		System.out.println();
		out.println();
		int R = scan.nextInt();
		int C = scan.nextInt();
		int M = scan.nextInt();
		
		int s = R*C-M;
		
		if (s == 1) {
			print(scan, out, R, C, 1, 1, 0, 0, false);
			return;
		}
		if (R == C && R > 3 && R-M == 1) {
			printSpecial(scan, out, R, C);
			return;
		}
		
		boolean flip = false;
		int r = R;
		int c = C;
		for (int i = 0; i < 2; i++) {
			for (int h = 2; h <= r; h++) {
				int w = s/h;
				int wExtra = s%h;
				if (w == c && wExtra == 0) {
					print(scan, out, r, c, h, w, 0, wExtra, flip);
					return;
				}
				if (w >= 2 && w < c && (wExtra >= 2 || wExtra == 0)) {
					print(scan, out, r, c, h, w, 0, wExtra, flip);
					return;
				}
			}
			r = C;
			c = R;
			flip = !flip;
		}
		
		System.out.println("Impossible");
		out.println("Impossible");
	}
	
	public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(new FileReader("inputqcl.in"));
        PrintWriter out = new PrintWriter("outputqcl.txt");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new Qc().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}