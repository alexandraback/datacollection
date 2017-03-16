package com.kohcha.r1c2013;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public final class ProblemB {

    public static void main(String[] args) throws IOException {
        long t0 = System.currentTimeMillis();
//        Parser parser = new Parser("B-sample.txt");
        Parser parser = new Parser("B-small-attempt0.in");
//        Parser parser = new Parser("B-large.in");
        int n = 1;
        boolean sane = true;
        for(TestCase test : parser) {
            String str = findPath(test.x, test.y);
            if(str.length() >= 500) {
                sane = false;
            }
            System.out.println("Case #" + n + ": " + str);
            n += 1;
        }
        System.out.println("Test took: " +  ((System.currentTimeMillis() - t0) / 1000.0));
        if(!sane) {
            System.out.println("Exceeded length!!!");
        }
    }

    private static int px;
    private static int py;
    private static int step;
    private static char prev;
    private static StringBuilder builder;
    
    private static String findPath(int x, int y) {
        builder = new StringBuilder();
//        int px = 0;
//        int py = 0;
//        int step = 0;
//        char prev = ' ';
//        while(px != x || py != y) {
//            step += 1;
//            if(px + step <= x) {
//                builder.append('E');
//                px += step;
//            } else if(px - step >= x) {
//                builder.append('W');
//                px -= step;
//            } else if(py + step <= y) {
//                builder.append('N');
//                py += step;
//            } else if(py - step >= y) {
//                builder.append('S');
//                py -= step;
//            } else if(px < x) {
//                builder.append('W');
//                px -= step;
//            } else if(px > x) {
//                builder.append('E');
//                px += step;
//            } else if(py < y) {
//                builder.append('S');
//                py -= step;
//            } else if(py > y) {
//                builder.append('N');
//                py += step;
//            } else {
//                throw new IllegalStateException("No move??");
//            }
//        }
        px = 0;
        py = 0;
        step = 0;
        prev = 0;
        while(px != x || py != y) {
            step += 1;
            if(px == x) {
                if(prev == 'N') {
                    goSouth();
                    continue;
                }
                if(prev == 'S') {
                    goNorth();
                    continue;
                }
                if(py + step <= y) {
                    goNorth();
                } else if(py - step >= y) {
                    goSouth();
                } else if(py < y) {
                    goSouth();
                } else {
                    goNorth();
                }
                continue;
            }
            if(py == y) {
                if(prev == 'E') {
                    goWest();
                    continue;
                }
                if(prev == 'W') {
                    goEast();
                    continue;
                }
                if(px + step <= x) {
                    goEast();
                } else if(px - step >= x) {
                    goWest();
                } else if(px < x) {
                    goWest();
                } else {
                    goEast();
                }
                continue;
            }
            if(px + step <= x && prev != 'E') {
                goEast();
            } else if(px - step >= x && prev != 'W') {
                goWest();
            } else if(py + step <= y && prev != 'N') {
                goNorth();
            } else if(py - step >= y && prev != 'S') {
                goSouth();
            } else {
                if(px > x && prev != 'E') {
                    goEast();
                } else if(px < x && prev != 'W') {
                    goWest();
                } else if(py > y && prev != 'N') {
                    goNorth();
                } else if(py < y && prev != 'S') {
                    goSouth();
                } else {
                    if(prev == 'S' || prev == 'N') {
                        if(px > x) {
                            goEast();
                        } else {
                            goWest();
                        }
                    } else {
                        if(py > y) {
                            goNorth();
                        } else {
                            goSouth();
                        }
                    }
                }
            }

        }
        return builder.toString();
    }


    private static void goSouth() {
        py -= step;
        builder.append('S');
        prev = 'S';
    }

    private static void goNorth() {
        py += step;
        builder.append('N');
        prev = 'N';
    }

    private static void goWest() {
        px -= step;
        builder.append('W');
        prev = 'W';
    }

    private static void goEast() {
        px += step;
        builder.append('E');
        prev = 'E';
    }



    private static final class TestCase {

        public final int x;
        public final int y;

        public TestCase(int x, int y) {
            this.x = x;
            this.y = y;
        }

    }


    private static final class Parser implements Iterable<TestCase> {
        
        private List<TestCase> cases = new ArrayList<TestCase>();
        
        public Parser(String file) throws IOException {
            BufferedReader reader = new BufferedReader(new InputStreamReader(ProblemB.class.getResourceAsStream(file)));
            int nCases = Integer.parseInt(reader.readLine());
            for(int i = 0; i < nCases; i++) {
                String[] xy = reader.readLine().split(" ");
                int x = Integer.parseInt(xy[0]);
                int y = Integer.parseInt(xy[1]);
                cases.add(new TestCase(x, y));
            }
        }
        
        @Override
        public Iterator<TestCase> iterator() {
            return cases.iterator();
        }
    }
}
