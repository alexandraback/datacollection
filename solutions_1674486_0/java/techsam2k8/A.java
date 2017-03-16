import java.io.*;
import java.util.*;
import java.math.*;
/** @author Samuel Ahn */

public class A {
    public static void main(String args[]) throws Exception {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for (int i = 1; i <= T; i++) {
	    int N = in.nextInt();
	    int[][] array = new int[N][N];
	    for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
		    array[j][k] = 0;
		}
	    }
	    for (int j = 0; j < N; j++) {
		int x = in.nextInt();
		for (int k = 0; k < x; k++) {
		    array[j][in.nextInt() - 1] = 1;
		}
	    }
	    boolean flag = false;
	    for (int j = 0; j < N; j++) {
		if (magic(array, N, j).equals("Yes")) {
		    flag = true;
		    break;
		}
	    }
	    if (flag) {
		System.out.printf("Case #%d: Yes\n", i);
	    } else {
		System.out.printf("Case #%d: No\n", i);
	    }
	}
    }
    public static String magic(int[][] array, int N, int start) {
	int[] visit = new int[N];
 
	Stack<Integer> stack = new Stack<Integer>();
	stack.push(start);
	visit[start] = 1;
	while (!stack.isEmpty()) {
	    int v = stack.pop();
	    for (int i = 0; i < N; i++) {
		if ((array[v][i] == 1) && (visit[i] == 1)) {
		    return "Yes";
		}
		if ((array[v][i] == 1) && (visit[i] == 0)) {
		    visit[i] = 1;
		    stack.push(i);
		}
	    }
	}
	return "No";
    }
	    
}
