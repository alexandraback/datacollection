package com.google.codejam.b14;

import com.google.codejam.Problem;

public class ProblemB extends Problem {

    public ProblemB() {
        //super("test/Test.in");
        //super("X-small.in");
        super("B-small-attempt0.in");
    }

    public static void main(String[] args) {
        new ProblemB().solve();
    }

    @Override
    protected String run() {
        String[] s = input.nextLine().split(" ");
        int a = Integer.parseInt(s[0]);
        int b = Integer.parseInt(s[1]);
        int k = Integer.parseInt(s[2]);

        int r = 0;
        for (int ia = 0; ia < a; ia++){
            for (int ib = 0; ib < b; ib++){
                if ((ia&ib) < k){
                    r++;
                }
            }
        }

        return r + "";
    }
}
