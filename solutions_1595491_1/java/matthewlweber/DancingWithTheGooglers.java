import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.FileWriter;

public class DancingWithTheGooglers {
  public static void main(String... args) {

    try {
      File f = new File("B-large.in");
      File outFile = new File("output.txt");
      FileWriter w = new FileWriter(outFile);
      Scanner s = new Scanner(f);
      int T = s.nextInt();
      s.nextLine();
      for(int i = 1; i<= T; i++) {
        int N = s.nextInt();
        int S = s.nextInt();
        int p = s.nextInt();
        int[] t = new int[N];
        for(int j = 0; j < N; j++) {
          t[j] = s.nextInt();
        }
        int max = findMax(N,S,p,t);
        String line = "Case #" + i +": " + max + '\n';
        System.out.print(line);
        w.write(line);
        if(s.hasNextLine()) s.nextLine();
      }
      w.close();
    }
    catch(Exception e) { }
  }
  private static int findMax(int N, int S, int p, int[] t) {
    int possible = 0;
    int surprising = 0;
    for(int i = 0; i < t.length; i++) {
      if(p == 1) {
        if(t[i] >= 1) {
          possible++;
        }
      }
      else if(t[i] >= (3*p - 2)){
        possible++;
      }
      else if(t[i] >= (3*p - 4)) {
        surprising++;
      }
    }
    return possible + Math.min(surprising, S);
  }
}