package com.vlatynski.rC;

import java.io.*;
import static java.util.Locale.ENGLISH;

import java.util.*;

public class A {

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(new File(args[0]));

        FileWriter output = new FileWriter(new File("out.txt"));

        int T = s.nextInt();

        for(int i=0;i<T;i++) {
            int N = s.nextInt();
            List<Set<Integer>> inherits = new ArrayList<Set<Integer>>(N);
            for(int j=0;j<N;j++) {
                int M = s.nextInt();
                Set<Integer> parents = new HashSet<Integer>();
                for(int k=0;k<M;k++) {
                    parents.add(s.nextInt()-1);
                }
                inherits.add(parents);
            }
            output.write("Case #" + (i + 1) + ": " + solution(inherits) + "\n");
        }
        output.flush();
        output.close();
    }

    private static String solution(List<Set<Integer>> inherits) {
        boolean[] marks;
        int L = inherits.size();
        for(int i=0;i<L;i++) {
            marks = new boolean[L];
            if(mark(inherits.get(i), marks, inherits)) {
                return "Yes";
            }
        }
        return "No";
    }

    private static boolean mark(Set<Integer> parents, boolean[] marks, List<Set<Integer>> inherits) {
        for(int p : parents) {
            if(marks[p]) {
                return true;
            } else {
                marks[p] = true;
            }
            if(mark(inherits.get(p),marks,inherits)) {
                return true;
            }
        }
        return false;
    }


}
