/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package problema;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A-large.in"));
        //Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        
        int test = in.nextInt();
        for (int t =0; t<test; t++){
            Long n = in.nextLong();
            String s = n.toString();
            long num=0;
            while (n>9){
                //s=n.toString();
                if (s.charAt(s.length()-1)=='0'){
                    n = n-9;
                    num+=9;
                    s = n.toString();
                } else{
                    n = n- (int)(s.charAt(s.length()-1)-'0')+1;
                    num+= (int)(s.charAt(s.length()-1)-'0')-1;
                }
                int ind = (s.length()+1)/2;
                long dec=1;
                for (int j=0; j<ind; j++){
                    dec*=10;
                }
                num+=n%dec-1;
                n=n-n%dec+1;
                s = n.toString();
                boolean q = false;
                for (int i=0; i<ind; i++){
                    if (s.charAt(i)!=s.charAt(s.length()-1-i)) {
                        q = true;
                    }
                }
                if (q){
                    num+=1;
                    String s1 = new String();
                    for (int i=s.length()-1; i>-1; i--){
                       s1+=s.charAt(i);
                    }
                    s=s1;
                    n=Long.decode(s1);
                }
                else if (n>1){
                    n-=2;
                    num+=2;
                    s=n.toString();
                }
            }
            if ((n>0)&&(n<10)){
                num+=n;
            }
            out.println("Case #"+(t+1)+": "+num);
        }
        
        out.flush();
        out.close();
    }
    
}
