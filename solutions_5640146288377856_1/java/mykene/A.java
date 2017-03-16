package round2c;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by rubenverboon on 11/04/15.
 */
public class A {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner sc = new Scanner(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-A.in"));
    PrintWriter pw = new PrintWriter(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/Prel-A.out"));
    A instance = new A();
    int c = sc.nextInt();
    for (int i = 0; i < c; i++) {
      pw.println("Case #" + (i + 1) + ": " + instance.solve(sc));
    }
    pw.close();
    sc.close();
  }


  private int solve(Scanner sc) {
    map = new HashMap<>();
    int r = sc.nextInt();
    int c = sc.nextInt();
    int w = sc.nextInt();

    int res = (r-1)*(c/w);
    return res+ s(-1, c, c, -1,0, w, c);

  }

  HashMap<Integer, Integer> map = new HashMap<>();

  public int s(int laagsteMis, int hoogsteMis, int laagsteRaak, int hoogsteRaak, int raak, int w, int c) {
    int key = laagsteMis + hoogsteMis*23+laagsteRaak*529 + hoogsteRaak*12167 + raak* 279841;
    if(map.containsKey(key)) return map.get(key);

    if (raak == w) {
      if(hoogsteRaak-laagsteRaak==w-1){
        return 0;
      } else {
        return -1;
      }
    }
    int min = Integer.MAX_VALUE;
    for (int i = laagsteMis + 1; i < Math.min(laagsteMis + 1 + w, c ); i++) {
      System.out.println(i);
      min = Math.min(min, 1 + b(laagsteMis, hoogsteMis, laagsteRaak, hoogsteRaak, i, raak, w, c));
    }
    map.put(key, min);
    return min;
  }

  public int b(int laagsteMis, int hoogsteMis, int laagsteRaak, int hoogsteRaak, int schot, int raak, int w, int c) {
    int mis = Integer.MIN_VALUE;
    if(schot>hoogsteRaak && schot-laagsteMis>w)
      mis = s(laagsteMis, schot, laagsteRaak, hoogsteRaak, raak, w, c);
    else if(schot<laagsteRaak && hoogsteMis-schot>w)
      mis = s(schot, hoogsteMis, laagsteRaak, hoogsteRaak, raak, w, c);

    int geraakt = s(laagsteMis, hoogsteMis, Math.min(laagsteRaak, schot), Math.max(hoogsteRaak, schot), raak + 1, w, c);
    if(geraakt==-1&& mis <0){
      return 10000;
    }
    return Math.max(mis, geraakt);
  }
}
