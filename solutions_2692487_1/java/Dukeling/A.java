package _2013_Round_1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.logging.Logger;

public class A
{
   static Scanner in;
   static BufferedWriter out;

   //static String inStr = name() + "-test.txt";
   //static String inStr = name() + "-small-attempt0.in";
   static String inStr = name() + "-large.in";
   static String outStr = name() + ".out";

   static String name()
   //{ return Logger.getLogger(new Throwable().getStackTrace()[0].getClassName()).getName(); }
   { return "A"; }

   public static void main(String[] args) throws Exception
   {
      in = new Scanner(new File(inStr));
      out = new BufferedWriter(new FileWriter(outStr));
      int count = in.nextInt();
      for (int i = 1; i <= count; i++)
      {
         int ourMote = in.nextInt();
         int moteCount = in.nextInt();
         int[] motes = new int[moteCount];
         for (int j = 0; j < moteCount; j++)
         {
            motes[j] = in.nextInt();
         }
         Arrays.sort(motes);
         int best = Integer.MAX_VALUE;
         int added = 0;
         for (int j = 0; j < moteCount; j++)
         {
            if (motes[j] < ourMote)
               ourMote += motes[j];
            else
            {
               int absorbAll = added + moteCount - j;
               if (absorbAll < best)
                  best = absorbAll;
               while (ourMote <= motes[j])
               {
                  added++;
                  ourMote += ourMote - 1;
                  if (ourMote == 1)
                     break;
               }
               if (ourMote == 1)
                  break;
               ourMote += motes[j];
            }
         }
         if (added < best && ourMote != 1)
            best = added;

         out.write("Case #" + i + ": ");
         out.write("" + best);
         out.write("\r\n");
      }
      out.flush();
   }
}
