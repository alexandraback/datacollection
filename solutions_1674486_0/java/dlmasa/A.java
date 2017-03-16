package A;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class A {
	
	public static void main(String[] args) throws Exception {
		int totalCase = 0;
		FileInputStream is = null;
		try {
			is = new FileInputStream(args[0]);
			Scanner scan = new Scanner(is);
			totalCase = scan.nextInt();
			scan.nextLine();
			for (int i = 0; i < totalCase; i++) {
				int n = scan.nextInt();
				HashSet<Integer> candidateSet = new HashSet<Integer>();
				HashMap<Integer, List<Integer>> rp = new HashMap<Integer, List<Integer>>();
				for (int j = 0; j < n; j++) {
					int m = scan.nextInt();
					
					for (int k = 0; k < m; k++) {
						int l = scan.nextInt();
						List<Integer> listR = null;
						if (!rp.containsKey(l)) {
							listR = new ArrayList<Integer>();
							rp.put(l, listR);
						} else {
							listR = rp.get(l);
							// ìØÇ∂ëJà⁄êÊÇÃÉpÉXÇ™2Ç¬à»è„Ç†ÇÈ
							candidateSet.add(l);
						}
						listR.add(j+1);
					}
				}
				solve(i+1, n, candidateSet, rp);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} finally {
			try {
				is.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	private static void solve(int testCase, int n,  HashSet<Integer> candidateSet, HashMap<Integer, List<Integer>> rp) throws Exception {
		String ans = "No";
		while(!candidateSet.isEmpty()) {
			Iterator<Integer> iter = candidateSet.iterator();
			int target = iter.next();
			candidateSet.remove(target);
			HashSet<Integer> set = new HashSet<Integer>();
			if (hasSameNodeWithDF(target, rp, set)) {
				ans = "Yes";
				break;
			}
		}
		System.out.printf("Case #%d: %s\n", testCase, ans);
	}

	private static boolean hasSameNodeWithDF(int target,
			HashMap<Integer, List<Integer>> rp, HashSet<Integer> set) throws Exception {
		List<Integer> list = rp.get(target);
		try {
			for (int i = 0; i < list.size(); i++) {
				find(list.get(i), rp, set);
			}
		} catch (Exception e) {
			if ("FOUND".equals(e.getMessage())){
				return true;
			}
			throw e;
		}
		return false;
	}

	private static void find(Integer integer,
			HashMap<Integer, List<Integer>> rp, HashSet<Integer> set) throws Exception {
		if (set.contains(integer)) {
			throw new Exception("FOUND");
		}
		set.add(integer);
		if (!rp.containsKey(integer)) {
			return;
		}
		List<Integer> list = rp.get(integer);
		for (int i = 0; i < list.size(); i++) {
			find(list.get(i), rp, set);
		}
		
	}
}
