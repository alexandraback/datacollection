import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
	
	final Scanner stdin = new Scanner(System.in);
	final int T = stdin.nextInt();

	for (int t = 1; t <= T; t++){
	    final int N = stdin.nextInt();
	    final int M = stdin.nextInt();

	    final int[][] map = new int[N][M];
	    for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
		    map[i][j] = stdin.nextInt();
		}
	    }
	    solve(t, map);
	}	
    }

    static final int FINISH = 0;
    
    static void solve(int t, int[][] map){
	final ArrayList<Integer> heightList = getHeightList(map);
	//printArray(map);
	
	for (Integer height : heightList){

	    checkColumnLineOf(height, map);
	    checkRowLineOf(height, map);

	    if (containHeight(map, height)) {
		System.out.printf("Case #%d: NO\n", t);
		return;
	    }
	    //printArray(map);
	}
	System.out.printf("Case #%d: YES\n", t);

    }

    static void checkColumnLineOf(int height, int[][] map){
	for (int r = 0; r < map[0].length; r++){
	    int count = 0;
	    for (int c = 0; c < map.length; c++){
		if (map[c][r] == FINISH || map[c][r] == height) {
		    count++;
		}
	    }
	    if (count == map.length){
		for (int c = 0; c < map.length; c++){
		    map[c][r] = FINISH;
		}
	    }
	}
    }

    static void checkRowLineOf(int height, int[][] map){
	for (int c = 0; c < map.length; c++){
	    int count = 0;
	    for (int r = 0; r < map[0].length; r++){
		if (map[c][r] == FINISH || map[c][r] == height) {
		    count++;
		}
	    }
	    if (count == map[c].length){
		for (int r = 0; r < map[0].length; r++){
		    map[c][r] = FINISH;
		}
	    }
	}
    }

    static boolean checkDiagonalLineOf(int height, int[][] map){
	final int N = map.length;
	final int M = map[0].length;
	
	for (int c = 0; c < map.length; c++){
	    int count = 0;
	    final int size = Math.min(M, c);
	    for (int l = 0; l < size; l++){
		if (map[c - l][l] == FINISH || map[c - l][l] == height){
		    count++;
		}
	    }
	    if (count == size){
		for (int l = 0; l < size; l++){
		    map[c - l][l] = FINISH;
		}
	    }

	    count = 0;
	    for (int l = 0; l < size; l++){
		if (map[c - l][M - l - 1] == FINISH || map[c - l][M - l - 1] == height){
		    count++;
		}
	    }
	    if (count == size){
		for (int l = 0; l < size; l++){
		    map[c - l][M - l - 1] = FINISH;
		}
	    }
	}

	for (int r = 0; r < map[0].length; r++){
	    int count = 0;
	    final int size = Math.min(M - r, N);
	    for (int l = 0; l < size; l++){
		if (map[N - 1 - l][r + l] == FINISH || map[N - 1 - l][r + l] == height){
		    count++;
		}
	    }
	    if(count == size){
		for (int l = 0; l < size; l++){
		    map[N - 1 - l][r + l] = FINISH;
		}   
	    }

	    count = 0;
	    for (int l = 0; l < size; l++){
		if (map[N - 1 - l][M - 1 - r - l] == FINISH || map[N - 1 - l][M - 1 - r - l] == height){
		    count++;
		}
	    }
	    if(count == size){
		for (int l = 0; l < size; l++){
		    map[N - 1 - l][M - 1 - r - l] = FINISH;
		}   
	    }
	}

	return !containHeight(map, height);
    }

    static boolean containHeight(int[][] map, int height){
	for (int i = 0; i < map.length; i++){
	    for (int j = 0; j < map[0].length; j++){
		if (map[i][j] == height){
		    return true;
		}
	    }
	}
	return false;
    }

    static ArrayList<Integer> getHeightList(int[][] map){
	ArrayList<Integer> list = new ArrayList<Integer>();
	for (int c = 0; c < map.length; ++c){
	    for (int r = 0; r < map[c].length; ++r){
		if (!list.contains(map[c][r])){
		    list.add(map[c][r]);
		}
	    }
	}
	Collections.sort(list);
	return list;
    }

    static void printArray(int[][] map){
	System.out.println(map.length + " " + map[0].length);
	for (int c = 0; c < map.length; ++c){
	    System.out.println(Arrays.toString(map[c]));
	}
    }    
}
