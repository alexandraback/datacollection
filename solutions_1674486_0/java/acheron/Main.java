/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Round1C2012.a;

import Qualifier2012.c.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;
import java.util.Vector;

/**
 *
 * @author Ant Ongun Kefeli
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileInputStream fis = new FileInputStream("src\\Round1C2012\\a\\A-small-attempt0.in");
        Scanner sc = new Scanner(fis);

        FileWriter fw = new FileWriter("src\\Round1C2012\\a\\output.out");
        BufferedWriter out = new BufferedWriter(fw);

        int caseCount = 0;
        caseCount = sc.nextInt();
        for (int casec = 0; casec < caseCount; casec++) {
            int nodeCount = sc.nextInt();
            ArrayList<ArrayList<Integer>> nodes = new ArrayList<ArrayList<Integer>>(nodeCount);
            for (int j = 0; j < nodeCount; j++) {
                int Mi = sc.nextInt();
                ArrayList<Integer> al = new ArrayList(Mi);
                for (int k = 0; k < Mi; k++) {
                    al.add(sc.nextInt() - 1);
                }
                nodes.add(al);
            }

            boolean res = doit(out, casec + 1, nodes);
            String resf = (res ? "Yes" : "No");
            out.write("Case #" + (casec+1) + ": " + resf + "\n");

        }

        out.close();
        sc.close();
    }

    private static boolean doit(BufferedWriter out, int casec, ArrayList<ArrayList<Integer>> nodes) throws IOException {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.get(i).size() >= 2) {
                Set tmp = null;
                for (int j = 0; j < nodes.get(i).size(); j++) {
                    list.clear();
                    list.add(nodes.get(i).get(j));
                    visit(nodes.get(i).get(j), nodes);
                    if (tmp != null) {
                        Set tmptmp = new HashSet(tmp);
                        tmptmp.retainAll(list);
                        if (tmptmp.size() > 0) {
                            return true;
                        }
                        tmp.add(list);
                    } else {
                        tmp = new HashSet(list);
                    }
                }
            }
        }
        return false;
    }
    static Set<Integer> list = new HashSet<Integer>();

    private static void visit(int node, ArrayList<ArrayList<Integer>> nodes) {
        for (int k = 0; k < nodes.get(node).size(); k++) {
            list.add(nodes.get(node).get(k));
            visit(nodes.get(node).get(k), nodes);
        }
    }
}
