import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: WANG
 * Date: 5/11/14
 * Time: 2:26 AM
 * To change this template use File | Settings | File Templates.
 */
public class round1c1 {
    public static void main(String[] args)
    {
        try {   Scanner input=new Scanner(new File("F:\\code\\test.in"));
        PrintWriter output=new PrintWriter("F:\\code\\round1problemDoutput.txt") ;
        int casenumber = input.nextInt();
            input.nextLine()   ;
            for (int i=0;i<casenumber;i++)
            {
                String nextl=input.nextLine();
                Scanner input1=new Scanner(nextl);
                input1.useDelimiter("/");
        //        String test1=input.next();
                long p,q;
                p= input1.nextLong();
                q=input1.nextLong();
                long temp1,temp2,min=-1,j=0,state=0;
                temp1=q;     temp2=p;
                while (temp1%2==0)
                {
                    if (j>=40)
                         break;
                    temp1=temp1/2;
                    if ((temp1==1)||(temp1==temp2))
                    {
                        if (min==-1)
                            min=j+1;
                        state=1;
                            break;
                    }
                       if (temp1<temp2)
                       {   if (min==-1)
                           min=j+1;
                       temp2-=temp1;
                       }

                    j++;

                }
                if (state==0)
                {
                    output.println("Case #"+(i+1)+": impossible");
                    output.flush();
                }
                else
                {
                    output.println("Case #"+(i+1)+": "+min);
                    output.flush();
                }
            }
        } catch(Exception e){}
    }
}
