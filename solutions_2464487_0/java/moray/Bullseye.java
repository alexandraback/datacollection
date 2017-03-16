import java.util.*;

class Bullseye{

    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);

	int T=sc.nextInt();
	for(int tt=1;tt<=T;tt++){
	    long r=sc.nextLong();long t=sc.nextLong();
	    long count=0;
	    while((r+1)*(r+1)-r*r<=t){
		t-=(r+1)*(r+1)-r*r;
		count++;r+=2L;
		//	System.out.printf("r=%d t=%d count=%d\n",r,t,count);
	    }

	    System.out.printf("Case #%d: %d\n",tt,count);
	}
    }
}
