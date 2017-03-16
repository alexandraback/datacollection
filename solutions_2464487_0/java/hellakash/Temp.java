import java.io.*;
import java.util.*;

/**
 *
 * @author Akash_Mahajan
 */
public class Temp
 {
  
    public static void main(String[] args) throws Exception
            
    {
    BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
    int testcase = Integer.parseInt(br.readLine());
    int i = 1;
    long count = 0;
    for(;i<=testcase;i++)
    {
        String s = br.readLine();
        //double r = Integer.parseInt(s.substring(0,s.indexOf(' ')));
        //double t = Integer.parseInt(s.substring(0,s.indexOf(' ')+1));
        StringTokenizer st = new StringTokenizer(s," ");
        double r = Double.parseDouble(st.nextToken());
        double t = Double.parseDouble(st.nextToken());
        
       
        count = 0;
        double m = t;
        
        double tr = r;
        while(m>=0)
        {
            //System.out.println("Here");
            double temp = ((tr+1)*(tr+1)-(tr)*(tr));
           // System.out.println(" temp " +temp+" "+m);
            if(m>=temp)
            {
                count++;
                tr = tr+2;
                m = m-temp;
            }
            else if(m<temp)
                break;
            
        }
        System.out.println("Case #"+i+": "+count);
     }
    //Case #1: 1
    
    
    }

}
