import java.io.*;
import java.util.*;
public class Q1{
  private static Map<Character, Character> m = new HashMap<Character, Character>();
  static{
    m.put('a', 'y');
    m.put('b', 'h');
    m.put('c', 'e');
    m.put('d', 's');
    m.put('e', 'o'); //yes
    m.put('f', 'c');
    m.put('g', 'v');
    m.put('h', 'x');
    m.put('i', 'd');
    m.put('j', 'u');
    m.put('k', 'i');
    m.put('l', 'g');
    m.put('m', 'l');
    m.put('n', 'b');
    m.put('o', 'k'); //
    m.put('p', 'r');
    m.put('q', 'z'); //yes
    m.put('r', 't');
    m.put('s', 'n');
    m.put('t', 'w');
    m.put('u', 'j');
    m.put('v', 'p');
    m.put('w', 'f');
    m.put('x', 'm');
    m.put('y', 'a'); //yes
    m.put('z', 'q'); //
    m.put(' ', ' ');
  }
  public static void main(String args[]){
    try {
      BufferedReader is = new BufferedReader(
        new InputStreamReader(new FileInputStream(new File("q1input.txt"))));
      BufferedWriter os = new BufferedWriter(
        new OutputStreamWriter(new FileOutputStream(new File("q1output.txt"))));

      int num = Integer.parseInt(in(is));

      for (int i=0;i<num;i++){
        String s = in(is);

        
        String o = convert(s);


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

  private static String convert(String in) {
p(in);
    StringBuffer sb = new StringBuffer();
    for ( int i=0;i<in.length();i++) {
      sb.append(convert(in.charAt(i)));
    }
    return sb.toString();
  }

  private static char convert(char c){
p(""+c);
    return m.get(c);
  }
}

