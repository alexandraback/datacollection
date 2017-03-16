package com.google.codejam.q;

import com.google.codejam.Problem;

public class ProblemA extends Problem {

    public ProblemA() {
        //super("test/Test.in");
        //super("A-small.in");
        super("A-small-attempt0.in");
    }

    public static void main(String[] args) {
        new ProblemA().solve();
    }

    @Override
    protected String run() {
        String[] in = input.nextLine().split(" ");
        String s = in[0];
        char[] c = new char[s.length()];
        s.getChars(0, c.length, c, 0);
        int n = Integer.valueOf(in[1]);

        int value = 0;
        for (int i = 0; i < c.length; i++){
            int count = 0;
            for (int k = i; k < c.length; k++){
                switch (c[k]){
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        count = 0;
                        break;
                    default:
                        count++;
                }
                if (count == n){
                    //System.out.println(i + ":" + k + ":" +  (c.length - k));
                    value += (c.length - k);
                    break;
                }
            }
        }


        return value + "";
    }
}
