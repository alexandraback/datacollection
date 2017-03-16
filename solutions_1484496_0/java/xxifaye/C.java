import java.util.*;
import static java.lang.System.*;

class C{
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int cases = Integer.parseInt(sc.nextLine());
	for(int c = 0; c<cases; c++){
	    out.println("Case #"+Integer.toString(c+1)+": ");  
	    // read
	    String read = sc.nextLine();
	    String[] ss = read.split(" ");
	    int[] o = new int[ss.length-1];
	    int n = ss.length-1;
	    long sum =0;
	    for(int i = 0; i < n; i++){
		o[i] = Integer.parseInt(ss[i+1]);
	    }
	    int[] s = new int[10000000];
	    boolean find = false;
	    for(int i = 1; i<(1<<n); i++){
	
		int  p =0;
		for(int j =0; j<n; j++){
		    if((i & (1<<j))!= 0)
			p+=o[j];
		}
	
		if(s[p] != 0){
		    find = true;
		    for(int j = 0; j<n; j++){
			if((i & (1<<j))!= 0)
			  out.print(o[j]+" ");
		    }
		    out.println();
		    for(int j = 0; j<n; j++){
			if((s[p] & (1<<j))!= 0)
			  out.print(o[j]+" ");
		    }
		    out.println();
		    break;
		} else
		    s[p] = i;
	    }
	    if(!find) out.println("Impossible");

	}
    }
}