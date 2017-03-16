import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class MeanGirls {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File("C-small-attempt4.in"));
    PrintWriter out = new PrintWriter(new File("gossipS.txt"));
    long numTests = in.nextLong();

    for (long test = 0; test < numTests; test++) {
      in.nextLine();
      int testSize = in.nextInt();
      int[] heights = new int[testSize];

      in.nextLine();
      for (int col = 0; col < testSize; col++) {
        int h = in.nextInt();
        heights[col] = h;
      }

      int maxSize = 0;
      int[] dest = new int[testSize];

      int[] orig = new int[testSize];
      
      for (int i : heights) {
        System.out.print(i);
      }

      for (int i = 0; i < testSize; i++) {
        orig[i] = heights[i];
      }
      System.out.println();
      for (int s = 0; s < testSize; s++) {
        int res = max(s,orig,new ArrayList<Integer>(),s,s);
        if(res > maxSize){
          maxSize = res;
        }
      }

      out.print("Case #" + (test + 1) + ": ");
      out.println(maxSize);
    }
    out.close();
    in.close();
  }
  
  public static int max(int cur, int[]bffs, ArrayList<Integer> v, int past, int first){
    if(v.contains(cur)){
      return 0;
    }
    v.add(cur);
    int res = 1;
    boolean f = false;
    for(int i = 0 ; i < bffs.length; i++){
      if((bffs[cur] == past+1 || bffs[cur] == i+1)){
        if(! v.contains(i)){
        int r = max(i,bffs,v,cur,first);
        if(res < r+1 && r > 0){
          res = r+1;
        }
        if(r > 0){
          f = true;
        }
        }
      }
    }
    if(!f){
      if(bffs[cur] != past+1 && bffs[cur] != first+1){
        res = 0;
      }
    }
    v.remove((Integer)cur);
    return res;
  }

}
