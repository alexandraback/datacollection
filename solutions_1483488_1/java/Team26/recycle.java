import java.util.*;
import java.io.*;

public class recycle {
    public static int[] pow10 = {1,10,100,1000,10000,100000,1000000,10000000};

    public static void main(String[] args) throws Throwable {
	Scanner input=new Scanner(new File("recycle.in"));
	PrintWriter out=new PrintWriter(new File("recycle.out"));
	int cases=input.nextInt();
	for(int test=1;test<=cases;test++) {
	    boolean[] visited=new boolean[2000001];
	    int a=input.nextInt();
	    int b=input.nextInt();
	    int rank=0, num=1;
	    int ans=0;
	    for(;num<=a;num*=10,rank++); // rank = #digits
	    for(int i=a;i<=b;i++) {
		if(visited[i]) continue;
		visited[i]=true;
		int temp=i;
		int count=1;
		for(int j=0;j<rank-1;j++) {
		    temp=temp/10+temp%10*pow10[rank-1];
		    if(temp<a || temp>b || visited[temp]) continue;
		    visited[temp]=true;
		    count++;
		    }
		ans+=count*(count-1)/2; //count choose 2
		}
	    out.println("Case #"+test+": "+ans);
	    }
	out.close();
	}
    }