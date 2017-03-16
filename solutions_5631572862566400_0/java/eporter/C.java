

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Queue;
import java.util.Scanner;

// Using the Google Guava library.
public class C {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/C-small-attempt0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
		    int n = in.nextInt();
		    int [] f = new int [n];
		    for (int i = 0; i < n; i++) {
		        f[i] = in.nextInt() - 1;
		    }
		    int maxSize = 0;
		    Queue<Circle> q = new ArrayDeque<>();
		    for (int i = 0; i < n; i++) {
	            for (int j = i+1; j < n; j++) {
	                q.add(new Circle(f, n, i, j));
//                    q.add(new Circle(f, n, j, i));
	            }
		    }
		    while (!q.isEmpty()) {
		        Circle cur = q.remove();
		        if (cur.isValid()) {
		            maxSize = Math.max(maxSize, cur.size);
		        }
                cur.addSuccessors(q);
		    }
			String ans = "Case #"+cs+": "+maxSize;
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
	
	private static class Circle {
	    int [] f;
	    int [] seats;
	    int n;
	    BitSet bs;
	    int size;
	    
	    public Circle(int [] f, int n, int i, int j) {
	        this.f = f;
	        this.n = n;
	        bs = new BitSet(n);
	        seats = new int[n];
            bs.set(i);
            bs.set(j);
            seats[0] = i;
            seats[1] = j;
	        size = 2;
	    }
	    
	    public Circle(int[] f, int n, BitSet bs, int [] seats, int size) {
            this.f = f;
            this.n = n;
            this.bs = bs;
            this.seats = seats;
            this.size = size;
        }

        public void addSuccessors(Queue<Circle> q) {
            if (size == n) {
                return;
            }
	        for (int i = 0; i < n; i++) {
	            int friendOfLast = f[seats[size-1]];
	            if (!bs.get(i) && (friendOfLast == seats[size-2] || friendOfLast == i)) {
	                BitSet bsc = (BitSet) bs.clone();
	                int [] seatsc = Arrays.copyOf(seats, n);
	                seatsc[size] = i;
	                bsc.set(i);
	                q.add(new Circle(f, n, bsc, seatsc, size+1));
	            }
	        }
	    }
        
        public boolean isValid() {
            int friendOfLast = f[seats[size-1]];
            int friendOfFirst = f[seats[0]];
            return size < 2 || ((friendOfLast == seats[size-2] || friendOfLast == seats[0]) && 
                    (friendOfFirst == seats[1] || friendOfFirst == seats[size-1]));
        }
	}
}
