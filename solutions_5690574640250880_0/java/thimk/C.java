import java.util.*;

public class C
{

    public static final String fail = "Impossible";
    /*
    public static final char start = 'c';
    public static final char clear = '.';
    public static final char mine  = '*';
    */

    public static int[][] map;
    public static final char[] symbols = {'*', '.', 'c'};
    //I use mines as the default;
    public static final int mine = 0;
    public static final int free = 1;
    public static final int init = 2;

    public static void clearSq(int R, int C)
    {
	for(int j = 1; j < C; j++)
	    map[0][j] = free;
	
	for(int i = 1; i < R; i++)
	    for(int j = 0; j < C; j++)
		map[i][j] = free;
    }

    public static void printMap(int R, int C)
    {
	for(int i = 0; i < R; i++){
	    for(int j = 0; j < C; j++)
		System.out.print(symbols[map[i][j]]);
	    System.out.println();
	}
    }

    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	
	for(int caseno = 1; caseno <= T; caseno++){
	    System.out.println("Case #" + caseno + ":");
	    
	    int R = in.nextInt();
	    int C = in.nextInt();
	    int M = in.nextInt();
	    
	    int O = R*C-M;
	    map = new int[R][C]; //note mine = 0, so filled with mines
	    map[0][0] = init; // set it to start

	    if(R == 1 || C == 1){
		int maxR = (O < R)? O : R;
		int maxC = (O < C)? O : C;
		clearSq(maxR,maxC);
		printMap(R,C);
	    }else if(R == 2 || C == 2){
		if((O == 2) || ((O % 2 == 1) && O > 1)){
		    System.out.println(fail);
		}else{
		    int maxR = (O/2 < R)? O/2 : R;
		    int maxC = (O/2 < C)? O/2 : C;
		    clearSq(maxR,maxC);
		    printMap(R,C);
		}
	    }else if(O == 2 || O == 3 || O == 5 || O == 7){
		System.out.println(fail);
	    }else{
		if(O == 1){
		    ;//do nothing
		}else if(O == 4){
		    clearSq(2,2);
		}else if(O == 6){
		    clearSq(3,2);
		}else if(O < 3*C){
		    clearSq(3,O/3);
		    if(O % 3 > 0){
			map[0][O/3] = free;
			map[1][O/3] = free;
			if(O % 3 == 1)
			    map[2][O/3-1] = mine;
		    }
		}else{
		    clearSq(O/C,C);
		    if(O % C == 1){
			map[O/C][0] = free;
			map[O/C][1] = free;
			map[O/C-1][C-1] = mine;
		    }else{
			for(int j = 0; j < O % C; j++)
			    map[O/C][j] = free;
		    }
		}
		printMap(R,C);
	    }
	}
    }
}