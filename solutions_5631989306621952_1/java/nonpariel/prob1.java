import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.lang.*; 
public class prob11{
    public static void main(String args[]) throws FileNotFoundException
    {
        File file = new File("D:/input.in");
        Scanner sc=new Scanner(file);
        //System.out.println("f");
        try{
        BufferedWriter br = new BufferedWriter(new FileWriter("D:/output.txt"));        
        StringBuilder sb = new StringBuilder();
        int t=Integer.parseInt(sc.nextLine());
        for(int i=0;i<t;i++)
        {
            String s=sc.nextLine();
            int le=s.length();String ss=""+s.charAt(0);
            for(int j=1;j<le;j++)
              if(s.charAt(j)>=ss.charAt(0))
                 ss=s.charAt(j)+ss;
              else 
                 ss=ss+s.charAt(j);
            
            sb.append("Case #"+(i+1)+": "+ss+"\n");
        }
        br.write(sb.toString());
        br.close();}
        
        catch(Exception e){
        }
    }
}