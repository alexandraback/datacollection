/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author akila
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        ArrayList<String> testCases = new ArrayList<String>();
        boolean isCaseNo = true;
        int testCount = 0;
        FileReader fr = new FileReader("B-large.in");
        BufferedReader br = new BufferedReader(fr);
        String s;

        while ((s = br.readLine()) != null) {
            if (isCaseNo) {
                testCount = Integer.parseInt(s);
                isCaseNo = false;
            } else {
                testCases.add(s);
            }
        }
        fr.close();
        Solve(testCount, testCases);
    }

    public static void Solve(int testCount, ArrayList<String> testCases) throws IOException {
        

        FileWriter fstream = new FileWriter("out.txt");
        BufferedWriter out = new BufferedWriter(fstream);

        for (int i = 0; i < testCount; i++) {
            ArrayList<Googler> googlers = new ArrayList<Googler>();
            String s = testCases.get(i);
            String[] ar = s.split(" ");

            int noOfGooglers = 0, sup = 0, min = -1, count = 0;
            noOfGooglers = Integer.parseInt(ar[0]);
            sup = Integer.parseInt(ar[1]);
            min = Integer.parseInt(ar[2]);

            for (int j = 3; j < noOfGooglers + 3; j++) {
                Googler g = new Googler();
                googlers.add(g);
                for (int a = 0; a <= 10; a++) {
                    if (a > Integer.parseInt(ar[j])) {
                        break;
                    }
                    for (int b = 0; b <= 10; b++) {
                        if (a + b > Integer.parseInt(ar[j])) {
                            break;
                        }
                        for (int c = 0; c <= 10; c++) {
                            if (a + b + c == Integer.parseInt(ar[j])) {
                                if ((Math.abs(a - b) <= 2)
                                        && (Math.abs(a - c) <= 2)
                                        && (Math.abs(b - c) <= 2)) {
                                    if ((Math.abs(a - b) == 2)
                                        || (Math.abs(a - c) == 2)
                                        || (Math.abs(b - c) == 2)) {

                                        Scores sc = new Scores();
                                        sc.A = a;
                                        sc.B = b;
                                        sc.C = c;
                                        g.sup.add(sc);
                                        g.hasSup = true;
                                        
                                    } else {
                                        Scores sc = new Scores();
                                        sc.A = a;
                                        sc.B = b;
                                        sc.C = c;
                                        g.normal.add(sc);
                                    }
                                }
                            } else if (a + b + c > Integer.parseInt(ar[j])) {
                                break;
                            }
                        }
                    }
                }
            }
            ArrayList<Googler> removed = new ArrayList<Googler>();
            for (int j = 0; j < googlers.size(); j++) {
                Googler googler = googlers.get(j);
                if (googler.hasSup && googler.normal.isEmpty() && sup > 0) {
                    if (googler.hasMinInSup(min)) {
                        count++;   
                    }
                    sup--;
                    removed.add(googler);
                }
            }
            googlers.removeAll(removed);
            
            for (int j = 0; j < googlers.size(); j++) {
                Googler googler = googlers.get(j);
                if (googler.hasMinInNorm(min)) {
                    count++;
                } else if (sup > 0 && googler.hasMinInSup(min)) {
                    count++;
                    sup--;
                }
            }

            out.write("Case #" + (i + 1) + ": " + count + "\n");
        }
        out.close();
    }
}

class Scores {
    public int A = -1, B = -1, C = -1;

    public boolean hasMin(int min) {
        return A >= min || B >= min || C >= min;
    }
}

class Googler {

    public ArrayList<Scores> normal = new ArrayList<Scores>();
    public ArrayList<Scores> sup = new ArrayList<Scores>();
    public boolean hasSup = false;

    public boolean hasMinInSup(int min) {
        for (int i = 0; i < sup.size(); i++) {
            if (sup.get(i).hasMin(min))
                return true;
        }
        return false;
    }

    public boolean hasMinInNorm(int min) {
        for (int i = 0; i < normal.size(); i++) {
            if (normal.get(i).hasMin(min))
                return true;
        }
        return false;
    }
}
