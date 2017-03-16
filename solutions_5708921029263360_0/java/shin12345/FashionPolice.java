import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;



public class FashionPolice {
	public static int[] perm(int j, int p, int s, int[] perm) {
		if (perm[0] == 0)
			return new int[]{1,1,1};
		if (perm[2] < s)
			perm[2]+=1;
		else  {
			perm[2] = 1;
			if (perm[1] < p)
				perm[1]+=1;
			else  {
				perm[1] = 1;
				if (perm[0] < j)
					perm[0]+=1;
				else  {
					return new int[] {0,0,0};
				}
			}
		}
		return perm;
		
	}
	
	public static void main(String[] args) {
	    //Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	 Scanner in = new Scanner(System.in);
	    int loops = in.nextInt();
	 	
	    for (int loop = 1; loop <= loops; ++loop) {
	    	int j = in.nextInt();
	    	int p = in.nextInt();
	    	int s = in.nextInt();
	    	int k = in.nextInt();
	       
	    	int[] perm = new int[] {0,0,0};
	    	int[][] perms = new int[j*p*s][3];
	    	
	    	for (int i = 0; i < j*p*s; i++) {
	    		perm = perm(j,p,s,perm);
	    		perms[i][0] = perm[0];
	    		perms[i][1] = perm[1];
	    		perms[i][2] = perm[2];
	    	}
	    	
	    	String line = "";
	    	int counter = 0;
	    	for (int i = 0; i < j*p*s; i++) {
	    		int this1 = perms[i][0];
	    		int this2 = perms[i][1];
	    		int this3 = perms[i][2];
	    		int jp = 0;
    			int js = 0;
    			int ps = 0;
	    		for (int prev = 0; prev < i; prev++) {
	    			int prev1 = perms[prev][0];
		    		int prev2 = perms[prev][1];
		    		int prev3 = perms[prev][2];
	    			
		    		if(this1 == prev1 && this2 == prev2)
		    			jp++;
		    		if(this1 == prev1 && this3 == prev3)
		    			js++;
		    		if(this3 == prev3 && this2 == prev2)
		    			ps++;
	    		}
	    		if (jp > k || js > k || ps > k) {
	    			continue;
	    		}
	    		line += String.format("%1$s %2$s %3$s\n", this1, this2, this3);
	    		counter++;
	    	}
	    	System.out.println(String.format("Case #%1$s: #%2$s", loop, counter));
	    	System.out.print(line);
	    	
	    }
	    in.close();
	}
}
