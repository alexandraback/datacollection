import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
    
    public static long checkPrime(long crunchifyNumber) {
 
        long crunchifyPrime = 1;
        long limit = 100;
 
        for (long i = 2; i <= limit; i++) {
            if (crunchifyNumber % i == 0) {
                crunchifyPrime = i;
                break;
            }
        }
 
        return crunchifyPrime;
    }
    public static void main(String[] args) throws Exception {
        
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();


        
        for(int m=1;m<=t;m++)
        {
            int n=in.nextInt();
            int e=in.nextInt();

            System.out.println("Case #1:");
            String ans[]=new String[e];
            int l=0;
            for(int i=1;i<Math.pow(2,n-2);i++)
            {
                StringBuilder a=new StringBuilder();
                a.append('1');
                String x=Integer.toBinaryString(i);
                int len=x.length();
                for(int k=0;k<n-2-len;k++)
                {
                    a.append('0');
                }
                a.append(x);
                a.append('1');
                int flag=1;
                ArrayList al=new ArrayList();
                for(int k=2;k<11;k++)
                {
                    long bleh=checkPrime(Long.parseLong(a.toString(),k));
                    if(bleh==1)
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        al.add(bleh);
                    }


                }

                if(flag==0)
                    continue;
                else
                {
                    System.out.print(a.toString()+" ");
                    for(int f=0;f<al.size()-1;f++)
                        System.out.print(al.get(f)+ " ");
                    System.out.println(al.get(al.size()-1));


                    l++;
                }

                if(l==e)
                    break;

            }

            





        }
    }
}
