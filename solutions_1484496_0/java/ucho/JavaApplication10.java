/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication10;

import com.sun.xml.internal.ws.util.StringUtils;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 *
 * @author ucho
 */
public class JavaApplication10 {
    static Map.Entry<Set<Integer>, Set<Integer>> doIt(Set<Integer> a, Set<Integer> b, SortedSet<Integer> pool, int sumA,int sumB) {
        if (!a.equals(b) && !a.isEmpty() && sumA==sumB && !b.isEmpty()) {
            //System.out.println("Impossible "+sumA+" "+sumB);
            return new HashMap.SimpleEntry<Set<Integer>, Set<Integer>>(a,b);
        }
        if (pool.isEmpty()) {
            return null;
        }
        Set<Integer> newA = new HashSet<Integer>(a);
        Set<Integer> newB = new HashSet<Integer>(b);
        SortedSet<Integer> newPool = new TreeSet<Integer>(pool);
        Integer tmp = newPool.first();
        newPool.remove(tmp);
        newA.add(tmp);
        Map.Entry<Set<Integer>, Set<Integer>> r = doIt(newA, b, newPool, sumA+tmp, sumB);
        if (r!= null) {
            return r;
        }
        newB.add(tmp);
        r = doIt(a, newB, newPool, sumA, sumB+tmp);
        if (r!= null) {
            return r;
        }
        
        return doIt(a, b, newPool, sumA, sumB);
        
        
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        PrintWriter writer = new PrintWriter(new FileWriter("output"));
        Scanner scanner = new Scanner(new FileReader("input"));
        int tests = scanner.nextInt();
        scanner.nextLine();
        for(int t=0;t<tests;t++) {
            int n = scanner.nextInt();
            int [] scores = new int[n];
            SortedSet<Integer> values = new TreeSet<Integer>();
            
            for (int i = 0; i < n; i++) {
                scores[i] = scanner.nextInt();
                values.add(scores[i]);
            }
            Map.Entry<Set<Integer>, Set<Integer>> r = doIt(new HashSet<Integer>(), new HashSet<Integer>(), values, 0, 0);
            String msg = "Case #"+(t+1)+":";
            System.out.println(msg);
            writer.println(msg);
            //System.out.println(r);
            if (r== null) {
                System.out.println("Impossible");
                writer.println("Impossible");
            } else {
                System.out.println(join(r.getKey(), " "));
                System.out.println(join(r.getValue(), " "));
                writer.println(join(r.getKey(), " "));
                writer.println(join(r.getValue(), " "));
            }
            scanner.nextLine();
        }
        writer.close();
        
    }
    
    
    public static String join(Collection s, String delimiter) {
        StringBuffer buffer = new StringBuffer();
        Iterator iter = s.iterator();
        while (iter.hasNext()) {
            buffer.append(iter.next());
            if (iter.hasNext()) {
                buffer.append(delimiter);
            }
        }
        return buffer.toString();
    }
}
