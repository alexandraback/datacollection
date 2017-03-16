package com.google.codejam.q;

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
        int x = Integer.valueOf(s[0]);
        int y = Integer.valueOf(s[1]);

        StringBuilder sb = new StringBuilder((Math.abs(x) + Math.abs(y))*2);
        solve(sb, "E", "W", x);
        solve(sb, "N", "S", y);

        return sb.toString();
    }

    private void solve(StringBuilder result, String forward, String backward, int value) {
        String first, second;
        int len;
        if (value > 0){
            first = backward;
            second = forward;
            len = value;
        } else {
            first = forward;
            second = backward;
            len = -value;
        }
        for (int i = 0; i < len; i++){
            result.append(first).append(second);
        }
    }
}
