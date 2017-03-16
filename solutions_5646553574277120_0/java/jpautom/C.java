import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;


public class C {
	static void solveCase() {
        int C = sc.nextInt();
        int D = sc.nextInt();
        int V = sc.nextInt();
        
        List<Integer> max = new ArrayList<>();
        max.add(0);
        List<Integer> d = new ArrayList<>();
        for (int i = 0; i < D; i++) {
            d.add(sc.nextInt());
        }
        d.add(V + 1);
        int added = 0;
        for (int i = 0; i < d.size(); ) {
            int currentD = d.get(i);
            int prev = max.get(i);
            if (currentD > prev + 1) {
                d.add(i, prev + 1);
                added++;
                continue;
            }
            else {
                max.add(C * currentD + max.get(i));
                i++;
            }
        }
        printf("%d\n", added);
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