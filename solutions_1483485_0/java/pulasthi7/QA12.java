
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author pulasthi
 */
public class QA12 {
    public static void main(String[] args) throws Exception{
        Scanner sc= new Scanner(System.in);
        PrintWriter out = new PrintWriter("a.txt");
        int T = sc.nextInt();
        sc.nextLine();
        char[] mapping = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
        for (int i = 0; i < T; i++) {
            String line = sc.nextLine();
            char[] dec = new char[line.length()];
            for (int j = 0; j < line.length(); j++) {
                if(line.charAt(j)==' '){
                    dec[j] = ' ';
                } else{
                    dec[j] = mapping[line.charAt(j)-'a'];
                }
            }
            out.print("Case #"+(i+1)+": ");
            out.println(new String(dec));
        }
        out.flush();
        out.close();
    }
    
}
