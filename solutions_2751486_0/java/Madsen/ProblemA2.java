package com.kohcha.r1c2013;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

public final class ProblemA {

    public static void main(String[] args) throws IOException {
        long t0 = System.currentTimeMillis();
//        Parser parser = new Parser("A-sample.txt");
        Parser parser = new Parser("A-small-attempt1.in");
//        Parser parser = new Parser("A-large.in");
        int n = 1;
        for(TestCase test : parser) {
            int sum = 0;
            for(int i = 0; i < test.str.length(); i++) {
                for(int k = i; k < test.str.length() + 1; k++) {
                    if(containsOverNCons(test.str.substring(i, k), test.n)) {
                        sum += 1;
                    }
                }
            }
//            int sum = findSequences(test.str, test.n);
            System.out.println("Case #" + n + ": " + sum);
            n += 1;
        }
        System.out.println("Test took: " +  ((System.currentTimeMillis() - t0) / 1000.0));
    }


    private static boolean containsOverNCons(String str, int n) {
        int cons = 0;
        for(int i = 0; i < str.length(); i++) {
            if(isVowel(str.charAt(i))) {
                cons = 0;
            } else {
                cons += 1;
                if(cons == n) {
                    return true;
                }
            }
        }
        return false;
    }
//    private static int findSequences(String str, int n) {
//        int sum = 0;
//        int cons = 0;
//        for(int i = 0; i < str.length(); i++) {
//            if(isVowel(str.charAt(i))) {
//                cons = 0;
//            } else {
//                cons += 1;
//                if(cons >= n) {
//                    sum += 
//                }
//            }
//        }
//        return sum;
//    }

    private static boolean isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }


    private static final class TestCase {

        public final String str;
        public final int n;

        public TestCase(String str, int n) {
            this.str = str;
            this.n = n;
        }

    }


    private static final class Parser implements Iterable<TestCase> {
        
        private List<TestCase> cases = new ArrayList<TestCase>();
        
        public Parser(String file) throws IOException {
            BufferedReader reader = new BufferedReader(new InputStreamReader(ProblemA.class.getResourceAsStream(file)));
            int nCases = Integer.parseInt(reader.readLine());
            for(int i = 0; i < nCases; i++) {
                String[] input = reader.readLine().split(" ");
                int n = Integer.parseInt(input[1]);
                cases.add(new TestCase(input[0], n));
            }
        }
        
        @Override
        public Iterator<TestCase> iterator() {
            return cases.iterator();
        }
    }
}
