package recycle_no;

import java.io.*;
import java.util.Arrays;

public class Recycle_no {
    int N,a,b,count=0;
    String s="",temp[];
    public Recycle_no(){
        try {
            FileInputStream fis=new FileInputStream("C-large.in");
            DataInputStream dis=new DataInputStream(fis);
            FileOutputStream fos = new FileOutputStream("C-large.out");
            DataOutputStream dos=new DataOutputStream(fos);
            N=Integer.parseInt(dis.readLine());
            for(int i=1;i<=N;i++)
            {
                s=dis.readLine();
                count=0;
                temp=s.split(" ");
                a=Integer.valueOf(temp[0]);
                b=Integer.valueOf(temp[1]);
                for(int j=a;j<b;j++)
                {
                    count+=recycle(j, a, b);
                }
                s="Case #"+i+": "+count;
                if(i!=N)
                {
                    s=s+"\n";
                }
//                System.out.println(s);
                dos.writeBytes(s);
            }
            fis.close();
            fos.close();
            }catch(Exception e){
                System.out.println("Error: "+e);
            }

    }
    private int recycle(int n,int min,int max){
        int no=n,temp_no=n,r,digit=0,d,c=0,a[];
        while(temp_no!=0){
            temp_no=temp_no/10;
            digit++;
        }
        d=digit;
        a=new int[d];
        Arrays.fill(a, -1);
        while(d!=1){
            r=n%10;
            n=n/10;
            n=(int) (Math.pow(10,(digit-1))*r+n);
            if(n>=min && n<=max && n>no)
            {
                int flg=0;
                for(int j=0;j<a.length;j++)
                {
                    if(n==a[j])
                    {
                        flg=1;
                        break;
                    }
                }
                if(flg==0)
                {
                    a[c++]=n;
//                    System.out.println("val="+n+",no= "+no);
                }
            }
            d--;
        }
        return c;
    }
    public static void main(String[] args) {
       new Recycle_no();
    }
}
