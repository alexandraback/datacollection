import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemC {
    private static final String FILENAME = "C-small-attempt0";

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(FILENAME + ".in"));
        PrintWriter output = new PrintWriter(new FileWriter(FILENAME + ".out"));

        long start = System.currentTimeMillis();
        int testCase = input.nextInt();
        for (int t=1; t<=testCase; t++) {
        	int J = input.nextInt();
        	int P = input.nextInt();
        	int S = input.nextInt();
        	int K = input.nextInt();
        	boolean[][][] r = new boolean[10][10][10];
        	int[] jp = new int[100];
        	int[] js = new int[100];
        	int[] ps = new int[100];
        	for (int j=0; j<J; j++) {
        		for (int p=0; p<P; p++) {
        			for (int s=0; s<S; s++) {
        				r[j][p][s] = true;
        				jp[j*10+p] += 1;
        				js[j*10+s] += 1;
        				ps[p*10+s] += 1;
        			}
        		}
        	}

        	if (S > K) {
        		for (int j=0; j<J; j++) {
            		for (int p=0; p<P; p++) {
            			while (jp[j*10+p] > K) {
            				int maxjs = 0;
            				int maxps = 0;
            				int sIdx = -1;
            				for (int s=0; s<S; s++) {
            					if (!r[j][p][s]) continue;
            					if (js[j*10+s] > maxjs || js[j*10+s] == maxjs && ps[p*10+s] > maxps) {
            						maxjs = js[j*10+s];
            						maxps = ps[p*10+s];
            						sIdx = s;
            					}
            				}
            				if (sIdx >= 0) {
            					r[j][p][sIdx] = false;
            					jp[j*10+p]--;
            					js[j*10+sIdx]--;
            					ps[p*10+sIdx]--;
            				}
            			}
            		}
        		}
        	}
        	if (P > K) {
        		for (int j=0; j<J; j++) {
        			for (int s=0; s<S; s++) {
            			while (js[j*10+s] > K) {
            				int maxps = 0;
            				int pIdx = -1;
            				for (int p=0; p<P; p++) {
            					if (!r[j][p][s]) continue;
            					if (ps[p*10+s] > maxps) {
            						maxps = ps[p*10+s];
            						pIdx = p;
            					}
            				}
            				if (pIdx >= 0) {
            					r[j][pIdx][s] = false;
            					jp[j*10+pIdx]--;
            					js[j*10+s]--;
            					ps[pIdx*10+s]--;
            				}
            			}
            		}
        		}
        	}
        	if (J > K) {
        		for (int p=0; p<P; p++) {
        			for (int s=0; s<S; s++) {
            			while (ps[p*10+s] > K) {
            				for (int j=0; j<J; j++) {
            					if (!r[j][p][s]) continue;
            					r[j][p][s] = false;
            					jp[j*10+p]--;
            					js[j*10+s]--;
            					ps[p*10+s]--;
            					break;
            				}
            			}
            		}
        		}
        	}

        	String result = "";
        	int cnt = 0;
        	for (int j=0; j<J; j++) {
        		for (int p=0; p<P; p++) {
        			for (int s=0; s<S; s++) {
        				if (r[j][p][s]) {
        					cnt++;
        					result = result + (j+1) + " " + (p+1) + " " + (s+1) + "\n"; 
        				}
        			}
        		}
        	}
        	output.print("Case #"+t+": "+cnt+"\n" + result);
        }
        System.out.printf("Total duration: %dms\n", System.currentTimeMillis() - start);

        input.close();
        output.close();
	}
}
