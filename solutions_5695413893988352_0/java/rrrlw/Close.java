import java.io.*;
import java.util.*;

public class Close
{
    public static void main(String[] args) throws IOException
    {
        Scanner cin = new Scanner(new File("README.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("Close.out"));
        int numTests = cin.nextInt();
        int len;
        String[] scores = new String[2];
        String tempF, tempS;
        int minDiff = Integer.MAX_VALUE;
        String saveF="", saveS="";
        for (int runs = 1; runs<=numTests; runs++)
        {
            scores[0] = cin.next();
            scores[1] = cin.next();
            System.out.println(scores[0]+" "+scores[1]);
            len = scores[0].length();
            minDiff = Integer.MAX_VALUE;
            for (int first = 0; first <= 999; first++)
                for (int sec = 0; sec <= 999; sec++)
                {
                    if (Math.abs(first-sec)>=minDiff) continue;
                    
                    tempF = intToStr(first, len);
                    tempS = intToStr(sec, len);
                    if (match(tempF, scores[0]) &&
                        match(tempS, scores[1]))
                    {
                        saveF = tempF;
                        saveS = tempS;
                        minDiff = Math.abs(first-sec);
                    }
                }
                
            out.println("Case #"+runs+": "+saveF+" "+saveS);
        }
        out.close();
    }
    static boolean match(String a, String b)
    {
        if (a.length()!=b.length()) return false;
        for (int i=0; i<a.length() && i<b.length(); i++)
        {
            if (a.charAt(i)=='?' || b.charAt(i)=='?') continue;
            if (a.charAt(i)!=b.charAt(i)) return false;
        }
        return true;
    }
    static String intToStr(int num, int length)
    {
        String answer = ""+num;
        while (answer.length()<length)
            answer = "0"+answer;
        return answer;
    }
}