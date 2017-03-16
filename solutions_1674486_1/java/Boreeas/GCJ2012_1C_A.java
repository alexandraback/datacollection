/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2012_1c_a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map.Entry;
import java.util.Set;

/**
 *
 * @author malte
 */
public class GCJ2012_1C_A {

    public static HashMap<Integer, Clazz> classes = new HashMap<Integer, Clazz>();
    
    static BufferedWriter writer;
    static int casenum = 0;
    
    public static void main(String[] args) throws Exception {
        
        File o = new File("./out");
        o.getParentFile().mkdirs();
        o.createNewFile();
        
        writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(o)));
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(new File("./in"))));
        
        String in;
        reader.readLine(); // Skip numofcases
        while ((in = reader.readLine()) != null && !in.equals("")) {
            
            classes.clear();
            
            int num = Integer.parseInt(in);
            for (int i = 1; i <= num; i++) {
                
                Clazz newClazz = new Clazz(i);
                classes.put(i, newClazz);
                
                String inherit = reader.readLine();
                String[] data = inherit.split(" ");
                for (int j = 1; j < data.length; j++) {
                    
                    newClazz.inherit.add(Integer.parseInt(data[j]));
                }
            }
            
            boolean match = false;
            for (Entry<Integer, Clazz> entry: classes.entrySet()) {
                
                if (getSub(entry.getKey(), 0) == null) {
                    
                    write("Yes");
                    match = true;
                    break;
                } 
            }
            
            if (!match) {
                write("No");
            }
        }
        
        reader.close();
        writer.flush();
        writer.close();
    }
    
    public static void write(String out) throws IOException {
        
        casenum++;
        writer.write(String.format("Case #%s: %s%n", casenum, out));
    }
    
    public static Set<Integer> getSub(int i, int in) {
        
        Set<Integer> indirect = new HashSet<Integer>();
        
        for (int j: classes.get(i).inherit) {
            
            if (indirect.contains(j)) {
                return null;
            }
            
            indirect.add(j);
            Set<Integer> sub = getSub(j, in+1);
            
            if (sub == null) {
                return null;
            }
            
            for (int k: sub) {
                if (indirect.contains(k)) {
                    return null;
                }
                
                indirect.add(k);
            }
        }
        
        return indirect;
    }
}
