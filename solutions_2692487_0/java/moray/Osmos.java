import java.util.*;

class Osmos{
    int INF=1<<28;
    boolean debug=false;
    int A,N;
    int[] m;
    void run(){
	Scanner sc=new Scanner(System.in);
	int T=sc.nextInt();
	for(int tt=1;tt<=T;tt++){
	    A=sc.nextInt(); N=sc.nextInt();
	    m=new int[N];
	    for(int i=0;i<N;i++)m[i]=sc.nextInt();
	    Arrays.sort(m);
	
	    int ans=INF;

	    LinkedList<int[]> q=new LinkedList<int[]>();
	    q.offer(new int[]{0,N-1,A,0});
	    while(!q.isEmpty()){
		int[] a=q.poll();
		int from=a[0];int to=a[1];int size=a[2];int count=a[3];
		while(from<=to && size>m[from]){size+=m[from++];}
		if(from>to){ans=count;break;}
		q.offer(new int[]{from,to,size+size-1,count+1});
		q.offer(new int[]{from,to-1,size,count+1});
	    }

	    System.out.printf("Case #%d: %d\n",tt,ans);
	}
    }

    int getmin(int from,int to,int size,int count){
	//Œ»İƒTƒCƒYsize,from~to‚Ü‚Å‚ÌÅ¬‘€ì‰ñ”‚ğ•Ô‚·
	if(!(from<=to))return count;

	int res=INF;
	int pt=from;
	while(from<=to && size>m[from]){size+=m[from++];}
	if(!(from<=to))return count;
	res=getmin(from,to,size+size-1,count+1);
	res=Math.min(from,getmin(from,to-1,size,count+1));

	return res;
    }

    public static void main(String[] args){
	new Osmos().run();
    }
}

	 