
package codejam2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CodeJam2 {

    public static void main(String[] args) {
    Scanner a=null;
        try {
            a = new Scanner(new File("B.in"));
        } catch (FileNotFoundException ex) {
       //     System.out.println("asdasd");
        }
        int E=5,R=5,n=10;
        int T=a.nextInt();
        int[] v= new int[10];
        long r, t;
        int p=0;
        while(p<T){
            E=a.nextInt();
            R=a.nextInt();
            n=a.nextInt();
            for(int j=0;j<n;j++)
                v[j]=a.nextInt();
            p++;
            int[] arr = new int[11];
            
            int l=1,sum,tot,gain,c;
            for(int i=0;i<n;i++)
            {
                int[] arr2=new int[11];
                for(int j=1;j<=E;j++)
                {
                    for(int k=0;k<=j;k++)
                    {
                        gain=arr[j]+k*v[i];
                        sum=j+R-k;
                        if(sum>E)
                            sum=E;
                        if(arr2[sum]<gain)
                            arr2[sum]=gain;
                  //      if(j==E&&k==E&&i==0)
                   //         System.out.println(gain+"  "+v[0]+"  "+arr[E]);
                        
                    }
                }
                arr=arr2;
          //      System.out.println(arr[0]);
            }
            int max=0;
            for(int i=1;i<=E;i++)
                if(max<arr[i])
                    max=arr[i];
            System.out.println("Case #"+p+": "+max);
        }

        
        
    }
}
