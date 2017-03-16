package codejam.morl99.c;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class ProblemC {
    public void solveSet(PrintWriter pw, BufferedReader reader) throws IOException {

        String firstLine = reader.readLine();
        Scanner scanner = new Scanner(firstLine);
        scanner.useDelimiter(" ");
        int T = scanner.nextInt();

        for (int i = 1; i <= T; i++) {
            scanner = new Scanner(reader.readLine());
            scanner.useDelimiter(" ");
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            System.out.println("-- n: " + n + " m: " + m);
            int solution = solveLine(n, m);
            pw.printf("Case #%d: %d", i, solution);
            System.out.println("Solved " + i);
            pw.println();
        }

    }

    public int solveLine(int A, int B) {
        int oldSize = 0;
        Set<Pair> pairs = new HashSet<Pair>();
        for (int i = A; i <= B; i++) {
            Set<Pair> newPairs = getPermutations(i);
            for (Pair p: newPairs) {
                if (p.isInBoundaries(A, B)) {
                    pairs.add(p);
                }
                
            }
            if (pairs.size() > oldSize) {
                oldSize = pairs.size();
//                System.out.println("New Pairs for "+ i + ": " + setToString(pairs) ) ;
            }
        }
        
        return pairs.size();
    }
    
    public Set<Pair> getPermutations(int i){
        Set<Pair> pairs = new HashSet<>();
        String number = "" + i;
        
        //we will now create the pairs by cutting the number in half and moving the second half in front of the first
        int position = number.length()-1;
        final int endIndex = number.length();
        while (position > 0) {
            String recycled = number.substring(position, endIndex) + number.substring(0, position);
            int r= Integer.parseInt(recycled);
            if (i != r) {
                pairs.add(new Pair(i,r));
//                System.out.println(number + " <-> " + recycled);
            }
            position--;
        }
        return pairs;
    }

    public static String setToString(Set<Pair> set) {
        StringBuilder s = new StringBuilder();
        for (Pair p:set) {
            s.append(p);
        }
        return s.toString();
    }
    
    public static void main(String[] args) throws IOException {
        ProblemC p = new ProblemC();

        OutputStream output = new FileOutputStream("res/C.out", false);
        PrintWriter pw = new PrintWriter(output);
        BufferedReader reader = new BufferedReader(new FileReader("res/C-large.in"));
        p.solveSet(pw, reader);
        pw.close();
        reader.close();

    }
}

class Pair {
    int n, m;

    public Pair(int x, int y) {
        if (x < y) {
            n = x;
            m = y;
        } else {
            m = x;
            n = y;
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Pair) {
            Pair other = (Pair) obj;
            if (n == other.n && m == other.m)
                return true;
            if (n == other.m && m == other.n)
                return true;
            return false;
        }
        return super.equals(obj);
    }

    public boolean isInBoundaries(int A, int B) {
        return n >= A && m <= B;
    }

    @Override
    public int hashCode() {
        return n+m;
    }
    
    @Override
    public String toString() {
        return "("+n+","+m+")";
    }
}