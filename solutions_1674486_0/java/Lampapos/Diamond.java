package com.google;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Diamond {
    public static void main(String[] args) throws IOException {
        final Scanner reader = new Scanner(new File("in.txt"));
        final FileWriter writer = new FileWriter(new File("out.txt"));
        
        final int T = reader.nextInt();
        reader.nextLine();

        for (int i = 0; i < T; i++) {
            final int N = reader.nextInt();
            reader.nextLine();

            final int [][] matrix = new int[N][N];
            
            for (int j = 0; j < N; j++) {
                final int M = reader.nextInt();
                for (int z = 0; z < M; z++) {
                    final int link = reader.nextInt();
                    matrix[j][link-1] = 1;
                }
            }
            
            boolean res = solve(matrix);
         
            writer.write(String.format("Case #%d: %s", i+1, (res ? "Yes" : "No")));
            if (i < T-1) {
                writer.write("\n");
            }
        }
        
        writer.close();
    }
    
    public static boolean solve(int [][] matrix) {
        final Set<Integer> globalWasThere = new HashSet<Integer>();
        
        boolean res = false;
        while (!res && globalWasThere.size() < matrix.length) {
            int i;
            for (i = 0; i < matrix.length; i++) {
                if (!globalWasThere.contains(i)) break;
            }
            final Set<Integer> localWasThere = new HashSet<Integer>();
            res = visit(i, localWasThere, matrix);
            globalWasThere.addAll(localWasThere);
        }
        
        return res;
    }
    
    public static boolean visit(int thereNow, Set<Integer> visited, int [][] matrix) {
        visited.add(thereNow);
        for (int i = 0; i < matrix[0].length; i++) {
            if (matrix[thereNow][i] == 1) {
                if (visited.contains(i)) {
                    return true;
                } else {
                    boolean res = visit(i, visited, matrix);
                    if (res) return true;
                }
            }
        }
        
        return false;
    }
}
