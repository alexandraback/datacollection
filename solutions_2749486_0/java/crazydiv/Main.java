

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
    String result="";
    String s = br.readLine();
    String s2[]=s.split(" ");
    int x=Integer.parseInt(s2[0]);
    int y=Integer.parseInt(s2[1]);
    int steps=0;
    int inc=2;
    for(int j=1;j<1000000;j++)
    {   inc =j;
        if(x>0)
        {
        if(steps+j<=x)    
        { steps+=j;
          result+="E";
        }
        else
            break;
        }
        else
        {
        if(steps-j>=x)    
        { steps-=j;
          result+="W";
        }
        else
            break;
        
        }
    }
      if(x>0)
    {
    while(steps<x)
    {   inc+=2;
        steps++;
        result+="WE";
    }
    }
    if(x<0)
    {
    while(steps>x)
    {   inc+=2;
        steps--;
        result+="EW";
    }
    }
    steps=0;
    for(int j=inc;j<1000000;j++)
    {
        if(y>0)
        {
        if(steps+j<=y)    
        { steps+=j;
          result+="N";
        }
        else
            break;
        }
        else
        {
        if(steps-j>=y)    
        { steps-=j;
          result+="S";
        }
        else
            break;
        
        }
    }
    if(y>0)
    {
    while(steps<y)
    {
        steps++;
        result+="SN";
    }
    }
    if(y<0)
    {
    while(steps>y)
    {
        steps--;
        result+="NS";
    }
    }
    System.out.println(result);
    int count=0;
    bw.write("Case #"+(i+1)+": "+result+"\n");
    }
    
    

    bw.close();
}
}
