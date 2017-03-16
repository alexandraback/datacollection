/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.*;
import java.util.Arrays;

/**
 *
 * @author wijebandara
 */
public class KingdomRush
{
    public static void main(String[] args) throws FileNotFoundException, IOException {

        //java.io.BufferedReader in = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        java.io.BufferedReader in=new java.io.BufferedReader(new java.io.FileReader("/home/wijebandara/Desktop/B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("/home/wijebandara/Desktop/B-small-attempt0.out")));
    
        int n=Integer.parseInt(in.readLine());
        
        for(int i=0;i<n;i++)
        {
            boolean ok1=false;
            boolean ok2=false;
            
            int m=Integer.parseInt(in.readLine());
            int data1[]=new int [m];
            int data2[]=new int [m];
            for(int j=0;j<m;j++)
            {
                java.util.StringTokenizer st =new java.util.StringTokenizer(in.readLine());
                data1[j]=Integer.parseInt(st.nextToken());
                data2[j]=Integer.parseInt(st.nextToken());
                
                if(data1[j]==0)
                {
                    ok1=true;
                }
                if(data2[j]==0)
                {
                    ok2=true;
                }
               
            }
            if(!ok1 & !ok1)
            {
                System.out.println("Case #"+(i+1)+": "+"Too Bad");            
                out.println("Case #"+(i+1)+": "+"Too Bad");
                continue;
            }
            Arrays.sort(data2);
            Arrays.sort(data1);
            boolean d1[]=new boolean[m];
            boolean d2[]=new boolean[m];
            for(int j=0;j<m;j++)
            {
                d1[j]=false;
                d2[j]=false;
            }
            
            int answer=0;
            int count=0;
            int hold=-1;
            
            boolean p=false;
            for(int j=0;j<m;j++)
            {   
                //System.out.println("**"+answer+" "+count);
                if(answer==hold)
                {
                    System.out.println("Case #"+(i+1)+": "+"Too Bad");            
                    out.println("Case #"+(i+1)+": "+"Too Bad");
                    p=true;
                    break;
                }
                hold=answer;
                count++;
                
                boolean a=true;
                if(data2[j]>answer)
                {
                    for(int k=0;k<m;k++)
                    {
                        if(!d2[k] && data2[k]<=answer)
                        {
                            if(d1[k])
                            {
                                boolean c=true;
                                for(int l=k+1;l<m;l++)
                                {
                                    if(!d2[l] && !d1[l]&& data2[l]<answer)
                                    {
                                        answer+=2;
                                        //System.out.println("--0");     
                                        d2[l]=true;;
                                        c=false;
                                        break;
                                    }
                                }
                                if(!c)
                                {
                                    j--;
                                    break;
                                }
                                answer++;
                               // System.out.println("--1");                             
                                
                            }
                            else 
                            {
                                answer+=2;
                               // System.out.println("--2");
                            }
                            d2[k]=true;
                            a=false;
                            j--;
                            break;
                        }
                    }
                    if(a)
                    {
                        for(int k=0;k<m;k++)
                        {
                            if(!d1[k] && data1[k]<=answer)
                            {
                                for(int l=k+1;l<m;l++)
                                {
                                    if(!d1[l] && data2[l]>data2[k] && data1[k]<=answer)
                                       k=l-1; 
                                       continue;
                                }
                                answer++;
                                d1[k]=true;
                                j--;
                                //System.out.println("--3");
                                break;
                            }
                        }
                    }
                    continue;
                }
                else
                {
                    if(d1[j])
                    {
                        answer++;
                       // System.out.println("--4");
                    }
                    else
                    {
                        answer+=2;
                        //System.out.println("--5");
                    }
                    d2[j]=true;
                }
            }
            if(!p)
            {
                System.out.println("Case #"+(i+1)+": "+count);            
                out.println("Case #"+(i+1)+": "+count);
            }
           
        }
        out.close();
        
    }
}
