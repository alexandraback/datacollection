import java.util.*;
import java.io.*;
import java.lang.*;

class RecycledNumbers { 
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = Integer.parseInt(sc.nextLine());
    boolean[] taken = new boolean[2000001];
    
    for (int i=0; i<T; i++) {
    	int count = 0;
    	String[] dat = sc.nextLine().split(" ");
    	Arrays.fill(taken, false);
    	int digits = dat[0].length();
    	int A = Integer.parseInt(dat[0]);
    	int B = Integer.parseInt(dat[1]);
    	for (int j=A; j<=B; j++) {
    		if (!taken[j]) {
    			//System.out.println(j);
    			taken[j] = true;
    			int c = 1;
    			for (int k=1; k<digits; k++) {
    				int rem = j % (int)Math.pow(10, k);
    				int res = rem * (int)Math.pow(10, digits-k) + j / (int)Math.pow(10, k);
    				if (A <= res && res <= B && j != res && !taken[res]) { taken[res] = true; c++; }
    			}
    			if (c > 1) {
    				//System.out.println(j+" "+c);
						int r = 0;
						for (int k=c-1; k>=1; k--) r += k;
						count += r;
					}
    		}
    	}
    	
    	/*int cc= 0;
    	for (int a=A; a<=B; a++) {
    		for (int b=a+1; b<=B; b++) {
    			boolean found = false;
    			for (int k=1; k<digits; k++) {
    				int rem = a % (int)Math.pow(10, k);
    				int res = rem * (int)Math.pow(10, digits-k) + a / (int)Math.pow(10, k);
    				if (res == b) { found = true; break; }
    			}
    			if (found) { cc++; }
    		}
    	}
    	System.out.println(cc);*/
    	System.out.println("Case #" + (i+1) + ": " + count);
    }
  }
}

