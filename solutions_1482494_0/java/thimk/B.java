import java.util.*;

public class B
{
    public static int starsLeft[];
    public static Level stage2[];
    public static Level stage1[];
    public static int a[];
    public static int b[];

    public static class Level implements Comparable<Level>
    {
	int n;
	int d;
	
	public Level(int no, int diff){
	    n = no;
	    d = diff;
	}

	public int compareTo(Level l)
	{
	    return -(d - l.d);
	}
    }
    
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);

	int T = in.nextInt();
	int caseno = 0;
	
	a = new int[1000];
	b = new int[1000];

	stage1 = new Level[1000];
	stage2 = new Level[1000];

	starsLeft = new int[1000];
	
	int N;

	while(caseno < T){
	    caseno++;
	    int steps = 0;
	    int stars = 0;

	    N = in.nextInt();
	    for(int i = 0; i < N; i++){
		a[i] = in.nextInt();
		b[i] = in.nextInt();
		starsLeft[i] = 2;
		stage1[i] = new Level(i, a[i]);
		stage2[i] = new Level(i, b[i]);
	    }
	    
	    Arrays.sort(stage1,0,N);
	    Arrays.sort(stage2,0,N);

	    //for(int i = 0; i < N; i++)
	    //	System.out.print(" " + stage1[i].d);
	    //System.out.println();

	    int s1i = N-1;
	    int s2i = N-1;

	    PriorityQueue<Level> next = new PriorityQueue<Level>();
	    
	    //prime the queue
	    while(s2i >= 0 && stage2[s2i].d <= stars){
		//System.out.println("playing hard version of level " + stage2[s2i].n);
		steps++;
		stars += starsLeft[stage2[s2i].n];
		starsLeft[stage2[s2i].n] = 0;
		s2i--;
	    }
	    while(s1i >= 0 && stage1[s1i].d <= stars){
		next.offer(new Level(stage1[s1i].n, b[stage1[s1i].n]));
		s1i--;
	    }
	    
	    while(!next.isEmpty()){
		//System.out.println("Grabbing from queue");
		Level best = next.poll();
		if(starsLeft[best.n] > 0){
		    //assert starsLeft[best.n] == 2;
		    //System.out.println("playing easy version of level " + best.n);
		    stars++;
		    steps++;
		    starsLeft[best.n] = 1;
		}

		while(s2i >= 0 && stage2[s2i].d <= stars){
		    //System.out.println("playing hard version of level " + stage2[s2i].n);
		    steps++;
		    stars += starsLeft[stage2[s2i].n];
		    starsLeft[stage2[s2i].n] = 0;
		    s2i--;
		}
		while(s1i >= 0 && stage1[s1i].d <= stars){
		    next.offer(new Level(stage1[s1i].n, b[stage1[s1i].n]));
		    s1i--;
		}
	    }
	    
	    System.out.print("Case #" + caseno + ": ");
	    if(stars < 2*N)
		System.out.println("Too Bad");
	    else
		System.out.println(steps);
	    
	    
	}
    }
}