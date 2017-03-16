import java.io.*;
import java.util.*;

public class D3 {
	public static void main(String args[]) {
		try {
			InputStreamReader isr = null;
			try {
				isr = new InputStreamReader(System.in, "UTF-8");
				BufferedReader br = null;
				try {
					br = new BufferedReader(isr);
					new D3().go(br);
				} finally {
					if (br != null) br.close();
				}
			} finally {
				if (isr != null) isr.close();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public void go(BufferedReader br) throws Exception {
		int num = Integer.parseInt(br.readLine());
		String lines[] = null;
		for (int n = 1; n <= num; n++) {
			Hashtable<Integer, Integer> needHash =
				new Hashtable<Integer, Integer>();
			Hashtable<Integer, Integer> haveHash =
				new Hashtable<Integer, Integer>();
			HashSet<String> dameHash = new HashSet<String>();

			lines = br.readLine().split(" ");
			int nkey = Integer.parseInt(lines[0]);
			int nbox = Integer.parseInt(lines[1]);
			int nget = 0;
			ArrayList<Integer> keys = new ArrayList<Integer>();
			lines = br.readLine().split(" ");
			for (int i = 0; i < lines.length; i++) {
				keys.add(Integer.parseInt(lines[i]));
				addHash(haveHash, Integer.parseInt(lines[i]));
			}
			int boxes[] = new int[nbox];
			ArrayList gets[] = new ArrayList[nbox]; 
			for (int i = 0; i < nbox; i++) {
				lines = br.readLine().split(" ");
				boxes[i] = Integer.parseInt(lines[0]);
				nget = Integer.parseInt(lines[1]);
				gets[i] = new ArrayList<Integer>();
				for (int j = 0; j < nget; j++) {
					gets[i].add(Integer.parseInt(lines[j + 2]));
					addHash(haveHash, Integer.parseInt(lines[j + 2]));
				}
			}

			for (int i = 0; i < boxes.length; i++)
				addHash(needHash, boxes[i]);

/*
System.out.println("have=" + haveHash);
System.out.println("need=" + needHash);
*/

			boolean canSolve = true;
			Enumeration e = needHash.keys();
			while (e.hasMoreElements()) {
				Integer a = (Integer)e.nextElement();
				int needNum = needHash.get(a);
				int haveNum = haveHash.get(a);
				if (needNum > haveNum)
					canSolve = false;
			}

			int indexes[] = sortGets(gets);

/*
			System.out.println("keys=" + keys);
			for (int i = 0; i < nbox; i++)
				System.out.println(boxes[i] + ":" + gets[i]);
*/

			ArrayList<Integer> selects = new ArrayList<Integer>();

			if (!canSolve)
				System.out.println("Case #" + n + ": IMPOSSIBLE");
			else if (!solve(n, keys, boxes, selects, gets, indexes, dameHash))
				System.out.println("Case #" + n + ": IMPOSSIBLE");
		}
	}

	public int[] sortGets(ArrayList gets[]) {
		int sizes[] = new int[gets.length];
		for (int i = 0; i < gets.length; i++)
			sizes[i] = gets[i].size();

		int rets[] = new int[gets.length];

		for (int i = 0; i < sizes.length; i++) {
			int max = -1;
			for (int j = 0; j < gets.length; j++) {
				if (sizes[j] > max) {
					max = sizes[j];
					rets[i] = j;
				}
			}
			sizes[rets[i]] = -2;
		}

		return rets;
	}

	public void addHash(Hashtable<Integer, Integer> hash, int n) {
		Integer a = hash.get(n);
		if (a == null)
			a = new Integer(1);
		else
			a = new Integer(a.intValue() + 1);
		hash.put(n, a);
	}


	public boolean solve(int n, ArrayList<Integer> keys, int boxes[],
		ArrayList<Integer> selects, ArrayList gets[], int indexes[],
		HashSet<String>dameHash) {

		Integer trySelects[] = selects.toArray(new Integer[0]);
		Arrays.sort(trySelects);
		String tryPattern = Arrays.toString(trySelects);
		if (dameHash.contains(tryPattern)) {
//System.out.println("match");
			return false;
		}

		// Solved
		if (selects.size() == boxes.length) {
			System.out.print("Case #" + n + ":");
			for (int i = 0; i < selects.size(); i++)
				System.out.print(" " + (selects.get(i) + 1));
			System.out.println();
			return true;
		}

		int nextKey = 0;
		for (int i = 0; i < boxes.length; i++) {
			nextKey = boxes[i];
			if (nextKey > 0) {
				if (keys.contains(nextKey)) {
					ArrayList<Integer> ckeys = (ArrayList<Integer>)keys.clone();
					ArrayList<Integer> cselects =
						(ArrayList<Integer>)selects.clone();
					int cboxes[] = Arrays.copyOf(boxes, boxes.length);

					cboxes[i] = 0;
					cselects.add(i);
					int index = ckeys.indexOf(nextKey);
					ckeys.remove(index);
					ckeys.addAll(gets[i]);

					if (solve(n, ckeys, cboxes, cselects, gets, indexes, dameHash))
						return true;
				}
			}
		}

		Integer dameSelects[] = selects.toArray(new Integer[0]);
		Arrays.sort(dameSelects);
		String damePattern = Arrays.toString(dameSelects);
//System.out.println(damePattern);
		dameHash.add(damePattern);
		return false;
	}

	public ArrayList<Integer> copy(ArrayList<Integer> a) {
		ArrayList<Integer> b = new ArrayList<Integer>();
		for (int i = 0; i < a.size(); i++) {
			b.add(a.get(i).intValue());
		}
		return b;
	}
}
