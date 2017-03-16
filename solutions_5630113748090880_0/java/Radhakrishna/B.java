package org.rk.onea;

import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class B {
	public void solve(String in) throws Exception {
		Scanner sc = new Scanner(new File(in));
		int N = sc.nextInt();
		HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
		for(int i=0;i<N;i++) {
			int C = sc.nextInt();
			int L = 2 * C - 1;
			hm.clear();
			for(int j=0;j<L;j++) {
				for(int k=0;k<C;k++) {
					int key = sc.nextInt();
					if(hm.containsKey(key)) {
						hm.put(key, hm.get(key)+1);
					} else {
						hm.put(key,1);
					}
				}
			}
			ArrayList<Integer> missing = new ArrayList<Integer>();
			for(Integer key : hm.keySet()) {
				if(hm.get(key) % 2 == 1) {
					missing.add(key);
				}
			}
			Collections.sort(missing);
			System.out.print("Case #"+(i+1)+":");
			for(Integer d : missing) {
				System.out.print(" "+d);
			}
			System.out.println("");
		}
		sc.close();
	}
}
