import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;


public class B {
    static char[] a, b;
    static long bestA, bestB, bestMin;
    
	static void solveCase() {
        a = sc.next().toCharArray();
        b = sc.next().toCharArray();
        bestMin = Long.MAX_VALUE;
        rec(0, 0, 0);
        String format = "%0" + a.length + "d";
        format = format + " " + format;
        printf(format, bestA, bestB);
        printf("\n");
	}

    static void rec( int pos, long valA, long valB) {
        //printf("rec(%d %d %d)\n", pos, valA, valB);
        if (pos >= a.length) {
            if (Math.abs(valA - valB) < bestMin 
                    || (Math.abs(valA - valB) == bestMin &&  valA < bestA)
                    || (Math.abs(valA - valB) == bestMin &&  valA == bestA && valB < bestB)) {
                bestMin = Math.abs(valA - valB);
                bestA = valA;
                bestB = valB;
            }
            return;
        }
        int va, vb;
        if (valA > valB) {
            va = a[pos] == '?' ? 0 : a[pos]-'0';
            vb = b[pos] == '?' ? 9 : b[pos]-'0';
            rec(pos+1, 10*valA+va, 10*valB+vb);
        }
        else if (valA < valB) {
            va = a[pos] == '?' ? 9 : a[pos]-'0';
            vb = b[pos] == '?' ? 0 : b[pos]-'0';
            rec(pos+1, 10*valA+va, 10*valB+vb);
        }
        else {
            if (a[pos] == '?' && b[pos] == '?') {
                va = 0;
                vb = 1;
                rec(pos+1, 10*valA+va, 10*valB+vb);
                va = 1;
                vb = 0;
                rec(pos+1, 10*valA+va, 10*valB+vb);
                va = 0;
                vb = 0;
                rec(pos+1, 10*valA+va, 10*valB+vb);
            }
            else if (a[pos] == '?') {
                vb = b[pos] - '0';
                for (va = vb-1; va <= vb+1; va++) {
                    if (va >= 0 && va <= 9) {
                        rec(pos+1, 10*valA+va, 10*valB+vb);
                    }
                }
            }
            else if (b[pos] == '?') {
                va = a[pos] - '0';
                for (vb = va-1; vb <= va+1; vb++) {
                    if (vb >= 0 && vb <= 9) {
                        rec(pos+1, 10*valA+va, 10*valB+vb);
                    }
                }
            }
            else {
                va = a[pos] - '0';
                vb = b[pos] - '0';
                rec(pos+1, 10*valA+va, 10*valB+vb);
            }
        }
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