package A;

import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: rathinakumar
 * Date: 5/3/13
 * Time: 12:00 PM
 * To change this template use File | Settings | File Templates.
 */
public class A {
    public static String  WORK_DIR="C:\\Documents and Settings\\rathinakumar\\IdeaProjects\\CodeJam\\src\\A";
    public static String PROB_NAME="A";
    static ArrayList<Integer> a = new ArrayList<Integer>();
    public static void rec(int A, int cnt, int ind, int[] arr)
    {
        if(ind==arr.length)
        {
            a.add(cnt);
            return;
        }

            if(arr[ind]<A)
            {
                A+=arr[ind];
                ind++;
                rec(A, cnt, ind, arr);
            }
            else
            {
                //delete
                ind++;
                cnt++;
                rec(A, cnt, ind, arr);
                cnt--;
                ind--;
                //absorb
                int tCnt = 0;
                while(true)
                {
                    tCnt++;
                    if(A+(A-1)>arr[ind])
                    {
                        A+=((A-1)+arr[ind]);
                        cnt+=tCnt;
                        ind++;
                        rec(A, cnt, ind, arr);
                        break;
                    }
                    else
                    {
                        A+=(A-1);
                    }
                }
            }
        return;

    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);//new File(WORK_DIR+"\\"+PROB_NAME+".input"));
        PrintWriter pw = new PrintWriter(new FileOutputStream(new File(WORK_DIR+"\\"+PROB_NAME+".output")));
        int T = sc.nextInt();
        for(int Case=1; Case<=T; Case++)
        {
            int A = sc.nextInt();
            int N = sc.nextInt();
            int[] arr = new int[N];
            for (int i=0;i <N; i++)
               arr[i] = sc.nextInt();
            Arrays.sort(arr);
            if(A==1)
            {
                System.out.println("Case #"+Case+": "+N);
                continue;
            }
            rec(A, 0, 0, arr);
            if(a.size()>0)
            {
                Collections.sort(a);
                System.out.println("Case #"+Case+": "+a.get(0));
            }
            else
                System.out.println("Case #"+Case+": "+0);

            a.clear();
            //pw.write("Case #"+Case+": "++"\n");
        }
        sc.close();
        pw.flush();
        pw.close();
    }

}
