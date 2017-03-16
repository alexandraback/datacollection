package com.google.codejam.q;

import com.google.codejam.Problem;

public class ProblemA extends Problem {

    private boolean notCompleted;
    private String solution;

    public ProblemA() {
        super("A-small-attempt0.in");
    }

    public static void main(String[] args) {
        new ProblemA().solve();
    }

    @Override
    protected String run() {
        char[][] m = new char[4][];
        m[0] = input.nextLine().toCharArray();
        m[1] = input.nextLine().toCharArray();
        m[2] = input.nextLine().toCharArray();
        m[3] = input.nextLine().toCharArray();
        input.nextLine();

        notCompleted = false;

        for (int i = 0 ; i < 4 ; i++) {
            if (row(m, i, 0, 0, 1)){
                return solution;
            }

            if (row(m, 0, i, 1, 0)){
                return solution;
            }
        }

        if (row(m, 0, 0, 1, 1)){
            return solution;
        }

        if (row(m, 0, 3, 1, -1)){
            return solution;
        }


        if (notCompleted){
            return "Game has not completed";
        } else {
            return "Draw";
        }
    }

    private boolean row(char[][] chars, int u, int v, int iu, int iv) {
        int x = 0,o = 0;
        for (int i = 0 ; i < 4; i++){
            switch (chars[u][v]){
                case 'X':
                    x++;
                    break;
                case 'O':
                    o++;
                    break;
                case 'T':
                    x++;
                    o++;
                    break;
                case '.':
                    notCompleted = true;
                    return false;
            }
            u += iu;
            v += iv;
        }
        if (x == 4){
            solution = "X won";
            return  true;
        } else if(o == 4){
            solution = "O won";
            return  true;
        }

        return false;
    }

}
