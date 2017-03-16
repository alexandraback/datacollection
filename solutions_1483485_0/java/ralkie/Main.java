package lt.kasrud.gcj.ex1;

import lt.kasrud.gcj.common.io.Reader;
import lt.kasrud.gcj.common.io.Writer;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created with IntelliJ IDEA.
 * User: ralkie
 * Date: 4/14/12
 * Time: 5:55 AM
 * To change this template use File | Settings | File Templates.
 */
public class Main {
  private static final Map<Character, Character> m = new HashMap<Character, Character>();
  static {
    m.put('y', 'a');
    m.put('n', 'b');
    m.put('f', 'c');
    m.put('i', 'd');
    m.put('c', 'e');
    m.put('w', 'f');
    m.put('l', 'g');
    m.put('b', 'h');
    m.put('k', 'i');
    m.put('u', 'j');

    m.put('o', 'k');
    m.put('m', 'l');
    m.put('x', 'm');
    m.put('s', 'n');
    m.put('e', 'o');
    m.put('v', 'p');
    m.put('z', 'q');
    m.put('p', 'r');
    m.put('d', 's');
    m.put('r', 't');

    m.put('j', 'u');
    m.put('g', 'v');
    m.put('t', 'w');
    m.put('h', 'x');
    m.put('a', 'y');
    m.put('q', 'z');
  }

  public static void main(String[] args) throws IOException {
    List<String> iData = Reader.readFile("A-small-attempt0.in");
    Writer.writeFile("out1.txt", process(iData.subList(1, iData.size())));
  }

  private static List<String> process(List<String> data) {
    List<String> result = new ArrayList<String>(data.size());
    for(String record : data){
      String decrypted = "";
      for (int i = 0; i < record.length(); i++) {
        Character c = record.charAt(i);
        decrypted += (m.containsKey(c) ? m.get(c) : c.toString().toUpperCase());
      }
      result.add(decrypted);
    }

    return result;
  }
}
