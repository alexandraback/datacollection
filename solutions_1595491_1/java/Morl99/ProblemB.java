package codejam.morl99.b;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

import codejam.morl99.a.ProblemA;

public class ProblemB {
    public void solveSet(PrintWriter pw, BufferedReader reader) throws IOException {

        String firstLine = reader.readLine();
        Scanner scanner = new Scanner(firstLine);
        scanner.useDelimiter(" ");
        int T = scanner.nextInt();
        
        for (int i = 1; i <= T; i++) {
            scanner = new Scanner(reader.readLine());
            scanner.useDelimiter(" ");
            int N = scanner.nextInt();
            int S = scanner.nextInt();
            int p = scanner.nextInt();
            int[] t = new int[N];
            for (int googler = 0; googler < N; googler++) {
                t[googler] = scanner.nextInt();
            }
            System.out.println("-- N: " + N + " S: " + S + " p>="+p +" t:"+ Arrays.toString(t)  ) ;
            int solution = solveLine(N,S,p,t);
            pw.printf("Case #%d: %d",i,solution);
            pw.println();
        }
        
    }
    
    public int solveLine(int N, int S, int p, int[] t) {
        int casesAbove = 0;
        for (int i = 0; i < N; i++) {
            if (isRegularScoreAbove(t[i], p)) {
                casesAbove++;
                continue;
            }
            
            //Whenever a regular score is not above the limit, but the best surprising distribution is
            //we take the greedy approach and assume this was a surprising score. What better than a score above 
            //could we hope for?
            if (S > 0 && isSurprisingScoreAbove(t[i], p)) {
                S--;
                casesAbove++;
            }
        }
        return casesAbove;
    }
    
    public boolean isRegularScoreAbove(int ti, int p) {
        //This is the formular for the best score that can be achieved, if no score can be
        //apart more than 1 from any other score
        int best = ti/3 + Math.min(ti%3,1);
        System.out.println("Best regular score for "  + ti + " is " + best);
        return best >= p;
    }
    
    public boolean isSurprisingScoreAbove(int ti, int p) {
        //integer division, which is exactly what we want!
        int b = ((ti-1) / 3);
        int best = b + 1 + (ti-b*3+1)/3;
        //Special case, that we are near zero...
        best = Math.min(ti,best);
        System.out.println("Best surprising score for "  + ti + " is " + best);
        return best >= p;
    }
    
    public static void main(String[] args) throws IOException {
        ProblemB p = new ProblemB();
        
        OutputStream output = new FileOutputStream("res/B.out", false);
        PrintWriter pw = new PrintWriter(output);
        BufferedReader reader = new BufferedReader(new FileReader("res/B-large.in"));
        p.solveSet(pw, reader);
        pw.close();
        reader.close();
        
        
    }
}
