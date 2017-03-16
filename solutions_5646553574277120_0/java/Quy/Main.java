import java.io.FileInputStream;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Quy Doan
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    int result;
    int V;
    void run(boolean[] used,boolean[] available,int level){
        if ( level >= result ){
            return;
        }
        int first = -1;
        for(int i = 0 ; i <= V ; ++i){
            if ( !available[i] ){
                first = i;
            }
        }

        if ( first == -1 ){
            result = level;
            return;
        }

        for(int i = 1 ; i <= first ; ++i){
            if ( used[i] ) continue;
            boolean[] _available = available.clone();
            for(int j = V - i ; j >= 0 ; --j){
                if (_available[j]){
                    _available[j+i] = true;
                }
            }
            used[i] = true;
            run(used,_available,level+1);
            used[i] = false;
        }

    }
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int C = in.nextInt();
        int D = in.nextInt();
        V = in.nextInt();
        result = V-D;
        boolean[] used = new boolean[V+1];
        boolean[] available = new boolean[V+1];
        available[0] = true;
        for(int i = 0 ; i < D ; ++i){
            int val = in.nextInt();
            used[val] = true;
            for(int j = V - val; j >= 0 ; --j){
                if (available[j]){
                    available[j+val] = true;
                }
            }
        }
        run(used, available, 0);
        out.println("Case #"+testNumber+": "+result);
    }
}

