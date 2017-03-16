import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.HashSet;
import java.io.FileWriter;

public class RecyclingNumbers {
  public static void main(String... args) {
    RecyclingNumbers obj = new RecyclingNumbers();
    obj.run();
  }
  public void run() {
    
    try {
      File f = new File("C-large.in");
      File outFile = new File("output.txt");
      FileWriter w = new FileWriter(outFile);
      Scanner s = new Scanner(f);
      int T = s.nextInt();
      s.nextLine();
      for(int i = 1; i<= T; i++) {
        int lower = s.nextInt();
        int upper = s.nextInt();
        int maxRecycled = findRecycled(lower, upper);
        String str = "Case #" + i +": " + maxRecycled + '\n';
        w.write(str);
        if(s.hasNextLine()) s.nextLine();
      }
      w.close();
    }
    catch(Exception e) {
      System.out.println(e.toString());
    }
  }
  private int findRecycled(int lower, int upper) {
    int recycled = 0;
    HashSet<Pair> set = new HashSet<Pair>();
    for(int n = lower; n <= upper; n++) {
      String current = (new Integer(n)).toString();
      for(int r = 0; r < current.length(); r++) {
        String check = current.substring(1) + current.charAt(0);
        int m = Integer.parseInt(check);
        if( lower <= n) {
          if(n < m) {
            if( m <= upper) {
              set.add(new Pair(n,m));
            }
          }
        }
        current = check;
      }
    }
    return set.size();
  }
  
  private class Pair {
    public int x, y;
    public Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
    public boolean equals(Object obj)
    {
      if(this == obj)
        return true;
      if((obj == null) || (obj.getClass() != this.getClass()))
        return false;
      Pair p = (Pair)obj;
      return x == p.x && y == p.y;
    }
    
    public int hashCode()
    {
      int hash = 7;
      hash = 31 * hash + x;
      hash = 31 * hash + y;
      return hash;
    }
  }
}
