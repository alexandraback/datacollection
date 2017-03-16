import java.util.*;
import java.io.*;

public class dancing {
    public static void main(String[] args) throws Throwable {
	Scanner input=new Scanner(new File("dancing.in"));
	PrintWriter out=new PrintWriter(new File("dancing.out"));
	int cases=input.nextInt();
	for(int test=1;test<=cases;test++) {
	    int n=input.nextInt();
	    int s=input.nextInt();
	    int p=input.nextInt();
	    int[] t=new int[n];
	    for(int i=0;i<n;i++) t[i]=input.nextInt();
	    int numNS=0, numS=0;
	    for(int i=0;i<n;i++) {
		if(t[i]/3+(t[i]%3==0?0:1)>=p) numNS++;
		}
	    for(int i=0;i<n;i++) {
		if(t[i]<2) {
		    if(t[i]>=p) numS++;
		    }
		else {
		    if((t[i]-2)/3+2>=p) numS++;
		    }
		}
	    int ans=numNS+Math.min(numS-numNS, s);
	    out.println("Case #"+test+": "+ans);
	    }
	out.close();
	}
    }