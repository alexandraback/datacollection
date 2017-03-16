/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.*;

/**
 *
 * @author wijebandara
 */
public class PasswordProblem {
    public static void main(String[] args) throws FileNotFoundException, IOException {

        //java.io.BufferedReader in = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        java.io.BufferedReader in=new java.io.BufferedReader(new java.io.FileReader("/home/wijebandara/Desktop/A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("/home/wijebandara/Desktop/A-small-attempt0.out")));
    
        int n=Integer.parseInt(in.readLine());
        java.util.StringTokenizer st;
        int a,b;
        float answer;
        for(int i=0;i<n;i++)
        {
            st=new java.util.StringTokenizer(in.readLine());
            a=Integer.parseInt(st.nextToken());
            b=Integer.parseInt(st.nextToken());
            //int data[]=new int[a];
            //int ans[]=new int [a];
            st=new java.util.StringTokenizer(in.readLine());
            float pro=1;
            float ex=0;
            answer=3*b; 
            for(int j=0;j<a;j++)
            {
                //data[j]=Integer.parseInt(st.nextToken());
                pro*=Float.parseFloat(st.nextToken());
                ex=0;
                ex+=pro*(b+a-2*j-1);
                ex+=(1-pro)*(2*b+a-2*j);
                //System.out.println("..."+ex);
               if(ex<answer)
               {
                   answer=ex;
               }
            }
            ex=b+2;
            //System.out.println("..."+ex);
            if(ex<answer)
               {
                   answer=ex;
               }
            
            ex=pro*(b-a+1);
            ex+=(1-pro)*(b-a+1+b+1);
            //System.out.println("..."+ex);
            if(ex<answer)
               {
                   answer=ex;
               }
            System.out.println("Case #"+(i+1)+": "+answer);            
            out.println("Case #"+(i+1)+": "+answer);
        }
        out.close();
        
    }
}   

