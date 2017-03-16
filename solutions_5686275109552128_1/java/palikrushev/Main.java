import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

 
public class Main {
  
  public static void main(String[] args) throws IOException {
    
    BufferedReader br = new BufferedReader(new FileReader(new File("B-large.in")));
    BufferedWriter bw = new BufferedWriter(new FileWriter(new File("B-large.out")));
    
    int testCases = Integer.parseInt(br.readLine());
    
    for (int i = 0; i < testCases; i++) {
      
      int diners = Integer.parseInt(br.readLine());
      int[] plates = new int[diners];
      
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int j = 0; j < plates.length; j++) {
        plates[j] = Integer.parseInt(st.nextToken());
      }
      
      int output = B.calculateNumberOfTurns(plates);
      
      bw.write("Case #" + String.valueOf(i+1) + ": " + output + "\n");
    }
    
    br.close();
    bw.close();    
    
  }

}
