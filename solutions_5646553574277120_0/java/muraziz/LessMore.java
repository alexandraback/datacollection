import java.util.*;

public class LessMore {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for (int t=0; t<T; t++) {
			int C = scan.nextInt();
			int D = scan.nextInt();
			int V = scan.nextInt();
			int[] denominations = new int[D];
			for (int d=0; d<D; d++) {
				denominations[d] = scan.nextInt();
			}
			solve(t+1, C, D, V, denominations);
		}
	}

	private static void solve(int caseNo, int C, int D, int V, int[] denom) {
		ArrayList<Integer> possibleVals = new ArrayList<Integer>();
		for (int i=0; i<D; i++) {
			int currentDenom = denom[i];
			int len = possibleVals.size();
			for (int j=0; j<len; j++) {
				int val = possibleVals.get(j);
				if (val + currentDenom <= V) {
					possibleVals.add(val + currentDenom);
					//System.out.println("---multiple-----> j="+j+", val="+val+", currentDenom="+currentDenom+", val+currentDenom="+(val+currentDenom));
				}
			}
			//System.out.println("---single----> "+currentDenom+", possibleVals.size()="+possibleVals.size());
			possibleVals.add(currentDenom);
		}
		TreeSet<Integer> sortedVals = new TreeSet<Integer>(possibleVals);
		int denomsAdded = 0;
		while (!full(sortedVals, V)) {
			denomsAdded++;
			int nextDenom = getNextDenom(sortedVals, V);
			//System.out.println("getNextDenom() -> "+nextDenom);
			ArrayList<Integer> vals = new ArrayList<Integer>();
			for (int val : sortedVals) {
				if (val + nextDenom <= V) {
					vals.add(val+nextDenom);
					//System.out.println("vals_add (val+nextDenom) -> "+(val+nextDenom));
				}
			}
			vals.add(nextDenom);
			sortedVals.addAll(vals);
			/*for (int s : sortedVals) {
				System.out.println("after denom="+nextDenom+" added: "+s);
			}*/
		}
		System.out.println("Case #"+caseNo+": "+denomsAdded);
		/*for (int s : sortedVals) {
			System.out.println(s);
		}
		System.out.println();*/
	}

	private static boolean full(TreeSet<Integer> vals, int V) {
		for (int i=1; i<=V; i++) {
			if (!vals.contains(i)) {
				return false;
			}
		}
		return true;
	}

	private static int getNextDenom(TreeSet<Integer> vals, int V) {
		for (int i=1; i<=V; i++) {
			if (!vals.contains(i)) {
				return i;
			}
		}
		return -1;
	}
}