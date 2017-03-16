import java.io.*;
import java.util.*;

public class LastWord {

    public static void main(String[] args) throws FileNotFoundException{
      Scanner in = new Scanner(new File(args[0]));
      int t = in.nextInt();
      
     for(int i = 0; i < t; i++) {
       String s = in.next();
       StringBuilder sb = new StringBuilder();
       char firstChar = s.charAt(0);
       sb.append(firstChar);
       for(int j = 1; j < s.length(); j++) {
         char curr = s.charAt(j);
         if(curr >= firstChar) {
           sb.insert(0, curr);
           firstChar = curr;
         } else {
           sb.append(curr);
         }
       }
       System.out.format("Case #%d: %s%n", i+1, sb.toString());
     }
    }

}