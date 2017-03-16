package codejam;

//--------------------------------------
//Systematically generate combinations.
//--------------------------------------

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class CombinationGenerator {

	private int[] a;
	private int n;
	private int r;
	private long numLeft;
	private long total;

	// ------------
	// Constructor
	// ------------

	public CombinationGenerator(int n, int r) {
		if (r > n) {
			throw new IllegalArgumentException("group size("+r+") smaller than total elements ("+n+")");
		}
		if (n < 1) {
			throw new IllegalArgumentException();
		}
		this.n = n;
		this.r = r;
		a = new int[r];
		BigInteger nFact = getFactorial(n);
		BigInteger rFact = getFactorial(r);
		BigInteger nminusrFact = getFactorial(n - r);
		total = nFact.divide(rFact.multiply(nminusrFact)).longValue();
		reset();
	}

	// ------
	// Reset
	// ------

	public void reset() {
		for (int i = 0; i < a.length; i++) {
			a[i] = i;
		}
		numLeft = total;
	}

	// ------------------------------------------------
	// Return number of combinations not yet generated
	// ------------------------------------------------

	public long getNumLeft() {
		return numLeft;
	}

	// -----------------------------
	// Are there more combinations?
	// -----------------------------

	public boolean hasMore() {
		return numLeft > 0;
	}

	// ------------------------------------
	// Return total number of combinations
	// ------------------------------------

	public long getTotal() {
		return total;
	}

	// ------------------
	// Compute factorial
	// ------------------

	private static BigInteger getFactorial(int n) {
		BigInteger fact = new BigInteger("1");
		for (int i = n; i > 1; i--) {
			fact = fact.multiply(new BigInteger(i+""));
		}
		return fact;
	}

	// --------------------------------------------------------
	// Generate next combination (algorithm from Rosen p. 286)
	// --------------------------------------------------------

	public int[] getNext() {

		if (numLeft == total) {
			numLeft = numLeft - 1;
			return a;
		}

		int i = r - 1;
		while (a[i] == n - r + i) {
			i--;
		}
		a[i] = a[i] + 1;
		for (int j = i + 1; j < r; j++) {
			a[j] = a[i] + j - i;
		}

		numLeft = numLeft - 1;
		return a;

	}
	
	public static <T> ArrayList<ArrayList<T>> compute(List<T> array, int minSize, int maxSize, CombinationValidator<T> validator) {
		return compute(array, minSize, maxSize, validator, false);
	}

	public static <T> ArrayList<ArrayList<T>> compute(List<T> array, int minSize, int maxSize, CombinationValidator<T> validator, boolean findFirst) {
		
		ArrayList<ArrayList<T>> results = new ArrayList<ArrayList<T>>();
		
		for (int size = minSize; size <= maxSize; size++) {
			if (array.size() < size) continue;
			
			CombinationGenerator gen = new CombinationGenerator(array.size(), size);
			
			while (gen.hasMore()) {
				
				int[] indices = gen.getNext();
				ArrayList<T> combination = new ArrayList<T>(indices.length);
				
				for (int i = 0; i < indices.length; i++) {
					T elemt = array.get(indices[i]);
					
					combination.add(elemt);
				}
				
				if (validator == null) {
					results.add(combination);
				} else if (validator.isValid(combination)) {
					
					if (!results.contains(combination)) {
						results.add(combination);
					}
					
					if (findFirst) return results;
				}
			}

		}
		
		return results;
	}
	
}
