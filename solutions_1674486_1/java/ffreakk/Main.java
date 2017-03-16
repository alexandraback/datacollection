package googlecodejam;

/**
 *
 * @author ffreakk
 */

import java.util.Scanner;
import java.lang.Math;
import java.lang.Object;
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException{
        //Scanner in = new Scanner(new File("input.txt"));
        //PrintStream out = new PrintStream(new File("output.txt"));
        Scanner in = new Scanner(System.in);
        PrintStream out = new PrintStream(System.out);
        int T = in.nextInt();

        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            int inheritance[][] = new int[N][N+1];

            boolean explored[] = new boolean[N+1];
            for (int i=0; i<=N; i++) {
                explored[i] = false;
            }

            int visited[] = new int[N+1];
            for (int i=0; i<=N; i++) {
                visited[i] = 0;
            }

            boolean found = false;
            for (int n=0; n<N; n++) {
                inheritance[n][0] = in.nextInt();
                for (int i=1; i<=inheritance[n][0]; i++) {
                    inheritance[n][i] = in.nextInt()-1;
                }
            }

            Stack<Integer> parents = new Stack<Integer>();

            for (int n=0; n<N; n++)
                if (!explored[n]) {
                    while (!parents.empty()) parents.pop();
                    for (int i=0; i<=N; i++) {
                        visited[i] = 0;
                    }
                    parents.push(n);
                    visited[n]++;
                    while( !parents.empty() ) {
                        int child = parents.pop();
                        explored[child] = true;                        
                        int nParents = inheritance[child][0];
                        for (int i=1; i<=nParents; i++) {
                            int newChild = inheritance[child][i];                            
                            visited[newChild]++;
                            if (!explored[newChild]) parents.push(newChild);
                            //explored[newChild] = true;
                            if (visited[newChild]>=2) found = true;
                        }
                        if (visited[child] >= 2) {
                            found = true;
                            //break;
                        }
                    }

                    //if (found) break;
                }

            if (found) out.println("Case #" +(t+1)+ ": Yes");
            else out.println("Case #" +(t+1)+ ": No");
        }
    }

}
