/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package energy1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Energy1 {

    public static int sum(int[] a, int[] b){
        int N=a.length;
        int summ = 0; 
        for(int i = 0; i<N; i++){
            summ+= a[i]*b[i];
        }
        return summ;
    }
    public static void main(String[] args) throws FileNotFoundException {
        String filename = "src/energy1/small";
        File file = new File(filename);
        Scanner scanner = new Scanner(file);
        int T = scanner.nextInt();
        for(int i=1; i<=T; i++){
            int E = scanner.nextInt();
            int R = scanner.nextInt();
            int N = scanner.nextInt();
            int[] v = new int[N];
            int[] e = new int[N];
            int max = 0;
            int sum = 0;
            int maxindex = -1;
            for(int s = 0; s<N; s++){
                v[s] = scanner.nextInt();
                if(v[s]>=max){
                    max=v[s];
                    maxindex = s;
                }
                sum+=v[s];
            }
            int n = E*v[maxindex]+R*(sum-v[maxindex]);
            System.out.println("Case #" + i + ":" + " " + n);
            
        }
    }
}
