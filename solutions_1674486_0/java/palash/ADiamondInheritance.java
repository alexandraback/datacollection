package com.afarok.google.codejam2012.FirstC;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;

public class ADiamondInheritance {
    public static void main(String[] ags) throws FileNotFoundException {
        System.setIn(new FileInputStream("src/com/afarok/google/codejam2012/FirstC/A-small-attempt0.in"));
        System.setOut(new PrintStream(new File("src/com/afarok/google/codejam2012/FirstC/A-small-attempt0.out")));

        Scanner stdIn = new Scanner(System.in);
        int t = stdIn.nextInt();
        stdIn.nextLine();
        for(int tCase =1;tCase<=t;++tCase) {
            int n = stdIn.nextInt();
            Map<Integer, int[]> inheritFrom = new HashMap<Integer, int[]>();
            
            for(int i=1;i<=n;++i) {
                int numOfParents = stdIn.nextInt();
                int[] parents = new int[numOfParents];
                for(int j=0;j<numOfParents;++j) {
                    parents[j] = stdIn.nextInt();
                }
                inheritFrom.put(i, parents);
            }
            printRes(tCase, inheritFrom);

        }
    }
    
    public static void printRes(int tCase, Map<Integer, int[]> inheritFrom) {
        System.out.print("Case #" + tCase + ": ");
        
        boolean found = false;
        for(int node : inheritFrom.keySet()) {
            boolean parentAlreadyVisited = dfsParentSearch(node, inheritFrom, new HashSet<Integer>());
            if(parentAlreadyVisited) {
                found = true;
                break;
            }
        }
        
        System.out.println(found?"Yes":"No");
        
        
    }
    
    public static boolean dfsParentSearch(int node,Map<Integer, int[]> inheritFrom, Set<Integer> disCoveredParents) {
        if(disCoveredParents.contains(node)) return true;
        
        for(int nd:inheritFrom.get(node)) {
            boolean parentAlreadyVisited = dfsParentSearch(nd, inheritFrom, disCoveredParents);
            if(parentAlreadyVisited) return true;
            disCoveredParents.add(nd);
        }
        return false;
    }
}
