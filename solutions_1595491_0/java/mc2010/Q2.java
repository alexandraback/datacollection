import java.io.*;
import java.util.*;
public class Q2{
  static Map<Integer, Integer> m1 = new HashMap<Integer, Integer>();
  static Map<Integer, Integer> m2 = new HashMap<Integer, Integer>();
  static {
    for (int i = 0;i<31;i++){
      m1.put(i, max1(i)); 
      m2.put(i, max2(i)); 
    }
  }
  private static int max1(int i){
    if (i % 3 == 0) {
      return i/3;
    } else if (i%3 == 1){
      return i/3 + 1;
    } else {
      return i/3 + 1;
    } 
  }
  private static int max2(int i){
    if (i == 0) return 0;
    if (i % 3 == 0) {
      return i/3 + 1;
    } else if (i%3 == 1){
      return i/3 + 1;
    } else {
      return i/3 + 2;
    } 
  }
  public static void main(String args[]){
    try {
      BufferedReader is = new BufferedReader(
        new InputStreamReader(new FileInputStream(new File("q2input.txt"))));
      BufferedWriter os = new BufferedWriter(
        new OutputStreamWriter(new FileOutputStream(new File("q2output.txt"))));

      int num = Integer.parseInt(in(is));

      for (int i=0;i<num;i++){
        String s = in(is);

        
        String o = answer(s);


        p("Case #" + (i + 1) + ": " + o, os);

      }
      is.close();
      os.close();
    }catch(Exception e){
      e.printStackTrace();
    }
  }

  private static String in(BufferedReader is) throws IOException{
    return is.readLine();
  }

  private static void p(String n, String w){
    System.out.println(n + ":" + w);
  }

  private static void p(String w) {
    System.out.println(w);
  }

  private static void p(String w, BufferedWriter os) throws IOException{
    os.write(w);
    os.newLine();
  }

  private static String answer(String s) {
    StringTokenizer st = new StringTokenizer(s);
    int num = Integer.parseInt(st.nextToken());
    int spr = Integer.parseInt(st.nextToken());
    int min = Integer.parseInt(st.nextToken());

    int result = 0;
    for (int i = 0;i<num;i++) {
      int score = Integer.parseInt(st.nextToken());
      int max = m1.get(score);
      if (max >= min) {
        result++;
      } else {
        max = m2.get(score);
        if (max >= min) {
          result++;
          spr--;
        }
      }
    }
    return "" + (result + ((spr < 0)?spr:0));
  }
}

