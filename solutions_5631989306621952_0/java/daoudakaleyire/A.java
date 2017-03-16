/**
 * Created by DAOUDA on 4/16/2016.
 */
import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token;
        int t;
        t = Integer.parseInt(br.readLine());
        String s;
        StringBuilder sb;
        for(int i = 1; i<=t;i++)
        {
            sb = new StringBuilder();
            s = br.readLine();
            for(int j = 0; j<s.length();j++){
                if(j ==0) sb.append(s.charAt(j));
                else {
                    if(sb.charAt(0)<=s.charAt(j)) sb.insert(0,s.charAt(j));
                    else sb.append(s.charAt(j));
                }
            }
            System.out.println("Case #"+i+": "+sb.toString());
        }
    }
}
