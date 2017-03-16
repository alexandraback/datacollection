package com.ariantoanugerah.gcj2014.r1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by ariantoanugerah on 04/05/14.
 */
public class CBoredTS {

    private String fileName = "C-small-attempt0";

    private Scanner sc;
    private PrintWriter pw;

    public static void main(String[] args) {
        CBoredTS q = new CBoredTS();
        q.start();
    }

    private void start() {
        try {
            String dir = "src" + File.separator + CBoredTS.class.getName().replaceAll("\\.", File.separator);
            dir = dir.substring(0, dir.lastIndexOf(File.separatorChar)+1);

            sc = new Scanner(new File(dir + fileName + ".in"));
            pw = new PrintWriter(new File(dir + fileName + ".out"));

            int totalCase = Integer.parseInt(sc.nextLine());

            for (int caseNo = 1; caseNo <= totalCase; caseNo++) {
                CaseSolver cs = new CaseSolver(caseNo, sc, pw);
                String result = cs.start();

                pw.println("Case #" + caseNo + ": " + result);
                System.out.println("Case #" + caseNo + ": " + result);
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

        String min = null;
        int targetLength = 0;

        Map<Integer, Set<CityZip>> routeMap = new HashMap<Integer, Set<CityZip>>();
        Map<Integer, CityZip> zipMap = new HashMap<Integer, CityZip>();

        public CaseSolver(int caseNo, Scanner sc, PrintWriter pw) {
            this.caseNo = caseNo;
            this.pw = pw;
            this.sc = sc;
        }

        public String start() {

            int n = sc.nextInt();
            int m = sc.nextInt();
            targetLength = n * 5;

            for (int i = 0; i < n; i++) {
                CityZip cz = new CityZip(i+1, sc.nextInt());
                zipMap.put(i + 1, cz);
            }
            for (int i = 0; i < m; i++) {
                int one = sc.nextInt();
                int two = sc.nextInt();

                if (routeMap.get(one) == null) {
                    routeMap.put(one, new TreeSet<CityZip>());
                }
                routeMap.get(one).add(zipMap.get(two));

                if (routeMap.get(two) == null) {
                    routeMap.put(two, new TreeSet<CityZip>());
                }
                routeMap.get(two).add(zipMap.get(one));

            }

            StringBuilder sb = new StringBuilder();

            for (Integer city : zipMap.keySet()) {
                trace(new Stack<Integer>(), city, sb);
            }


            return min;
        }

        public void trace(Stack<Integer> traversed, int city, StringBuilder sb) {
            sb.append(zipMap.get(city).zip);
            traversed.push(city);
            System.out.println(sb.toString());
            if (sb.length() == targetLength) {

                if (min == null || min.compareTo(sb.toString()) > 0) {
                    min = sb.toString();
                }
            } else {
                Set<CityZip> czset = routeMap.get(city);
                for (CityZip cz : czset) {
                    if (!traversed.contains(cz.id)) {
                        trace(traversed, cz.id, sb);
                    }
                }
            }

            traversed.pop();
            sb.delete(sb.length()-5, sb.length());
        }

    }

    class CityZip implements Comparable<CityZip> {
        int id;
        int zip;

        public CityZip(int id, int zip) {
            this.id = id;
            this.zip = zip;
        }

        @Override
        public int compareTo(CityZip cityZip) {
            if (this.zip < cityZip.zip) {
                return -1;
            } else if (this.zip > cityZip.zip) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

