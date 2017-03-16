package x;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.Arrays;

public class Main
{
    private static long array1[];
    private static long array2[];
    private static boolean isOnSubSet1[];
    private static boolean isOnSubSet2[];
    public static void main(String[] args) 
    {
        try
        {

            Scanner inp = new Scanner(new File("mm.in"));
            FileWriter fw = new FileWriter(new File("mm.out"));
            int cnt=Integer.valueOf(inp.nextLine());
            for (int i = 0; i < cnt; i++)
            {
                int size=Integer.valueOf(inp.next());
                array1=new long[size];
                array2=new long[size];
                isOnSubSet1=new boolean[size];
                isOnSubSet2=new boolean[size];
                for (int j = 0; j < size; j++)
                {
                    array1[j]=array2[j]=Long.valueOf(inp.next());
                }
                fw.write("Case #"+String.valueOf(i+1)+":\n");
                if(subSet1(0))
                {
                    for(int j=0;j<array1.length;j++)
                    {
                        if(isOnSubSet1[j])
                            fw.write(array1[j]+" ");
                    }
                    fw.write("\n");
                    for(int j=0;j<array1.length;j++)
                    {
                        if(isOnSubSet2[j])
                            fw.write(array2[j]+" ");
                    }
                    fw.write("\n");
                }
                else
                {
                    fw.write("Impossible\n");
                }
            }
            fw.close();
            inp.close();
        }
        catch (Exception e)
        {}
    }

    private static boolean subSet1(int index)
    {
        if(index==(array1.length-1))
        {
            return subSet2(0);
        }
        else
        {
            for(int i=0;i<2;i++)
            {
                isOnSubSet1[index]=(i==0)?false:true;
                boolean cnd= subSet1(index+1);
                if(cnd)
                    return true;
            }
        }
        return false;
    }

    private static boolean subSet2(int index)
    {
        if(index==(array2.length-1))
        {
            for(int i=0;i<2;i++)
            {
                isOnSubSet2[index]=(i==0)?false:true;
                //Arrays.sort(array1);
                //Arrays.sort(array2);
                boolean cnd=check();
                if(cnd)
                    return true;
            }

        }
        else
        {
            for(int i=0;i<2;i++)
            {
                isOnSubSet2[index]=(i==0)?false:true;
                boolean cnd= subSet2(index+1);
                if(cnd)
                    return true;
            }
        }
        return false;
    }

    private static boolean check()
    {
        boolean cnd=true;
        for(int i=0;((i<array1.length)&&cnd);i++)
        {
            if(isOnSubSet1[i]!=isOnSubSet2[i])
                cnd=false;
        }
        if(cnd)
            return false;
        long sum1=0,sum2=0;
        for(int i=0;i<array1.length;i++)
        {
            if(isOnSubSet1[i])
            {
                sum1+=array1[i];
            }
            if(isOnSubSet2[i])
            {
                sum2+=array2[i];
            }
        }
        if(sum1==sum2)
            return true;
        else
            return false;
    }
}