
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author bartosz
 */
public class A {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int i=0;i<t;i++){
            String s = in.next();
            String answer = ""+s.charAt(0);
            for(int j=1;j<s.length();j++){
                int first =(int) answer.charAt(0);
                int current = (int) s.charAt(j);
                if(current>=first)
                    answer = s.charAt(j) + answer;
                else
                    answer = answer + s.charAt(j);
            }
            System.out.println("Case #"+(i+1)+": "+answer);
        }
    }
}
