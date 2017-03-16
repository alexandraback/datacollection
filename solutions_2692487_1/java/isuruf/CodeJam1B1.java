
package codejam2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class CodeJam1B1 {

    public static void main(String[] args) {
    Scanner a=null;
        try {
            a = new Scanner(new File("A1.in"));
        } catch (FileNotFoundException ex) {
       //     System.out.println("asdasd");
        }
    int t=a.nextInt();
    int p=0,A,N;
    int arr[] = new int[1000000];
    while(p<t)
    {
        A=a.nextInt();
        N=a.nextInt();
        for(int j=0;j<N;j++)
            arr[j]=a.nextInt();
        Arrays.sort(arr, 0, N);
        p++;
        System.out.println("Case #"+p+": "+f(arr,0,A,N));
    } 
    }
    public static int f(int[] arr, int i, long A, int N)
    {
        if(A<0)
            System.out.println("error");
        if(i==N)
            return 0;
        if(arr[i]<A)
        {   
            return f(arr,i+1,A+arr[i],N);
        }
        else{
            int r=1+f(arr,i+1,A,N);
            int j=0;
            while(arr[i]>=A&&A!=1)
            {
                A+=A-1;
                j++;
            }
            if(A<0)
                System.out.println("error");
            if(A==1)
            {
                return N-i;
            }
            int s=j+f(arr,i+1,A+arr[i],N);
            if(s<r)
                return s;
            else
                return r;
        }
    }
}
