import java.util.*;
import static java.lang.System.*;

class A{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int cases = Integer.parseInt(sc.nextLine());
	for(int c = 0; c<cases; c++){
	    out.print("Case #"+Integer.toString(c+1)+": ");  

	    // read
	    String read = sc.nextLine();
	    String[] ss = read.split(" ");
	    int n =  Integer.parseInt(ss[0]);
	    boolean[] isRoot = new boolean[n+1];
	    Arrays.fill(isRoot, true);
	    isRoot[0] = false;
	    int[][] a = new int[n+1][];
	    for(int k = 0; k<n; k++){
		read = sc.nextLine();
		ss = read.split(" ");
		a[k+1] = new int[ss.length-1];
		int ni = ss.length-1;
		for(int i = 0; i < ni; i++){
		    a[k+1][i] = Integer.parseInt(ss[i+1]);
		    isRoot[a[k+1][i]] = false;
		}
		// 	out.println((k+1)+Arrays.toString(a[k+1]));
	    }
	    boolean yes = false;
	    for(int i = 1; i<n+1; i++){
		if(!isRoot[i])
		    continue;
		HashSet<Integer> sett = new HashSet<Integer>();
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(i);

		while(!q.isEmpty() && !yes){
		    //  out.println(q);
		    int  ccc = q.poll();
		    for(int ii = 0; ii<a[ccc].length; ii++){
			if(sett.contains(a[ccc][ii])){
			    yes = true;
			} else{
			    sett.add(a[ccc][ii]);
			    q.add(a[ccc][ii]);
			}
		    }
		}
	    }
		if(yes) 
		    out.println("Yes");
		else
		    out.println("No");
	    
	    //out.println(Arrays.toString(isRoot));
	}
    }
}