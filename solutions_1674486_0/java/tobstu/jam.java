/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;

import java.text.*;
import java.util.ArrayList;
import java.util.Queue;

/**
 *
 * @author Tobi
 */
public class jam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt(); //number of testcases
        for(int t = 1; t <= T; t++) {
            int N = s.nextInt(); //number of classes
            Node[] nodes = new Node[N];
            java.util.HashSet<Node> startCandidates = new java.util.HashSet<Node>();
            
            for(int i = 0; i < N; i++) { //init empty tree
                nodes[i] = new Node();
                startCandidates.add(nodes[i]);
            }
            
            for(int n = 0; n < N; n++) { //build tree
                int num = s.nextInt(); //number of classes this class inherits from
                nodes[n].id = n + 1;
                nodes[n].inheritsFrom = new Node[num];
                for(int v = 0; v < num; v++) {
                    int from = s.nextInt() - 1;
                    nodes[n].inheritsFrom[v] = nodes[from];
                    startCandidates.remove(nodes[from]);
                }
            }
            
            boolean result = false;
            if(startCandidates.size() == 0) //no start canidate? every node is a startCandidate!
                for(int i = 0; i < nodes.length; i++)
                    startCandidates.add(nodes[i]);
            
            for(Node curr : startCandidates){
                java.util.Queue<Node> lookAtThis = new java.util.LinkedList<Node>();
                for(int u = 0; u < curr.inheritsFrom.length; u++)
                    lookAtThis.add(curr.inheritsFrom[u]);
                while(lookAtThis.size() > 0 && !result) {
                    Node tmp = lookAtThis.poll();
                    if(tmp.visited) {
                        result = true;
                        break;
                    }
                    
                    tmp.visited = true;
                    for(Node in : tmp.inheritsFrom)
                        lookAtThis.add(in);
                }
                
                //reset the graph
                for(int j = 0; j < nodes.length; j++)
                    nodes[j].visited = false;
            }
            
            if(result)
                System.out.println("Case #" + t + ": Yes");
            else
                System.out.println("Case #" + t + ": No");            
        }
    }
}

class Node {
    public int id;
    public Node[] inheritsFrom;
    public boolean visited = false;
}
