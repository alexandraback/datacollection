import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class P31 {

    public static void main(String[] args) {
        int[] arr = new int[4];
        int i,j;
        long[] num = new long[1000];
        int l=0;
        for(i=1;i<10000;i++)
        {
            String tex=String.valueOf(i);
            String rev=""+(new StringBuffer(tex)).reverse();
            num[l]=f(tex+rev);
            if(num[l]>0)
                l++;
            num[l]=f(tex+rev.substring(1));
            if(num[l]>0)
                l++;    
        }
        Arrays.sort(num,0,l);
        Scanner scan=null;
        int t;
        try {
            scan = new Scanner(new File("3.in"));
            t=scan.nextInt();
        } catch (FileNotFoundException ex) {
           t=0;
        }
        i=0;
        int count;
        while(i<t)
        {
            count=0;
            long a = scan.nextLong();
            long b = scan.nextLong();
            for(j=0;j<l&&num[j]<=b;j++)
            {
                if(num[j]>=a)
                    count++;
            }
            i++;
            System.out.println("Case #"+i+": "+count);
        }
    }
    public static long f(String a)
    {
        long b = Long.parseLong(a);
        b=b*b;
        String text=String.valueOf(b);
        int check=1;
        for(int i=0;i<text.length();i++)
            if(text.charAt(i)!=text.charAt(text.length()-1-i))
                check=0;
        return b*check;
    }
}
