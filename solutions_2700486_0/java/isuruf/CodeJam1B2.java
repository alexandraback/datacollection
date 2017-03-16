
package codejam2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CodeJam1B2 {

    public static void main(String[] args) {
    Scanner a=null;
        try {
            a = new Scanner(new File("B.in"));
        } catch (FileNotFoundException ex) {
       //     System.out.println("asdasd");
        }
    int t=a.nextInt();
    int p=0,X,Y,N;
    int arr[] = new int[1000000];
    while(p<t)
    {   
        N=a.nextInt();
        X=a.nextInt();
        Y=a.nextInt();
        if(X<0)
            X=-X;
        int q=(X+Y)/2+1;
        double s=0.00;
        p++;
        if(N>=2*q*q-q)
            System.out.println("Case #"+p+": "+"1");
        else if(N<=2*(q-1)*(q-1)-(q-1))
            System.out.println("Case #"+p+": "+"0");
        else{
            int count=0,total=0,c;
            int w=N-2*(q-1)*(q-1)+(q-1);
            System.out.println("Case #"+p+": "+f(w,2*q-2,0,0,Y+1));
        }
    }
    }
    public static double f(int i,int max, int r, int s, int target){
        if(i==0&&r>=target)
            return 1;
        if(i==0&&r<target)
            return 0;
        if(r>=max)
            return f(i-1,max,r,s+1,target);
        if(s>=max)
            return f(i-1,max,r+1,s,target);
        return (f(i-1,max,r,s+1,target)+f(i-1,max,r+1,s,target))/2.0000;
    }
}
