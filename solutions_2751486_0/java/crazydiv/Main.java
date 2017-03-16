import java.io.*;
import java.util.Arrays;
public class Round1A1 {

public static void main(String args[]) throws Exception
{
    BufferedReader br=new BufferedReader(new FileReader("C:/in.txt"));
    BufferedWriter bw=new BufferedWriter(new FileWriter("C:/out.txt"));
    long t=Long.parseLong(br.readLine());
   
    for(long i=0;i<t;i++)
    {   
    String s = br.readLine();
    String s2[]=s.split(" ");
    char[] arr =s2[0].toCharArray();
    int len = Integer.parseInt(s2[1]);
    long count=0;
    int size = s2[0].length();
    for(int a=0;a<size;a++)
    {   int cons=0;
        int consflag=0;
        for(int b=a;b<size;b++)
        {
            if(arr[b]!='a'&&arr[b]!='e'&&arr[b]!='i'&&arr[b]!='o'&&arr[b]!='u')
                cons++;
            else
                cons=0;
            if(cons==len)
                consflag=1;
            if(consflag==1)
                count++;
        }
    }
    
    bw.write("Case #"+(i+1)+": "+count+"\n");
    }
    
    

    bw.close();
}
}
