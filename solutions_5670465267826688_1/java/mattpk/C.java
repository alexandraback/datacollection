import java.io.*;
import java.util.*;

public class C
{
  public static void main (String[] args) throws Exception
  {
 Scanner in = new Scanner(new File("C-large.in"));
   //Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    
    int n = in.nextInt();
    for(int t =0; t<n; t++)
    {
            String ans = "NO";
      int len = in.nextInt();
      long repeat = in.nextLong();
      String part = in.next();
      long i = 0;
      long j = 0;
      long k = 0;
      for (int x =0; x< len;x++){
        if (part.charAt(x)=='i') i+= repeat;
        if (part.charAt(x)=='j') j+= repeat;
        if (part.charAt(x)=='k') k+= repeat;
      }
      long usedOnA= 1;
      
      char current = part.charAt(0);
      String used = ""+current;
      boolean worked = false;
      while(usedOnA<Math.min(len*5,len*repeat)) // we'll do upper limit 12 to try and find solution
      {
        if(current == 'i') break;
        if(usedOnA%len == 0) used = "";
        current = m(current,part.charAt((int)(usedOnA%len)));
        used+=part.charAt((int)(usedOnA%len));
        usedOnA++;
      }
      
        long usedOnB = 1;
        String usedAfter = "";
      //System.out.println(current + " " + usedOnA);
      if (current =='i')
      {
        
        current = part.charAt(len-1);
        usedAfter = current+"";
        while(usedOnB<Math.min(len*5,len*repeat))
        {
          if (current == 'k') break;
          if(usedOnB%len == 0) usedAfter = "";
          char put = part.charAt((len-1)-((int)(usedOnB%len)));
          current = m(put,current);
          usedOnB++;
          usedAfter= put+usedAfter;
        }
        //System.out.println(current + " " + usedOnB);
        if (current == 'k') worked = true;
      }
      if (worked)
      {
        if (used.length()%len == 0) used = "";
        if (usedAfter.length()%len == 0 ) usedAfter = "";
        long midLen = ((long)(len))*repeat-usedOnB-usedOnA;
        if (midLen > 0)
        {
         // System.out.println("midLength: " +midLen+ " " + usedOnA + " " + usedOnB);
          
          String newUsed = part.substring(used.length());
          if (newUsed.length() > (len*repeat)-used.length()-usedAfter.length())
            newUsed = newUsed.substring(0,(int)((len*repeat)-used.length()-usedAfter.length()));
          String       newUsedAfter = part.substring(0,len-usedAfter.length());
          if ((long)(newUsedAfter.length()) >len*repeat-used.length()-newUsed.length()-usedAfter.length())
            newUsedAfter = newUsedAfter.substring(0,(int)(len*repeat)-used.length()-newUsed.length()-usedAfter.length());
        //  System.out.println("inner used:" + newUsed + " usedA:" + newUsedAfter);
          long ok;
            ok = (midLen-newUsed.length()-newUsedAfter.length());
          long numMid = ok/len;
       // System.out.println("number of mid elements that group: " + ok + " #mid set: " + numMid);
        char midAns = part.charAt(0);
        for (int x = 1; x< len; x++)
        {
          midAns = m(midAns,part.charAt(x));
        }
       // System.out.println("Answer for single middle: " + midAns);
        char midFinalAns='?';
        int modAns = (int)(numMid%4);
        char[] ans2 = new char[4];
        ans2[0] = '1';
        ans2[1] = m(ans2[0],midAns);
        ans2[2] = m(ans2[1],midAns);
        ans2[3] = m(ans2[2],midAns);
        midFinalAns = ans2[modAns];
       // System.out.println("Middle subtotal: " + midFinalAns);
        // now multiply midfinalans by the used strings
        char obama = '1';
        if (newUsed.length() > 0)
        {
        //  System.out.println("first half");
          obama = newUsed.charAt(0);
          for (int x =1; x< newUsed.length(); x++)
            obama = m(obama,newUsed.charAt(x));
        }
        midFinalAns = m(obama,midFinalAns);
        obama = '1';
        if (newUsedAfter.length() > 0)
        {
        //  System.out.println("second half");
          obama = newUsedAfter.charAt(0);
          for (int x =1;x<newUsedAfter.length(); x++)
            obama = m(obama,newUsedAfter.charAt(x));
        }
        midFinalAns = m(midFinalAns,obama);
   //     System.out.println("Final middle ans: " + midFinalAns);
        if (midFinalAns == 'j') ans = "YES";
        }
      }
      out.println("Case #" + (t+1) + ": " + ans);
//      System.out.println("Case #" + (t+1) + ": " + ans);
    }
    
    
    in.close();
    out.close();
  }
  // let a be pos i, let I be negative
  // let 1 be pos 1, let 0 be neg
  public static char m(char a, char b)
  {
    if (a == '1')
      return b;
    if (b == '1')
      return a;
    if (a == '0')
    {
      if (b == '0') return '1';
      if (b == 'i') return 'I';
      if (b == 'j') return 'J';
      if (b == 'k') return 'K';
      if (b == 'I') return 'i';
      if (b == 'K') return 'k';
      if (b == 'J') return 'j';
    }
    if (b == '0')
    {
      if (a == '0') return '1';
      if (a == 'i') return 'I';
      if (a == 'j') return 'J';
      if (a == 'k') return 'K';
      if (a == 'I') return 'i';
      if (a == 'K') return 'k';
      if (a == 'J') return 'j';
    }
    if (a == 'i')
    {
      if (b == 'i') return '0';
      if (b == 'j') return 'k';
      if (b == 'k') return 'J';
      if (b == 'I') return '1';
      if (b == 'J') return 'K';
      if (b == 'K') return 'j';
    }
    if (a == 'I')
    {
      if (b == 'i') return '1';
      if (b == 'j') return 'K';
      if (b == 'k') return 'j';
      if (b == 'I') return '0';
      if (b == 'J') return 'k';
      if (b == 'K') return 'J';
    }
    if (a == 'j')
    {
      if (b == 'i') return 'K';
      if (b == 'j') return '0';
      if (b == 'k') return 'i';
      if (b == 'I') return 'k';
      if (b == 'J') return '1';
      if (b == 'K') return 'I';
    }
    if (a == 'J')
    {
      if (b == 'i') return 'k';
      if (b == 'j') return '1';
      if (b == 'k') return 'I';
      if (b == 'I') return 'K';
      if (b == 'J') return '0';
      if (b == 'K') return 'i';
    }
    if (a == 'k')
    {
      if (b == 'i') return 'j';
      if (b == 'j') return 'I';
      if (b == 'k') return '0';
      if (b == 'I') return 'J';
      if (b == 'J') return 'i';
      if (b == 'K') return '1';
    }
    if (a == 'K')
    {
      if (b == 'i') return 'J';
      if (b == 'j') return 'i';
      if (b == 'k') return '1';
      if (b == 'I') return 'j';
      if (b == 'J') return 'I';
      if (b == 'K') return '0';
    }
    return '?';
  }
}