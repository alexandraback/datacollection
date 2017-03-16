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
public class PB_Pogo {
    static Scanner sc=new Scanner(System.in);
    static PrintWriter out=new PrintWriter(System.out);
    
    public static void main(String[]args){
        int t,a,b;
        StringBuffer sx;
        StringBuffer sy;
        t=sc.nextInt();
        for(int ii=1;ii<=t;ii++){
            a=sc.nextInt();
            b=sc.nextInt();
            sx=new StringBuffer("");
            sy=new StringBuffer("");
            if(a!=0){
                if(a<0){
                    sx.append("E");
                }else{
                    sx.append("W");
                }
                sx.append(sx.charAt(sx.length()-1)=='E'?'W':'E');
                for(int i=1;i<Math.abs(a);i++){
                    sx.append(sx.charAt(sx.length()-1)=='E'?'W':'E');
                    sx.append(sx.charAt(sx.length()-1)=='E'?'W':'E');
                }
            }
            if(b!=0){
                if(b<0){
                    sy.append("N");
                }else{
                    sy.append("S");
                }
                sy.append(sy.charAt(sy.length()-1)=='N'?'S':'N');
                for(int i=1;i<Math.abs(b);i++){
                    sy.append(sy.charAt(sy.length()-1)=='N'?'S':'N');
                    sy.append(sy.charAt(sy.length()-1)=='N'?'S':'N');
                }
            }
            sx.append(sy);
            out.printf("Case #%d: %s\n",ii,sx.toString());
        }
        out.flush();
    }
}
