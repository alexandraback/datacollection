import java.util.*;

public class D
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();

        for(int ca=1;ca <= T;ca++)
        {
            int n = scan.nextInt();
            double[] a = new double[n];
            double[] b = new double[n];
            for(int i=0;i < n;i++)
                a[i] = scan.nextDouble();
            for(int i=0;i < n;i++)
                b[i] = scan.nextDouble();
            Arrays.sort(a);
            Arrays.sort(b);
            double[] A = new double[2*n];
            boolean[] B = new boolean[2*n];
            

            int i1 = 0;
            int i2 = 0;
            while(i1 + i2 < 2*n)
            {
                if(i1 < n && i2 < n)
                {
                    if(a[i1] < b[i2])
                    {
                        A[i1+i2] = a[i1];
                        i1++;
                    }
                    else
                    {
                        A[i1+i2] = b[i2];
                        B[i1+i2] = true;
                        i2++;
                    }
                }
                else if(i1 < n)
                {
                    A[i1+i2] = a[i1];
                    i1++;
                }
                else
                {
                    A[i1+i2] = b[i2];
                    B[i1+i2] = true;
                    i2++;
                }
            }

            System.out.print("Case #" + ca + ":");

            // Deceitful War
            int ans = 0;
            int idx = 0;
            boolean[] u = new boolean[2*n];

            while(idx < 2*n)
            {
                //System.out.println("TRYING " + idx);
                if(B[idx] && !u[idx])
                {
                    //System.out.println("  KEN");
                    int idx2 = idx+1;
                    while(idx2 < 2*n)
                    {
                        if(!B[idx2] && !u[idx2])
                        {
                            //System.out.println("  MATCHES " + idx2);
                            u[idx2] = true;
                            ans++;
                            break;
                        }
                        idx2++;
                    }
                }
                else if(!B[idx] && !u[idx])
                {
                    int idx2 = 2*n-1;
                    while(idx2 > idx && (!B[idx2] || u[idx2]))
                    {
                        //System.out.println("TRY " + idx2 + " " + B[idx2] + " " + u[idx2]);
                        idx2--;
                    }
                    if(B[idx2] && !u[idx])
                    {
                        //System.out.println("  NAOMI LOSES " + idx + " " + idx2);
                        u[idx] = u[idx2] = true;
                    }
                }
                u[idx] = true;
                idx++;
            }

            System.out.print(" " + ans);


            // War
            ans = n;
            idx = 0;
            u = new boolean[2*n];

            while(idx < 2*n)
            {
                if(!B[idx] && !u[idx])
                {
                    int idx2 = idx+1;
                    while(idx2 < 2*n)
                    {
                        if(B[idx2] && !u[idx2])
                        {
                            ans--;
                            u[idx2] = true;
                            break;
                        }
                        idx2++;
                    }
                }
                idx++;
            }

            System.out.println(" " + ans);
        }
    }
}