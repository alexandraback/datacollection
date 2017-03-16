package A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

class CookieClicker {

    Scanner in;
    BufferedWriter out;

    CookieClicker(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    public static void main(String[] args) throws Exception {
        CookieClicker tictactoe = new CookieClicker("src/A/in.txt", "src/A/out.txt");
        tictactoe.solve();
        tictactoe.close();
    }

    public void solve() throws IOException {
        int t = in.nextInt();

        for (int i = 1; i <= t; i++) {
            double C = in.nextDouble();
            double F = in.nextDouble();
            double X = in.nextDouble();

            double P = 2.0;
            double extraTime = 0.0;
            double currentSol;
            double nextSol;
            
            do {
                currentSol = X/P;
                nextSol = C/P + X/(P+F);
                
                extraTime += C/P;
                P += F;
            } while (currentSol >= nextSol);
            
            printSolution(i, currentSol + extraTime - C/(P - F));
        }
    }
    
    private void print(String s) throws IOException {
        out.write(s);
    }

    private void printSolution(int test, double d) throws IOException {
        DecimalFormat df = new DecimalFormat("#.#######");
        print("Case #" + test + ": " + df.format(d) + "\n");
    }

    private void close() throws IOException {
        this.in.close();
        this.out.close();
    }
}