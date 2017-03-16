import java.util.*;

class C1{

    public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int T=sc.nextInt();
	for(int tt=1;tt<=T;tt++){
	    int R=sc.nextInt();int N=sc.nextInt();
	    int M=sc.nextInt();int K=sc.nextInt();

	    System.out.printf("Case #%d:\n",tt);
	    while(R-->0){

	    int[] p=new int[M+1];
		for(int j=0;j<K;j++){
		    int x=sc.nextInt();
		    if(x==1)continue;
		    for(int k=2;k<=M;k++){
			int z=x;
			while(z>1 && z%k==0){
			    p[k]++;z/=k;
			}
		    }
		}
	    
 
	    for(int i=0;i<N;i++){
		int maxp=-1;int max=0;
		for(int j=M;j>=2;j--){
		    if(p[j]>maxp){
			max=j;maxp=p[j];
		    }
		}
		System.out.print(max);
		p[max]=(int)Math.sqrt(p[max]);
	    }
	    System.out.println();
	}
	}
    }
}