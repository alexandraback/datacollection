import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;


public class A {
	static void solveCase() {
        int R = sc.nextInt();
        int C = sc.nextInt();
        int W = sc.nextInt();
        
        int perRow = (int)Math.floor((double)C / W);
        int extraHit = C % W > 0 ? W : W-1;
        printf("%d\n", R * perRow + extraHit);
	}
	
	
	static void printf(String f, Object... args) {
		System.out.printf(f, args);
	}
	
	static void p(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	
	static Scanner sc;
	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(args.length > 0 ? new FileInputStream(args[0]) : System.in);
		int numCases = sc.nextInt();
		for (int nCase=1; nCase<=numCases; nCase++) {
			printf("Case #%d: ", nCase);
			solveCase();
		}
		sc.close();
	}

}