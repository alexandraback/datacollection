/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package RecycledNumbers;

import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Rishabh
 */
public class RecycledNumbers {
    
    public void readFile(String path) throws Exception{
        File f = new File(path);
        Scanner scan = new Scanner(f);
        String name = f.getName().substring(0,f.getName().indexOf('.'));
        Writer writer = new FileWriter(name+".out");
        int total_cases = Integer.parseInt(scan.nextLine());
        int caseno=0;
        while(scan.hasNextLine()){
            caseno++;
            long[] toIntArray = toIntArray(scan.nextLine().split(" "));
            int ans = compute((int)toIntArray[0],(int)toIntArray[1]);
            writer.write("Case #"+caseno+": "+ans+"\r\n");
        }
        writer.close();
        scan.close();
    }
    
    public static long[] toIntArray(String[] arr){
        long[] new_arr = new long[arr.length];
        int count = 0;
        for(String g : arr){
            new_arr[count] = Long.parseLong(g);
            count++;
        }
        return new_arr;
    }

    private int compute(int A, int B) {
        int count=0;
        List[] l = new LinkedList[B-A+1];
        for(int i=A;i<=B;i++){
            int c = getAllPermutations(i, A, B, l);
            count += c;
            //System.out.println("permutations for : "+i+" are " + c);
        }
        return count;
    }
    
    private int getAllPermutations(int num, int A, int B, List[] l){
        String g = String.valueOf(num);
        List<Integer> permutations = new LinkedList<Integer>();
        boolean found = false;
        for(int i=1;i<g.length();i++){
            String new_g = g.substring(i) + g.substring(0, i);
            if(new_g.charAt(0) == '0')
                continue;
            int parseInt = Integer.parseInt(new_g);
            if(parseInt>B||parseInt<A||parseInt==num)
                continue;
            found = false;
            for(int n : permutations){
                if(n==parseInt){
                    found = true;
                    break;
                }
            }
            if(found)
                continue;
            if(l!=null && contains(l[num-A],parseInt))
                continue;
            permutations.add(parseInt);
            if(l[parseInt-A]==null){
                l[parseInt-A] = new LinkedList();
            }
            l[parseInt-A].add(num);
        }
        return permutations.size();
    }
    
    private boolean contains(List l, int n){
        if(l != null)
            for(Object k : l){
                if(n==(Integer)k)
                    return true;
            }
        return false;
    }
    
    public static void main(String args[]) throws Exception{
        RecycledNumbers recycledNumbers = new RecycledNumbers();
        recycledNumbers.readFile("A-small-practice.in");
    }
    
}
