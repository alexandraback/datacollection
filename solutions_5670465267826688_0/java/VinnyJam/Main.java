/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package problem3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C-small-attempt2.in"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        
        final int[][] mult = {{2, 3, 1, 0, 7, 6, 4, 5}, {4, 5, 6, 7, 1, 0, 3, 2}, {6, 7, 5, 4, 2, 3, 1, 0}}; 
        
        int t = in.nextInt();
        for (int i=0; i<t; i++){
//            String s0;
//            if (i==1) {
//                 s0 = in.nextLine();
//            }
            int l = in.nextInt();
            long b = in.nextLong();
            long rb=b%4;
            if (b>20) {
                b=21;
            }
            String s = in.nextLine();
            s = in.nextLine();
            String realS = s;
            for (int j=1; j<b; j++){
                realS = realS+s;
            }
            boolean foundi= false, foundj=false , foundk=false;
            int state = 0;
            for (int j=0; j<realS.length(); j++){
                char c = realS.charAt(j);
                int ci=0;
                if (c=='i') ci=0;
                if (c=='j') ci=1;
                if (c=='k') ci=2;
                state = mult[ci][state];
                if (state==2) foundi=true;
                if ((state==6)&&foundi) foundj=true;
                if ((state==1)&&foundj) foundk=true;                
            }
            boolean balance=false;
            if (b==21){
                    if ((rb==1)&&(state==1)) balance=true;
                    if ((rb==2)&&((state>1))) balance=true;
                    if ((rb==3)&&(state==1)) balance = true;
                }
            else{
                if (state==1) balance=true;
            }
            if ((foundk)&&(balance)) {
                out.println("Case #"+(i+1)+": YES");
            }
            else{
                out.println("Case #"+(i+1)+": NO");
            }
        }
        out.flush();
        out.close();
        
    }
    
    
}
