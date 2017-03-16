/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamround1c;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/**
 *
 * @author Dean
 */
public class A {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numCases = Integer.parseInt(reader.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            int classes = Integer.parseInt(reader.readLine().trim());
            ArrayList<Integer> adj[] = new ArrayList[classes];
            for (int j = 0; j < classes; j++) {
                adj[j] = new ArrayList<Integer>();
            }
            for (int j = 0; j < classes; j++) {
                String line[] = reader.readLine().trim().split(" ");
                int numParents = Integer.parseInt(line[0]);
                for (int k = 1; k < line.length; k++) {
                    int p = Integer.parseInt(line[k]);
                    adj[p-1].add(j);
                }
            }
            System.out.println("Case #" + i + ": " + findDiamond(adj));
        }

    }
    
    public static String findDiamond(ArrayList<Integer> adj[]) {
        int visits[] = new int[adj.length];
        for (int i = 0; i < adj.length; i++) {
            boolean visited[] = new boolean[adj.length];
                   
            if (DFS(i, adj, visited, visits)) {
                return "Yes";
            }
        }
        return "No";
    }
    
    public static boolean DFS(int curr, ArrayList<Integer> adj[], boolean visited[], int visits[]) {
        if (visited[curr]) {
            return true;
        }
        visited[curr] = true;
        if (visits[curr] == 1) {
            //return false; //seen this path already
        }
        for (Integer i: adj[curr]) {
            
            visits[i]++;
            if (DFS(i, adj, visited, visits)) {
                return true;
            }
            
        }
        return false;
    } 
}
