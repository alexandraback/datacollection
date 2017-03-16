
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Me
 */
public class Main {

 public static Scanner s = new Scanner(System.in);
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int t = s.nextInt();
        for(int i = 1 ; i <= t ; i++){
            System.out.print("Case #"+i+": ");
            start();
        }
    }

    private static void start() {
        int n = s.nextInt();
        ArrayList<HashSet<Integer>> tree = new ArrayList<HashSet<Integer>>();
        //int[] cnt = new int[n];
        for(int i = 0 ; i < n ; i++){
            HashSet<Integer> ta = new HashSet<Integer>();
            tree.add(ta);
        }
         for(int i = 0 ; i < n ; i++){
           int ni = s.nextInt();
           for(int j = 0 ; j < ni ; j++){
               tree.get(s.nextInt()-1).add(i);
           }
           
        }
        //System.out.println(tree);

        for(int i = 0 ; i < n ; i++){
            int[] cnt = new int[n];
            ArrayList<Integer> t = new ArrayList<Integer>();
            t.add(i);
            while(!t.isEmpty()){
                int ind = t.remove(0);
                for(Integer val : tree.get(ind)){
                    cnt[val]++;
                    t.add(val);
                }
            }
            //System.out.println(Arrays.toString(cnt));
            for(int j = 0 ; j < n ; j++){
                if(cnt[j]>1){
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }
}
