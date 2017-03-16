import java.util.*;
import static java.lang.System.*;

class B{

    static public void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int cases = Integer.parseInt(sc.nextLine());
	for(int c = 1; c<=cases; c++){
	    String[] s = sc.nextLine().split(" ");
	    int n = Integer.parseInt(s[0]);
	    int sur = Integer.parseInt(s[1]);
	    int p = Integer.parseInt(s[2]);
	    int[] score = new int[n];
	    int cz = 0;
	    for(int i = 0; i<n; i++){
		score[i] = Integer.parseInt(s[3+i]);
		if(score[i] == 0)
		    cz ++;
	    }
	    if(p == 1){
		out.println("Case #"+c+": "+(n-cz));
		continue;
	    }
	    if(p == 0){
		out.println("Case #"+c+": "+(n));
		continue;
	    }
	    int cnt = 0;
	    int pot = 0;
	    for(int i:score){
		if(i <= 1) continue;
		int nsur = (i-1)/3+1;
		if(nsur >=p)
		    cnt++;
		else{
		    if(nsur == (p-1)){
			if(i%3 != 1)
			    pot++;
		    }
		}
	    }
	    cnt += Math.min(pot, sur);	
	    out.println("Case #"+c+": "+cnt);
	}
    }

}