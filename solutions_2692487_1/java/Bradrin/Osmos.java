import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
	
	public void solve(Scanner scan, PrintWriter out) {
		int a = scan.nextInt();
		int n = scan.nextInt();
		int array[] = new int[n];
		for (int i = 0; i < n; i++) {
			array[i] = scan.nextInt();
		}
		int result = 0;
		Arrays.sort(array);
		int i = 0;
		int temp[] = new int[n];
		if (a <= 1) {
			System.out.println(n);
			out.println(n);
			return;
		}
		while (i < n) {
			if (array[i] < a) {
				temp[i] = Integer.MAX_VALUE;
				a += array[i];
				i++;
			}
			else {
				temp[i] = result + n-i;
				while (a <= array[i]) {
					a = 2*a - 1;
					result++;
				}
				a += array[i];
				i++;
			}
		}
		for (int k = 0; k < n; k++) {
			if (temp[k] < result) {
				result = temp[k];
			}
		}
		System.out.println(result);
		out.println(result);
	}
	
	public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(new FileReader("input2.in"));
        PrintWriter out = new PrintWriter("output.txt");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new Osmos().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}