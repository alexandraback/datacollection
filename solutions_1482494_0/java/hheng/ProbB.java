import java.util.*;
import java.io.*;
import java.lang.*;

class ProbB { 
	static Level[] levels; 
	static int N;
	static int minStep;
	static boolean[][] visited;
	
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    
    for (int c=0; c<T; c++) {
    	N = sc.nextInt();
    	levels = new Level[N];
    	for (int i=0; i<N; i++) {
    		levels[i] = new Level(sc.nextInt(), sc.nextInt());
    	}
    	Arrays.sort(levels);
    	minStep = Integer.MAX_VALUE;
    	visited = new boolean[(1<<(N+1))][(1<<(N+1))];
    	for (int i=0; i<visited.length; i++) Arrays.fill(visited[i], false);
    	doit(0, 0);
    	if (minStep == Integer.MAX_VALUE) System.out.println("Case #" + (c+1) + ": Too Bad");
    	else System.out.println("Case #" + (c+1) + ": " + minStep);
    }    
  }
  
  public static void doit(int star1, int star2) {
  	//System.out.println(star1+" "+star2);
  	if (star2 == ((1<<N) - 1)) {
  		minStep = Math.min(minStep, countStep(star1, star2));
  		return;
  	}
  	if (visited[star1][star2]) return;
  	visited[star1][star2] = true;
  	
  	int star = countStar(star1, star2);
  	for (int i=0; i<N; i++) {
  		if (((1<<i) & star2) == 0 && levels[i].twoStar <= star) {
  			if (((1<<i) & star1) == 0) doit(star1, star2 | (1<<i));
  			else doit(star1, star2 | (1<<i));
  		}
  	}
  	
  	for (int i=0; i<N; i++) {
  		if (((1<<i) & star1) == 0 && levels[i].oneStar <= star) {
  			doit(star1 | (1<<i), star2);
  		}
  	}
  }
  
  public static int countStar(int star1, int star2) {
  	int count = 0;
  	boolean[] taken = new boolean[N];
  	for (int i=0; i<N; i++) {
  		if (((1<<i) & star2) != 0) { count+=2; taken[i] = true; }
  	}
  	for (int i=0; i<N; i++) {
  		if (!taken[i] && ((1<<i) & star1) != 0) { count+=1; taken[i] = true; }
  	}
  	return count;
  }
  
  public static int countStep(int star1, int star2) {
  	int count = 0;
  	for (int i=0; i<N; i++) {
  		if (((1<<i) & star2) != 0) count++;
  		if (((1<<i) & star1) != 0) count++;  		
  	}
  	return count;
  }
}

class Level implements Comparable<Level> {
	int oneStar, twoStar;
	Level (int a, int b) { oneStar = a; twoStar = b; }
	
	public int compareTo(Level l) {
		if (l.oneStar != oneStar) return oneStar - l.oneStar;
		return twoStar - l.twoStar;
	}
}


