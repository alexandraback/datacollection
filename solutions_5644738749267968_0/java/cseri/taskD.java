package hu.csq.codejam2014;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Scanner;


public class taskD {
    
    private static LinkedList<Double> arrayToList(double[] arr)
    {
        LinkedList<Double> ret = new LinkedList<>();
        for (double e : arr) {
            ret.add(e);
        }
        return ret;
    }
    
    private static int solveDWar(int n, double[] nao_, double[] ken_)
    {
        LinkedList<Double> nao = arrayToList(nao_);
        LinkedList<Double> ken = arrayToList(ken_);
        
        int naopoints = 0;
        
        while (!nao.isEmpty()) {
            if (nao.getFirst() > ken.getFirst()) {
                //Nao can win an element
                nao.pollFirst();
                ken.pollFirst();
                ++naopoints;
            } else {
                //Nao can pop Ken's biggest element
                nao.pollFirst();
                ken.pollLast();
            }
        }
        
        return naopoints;
    }
    
    private static int solveWar(int n, double[] nao, double[] ken)
    {
        int naoat = 0;
        int kenpoints = 0;
        
        for (int kenat = 0; kenat < n; ++kenat)
        {
            if (ken[kenat] > nao[naoat]) {
                ++naoat;
                ++kenpoints;
            }
        }

        return n - kenpoints;    
    }
    
    private static int[] mainTestCase(Scanner sc) {
        int n = sc.nextInt();
        
        double[] nao = new double[n];
        for (int i = 0; i < n; ++i) {
            nao[i] = sc.nextDouble();
        }
        double[] ken = new double[n];
        for (int i = 0; i < n; ++i) {
            ken[i] = sc.nextDouble();
        }

        Arrays.sort(nao);
        Arrays.sort(ken);
        
        if (n < 20) {
            System.out.println("Nao: " + Arrays.toString(nao));
            System.out.println("Ken: " + Arrays.toString(ken));
        }
        
        
        int[] ret = new int[2];
        ret[0] = solveDWar(n, nao, ken);
        ret[1] = solveWar(n, nao, ken);
        return ret;
    }

    public static void main(String[] args) throws IOException {
        //final String baseFileName = args.length > 2 ? "taskD."+args[1] : "taskD.example";
        final String baseFileName = "D-small-attempt0";
        Scanner sc = new Scanner(new File(baseFileName+".in"));
        sc.useLocale(Locale.ROOT);
        

        PrintWriter pw = new PrintWriter(baseFileName+".out");

        int tn = sc.nextInt();
        for (int ti = 0; ti < tn; ++ti) {
                int[] result = mainTestCase(sc);

                String output = "Case #" + (ti+1) + ": " + result[0] + " " + result[1];
                System.out.println(output);
                pw.println(output);
        }

        sc.close();
        pw.close();        
    }
    
}
