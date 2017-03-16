import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
    
    public static void main(String[] args) throws Exception {
        
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        String bad=in.nextLine();

        for(int m=1;m<=t;m++)
        {
          String s=in.nextLine();
           System.out.printf("Case #%d: ",m);
            
            ArrayList<Integer> a=new ArrayList<Integer>();
            ArrayList<Integer> b=new ArrayList<Integer>();

            char max=s.charAt(0);
            for(int i=1;i<s.length();i++)
            {
                if(s.charAt(i)>=max)
                {
                    max=s.charAt(i);
                    a.add(i);
                }
                else
                    b.add(i);
            }

            StringBuilder ans=new StringBuilder();

            for(int i=a.size()-1;i>=0;i--)
            {   
                ans.append(s.charAt(a.get(i)));
            }
            ans.append(s.charAt(0));

            for(int i=0;i<b.size();i++)
            {
                ans.append(s.charAt(b.get(i)));
            }


            System.out.println(ans);

        }
    }
}
