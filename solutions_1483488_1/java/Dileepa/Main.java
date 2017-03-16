/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package recycle;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

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
         FileReader fr=new FileReader("C-large.in");
        BufferedReader br=new BufferedReader(fr);
        FileWriter fw=new FileWriter("result.txt");
        PrintWriter pw=new PrintWriter(fw);
getOutPut(br,pw);
pw.close();
    }
    public  static void getOutPut(BufferedReader br,PrintWriter pw) throws IOException {
        int t=Integer.parseInt(br.readLine());
       int A,B;
        for(int i=0;i<t;i++){
        String[] s=br.readLine().split(" ");
         A=Integer.parseInt(s[0]);
         B=Integer.parseInt(s[1]);
           
        pw.print("Case #"+(i+1)+": "+recyles(A,B));
         
        pw.println();
        }
    }

    public  static int recyles(int A,int B) {
        ArrayList<Integer> num;
        String Sa,Sb;
        int count=0;
        Sa=Integer.toString(A);
        Sb=Integer.toString(B);
        for(int i=A;i<=B;i++){
            num=new ArrayList<Integer>();
          for(int j=Sa.length()-1;j>0;j--){
            Sa=Integer.toString(i).substring(j)+Integer.toString(i).substring(0,j);
            if(Integer.parseInt(Sa)<=B&&Sa.charAt(0)!='0'&&i<Integer.parseInt(Sa)){
                if(!num.contains(Integer.parseInt(Sa))){
                num.add(Integer.parseInt(Sa));
                count++;
                }

              }
          }
        }
        
        return count;
    }

}
