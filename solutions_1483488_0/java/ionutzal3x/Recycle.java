/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package recycle;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 *
 * @author ALEX
 */
public class Recycle {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try {
             FileReader fin=new FileReader("C-small-attempt0.in");
             BufferedReader in = new BufferedReader(fin);
             FileWriter fout=new FileWriter("result.txt");
             BufferedWriter out=new BufferedWriter(fout);
             int nrt;
             nrt=Integer.valueOf(in.readLine());
             String [] med;
             String str;
             for(int i=1;i<=nrt;i++)
             {  
                 str=in.readLine();
                 med=str.split(" ");
                 int A=Integer.valueOf(med[0]);
                int B=Integer.valueOf(med[1]);
                int nr=0;
                String s;
                for (int a=A;a<=B;a++){
                    int x;
                    int mo=1;
                    while((a/mo)%10==0){
                mo=mo*10;
                    } 
                    if(a/mo>9){
                        mo=mo*10;
                        s=(a%mo+""+a/mo);
                        x=Integer.valueOf(s);
                    }
                    else continue;                    
                    while(a!=x){
                        if(x>=A&&x<=B){
                            nr++;
                        }
                        mo=1;
                    while((x/mo)%10==0){
                        mo=mo*10;
                    } 
                    if(x/mo>9){
                        mo=mo*10;
                        s=(x%mo+""+x/mo);
                        x=Integer.valueOf(s);
                    }
                    else break; 
                    }      
                }
                System.out.println(nr/2);
                out.write("Case #"+i+": "+nr/2);
                out.newLine();
                }
             in.close();
             fin.close();
             out.close();
             fout.close();
             }
        catch(Exception e){} 
    }       
             
}
