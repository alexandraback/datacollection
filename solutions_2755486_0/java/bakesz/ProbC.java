
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adam
 */
public class ProbC {
            public static void main(String[] args) 
    {
        
        Scanner s=new Scanner(System.in);
        int casenum=s.nextInt();
                for (int i=1;i<=casenum;i++)
                {System.out.print("Case #"+i+": ");
                solve(s);
                System.out.println();
                }
    }

            static class tribe{
                long d;
                long n;
                long w,e,s,dd,dp,ds;
                long rem;
            }
            
            
    private static void solve(Scanner s) {
        Map<Long,Integer> wall=new TreeMap<Long,Integer>();
        List<tribe> t=new LinkedList<tribe>();
        int n=s.nextInt();
        for (int i=0;i<n;i++)
        {
            tribe tt=new tribe();
            tt.d=s.nextLong();
            tt.n=s.nextLong();
            tt.w=s.nextLong();
            tt.e=s.nextLong();
            tt.s=s.nextLong();
            tt.dd=s.nextLong();
            tt.dp=s.nextLong();
            tt.ds=s.nextLong();
            tt.rem=tt.d;
            t.add(tt);
        }
        int ret=0;
        for (int i=0;i<676060*11;i++)
        {
            TreeMap<Long,Integer> new_h=new TreeMap<Long, Integer>();
            for (tribe tt:t)
            {
                if (tt.rem==0)
                {
                    
                    boolean succes=false;
                    for (long ii=tt.w;ii<tt.e ;ii++)
                    {
                        //System.err.println("tamadas"+ii+" "+tt.s);
                        if (wall.get(ii)==null)
                            wall.put(ii, 0);
                        if (wall.get(ii)< tt.s)
                        {
                          //  System.err.println("sikeres tamadas");
                            new_h.put(ii, (int)tt.s);
                            succes=true;
                        }
                    }
                    if (succes) {
                   //     System.err.println(i);
                        ret++;
                    }
                    tt.s+=tt.ds;
                    tt.w+=tt.dp;
                    tt.e+=tt.dp;
                    
                    tt.n--;
                    if (tt.n==0)
                        tt.rem=-1;
                    else
                    tt.rem=tt.dd;
                }
                tt.rem=Math.max(tt.rem-1, -1);
            }
            wall.putAll(new_h);
        }
        System.out.print(ret);
    }
}
