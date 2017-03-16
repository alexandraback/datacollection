import java.util.*;
import java.io.*;

public class Slides{
    static Scanner in = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args){
	int t = in.nextInt();

	for(int c = 1; c<=t; c++){
	    out.println("Case #"+c+": "+solve());
	}

	out.close();
    }

    static String solve(){
	int b = in.nextInt();
	long m = in.nextInt();

        // b = 2 -> 1 path
	// b = 3 -> 2 paths
	// 
	
	if((1L<<(b-2))<m)
	    return "IMPOSSIBLE";

	int[][] matrix = new int[b][b];
	for(int i = 1; i<b; i++)
	    for(int j = i+1; j<b; j++)
		matrix[i][j] = 1;
	
	m--;
	matrix[0][b-1] = 1;
	
	int d = b-2;

	while(m>0){
	    if(m%2!=0)
		matrix[0][d]=1;
	    d--;
	    m/=2;
	}
	
	StringBuilder answer = new StringBuilder();

	answer.append("POSSIBLE");

	for(int i = 0; i<b; i++){
	    answer.append('\n');
	    for(int j = 0; j<b; j++)
		answer.append(matrix[i][j]);
	}

	return answer.toString();
    }

}

