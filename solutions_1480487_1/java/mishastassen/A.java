import java.util.*;
import java.io.*;

public class A
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int cas=1;cas<=t;cas++)
        {
            int n=sc.nextInt();
            int[] point=new int[n];
            int sum=0;
            for(int i=0;i<n;i++)
            {
                point[i]=sc.nextInt();
                sum+=point[i];
            }
            double[] score=new double[n];
            for(int i=0;i<n;i++)
            {
                score[i]=(double)point[i]/sum;
                //System.out.println("score[i]: "+score[i]);
            }
            System.out.print("Case #"+cas+":");
            for(int ik=0;ik<n;ik++)
            {
                double lo=score[ik],hi=1;
                for(int rep=0;rep<50;rep++)  //?????? HEEEEEEEEEEEEEEEEE
                {
                    double mid=(lo+hi)/2;
                    double zij=0;
                    for(int i=0;i<n;i++)
                        zij+=Math.max(0,mid-score[i]);
                    //System.out.println("mid: "+mid+", zij:"+zij);
                    if(zij>1)
                        hi=mid;
                    else
                        lo=mid;
                }
                double res=100*(lo-score[ik]);
                System.out.print(" "+res);
            }
            System.out.println();
        }
    }
}