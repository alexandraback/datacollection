
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
        int[] l = new int[n];
        double[] r = new double[n];
        double sum = 0;
        for(int i = 0 ; i < n ; i++){
            l[i] = s.nextInt();
            sum += l[i];
        }
        for(int i = 0 ; i < n ; i++){
            r[i] = 1.0/n + ((sum/n) - l[i])/sum;
        }

        for(int i = 0 ; i < n ; i++){
            if(r[i]<0){
                int c = 0;
                for(int t = 0 ; t < n ; t++){if(r[t] > 0){c++;}}
                double v = r[i]/c;
                for(int t = 0 ; t < n ; t++){if(r[t]>0){r[t] += v;}}
                r[i] = 0;
            }
        }

        for(int i = 0 ; i < n; i++){
            r[i] *= 100;
            System.out.print(r[i]+" ");
        }
        System.out.println();
        
    }

}
