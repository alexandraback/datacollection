import java.util.*;
import java.io.*;

public class B {
    FastScanner in;
    PrintWriter out;

    private int triangleNumber(int n) {
    	return ((n + 1) * n) / 2;
    }
    
    private int triangleBinSearch(int n) {
    	int left = 0, right = 7000;
    	int mid;
    	while (left + 1 < right) {
    		mid = (left + right) >> 1;
    		
    		if (triangleNumber(mid) > n) {
    			right = mid;
    		} else {
    			left = mid;
    		}
    	}
    	return left - (left % 2 == 0? 1 : 0);
    }
    
    int mx = 100;
    

    
    private double solutionForTest(int n, int x, int y) {
    	int curFullTr = triangleBinSearch(n);
    	if (x + y <= curFullTr) {
    		return 1.0;
    	} else if (x + y == curFullTr + 1 && x != 0) {
    		int height = y;
    		int left = n - triangleNumber(curFullTr);
    		int capacity = curFullTr + 2;
    		double success = 0, all = 0;
    		double[][] table = new double[capacity][capacity];
    		table[0][0] = 1;
    		for (int i = 0; i < capacity; i++) {
    			for (int j = 0; j < capacity; j++) {
    				if (i == j && j == capacity - 1) {
    					continue;
    				}
    				else if (i == capacity - 1) {
    					table[i][j + 1] += table[i][j];
    				} else if (j == capacity - 1) {
    					table[i + 1][j] += table[i][j];
    				} else {
    					double temp = table[i][j] / 2;
    					table[i + 1][j] += temp;
    					table[i][j + 1] += temp;
    				}
    			}
    		}
    		capacity--;
    		double ans = 0;
    		for (int i = y + 1; i <= left; i++) {
    			int j = left - i;
    			if (i > capacity || j > capacity) {
    				continue;
    			}
    			ans += table[i][j];
    		}
    		return ans;
    	} 
    	return 0;
    }
    
    public void solve() throws IOException {
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
        	int n = in.nextInt();
        	int x = in.nextInt();
        	int y = in.nextInt();
        	out.println("Case #" + (i + 1) + ": " + solutionForTest(n, x, y));
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-small-attempt1.in"));
            out = new PrintWriter(new File("output1.out"));
            
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new B().run();
    }
}