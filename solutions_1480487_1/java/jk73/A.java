import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class A {

    public static void main(String[] args) throws Throwable {
	//       BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/jk/A.in")));
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(reader.readLine());

        for (int c = 1; c <= numCases; c++) {
            solveCase(c, reader.readLine());
        }
    }

    private static void solveCase(int c, String line) {
        String[] split = line.split(" ");
        int n = Integer.parseInt(split[0]);
        int[] ss = new int[n];
        int x = 0;
        for (int i = 1; i <= n; i++) {
            int parseInt = Integer.parseInt(split[i]);
            x += ss[i - 1] = parseInt;
        }

	double dx = x * 2.0 / n;
	double xxxx = dx;
	int xx = 0;
	int m = 0;
        for (int i = 0; i < n; i++) {
	    if (ss[i] < dx) {
		xx += ss[i];
		m++;
	    }
        }
	dx = ((double) (x + xx)) / m; 
        System.out.print("Case #" + c + ":");
        for (int i = 0; i < n; i++) {
	    if (ss[i] >= xxxx) {
		System.out.print(" 0.000000");
	    } else {
		double xxx = (dx - ss[i]) / x;
		System.out.format(" %.6f", 100.0 * xxx);
	    }
        }
        System.out.println();
    }
}
