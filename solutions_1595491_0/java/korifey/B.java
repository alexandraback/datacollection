package gcj2012.qual;


import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

import common.AbstractRunner;
import common.AbstractRunner.SIZE;

public class B extends AbstractRunner {
	
	public void handleCase(int caseNumber) throws Exception {
		int n = scanner.nextInt();
		int s = scanner.nextInt();
		int p = scanner.nextInt();
		
		//if (p == 0)
		
		int res = 0;		
		for (int i=0; i<n; i++) {
			int x = scanner.nextInt();
			x -= p;
			if (x >= 0) {
				if (2*(p-1) <= x) res++;
				else if (s > 0 && 2*(p-2) <= x) {
					s--;
					res++;
				}
			}
		}
		out.write(Integer.toString(res)+"\n");
	}

	public static void main(String[] args) throws Exception {
		new B().init(SIZE.small).execute();
	}
		
}
