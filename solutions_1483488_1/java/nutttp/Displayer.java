import java.util.Scanner;
import java.io.*;

public class Displayer
{
    public static void main(String[] args) throws IOException
    {
        Scanner kb = new Scanner(new File("/Users/mbp13/Documents/Google Code Jam/GCJ_Q3/src/input"));
        PrintStream out = new PrintStream(new File("/Users/mbp13/Documents/Google Code Jam/GCJ_Q3/src/output_q3"));
        int testNum,A,B;
        String tmpStr,tmpStr2,cut1,cut2;
        int cnt,x;
        int[] tmp = new int[15];
        int tmpCnt;
        int isRepeat;
        testNum = kb.nextInt();
        for(int i=0;i<testNum;i++)
        {
            A = kb.nextInt();
            B = kb.nextInt();
            cnt = 0;
            System.out.println("@Case "+(i+1));
            for(int j=A;j<=B;j++)
            {
                tmpCnt = 0;
                tmpStr = j+"";
                for(int k=1;k<tmpStr.length();k++)
                {
                    cut1 = tmpStr.substring(0,k);
                    cut2 = tmpStr.substring(k,tmpStr.length());
                    tmpStr2 = cut2 + cut1;
                    x = Integer.parseInt(tmpStr2);
                    if(x > j && x >= A && x <= B)
                    {
                        isRepeat=0;
                        for(int l = 0; l < tmpCnt; l++)
                        {
                            if(x == tmp[l])
                            {
                                isRepeat = 1;
                                break;
                            }
                        }
                        if(isRepeat == 0)
                        {
                            //System.out.println(j + " " + tmpStr2);
                            cnt++;
                            tmp[tmpCnt] = x;
                            tmpCnt++;
                        }
                    }
                }
            }
            out.println("Case #"+(i+1)+": "+cnt);
        }
    }
}
