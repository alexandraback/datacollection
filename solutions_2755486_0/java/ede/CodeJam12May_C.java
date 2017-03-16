/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam12may_c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.TreeMap;
import javax.swing.JFileChooser;

/**
 *
 * @author fgoss_000
 */
public class CodeJam12May_C {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JFileChooser fc = new JFileChooser("C:\\Users\\fgoss_000\\Desktop");
        int res = fc.showOpenDialog(null);
        if(res == JFileChooser.APPROVE_OPTION){
            File file = fc.getSelectedFile();
            try{
                computeFile(file);
                System.out.println("done. ");
            }catch(FileNotFoundException ex){
                System.err.println("file not found: " + ex);
            } catch (IOException ex) {
                System.err.println("io exception: " + ex);
            }
        }
    }

    public static void computeFile(File file) throws FileNotFoundException, IOException{
        BufferedReader in = new BufferedReader(new FileReader(file));
        BufferedWriter out = new BufferedWriter(new FileWriter(new File(file.getParent(), "solution_C.txt")));
        int nCases = Integer.parseInt(in.readLine());
        for(int i=0; i<nCases; i++){
            String[] words = in.readLine().split(" ");
            int n = Integer.parseInt(words[0]);
            int[] firstDay = new int[n];
            int[] attacks = new int[n];
            int[] firstWest = new int[n];
            int[] firstEast = new int[n];
            int[] firstStrength = new int[n];
            int[] time = new int[n];
            int[] distance = new int[n];
            int[] deltaStrength = new int[n];
            for(int j=0; j<n; j++){
                words = in.readLine().split(" ");
                firstDay[j] = Integer.parseInt(words[0]);
                attacks[j] = Integer.parseInt(words[1]);
                firstWest[j] = Integer.parseInt(words[2]);
                firstEast[j] = Integer.parseInt(words[3]);
                firstStrength[j] = Integer.parseInt(words[4]);
                time[j] = Integer.parseInt(words[5]);
                distance[j] = Integer.parseInt(words[6]);
                deltaStrength[j] = Integer.parseInt(words[7]);
            }
            int solution = computeCase(firstDay, attacks, firstWest, firstEast, firstStrength, time, distance, deltaStrength);
            out.write("Case #" + (i+1) + ": " + solution + "\n");
        }
        in.close();
        out.close();
    }

    public static int computeCase(int[] firstDay, int[] attacks, int[] firstWest, int[] firstEast, int[] firstStrength, int[] time, int[] distance, int[] deltaStrength){
        ArrayList<Attack> list = new ArrayList<>();
        for(int i=0; i<firstDay.length; i++){
            for(int j=0; j<attacks[i]; j++){
                list.add(new Attack(firstDay[i] + time[i]*j, firstWest[i] + distance[i]*j, firstEast[i] + distance[i]*j, firstStrength[i] + deltaStrength[i]*j));
            }
        }
        Collections.sort(list);
        System.out.println(list);
        TreeMap<Integer, Integer> wall = new TreeMap<>();
        TreeMap<Integer, Integer> repairedWall = (TreeMap<Integer, Integer>)wall.clone();
        int successfulAttacks = 0;
        int dayBefore = -1;
        for(Attack a : list){
            if(a.day > dayBefore)
                wall = (TreeMap<Integer, Integer>)repairedWall.clone();
            boolean success = false;
            for(int i=a.west; i<=a.east; i++){
                if(wall.get(i) == null)
                    wall.put(i, 0);
                if(wall.get(i) < a.strength){
                    success = true;
                    repairedWall.put(i, a.strength);
                }
            }
            if(success)
                successfulAttacks++;
        }
        return successfulAttacks+1;
    }
}
