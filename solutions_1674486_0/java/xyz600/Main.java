import java.util.Scanner;

class Main {

    public static void main(String[] args){
	
	Scanner stdin = new Scanner(System.in);
	int times = stdin.nextInt();

	for (int t = 1; t <= times; t++){
	    int n = stdin.nextInt();
	    boolean[][] table = new boolean[n][n];
	    for (int i = 0; i < n; i++){
		int k = stdin.nextInt();
		for (int j = 0; j < k; j++){
		    table[i][stdin.nextInt() - 1] = true;
		}
	    }
	    if (solve(table)){
		System.out.println("Case #" + t + ": Yes");
	    } else {
		System.out.println("Case #" + t + ": No");
	    }	    
	}	
    }

    static boolean solve(boolean[][] table){
	for (int i = 0; i < table.length; i++){
	    for (int j = 0; j < table.length; j++){
		if (i != j){
		    int[] count = new int[1];
		    if (hasTwoPass(i, j, table, count)){
			return true;
		    }
		}
	    }
	}
	return false;
    }

    static boolean hasTwoPass(int i, int j, boolean[][] table, int[] count){
	
	if (i == j){
	    count[0] += 1;
	    //‚È‚ñ‚Å‚à‚¢‚¢
	    return true;
	} else {
	    for (int l = 0; l < table.length; l++){
		if (table[i][l]){
		    hasTwoPass(l, j, table, count);
		}
	    }
	    return (count[0] >= 2);
	}
    }
}