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
public class RecycledNumbers {
    public static void main(String[] args) throws FileNotFoundException, IOException {

        //java.io.BufferedReader in = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        java.io.BufferedReader in=new java.io.BufferedReader(new java.io.FileReader("/home/wijebandara/Desktop/C-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("/home/wijebandara/Desktop/C-large.out")));

        int n = Integer.parseInt(in.readLine());
        
        java.util.StringTokenizer st ;
        for(int i=0;i<n;i++)
        {
            st=new java.util.StringTokenizer(in.readLine());
            
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int ans=0;
            for(int j=a;j<=b;j++)
            {
                java.util.ArrayList <Integer> l =new java.util.ArrayList<Integer>();
                int h =(int)Math.log10(j);
                for(int k=1;k<=h;k++)
                {
                    int p=change(j,k);
                    if(p>j && !l.contains(p) && p>=a && p<=b)
                    {
                        l.add(p);
                        ans++;
                    }
                }
            }
            //System.out.print("Case #" + (i + 1) + ": ");
            out.print("Case #" + (i + 1) + ": ");
            //System.out.println(ans);
            out.println(ans);
        }
        out.close();
    }
    static int change(int x,int n)
    {
        int a=(int)(Math.pow(10, n));
        int hold=x%a;

        int b =(int)Math.log10(x)+1;
        x=(x-hold)/a;

        return hold*(int)Math.pow(10, b-n)+x;
    } 
}
