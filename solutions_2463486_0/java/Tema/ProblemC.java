package com.google.codejam.q;

import com.google.codejam.Problem;

public class ProblemC extends Problem {

    public ProblemC() {
        //super("test/Test.in");
        //super("X-small.in");
        super("C-small-attempt0.in");
    }

    public static void main(String[] args) {
        new ProblemC().solve();
    }

    static int[] n = {1,4,9,121,484};
    //int[] n = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};


    @Override
    protected String run() {
        String[] line = input.nextLine().split(" ");
        int i1 = Integer.valueOf(line[0]);
        int i2 = Integer.valueOf(line[1]);

        int p = 0;
        for (int i : n) {
            if (i >= i1) {
                if (i > i2) {
                    break;
                }
                p++;
            }
        }
        return String.valueOf(p);
    }
}
