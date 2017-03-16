package com.ariantoanugerah.gcj2014.r1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by ariantoanugerah on 04/05/14.
 */
public class BNewLottery {

    private String fileName = "B-small-attempt0";

    private Scanner sc;
    private PrintWriter pw;

    public static void main(String[] args) {
        BNewLottery q = new BNewLottery();
        q.start();
    }

    private void start() {
        try {
            String dir = "src" + File.separator + BNewLottery.class.getName().replaceAll("\\.", File.separator);
            dir = dir.substring(0, dir.lastIndexOf(File.separatorChar)+1);

            sc = new Scanner(new File(dir + fileName + ".in"));
            pw = new PrintWriter(new File(dir + fileName + ".out"));

            int totalCase = Integer.parseInt(sc.nextLine());

            for (int caseNo = 1; caseNo <= totalCase; caseNo++) {
                CaseSolver cs = new CaseSolver(caseNo, sc, pw);
                String result = cs.start();

                pw.println("Case #" + caseNo + ": " + result);
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } finally {
            if (sc!=null) {
                sc.close();
            }
            if (pw!=null) {
                pw.close();
            }
        }
    }

    class CaseSolver {
        Scanner sc;
        PrintWriter pw;
        int caseNo;

        public CaseSolver(int caseNo, Scanner sc, PrintWriter pw) {
            this.caseNo = caseNo;
            this.pw = pw;
            this.sc = sc;
        }

        public String start() {

            int a = sc.nextInt();
            int b = sc.nextInt();
            int k = sc.nextInt();

            int result = 0;

            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if ((i & j) < k) {
                        result++;
                    }
                }
            }

            return String.valueOf(result);
        }

    }
}

