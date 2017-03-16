import java.util.*;
import java.io.*;
import java.util.Arrays;

public class B{
  public static void main(String[] args){
    File file = new File("Binput.txt");
    BufferedWriter writer = null;
    try {
      Scanner in = new Scanner(file);
      writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("Boutput.txt"), "utf-8"));
      
      int T = in.nextInt();
      for (int t = 1; t <= T; t++){
        
        long a = in.nextLong();
        long b = in.nextLong();
        long k = in.nextLong();
        
        long sum = 0;
        
        for (long i = 0; i < a; i++){
          for (long j = 0; j < b; j++){
            long val = i;
            val &= j;
            if (val < k)
              sum++;
          }
        }
        
        
        
        
        writer.write("Case #" + t + ": " + sum);
        if (t!=T)
          writer.newLine();
      }
      in.close();
      writer.close();
    } catch (Exception e){
      e.printStackTrace();
    }
  }
}