import java.util.*;

public class BFFsilly {

	static int max = 1;
	static HashMap<Integer, Integer> bffmap;

	public static void permutation(ArrayList<Integer> array, ArrayList<Integer> remaining) {
		//System.out.println(array);
		//System.out.println(remaining);
		int alength = array.size();
		if (max < alength) {
			boolean success = true;
			for (int i = 0; i < alength; i++) {
				int check = array.get(i);
				int above;
				int below;
				if (i != 0 && i != alength-1) {
					above = array.get(i+1);
					below = array.get(i-1);
				}
				else if (i == 0) {
					above = array.get(i+1);
					below = array.get(alength-1);
				}
				else {
					above = array.get(0);
					below = array.get(i-1);
				}
		

				if (above == bffmap.get(check) || below == bffmap.get(check)) {
					continue;
				}
				else {
					success = false;
					break;
				}
			}
			if (success) {
				max = alength;
			}
		}

		int length = remaining.size();
		if (length == 0) return;
		for (int i = 0; i < length; i++) {
			ArrayList<Integer> copy = new ArrayList<Integer>(remaining);
			ArrayList<Integer> copyA = new ArrayList<Integer>(array);
			copyA.add(copy.remove(i));
			permutation(copyA, copy);
		}
	}


public static void main(String[] args) {

	Scanner in = new Scanner(System.in);
	int cases = in.nextInt();

	for (int c = 0; c < cases; c++) {

		int kids = in.nextInt();
		bffmap = new HashMap<Integer, Integer>();
		max = 1;

		for (int i = 0; i < kids; i++) {
			int read = in.nextInt();
			bffmap.put(i, read-1);
		}

		ArrayList<Integer> empty = new ArrayList<Integer>();
		ArrayList<Integer> full = new ArrayList<Integer>();
		for (int i = 0; i < kids; i++) full.add(i);

		permutation(empty, full);
		System.out.println("Case #" + (c+1) + ": " + max);

	} //endcases

} //em

}  //EM
