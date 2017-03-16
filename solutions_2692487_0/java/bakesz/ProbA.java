
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adam
 */
public class ProbA {
        public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        int casenum=s.nextInt();
        for (int i=1;i<=casenum;i++)
        {
            System.out.print("Case #"+i+": ");
            solve(s);
            System.out.println();
        }
    }

    private static int r(config start) {
        if (start.index>=start.motes.size())
            return start.stepnum;
        /*System.out.println(start.index);
        System.out.println(start.size);
        System.out.println(start.stepnum);
        System.out.println(start.motes.get(start.index) );
        System.out.println("-------------");*/
        if (start.motes.get(start.index)<start.size )
        {
            config c2=new config();
            c2.index=start.index+1;
            c2.motes=start.motes;
            c2.size=start.size+start.motes.get(start.index);
            c2.stepnum=start.stepnum;
            return r(c2);
        }
        else
        {
          //  System.out.println("problemo");
            //megprobalom kivenni meg megprobalom hozzatenni is.
            //hozzateszem.
            config c2=new config();
            c2.index=start.index;
            c2.motes=start.motes;
            c2.size=start.size+start.size-1;
            c2.stepnum=start.stepnum+1;
            //System.err.println(c2.size+" "+start.size);
            int hozzaadassal=Integer.MAX_VALUE;
            if (start.size-1!=0)
            hozzaadassal=r(c2);
            c2.index=start.index+1;
            c2.motes=start.motes;
            c2.size=start.size;
            c2.stepnum=start.stepnum+1;
            int kivevessel=r(c2);
            return Math.min(kivevessel, hozzaadassal);
        }
    }

        static class config
        {
            long size;
            int index;//kov elem,amit ki kel venni
            List<Long> motes;
            int stepnum;
        }
    private static void solve(Scanner s) {
        long startsize=s.nextLong();
        long motenum=s.nextLong();
        ArrayList<Long> motes=new ArrayList<Long>();
        for (long a=0;a<motenum;a++)
            motes.add(s.nextLong());
            Collections.sort(motes);
          //  System.out.println(motes);
            config start=new config();
            start.size=startsize;
            start.motes=motes;
            start.index=0;
            start.stepnum=0;
            int result=r(start);
            System.out.print(result);
    }
}
