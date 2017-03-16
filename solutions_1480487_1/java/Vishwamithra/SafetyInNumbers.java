/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package competition.round1B;

import java.io.*;
import java.util.*;

/**
 *
 * @author Sriram
 */
public class SafetyInNumbers {

    public static void main(String[] args) throws Exception
    {
//        PrintStream out = new PrintStream(System.out);
        PrintStream out = new PrintStream(new FileOutputStream("f:\\codeJam\\output.out"));
        Scanner in = new Scanner(new FileInputStream("f:\\codeJam\\input.in"));
        int T = in.nextInt();
        for(int zz=0;zz<T;zz++)
        {
            int participants = in.nextInt();
            int[] scores = new int[participants];
            int sum = 0;
            for(int i=0;i<participants;i++)
            {
                scores[i] = in.nextInt();
                sum += scores[i];
            }
            
            float avg = sum/(float)participants;
            float required = avg*2;
            //out.println(avg+ " "+required);
            float[] audiance = new float[participants];
            int no_greater = participants;
            for(int i=0;i<participants;i++)
            {
                if(scores[i]>required)
                {
                    no_greater--;
                    //sum -= scores[i];
                }
            }
            out.print("Case #"+(zz+1)+":");
            float nve_sum = 0.f;
//            if(no_greater == participants)
            {
            for(int i=0;i<participants;i++)
            {
                audiance[i] = ((required-scores[i])/sum)*100f;
                if(audiance[i]<0)
                    nve_sum += audiance[i];
               // out.printf(" %.6f ", audiance[i]);
            }
            for(int i=0;i<participants;i++)
            {
                if(audiance[i]<0)
                    audiance[i] = 0;
                else
                {
                    audiance[i] += (nve_sum/no_greater);
                }
                out.printf(" %.6f ", audiance[i]);
            }
            }
//            else
//            {
//                for(int i=0;i<participants;i++)
//                {
//                    if(scores[i]>required)
//                       audiance[i] = 0f;
//                    else
//                    {
//                        audiance[i] = (1/(float)no_greater)*100f;
//                    }
//                    out.printf(" %.6f ", audiance[i]);
//                }
//            }
            out.print('\n');
        }
    }

}
