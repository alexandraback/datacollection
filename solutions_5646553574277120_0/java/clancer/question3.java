package gcj;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;


public class question3 implements Runnable {

	
	Integer C,D,V;
	
	int min;
	
	public int brute_force(boolean[] coins, int added) {
		if (added > min) {
			return 30;
		}
		if (can_make(coins)) {
			//System.out.println("here" + min);
			/*if (added < min) {
				for (int i = 1; i < 31; i++) {
					if (coins[i]) {
						System.out.print(i + " ");
					}
				}
				System.out.println();
			}*/
			return added;
		}
		if (added+1 > min) {
			return 30;
		}
		for (int i = 1; i <= V; i++) {
			if (coins[i] == false) {
				boolean[] temp = Arrays.copyOf(coins, 31);
				temp[i] = true;
				int ret = brute_force(temp, added+1);
				//System.out.println(ret);
				if (ret < min) {
					min = ret;
				}
			}
		}
		return min;
	}
	
	public boolean can_make(boolean[] coins) {
    	boolean[] can_make_n = new boolean[V+1];
    	
    	for (int i = 1; i <= V; i++) {
    		can_make_n[i] = false;
    	}
    	
    	for (int i = 1; i < 30; i++) {
    		if (coins[i]) {
    			ArrayList<Integer> made = new ArrayList<Integer>();
    			made.add(i);
	    		can_make_n[i] = true;
	    		for (int v = i+1; v <= V; v++) {
	    			if (v-i > 0 && !made.contains(v-i)) {
	    				can_make_n[v] = can_make_n[v] || can_make_n[v-i];
	    				made.add(v);
	    			}
	    		}
    		}
    		
    	}
    	
    	boolean found = true;
    	for (int i = 1; i <= V; i++) {
    		found = found && can_make_n[i];
    	}
    	return found;
	}
	
	
	static HashMap<Integer,Integer> results = new HashMap<Integer,Integer>();
	public static void main(String[] args) throws FileNotFoundException, IOException, InterruptedException {	
		String file = "small3.in";
		ArrayList<Thread> ts = new ArrayList<Thread>();
		
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
		    String line;
		    Integer N = Integer.parseInt(br.readLine());
		    for (int n = 0; n < N; n++) {
		    	String[] CDV = br.readLine().split(" ");
		    	int C = Integer.parseInt(CDV[0]);
		    	int D = Integer.parseInt(CDV[1]);
		    	int V = Integer.parseInt(CDV[2]);
		    	
		    	String[] coins_s = br.readLine().split(" ");
		    	boolean[] coins = new boolean[31];
		    	for (int i = 0; i < 31; i++) {
		    		coins[i] = false;
		    	}
		    	
		    	for (int i = 0; i < D; i++) {
		    		coins[Integer.parseInt(coins_s[i])] = true;
		    	}
		    	
		    	
		    	Thread t = new Thread(new question3(C,D,V,coins,n));
		    	t.start();
		    	ts.add(t);

		    	

		    }
			for (Thread t : ts) {
				t.join();
			}
			
			for (int i = 0; i < N; i++) {
				System.out.println("Case #" + (i+1) + ": " + results.get(i));	
			}
		}
		

		

	}

	int my_n;
	boolean[] coins;
	public question3(int C, int D, int V, boolean[] coins, int n) {
		min = 30;
		this.C = C;
		this.D = D;
		this.V = V;
		this.coins = coins;
		this.my_n = n;
	}
	
	@Override
	public void run() {
		int ret = brute_force(coins, 0);
		results.put(my_n, ret);
	}
	
	
}
