import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.TreeSet;


public class D {

  static String inputFile = "D-small-attempt0.in";
  static String outputFile = "D-small-attempt0.out";

  public static void main(String[] args) throws FileNotFoundException {
     Scanner in = new Scanner(new File(inputFile));
     PrintWriter out = new PrintWriter(new File(outputFile));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {

      int n = in.nextInt();
      int naomiWeights[] = new int[n];
      int kenWeights[] = new int[n];
      for (int i = 0; i < n; i++) {
        String w = in.next().substring(2);
        while (w.length() < 5)
          w = w + "0";
        naomiWeights[i] = Integer.parseInt(w);
      }
      for (int i = 0; i < n; i++) {
        String w = in.next().substring(2);
        while (w.length() < 5)
          w = w + "0";
        kenWeights[i] = Integer.parseInt(w);
      }
      out.println("Case #" + t + ": " + solve(naomiWeights, kenWeights));
    }
    out.close();
  }

  public static String solve(int[] naomiWeights, int[] kenWeights) {

    Arrays.sort(naomiWeights);
    Arrays.sort(kenWeights);
    
    int resultWar = playWar(naomiWeights, kenWeights);
    int resultDeceptiveWar = playDeceptiveWar(naomiWeights, kenWeights);
    
    return resultDeceptiveWar + " " + resultWar;
  }


  private static int playWar(int[] naomiWeights, int[] kenWeights) {

    TreeSet<Integer> set = new TreeSet<Integer>();
    for (int i = 0; i < kenWeights.length; i++) {
      set.add(kenWeights[i]);
    }
    
    int result = 0;
    for (int i = 0; i < naomiWeights.length; i++) {
      Integer higher = set.higher(naomiWeights[i]);
      Integer lowest = set.lower(naomiWeights[i]);
      if(higher == null) {
        result++;
        set.remove(lowest);
      }
      else {
        set.remove(higher);
      }
    }
    
    return result;
  }
  

  private static int playDeceptiveWar(int[] naomiWeights, int[] kenWeights) {
    
    LinkedList<Integer> list = new LinkedList<Integer>();
    for (int i = 0; i < naomiWeights.length; i++) {
      list.addLast(naomiWeights[i]);
    }
    int result = 0;
    for(int i = kenWeights.length - 1; i >= 0; i--){
      int naomiLowestWeight = list.getFirst();
      int naomiHighestWeight = list.getLast();
      if(naomiHighestWeight > kenWeights[i]) {
        result++;
        list.removeLast();
      }
      else {
        list.removeFirst();
      }
    }
    return result;
  }
  

}
