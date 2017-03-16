/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication7;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeSet;

/**
 *
 * @author admin
 */
public class Round1A_B_2016 {

    /**
     * @param args the command line arguments
     */
        
    public static void main(String[] args) {
        BufferedReader br1 = null;
        BufferedWriter br2 = null;
        try {
 		br1 = new BufferedReader(new FileReader("B-large.in"));
                br2 = new BufferedWriter(new FileWriter("B-large-practice-1.out"));
                int noLines = Integer.parseInt(br1.readLine());
                for (int i = 0; i < noLines; i++) {
                    String line = br1.readLine();
                    String[] orders = new String[Integer.parseInt(line)];
                    HashMap<String,Integer> numberCount = new HashMap<>();
                    for (int j=0; j< 2*Integer.parseInt(line)-1; j++) {
                        orders = br1.readLine().split(" ");
                        for (int k=0; k<orders.length; k++)
                            if (numberCount.containsKey(orders[k])) {
                                int num = numberCount.get(orders[k]);
                                numberCount.put(orders[k], ++num);
                            }
                            else
                                numberCount.put(orders[k], 1);
                    }
                    TreeSet<Integer> ans = new TreeSet();
                    Iterator it = numberCount.entrySet().iterator();
                    while (it.hasNext()) {
                        Map.Entry pair = (Map.Entry)it.next();
                        if ((int)pair.getValue() % 2 == 1) {
                            String temp = (String)pair.getKey();
                            ans.add(Integer.parseInt(temp));
                        }
                    }
                    line = ans+"";
                    line = line.replace(",", "");
                    line = line.replace("[", "");
                    line = line.replace("]", "");
                    System.out.println(line);
                    br2.write("Case #"+(i+1)+": "+line+"\n");
                }
            br1.close();
            br2.close();
        } catch (Exception e) {
            e.printStackTrace();
        }	
    }

}
