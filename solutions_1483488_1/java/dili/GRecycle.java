
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Chamika
 */
public class GRecycle {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int cases = s.nextInt();
        HashSet<Integer> al = new HashSet<>();
        for(int i = 0;i < cases;i++){
            int x = s.nextInt();
            int y = s.nextInt();
            int res = 0;
            
            for(int j = x;j <= y;j++){
                int z = Integer.toString(j).length();
                int a = j;
                al.clear();
                for(int k = 0;k < z;k++){
                    a = (a%(10))*(int)Math.pow(10,z - 1) + a/10;
                    res = (a > j && a <= y && !al.contains(a)) ? res + 1 : res;
                    al.add((a > j && a <= y) ? a : 0);
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + res);
        }
    }
}
