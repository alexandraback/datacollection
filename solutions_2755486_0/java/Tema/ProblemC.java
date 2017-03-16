package com.google.codejam.q;

import com.google.codejam.Problem;

import java.util.ArrayList;
import java.util.List;

public class ProblemC extends Problem {

    public ProblemC() {
        //super("test/Test.in");
        //super("X-small.in");
        super("C-small-attempt0.in");
    }

    public static void main(String[] args) {
        new ProblemC().solve();
    }

    @Override
    protected String run() {
        int count = 0;
        int N = Integer.valueOf(input.nextLine());
        Tribe[] tribes = new Tribe[N];
        for (int i = 0; i < N; i++) {
            String[] s = input.nextLine().split(" ");
            Tribe t = new Tribe();
            t.di = Integer.valueOf(s[0]);
            t.ni = Integer.valueOf(s[1]);
            t.left = Integer.valueOf(s[2]);
            t.right = Integer.valueOf(s[3]);
            t.si = Integer.valueOf(s[4]);
            t.delta_di = Integer.valueOf(s[5]);
            t.delta_pi = Integer.valueOf(s[6]);
            t.delta_si = Integer.valueOf(s[7]);
            tribes[i] = t;
        }

        GreatWall gw = new GreatWall();

        List<Tribe> list = new ArrayList<Tribe>(10);

        while (true) {
            list.clear();
            int min = Integer.MAX_VALUE;
            for (Tribe tribe : tribes) {
                if (tribe.di < min){
                    min = tribe.di;
                }
            }

            if (min == Integer.MAX_VALUE){
                return "" + count;
            }


            for (Tribe tribe : tribes) {
                if (tribe.di == min){
                    if (gw.attack(tribe)){
                        count++;
                        list.add(tribe);
                    } else {
                        tribe.next();
                    }
                }
            }

            for (Tribe tribe : list){
                gw.buildWall(tribe);
                tribe.next();
            }
        }
    }

    class GreatWall{

        ArrayList<Wall> list = new ArrayList<Wall>(100);

        boolean attack(Tribe t) {
            L: for (double i = t.left; i <= t.right; i += 0.5){
                for (Wall w : list) {
                    if (i >= w.left && i <= w.right && w.si >= t.si){
                        continue L;
                    }
                }
                return true;
            }
            return false;
        }

        public void buildWall(Tribe tribe) {
            list.add(new Wall(tribe.left, tribe.right, tribe.si));
        }
    }

    class Wall{
        int left;
        int right;
        int si;

        Wall(int wi, int right, int si) {
            this.left = wi;
            this.right = right;
            this.si = si;
        }
    }


    class Tribe{
        int di,ni, left, right,si,delta_di,delta_pi,delta_si;

        boolean next(){
            di += delta_di;
            left += delta_pi;
            right += delta_pi;
            si += delta_si;
            ni--;
            if (ni > 0){
                return true;
            } else {
                di = Integer.MAX_VALUE;
                return false;
            }
        }
    }


}


/**
 * The first line of the input gives the number of test cases, T.
 T test cases follow. Each test case begins with a line containing a single integer N:
 the number of the tribes attacking the Wall. N lines follow, each describing one tribe.
 The ith line contains eight integers di, ni, left, right, si, delta_di, delta_pi and delta_si separated by spaces,
 describing a single nomadic tribe:

 di – the day of the tribe's first attack (where 1st January, 250BC, is considered day 0)
 ni – the number of attacks from this tribe
 left, right – the westmost and eastmost points respectively of the Wall attacked on the first attack
 si – the strength of the first attack
 delta_di – the number of days between subsequent attacks by this tribe
 delta_pi – the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
 delta_si – the change in strength between subsequent attacks
 */
