import java.io.*;
import java.util.*;
public class a

{
     BufferedReader read;
     BufferedWriter write;
    public static void main(String args[])
    {
        try {
            new a().init("A-small-attempt0");
        } catch (Exception ex) {
            System.out.println("errror  "+ex);

        }
    }
    void init(String name) throws Exception
        {
        read=new BufferedReader(new FileReader(new File(name+".in")));
        write=new BufferedWriter(new FileWriter(new File(name+".out")));

		String x="";

            try {
                   x = read.readLine();
                   int num = Integer.parseInt(x);
                   for(int test=0;test<num;test++)
                      {
                          x = read.readLine();
                          String[] ss = x.split(" ");
                          int n = Integer.parseInt(ss[0].trim());
                          int[] s = new int[n];
                          int sum =0,total =0;
                          for(int i=0;i<n;i++)
                          {
                            s[i] = Integer.parseInt(ss[i+1].trim());
                            sum = sum + s[i];
                          }
                          //System.out.println("sum..."+sum);
                          total = sum *2 ;
                          double each  = (double)total / (double)n;
                          System.out.println("each..."+each);
                          double[] sh = new double[n];
                          int count=0;
                          double s1=0;
                          for(int i=0;i<n;i++)
                          {
                           if((double)s[i]>=each)
                           {
                               count++;
                               s1 = s1 + (double)s[i];
                              }
                          }
                          double orig = each;
                          each = ((double)total-s1) / (double)(n-count);
                          System.out.println("each..."+each);
                          for(int i=0;i<n;i++)
                          {
                           if((double)s[i]>=orig)
                            {
                              sh[i] = 0;
                            }
                           else
                            {
                              sh[i] = ((each - (double)s[i])/(double)sum)*100;
                            }
                          }
                          display(test,sh);

                       }
			        write.flush();
				write.close();
				read.close();
                }


                  // System.out.println(a+"    "+b);

             catch (Exception ex)
			 {
                           System.exit(0);
             }
	    }

    public void display(int i,double[] sh)
    {
        try{
    write.write("Case #"+(i+1)+":"+" ");
    System.out.print("Case #"+(i+1)+":"+" ");
         for(int j=0;j<sh.length;j++)
         {
          write.write(sh[j]+" ");
           System.out.print(sh[j]+" ");
         }
    write.write("\n");
    System.out.println("\n");
        }
        catch(Exception ex){
        System.out.println(ex);}

    }
}
