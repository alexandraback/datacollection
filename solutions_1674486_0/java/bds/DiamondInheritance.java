package org.bali.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

/**
 * User: bds
 * 06/05/2012 11:20
 */
public class DiamondInheritance {
    public static void main(String[] args) throws Exception {
        String input = args[0];
        String output = args[1]+".out.txt";
        System.out.println("Input: "+input+"\nOutput: "+output);

        new DiamondInheritance().run(input, output);
    }

    void run(String input, String output) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(input));
        BufferedWriter writer = new BufferedWriter(new FileWriter(output));
        int nCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < nCases; i++) {
            System.out.println("case: "+i);
            int N = Integer.parseInt(reader.readLine());
            ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
            String result = "No";
            for (int j = 0; j < N; j++) {
                ArrayList<Integer> neighbours = new ArrayList<Integer>();
                String node = reader.readLine();
                String part[] = node.split(" ");
                int nn = Integer.parseInt(part[0]);
                for (int k = 0; k < nn; k++) {
                    neighbours.add(Integer.parseInt(part[k + 1])-1);
                }
                graph.add(neighbours);
            }
            //printGraph(graph);

            if (hasDiamondInheritance(graph)) {
                result = "Yes";
            }
            writer.write("Case #"+(i+1)+": "+result+"\n");
        }
        reader.close();
        writer.close();
    }

    void printGraph(ArrayList<ArrayList<Integer>> graph) {
        for (int i = 0; i < graph.size(); i++) {
            System.out.print("i="+i+" : [");
            for (int j = 0; j < graph.get(i).size(); j++) {
                System.out.print(""+graph.get(i).get(j)+", ");
            }
            System.out.println("]\n");
        }
    }

    boolean hasDiamondInheritance(ArrayList<ArrayList<Integer>> graph) {
        for (int i = 0; i < graph.size(); i++) {
            if(dfs(graph, i, new HashSet<Integer>())) {
                return true;
            }
        }
        return false;
    }

    boolean dfs(ArrayList<ArrayList<Integer>> graph, int toVisit, HashSet<Integer> visited) {
        //if(toVisit.isEmpty()) return false;
        //int curr = toVisit.remove(0);
        visited.add(toVisit);
        ArrayList<Integer> currNode = graph.get(toVisit);
        for (int i = 0; i < currNode.size(); i++) {
            if (visited.contains(currNode.get(i))) {
                return true;
            }
            if (dfs(graph, currNode.get(i), visited)) {
                return true;
            }
        }
        return false;
    }

}
