
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Chamika
 */
public class GDance {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int cases = s.nextInt();
        
        for(int i = 0;i < cases;i++){
            int x = s.nextInt();
            int y = s.nextInt();
            int z = s.nextInt();
            int res = 0;
            for(int j = 0;j < x;j++){
                int a = s.nextInt();
                int X = a/3;
                int Y = a%3;
                if (X >= z){
                    res++;
                }else if (Y >= 1 && X + 1 >= z){
                    res++;
                }else if( y != 0 && Y == 2 && X + Y >= z){
                    y--;
                    res++;
                }else if (y != 0 && X != 0 && Y == 0 && X + 1 >= z){
                    y--;
                    res++;
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + res);
        }
    }
}
