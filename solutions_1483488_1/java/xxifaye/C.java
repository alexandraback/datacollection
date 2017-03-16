import java.util.*;
import static java.lang.System.*;

class C{

    static public void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int cases = Integer.parseInt(sc.nextLine());
	for(int c = 1; c<=cases; c++){
	    String[] s = sc.nextLine().split(" ");
	    int a = Integer.parseInt(s[0]);
	    int b = Integer.parseInt(s[1]);
	    int l = s[0].length();
	    long cnt = 0;
	    for(int i = a; i<b; i++){
		HashSet<Integer> set = new HashSet<Integer>();
		for(int pos = 1; pos<l; pos++){
		    int k = (int)Math.pow(10,pos);
		    int kk = (int)Math.pow(10,l-pos);
		    int front = i/k;
		    int back = i-front*k;
		    int newn = back*kk+front;
		    if(newn>i && newn<=b){
			set.add(newn);
		    }
		}
		cnt+=set.size();
	    }
	    out.println("Case #"+c+": "+cnt);
	}
    }
}