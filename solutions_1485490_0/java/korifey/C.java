package gcj2012.round1c;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;

import org.korifey.ffalg.NumberTheory;
import org.korifey.ffalg.Probabilities;

import common.AbstractRunner;
import common.AbstractRunner.SIZE;

public class C extends AbstractRunner {
	
	public int[] A;
	public int[] B;
	public long[] a;
	public long[] b;
	
	long[][] left;
	long[][] leftRest;
	
	long[][] right;
	long[][] rightRest;
	
	int n, m;
	
	public long rec(int i, int j, long rest, boolean isLeft) {
		if (rest < 0) throw new IllegalArgumentException();
		if (rest == 0 && !isLeft) throw new IllegalArgumentException();
		if (i > n || j>m ) return 0;
		if (i == n && (rest == 0 || !isLeft)) return 0;
		if (j == m && (rest == 0 || isLeft)) return 0;
		
		if (isLeft && leftRest[i][j] >= rest) return left[i][j];
		if ((!isLeft) && rightRest[i][j] >= rest) return right[i][j];
			
		long best;
		if (rest == 0) {
			if (A[i] == B[j]) {
				if (a[i] > b[j]) {
					best = b[j] + rec(i+1, j+1, a[i] - b[j], true);
				} else if (a[i] == b[j]) {
					best = a[i] + rec(i+1, j+1, 0, true);
				} else {
					best = a[i] + rec(i+1, j+1, b[j]-a[i], false);
				}
			} else {
				best = 0;
				for (int x = i; x<n; x++) {
					for (int y = j; y<m; y++) {
						if (A[x] == B[y]) best = Math.max(rec(x, y, 0, true), best);
					}
				}
			}
			
		} else {
			if (isLeft) {
				if (A[i-1] == B[j]) {
					if (rest > b[j]) {
						best = b[j] + rec(i, j+1, rest-b[j], true);
				    } else if (rest == b[j]) {
						best = rest + rec(i, j+1, 0, true);
					} else {
						best = rest + rec(i, j+1, b[j] - rest, false);
					}
					
				} else {
					best = rec(i, j, 0, true);
					for (int y=j+1; y<m; y++) {
						best = Math.max(best, rec(i,y,rest, isLeft));
					}
				}
				
			} else {
				if (A[i] == B[j-1]) {
					if (rest > a[i]) {
						best = a[i] + rec(i+1, j, rest-a[i], false);
					} else {
						best = rest + rec(i+1, j, a[i] - rest, true);
					}
				} else {
					best = rec(i, j, 0, true);
					for (int x=i+1; x<n; x++) {
						best = Math.max(best, rec(x, j, rest, isLeft));
					}
				}
			}
		}
		
		//System.out.println("best "+i+","+j+" "+rest+" "+isLeft+" = "+best);
		
		if (isLeft) {
			left[i][j] = best;
			leftRest[i][j] = rest;
		} else {
			right[i][j] = best;
			rightRest[i][j] = rest;
			
		}
		return best;
	}
	
	@Override
	public void handleCase(int caseNumber) throws Exception {
		System.out.println("Case: "+caseNumber);
		n = scanner.nextInt();
		m = scanner.nextInt();
		
		a = new long[n];
		A = new int[n];
		
		b = new long[m];
		B = new int[m];
		
		for (int i=0; i<n; i++) {
			a[i] = scanner.nextLong();
			A[i] = scanner.nextInt();			
		}
		for (int i=0; i<m; i++) {
			b[i] = scanner.nextLong();
			B[i] = scanner.nextInt();
		}
		
		n = 0;
		for (int i=1; i<a.length; i++) {
			if (A[i] == A[n]) {
				a[n] += a[i];
			} else {
				a[++n] = a[i];
				A[n] = A[i]; 
			}
		}
		n++;
		
		m = 0;
		for (int j=1; j<b.length; j++) {
			if (B[j] == B[m]) {
				b[m] += b[j];
			} else {
				b[++m] = b[j];
				B[m] = B[j]; 
			}
		}
		m++;
		
		left = new long[n+1][m+1];
		leftRest = new long[n+1][m+1];
		right = new long[n+1][m+1];
		rightRest = new long[n+1][m+1];
		
		for (int i=0; i<=n; i++) {
			for (int j=0; j<=m; j++) {
				leftRest[i][j] = -1;
				rightRest[i][j] = -1;
			}
		}
		
		out.write(rec(0, 0, 0, true)+"\n");				
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		new C().init(SIZE.small).execute();
	}

}
