/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author Bansari
 */
public class omino {
    
    public static void main(String ar[]) throws Exception{
        BufferedReader f = new BufferedReader(new FileReader("omino.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
        int cases = Integer.parseInt(f.readLine());
        for(int i = 0;i<cases;i++){
              StringTokenizer st = new StringTokenizer(f.readLine());
              
              int x = Integer.parseInt(st.nextToken());
              int r = Integer.parseInt(st.nextToken());
              int c = Integer.parseInt(st.nextToken());
              
              //Richard will pick omino so that gabriel will not be
//              able to solve puzzle
//              
              boolean ans = true;
              if (x>=7){
                  ans = false;
              }else if(x>r && x>c){
                  ans = false;
              }else if(r*c % x !=0){
                  ans = false;
              }else if( (x+1)/2 > Math.min(r, c)){
                  ans = false;
              }else if(x==1 || x==2 || x==3){
                  ans = true;
              }else if(x==4){
                  ans = Math.min(r, c) > 2;
              }else if(x == 5){
                  ans = !(Math.min(r, c)==3 && Math.max(r, c) == 5);
              }else if(x == 6){
                  ans = Math.min(r, c) > 3;
              }
              System.out.println("Case #"+(i+1)+": "+(ans?"GABRIEL":"RICHARD"));
              out.println("Case #"+(i+1)+": "+(ans?"GABRIEL":"RICHARD"));
              
        }
        f.close();
        out.close();
        
    }

}
