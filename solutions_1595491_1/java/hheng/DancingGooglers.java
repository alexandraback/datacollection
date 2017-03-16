import java.util.*;
import java.io.*;
import java.lang.*;

class DancingGooglers { 
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = Integer.parseInt(sc.nextLine());
    
    for (int i=0; i<T; i++) {
    	String[] dat = sc.nextLine().split(" ");
    	int N = Integer.parseInt(dat[0]); // number of googlers
    	int S = Integer.parseInt(dat[1]); // number of surprising triplets
    	int p = Integer.parseInt(dat[2]); // required at least
    	int count = 0;
    	
    	List<Googler> g = new ArrayList<Googler>();
    	for (int j=0; j<N; j++) {
    		int score = Integer.parseInt(dat[3+j]);
    		
    		// Possible scores
    		int bestNonSurprising = 0;
    		int bestSurprising = 0;
    		for (int a=0; a<=10; a++) {
    			for (int b=0; b<=10; b++) {
    				int c = score - a - b;
    				if (c < 0 || c > 10) continue;
    				if (Math.abs(a-b) > 2 || Math.abs(b-c) > 2 || Math.abs(a-c) > 2) continue;
    				if (Math.abs(a-b) == 2 || Math.abs(b-c) == 2 || Math.abs(a-c) == 2) {
    					// surprising
    					bestSurprising = Math.max(bestSurprising, Math.max(a, Math.max(b, c)));
    				} else {
    					// no
    					bestNonSurprising = Math.max(bestNonSurprising, Math.max(a, Math.max(b, c)));
    				}
    			}
    		}
    		g.add(new Googler(bestNonSurprising, bestSurprising));
    	}
    	
    	Collections.sort(g);
    	//for (int k=0; k<g.size(); k++) System.out.println(g.get(k).bns+" "+g.get(k).bs);
    	boolean[] taken = new boolean[N];
    	for (int k=0; k<g.size(); k++) {
    		if (g.get(k).bns >= p) { taken[k] = true; count++; }
    	}
    	int countsurprise = 0;
    	for (int k=0; k<g.size(); k++) {
    		if (countsurprise == S) break;
    		if (!taken[k]) {
    			if (g.get(k).bs >= p) { taken[k] = true; count++; countsurprise++; }
    		}
    	}
    	System.out.println("Case #" + (i+1) + ": " + count);
    }
  }
}

class Googler implements Comparable<Googler> {
	int bns = 0, bs = 0; // Best Non, Best Surprising
	Googler(int a, int b) { bns = a; bs = b; }
	
	public int compareTo(Googler g) {
		if (this.bs != g.bs) return g.bs - this.bs;		
		return this.bns - g.bns;
	}
}



