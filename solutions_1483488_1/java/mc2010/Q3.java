import java.io.*;
import java.util.*;
public class Q3{
  public static void main(String args[]){
    try {
      BufferedReader is = new BufferedReader(
        new InputStreamReader(new FileInputStream(new File("C-large.in"))));
      BufferedWriter os = new BufferedWriter(
        new OutputStreamWriter(new FileOutputStream(new File("q3output-l.txt"))));

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

  private static void p(int w) {
    p(""+w);
  }

  private static void p(String w, BufferedWriter os) throws IOException{
    os.write(w);
    os.newLine();
  }

  private static String answer(String s) {
    StringTokenizer sb = new StringTokenizer(s);
    int result = 0;
    int min = Integer.parseInt(sb.nextToken());
    int max = Integer.parseInt(sb.nextToken());
    int border = first(max);
    
    for (int i=min;i<=max;i++){
    	result += pair(i, border, max);
    }
    return ""+result;
  }

  private static int pair(int i, int border, int max){
    int result = 0;
    int first = first(i);
    int num = i;
    int target = 0;
    int out = 0;
    Set<Integer> dup = new HashSet<Integer>();
    while(num >= 10 ) {
      target = num % 10;
      num = num/10;
      out++;
      int convert = convert(num, i, out);
      if (target > first && target < border) {
        if(!dup.contains(convert)){
          dup.add(convert);
          result++;
        }
      } else if(target == first && target == border) {
        if(!dup.contains(convert) && compare(convert, i) && !compare(convert, max)){
          dup.add(convert);
          result++;
        }
      } else if(target == first) {
        if(!dup.contains(convert) && compare(convert, i) && !compare(convert, max)){
          dup.add(convert);
          result++;
        }
      } else if(target == border) {
        if(!dup.contains(convert) && compare(convert, i) && !compare(convert, max)){
          dup.add(convert);
          result++;
        }
      }
    }
    return result;
  }

  private static int first(int num){
    int ret = num;
    while(ret >= 10) {
      ret = ret/10;
    }
    return ret;
  }

  private static int convert(int num, int all, int out){
    int m = power(out);
    int p = digits(num);
    return (all - num * m) * p + num;
  }

  private static boolean compare(int n, int com){
    return n > com;
  }

  private static int digits(int num){
    int ret = 10;
    while(num >= 10) {
      num = num/10;
      ret*=10;
    }
    return ret;
  }

  private static int power(int out){
    int ret = 1;
    for(int i =0;i<out;i++){
      ret *= 10;
    }
    return ret;
  }
}

