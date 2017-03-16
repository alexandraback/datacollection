import java.util.Scanner;

class Main {

    static final int UNSOLVE = -1;
    
    public static void main(String[] args){

	Scanner stdin = new Scanner(System.in);
	int times = stdin.nextInt();
	int N = -1;
	int stars[][];
	for(int t = 1; t <= times; t++){
	    N = stdin.nextInt();
	    stars = new int[N][2];
	    for(int i = 0; i < N; i++){
		stars[i][0] = stdin.nextInt();
		stars[i][1] = stdin.nextInt();
	    }

	    int solve = solve(N, stars);
	    if (solve == UNSOLVE){
		System.out.println("Case #" + t + ": Too Bad"); 
	    } else {
		System.out.println("Case #" + t + ": " + solve); 
	    }
	}
	
    }

    static int solve(int N, int stars[][]){
	int timesOfSearch = 0;
	int star = 0;
	int lastLevel = -1;
	int lastRate = -1;	
	boolean clearLevel[][] = new boolean[N][2];
	boolean start = false;

	while(!clearAll(clearLevel)){
	    int level1 = selectLevel1(clearLevel, stars);
	    int level0 = selectLevel0(clearLevel, stars);
	    if (level1 != -1 && stars[level1][1] <= star){
		//System.out.println("select2rate:" + level1 + " " + star);
		clearLevel[level1][1] = true;
		star += 2;
		lastLevel = level1;
		lastRate = 1;
		start = true;
		timesOfSearch += 1;
	    } else if (start &&
		       clearLevel[lastLevel][0] &&
		       !clearLevel[lastLevel][1] &&
		       stars[lastLevel][1] <= star){
		//System.out.println("select1->2rate:" + lastLevel + " " + star);
		clearLevel[lastLevel][1] = true;
		star += 1;
		lastRate = 1;
		timesOfSearch += 1;
	    } else if (!clearLevel[level0][0] &&
		       !clearLevel[level0][1] &&
		       stars[level0][0] <= star){
		//System.out.println("select1rate:" + level0 + " " + star);
		star += 1;
		lastLevel = level0;
		lastRate = 0;
		start = true;
		timesOfSearch += 1;
	    } else {
		return UNSOLVE;
	    }
	}
	return timesOfSearch;	
    }

    static int selectLevel1(boolean[][] clearLevel, int[][] stars){
	int minStar = Integer.MAX_VALUE;
	int answer = -1;
	for(int i = 0; i < clearLevel.length; i++){
	    if (!clearLevel[i][1] && !clearLevel[i][0]){
		if(minStar > stars[i][1]){
		    minStar = stars[i][1];
		    answer = i;
		}
	    }
	}
	return answer;
    }

    static int selectLevel0(boolean[][] clearLevel, int[][] stars){
	int minStar = Integer.MAX_VALUE;
	int answer = -1;
	for(int i = 0; i < clearLevel.length; i++){
	    if (!clearLevel[i][0] && !clearLevel[i][1]){
		if(minStar > stars[i][0]){
		    minStar = stars[i][0];
		    answer = i;
		}
	    }
	}
	return answer;
    }


    static boolean clearAll(boolean[][] levels){
	for(int i = 0; i < levels.length; i++){
	    if (!levels[i][1]){
		return false;
	    }
	}
	return true;
    }
	    
}
    