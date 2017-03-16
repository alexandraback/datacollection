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
	    int[] o = new int[ss.length-1];
	    int n = ss.length-1;
	    long sum =0;
	    for(int i = 0; i < n; i++){
		o[i] = Integer.parseInt(ss[i+1]);
		sum += o[i];
	    }

	    double ret= 0;
	    int[] s = o.clone();
	    Arrays.sort(s);
	    for(int i = 1; i <= n; i++){
		int p = 0;
		for(int j = 0; j < i; j++){
		    p += s[i-1] - s[j];
		}
		ret = (double)s[i-1] + ((double)sum-p)/(i);
		if (i == n || ret <= s[i]) {
		    break;
		}
	    }
	
	    for(int i = 0; i < n; i++){
		double r = Math.max((ret-o[i])/sum,0);
		out.print(r*100+" ");
	    }
	    out.println();
	}
	
   }
}