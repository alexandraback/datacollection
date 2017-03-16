package gcj2013.round1c;


import java.util.*;
import java.math.*;
import org.korifey.ffalg.*;

import sun.awt.windows.WTrayIconPeer;

import common.AbstractRunner;

public class C extends AbstractRunner {
		
	
	@Override
	public void handleCase(int caseNumber) throws Exception {		
		int n = scanner.nextInt();
		Pair<Integer, Integer>[] attacks = new Pair [n*10];
		int w[] = new int[n];
		int e[] = new int[n];
		int s[] = new int[n];
		int delta_p[] = new int[n];
		int delta_s[] = new int[n];
		
		int nattacks = 0;
		
		for (int i=0; i<n; i++) {			
			int di = scanner.nextInt();
			int ni = scanner.nextInt();
			w[i] = scanner.nextInt();
			e[i] = scanner.nextInt();
			s[i] = scanner.nextInt();
			
			int delta_di = scanner.nextInt();
			for (int j=0; j<ni; j++) attacks[nattacks++] = new Pair(di+j*delta_di, i);
			
			delta_p[i] = scanner.nextInt();
			delta_s[i] = scanner.nextInt();
		}
				
		Arrays.sort(attacks, 0, nattacks, Pair.DEFAULT_COMPARATOR);
		
		int offset = 250;
		int[] wall = new int[500];
		int[] newwall = wall.clone();
		
		int res = 0;		
		int pday = -1;
		for (int i=0; i<nattacks; i++) {			
			int day = attacks[i].A();
			if (day != pday) {
				wall = newwall.clone();
				pday = day;
			}
			int tribe = attacks[i].B();
			boolean success = false;
			for (int j=0; j < e[tribe] - w[tribe]; j++) {
				int pos = offset+w[tribe]+j;
				if (wall[pos] < s[tribe]) {
					success = true;
					newwall[pos] = Math.max(newwall[pos], s[tribe]);
				}
			}
			if (success) res++;
			s[tribe] += delta_s[tribe];
			w[tribe] += delta_p[tribe];
			e[tribe] += delta_p[tribe];
		}
		
		out.write(res+"\n");
	}
	
	public static void main(String[] args) throws Exception {
		new C().init(SIZE.small).execute();
	}
}

