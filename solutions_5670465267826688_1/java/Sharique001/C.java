import java.util.Scanner;
import java.io.*;
public class C
{
    static int combination(int a, int b)
    {
        int sign;
        if((a<0 && b<0) || (a>0 && b>0))
            sign=1;
        else sign=-1;
        if(a<0)
            a*=-1;
        if(b<0)
            b*=-1;
        if(a==(int)'i' && b==(int)'j')
            return sign*((int)'k');
        else if(a==(int)'i' && b==(int)'k')
            return sign*(-(int)'j');  
        else if(a==(int)'i' && b==(int)'i')
            return sign*(-1);
        else if(a==(int)'j' && b==(int)'i')
            return sign*(-(int)'k');
        else if(a==(int)'j' && b==(int)'k')
            return sign*((int)'i');    
        else if(a==(int)'j' && b==(int)'j')
            return sign*(-1); 
        else if(a==(int)'k' && b==(int)'i')
            return sign*((int)'j');  
        else if(a==(int)'k' && b==(int)'j')
            return sign*(-(int)'i'); 
        else if(a==(int)'k' && b==(int)'k')
            return sign*(-1);   
        else if(a==1)
            return sign*b;
        else if(b==1)
            return sign*a;
        return 0;           
        }
    public static void main(String args[])throws IOException
    {
        Scanner sc=new Scanner(new File("C-large (1).in"));        
        FileWriter fWriter = new FileWriter ("output10.out");
        PrintWriter pWriter = new PrintWriter (fWriter);
        int cases=Integer.valueOf(sc.nextLine());
        for(int k=1;k<=cases;k++)
        {
            String temp=sc.nextLine();
            String temp2[]=temp.split(" ");
            long L=Long.valueOf(temp2[0]);
            long X=Long.valueOf(temp2[1]);
            if(X>12){
            if(X%4==0)
                X=8;
            else if(X%4==1)
                X=9;
            else if(X%4==2)
                X=10;
            else
                X=11;
            }
            String a=sc.nextLine();
            String A=a;
            if(L<=1 || L*X<3)
                pWriter.println("Case #"+k+": "+"NO");
            else{    
                for(int i=0;i<X-1;i++)
                    A+=a;
                int B[]=new int[A.length()];
                for(int i=0;i<B.length;i++)
                    B[i]=(int)(A.charAt(i));
                int fin[]=new int[B.length];
                fin[0]=B[0];
                for(int i=1;i<fin.length;i++)
                  fin[i]=combination(fin[i-1],B[i]);
                if(fin[fin.length-1]!=-1)
                    pWriter.println("Case #"+k+": "+"NO");
                else
                    {
                        boolean flag1=false,flag2=false;
                        for(int i=0;i<fin.length;i++)
                        {
                            if(fin[i]==105)
                            flag1=true;
                            if(fin[i]==107 && flag1==true)
                            flag2=true;
                        }
                        if(flag2==true)
                        pWriter.println("Case #"+k+": "+"YES");
                        else
                        pWriter.println("Case #"+k+": "+"NO");
                    }
                }
        }             
            pWriter.close();
        }
    }

            