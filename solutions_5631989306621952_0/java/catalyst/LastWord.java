/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lastword;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author bhavishyasharma
 */
public class LastWord {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
            // TODO code application logic here
            Scanner sc = new Scanner(System.in);
            int t=sc.nextInt();
            sc.nextLine();
            for(int i=0;i<t;i++){
                String str=sc.nextLine();
                StringBuilder sb=new StringBuilder("");
                sb.append(str.charAt(0));
                for(int j=1;j<str.length();j++){
                    if(str.charAt(j)>=sb.charAt(0)){
                        sb.insert(0, str.charAt(j));
                    }
                    else{
                        sb=sb.append(str.charAt(j));
                    }
                }
                System.out.printf("Case #%d: %s\n", i + 1, sb.toString());
            }
    }
    
}
