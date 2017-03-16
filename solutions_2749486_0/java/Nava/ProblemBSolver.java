package com.google.code.jam.third;

/**
 * @author: nava
 * @date: 04.05.13
 */
public class ProblemBSolver implements ProblemSolver {
    public String getResult(Input input) {
        long i = 1;
        long dist_x = 0;
        long dist_y = 0;
        StringBuilder path = new StringBuilder("");
        char W = input.x > 0 ? 'W' : 'E';
        char E = input.x > 0 ? 'E' : 'W';
        char N = input.y > 0 ? 'N' : 'S';
        char S = input.y > 0 ? 'S' : 'N';
        long x = Math.abs(input.x);
        long y = Math.abs(input.y);

        while (dist_x + i <= x) {
            dist_x += i;
            i++;
           path.append(E);
        }

        while (dist_y + i <= y) {
            dist_y += i;
            i++;
            path.append(N);
        }

        for (int j = 0; j < x - dist_x; j++) {
            path.append(W).append(E);
        }

        for (int j = 0; j < y - dist_y; j++) {
            path.append(S).append(N);
        }
        return path.toString();
    }


}
