import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.lang.*; 
public class prob12{
    public static void main(String args[]) throws FileNotFoundException
    {
        File file = new File("D:/B-small-attempt1.in");
        Scanner sc=new Scanner(file);
        //System.out.println("f");
        try{
        BufferedWriter br = new BufferedWriter(new FileWriter("D:/output.txt"));        
        StringBuilder sb = new StringBuilder();
        int t=sc.nextInt();
        for(int i=0;i<t;i++)
        {
            int n=sc.nextInt();System.out.println("a"+n+" "+i);
            int nn=n*2-1;int h[]=new int[2501];
            for(int j=1;j<=nn;j++)
             {
                 for(int g=0;g<n;g++){
                 int aaa=sc.nextInt();
                 h[aaa]++;
                }
                             System.out.println(j);
                }
                int ab[]=new int[n];int cc=0;
            for(int j=1;j<=2500;j++)
               if(h[j]%2!=0)  ab[cc++]=j;
            
            System.out.println(cc+ab[0]);
           // System.out.println("Case #"+(i+1)+": "+ab[0]+" "+ab[1]+" "+ab[2]+"\n");
            String ss="Case #"+(i+1)+":";
            for(int g=0;g<n;g++)
             ss=ss+" "+ab[g];
            sb.append(ss+"\n");
            System.out.println(ss);
        }
        br.write(sb.toString());
        br.close();}
        
        catch(Exception e){
        }
    }
}