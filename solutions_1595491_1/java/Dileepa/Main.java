/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package dancing;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 *
 * @author admin
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        FileReader fr=new FileReader("B-large.in");
        BufferedReader br=new BufferedReader(fr);
        FileWriter fw=new FileWriter("result3.txt");
        PrintWriter pw=new PrintWriter(fw);
getOutPut(br,pw);
pw.close();
    }
 public  static void getOutPut(BufferedReader br,PrintWriter pw) throws IOException {
        int t=Integer.parseInt(br.readLine());
       int N,S,P;
       int[] num;
        for(int i=0;i<t;i++){
        String[] s=br.readLine().split(" ");
         N=Integer.parseInt(s[0]);
         S=Integer.parseInt(s[1]);
         P=Integer.parseInt(s[2]);
         
           num=new int[N];
           addToArray(s,num);
          Arrays.sort(num);
        pw.print("Case #"+(i+1)+": "+getMax(num,S,P));
         
        pw.println();
        }
    }

    public  static void addToArray(String[] s, int[] num) {
        for(int i=0;i<num.length;i++){
        num[i]=Integer.parseInt(s[3+i]);
        }
    }

    public  static int getMax(int[] num,int S, int P) {
        int count=0;
        for(int i=0;i<num.length;i++){
        if(num[i]%3==0){
        
  if((num[i])/3>=P&&(num[i])/3>=0){
   count++;
 }
 else if ((num[i] + 3) / 3 >= P  && ((num[i] / 3) - 1 >= 0)&&S>0)
        {count++;
         S--;
        }
        }
        if(num[i]%3==1){
            if((num[i]+2)/3>=P&&((num[i]+2)/3)-1>=0 ){
   count++;
 }
 else if ((num[i] + 2) / 3 >= P && ((num[i] + 2) / 3) - 2 >= 0&&S>0) {
          count++;
          S--;
          }
           
        }
        if(num[i]%3==2){
            if((num[i]+1)/3>=P&&((num[i]+1)/3)-1>=0){
   count++;
 }
 else if (S>0&&(num[i] + 4) / 3 >= P &&  ((num[i] + 4) / 3) - 2 >= 0) {
          count++;
           // System.out.print(num[i]+" ");
          S--;
          }
         
        }
        }
        return count;
    }
}
