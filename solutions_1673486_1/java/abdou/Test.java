/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;

/**
 *
 * @author Student
 */
public class Test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        // TODO code application logic here
        int i=1,max=0;
        Scanner s=new Scanner(new File("A-large.in"));
        PrintWriter x=new PrintWriter(new File("A-large.out"));
        if(s.hasNextLine()) max=s.nextInt();
                    s.nextLine();
        while(i<=max){
            String a = null;
            if(s.hasNextLine())  a=s.nextLine();
            String[] S=a.split(" ");
            int A=Integer.parseInt(S[0]+"");
            int B=Integer.parseInt(S[1]+"");
            if(s.hasNextLine())  a=s.nextLine();
            S=a.split(" ");
            double[] d=new double[A];
            for(int j=0;j<A;j++) d[j]= Double.parseDouble(S[j]+"");
            double T=Math.min((double)B+2,(double)A+B+1);
            for(int y=0;y<A;y++){
                double p=1.0;
                for(int k=0;k<A-y;k++){
                    p=p*d[k];    
                } 
              T=Math.min(T,(1-p)*(y+B-(A-y)+B+2)+p*(y+B-(A-y)+1)) ;
            }

            DecimalFormat df=new DecimalFormat(".000000", new DecimalFormatSymbols(Locale.US));
            x.println("Case #"+i+": "+df.format(T));
            i++;
        }
        x.close();
        }

    }

   
