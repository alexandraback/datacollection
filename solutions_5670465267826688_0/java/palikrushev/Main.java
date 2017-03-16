import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

 
public class Main {
  
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new FileReader(new File("C-small-attempt2.in")));
    BufferedWriter bw = new BufferedWriter(new FileWriter(new File("C-small-attempt2.out")));
    
    int testCases = Integer.parseInt(br.readLine());
    
    for (int i = 0; i < testCases; i++) {
      
      StringTokenizer st = new StringTokenizer(br.readLine());
      st.nextToken();
      int repetition = Integer.parseInt(st.nextToken());
      
      String baseString = br.readLine();
      
      boolean output = C.check(baseString, repetition);
      String outString = output?"YES":"NO";
      
      bw.write("Case #" + String.valueOf(i+1) + ": " + outString + "\n");
    }
    
    br.close();
    bw.close();    
    
  }

}
