/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package GCJ20131C;

/**
 *
 * @author JuanM
 */
import java.util.Scanner;
import java.io.PrintWriter;
public class PA_Consonants {
    static Scanner sc=new Scanner(System.in);
    static PrintWriter out=new PrintWriter(System.out);
    static int cnt,d;
    
    public static void countCons(String st){
        int c=0;
        for(int i=0;i<st.length();i++){
            if(st.charAt(i)!='a'&&st.charAt(i)!='e'&&st.charAt(i)!='i'&&st.charAt(i)!='o'&&st.charAt(i)!='u'){
                c++;
            }else{
                c=0;
            }
            if(c==d){
                cnt++;
                break;
            }
        }
    }
    
    public static void main(String[]args){
        int t;
        String s;
        t=sc.nextInt();
        for(int ii=1;ii<=t;ii++){
            cnt=0;
            s=sc.next();
            d=sc.nextInt();
            for(int i=0;i<=s.length()-d;i++){
                for(int j=i+d;j<=s.length();j++){
                    //out.println(s.substring(i,j));
                    countCons(s.substring(i,j));
                }
            }
            out.printf("Case #%d: %d\n",ii,cnt);
        }
        out.flush();
    }
    
}
