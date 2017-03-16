import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class AA extends A {

	
	protected Set<Integer> getChildren(HashMap<Integer, Set<Integer>> hm, int c) {
		Set<Integer> set = hm.get(c);
		if (set==null) {
			set = new TreeSet<Integer>();
			hm.put(c, set);
		}
		return set;
	}
	
	protected Set<Integer> getParents(HashMap<Integer, Set<Integer>> hms, int c) {
		Set<Integer> set = hms.get(c);
		if (set==null) {
			set = new TreeSet<Integer>();
			hms.put(c, set);
		}
		return set;
	}
	
	protected boolean addParent(HashMap<Integer, Set<Integer>> hm, int c, int parent) {
		Set<Integer> set = getParents(hm, c);
		if (set.contains(parent)) {
			return true;
		}
		set.add(parent);
		return false;
	}
	
	protected void addChild(HashMap<Integer, Set<Integer>> hms, int parent, int c) {
		Set<Integer> set = getChildren(hms, parent);
		set.add(c);
	}
	

	protected boolean addParent(HashMap<Integer, Set<Integer>> hm,HashMap<Integer, Set<Integer>> hms, int me, int parent) {
		Set<Integer> nwgparents = getParents(hm, parent);
		Set<Integer> cn = getChildren(hms, me);
		
		//me
		if (addParent(hm, me, parent)) return true;
		for (int gp : nwgparents) {
			if (addParent(hm, me, gp)) return true;
		}
		
		//sons
		for (int c : cn) {
			if (addParent(hm, c, parent)) return true;
			for (int gp : nwgparents) {
				if (addParent(hm, c, gp)) return true;
			}
		}
		
		//newgparents
		for (int gp : nwgparents) {
			addChild(hms, gp, me);
			for (int s : cn) {
				addChild(hms, gp, s);
			}
		}
		
		//parent
		addChild(hms, parent, me);
		for (int s : cn) {
			addChild(hms, parent, s);
		}
		
		return false;
	}
	
	protected String run(Scanner s, Object dummy) {
		int n = s.nextInt();
		return run(n, s);
	}
	
	protected String run(int classes, Scanner s) {
		HashMap<Integer, Set<Integer>> hm = new HashMap<Integer, Set<Integer>>();
		HashMap<Integer, Set<Integer>> hms = new HashMap<Integer, Set<Integer>>();
		
		boolean ret = false;
		for (int c=0; c<classes; c++) {
			int nparents = s.nextInt();
			for (int p=0; p<nparents; p++) {
				int parent = s.nextInt();
				if (!ret)
					ret = addParent(hm, hms, c+1, parent);
			}
		}
		
		return ret?"Yes":"No";
	}

	public static void main(String[] args) throws IOException {

		File input = new File("input");
		File output = new File("output");

		AA t = new AA();
		t.run(input, output, 1);
	}
}
