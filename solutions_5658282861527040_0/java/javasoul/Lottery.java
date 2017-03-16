import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import java.io.*;
import java.awt.*;

public class Lottery{
    public static void main(String[] args){
        new Lottery();
    }
    int[] getData(String s)
    {
      String[] all = s.split(" ");
      int[] res=new int[3];
      int i=0;
      for(String k:all)
        res[i++]=Integer.parseInt(k);
      return res;
    }
    Lottery()
    {
            int TTC=0;
            int index=1;

        try
        {
            File inFile=new File("./A-small.in");
            File outFile=new File("./A-small.out");
            if(outFile.exists())
               outFile.delete();
            boolean bool=outFile.createNewFile();
            RandomAccessFile rac=new RandomAccessFile(inFile,"r");
            TTC=Integer.parseInt(rac.readLine());
            String res="";

            while(TTC>0)
            {
                res="";
                long rc=0l;
                int[] all= getData(rac.readLine());
                int A=all[0];
                int B=all[1];
                int C =all[2];
                for(int i=0;i<A;i++)
                {
                  for(int j=0;j<B;j++)
                    if((i&j)<C)
                      rc++;
                }
                   res=""+rc;
                RandomAccessFile rac2=new RandomAccessFile(outFile,"rw");
                rac2.seek(rac2.length());
                rac2.writeBytes("Case #"+index+": "+res);
                rac2.writeBytes("\r\n");
                rac2.close();
                index++;
                TTC--;
            }
            rac.close();
        }catch(Exception e)
        {
            System.out.println("Error: "+e.getMessage());
            e.printStackTrace();
        }
 }
}