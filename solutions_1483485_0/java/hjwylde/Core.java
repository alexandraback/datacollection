package qualification.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Core {
  
  public static void main(String[] args) {
    Map<Character, Character> mapping = new HashMap<Character, Character>();
    mapping.put('a', 'y');
    mapping.put('b', 'h');
    mapping.put('c', 'e');
    mapping.put('d', 's');
    mapping.put('e', 'o');
    mapping.put('f', 'c');
    mapping.put('g', 'v');
    mapping.put('h', 'x');
    mapping.put('i', 'd');
    mapping.put('j', 'u');
    mapping.put('k', 'i');
    mapping.put('l', 'g');
    mapping.put('m', 'l');
    mapping.put('n', 'b');
    mapping.put('o', 'k');
    mapping.put('p', 'r');
    mapping.put('q', 'z');
    mapping.put('r', 't');
    mapping.put('s', 'n');
    mapping.put('t', 'w');
    mapping.put('u', 'j');
    mapping.put('v', 'p');
    mapping.put('w', 'f');
    mapping.put('x', 'm');
    mapping.put('y', 'a');
    mapping.put(' ', ' ');
    mapping.put('z', 'q');
    // qz
    
    try {
      Scanner scan = new Scanner(new File(args[0]));
      
      int t = scan.nextInt();
      for (int i = 1; i <= t; i++) {
        String line = scan.nextLine();
        if (line.length() == 0) {
          i--;
          continue;
        }
        
        System.out.println(solve(i, line, mapping));
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }
  
  public static String solve(int caseNumber, String line,
      Map<Character, Character> mapping) {
    // line = line.replaceAll("b", "<b>");
    // line = line.replaceAll("q", "<q>");
    // line = line.replaceAll("z", "<z>");
    
    String newLine = "";
    for (int i = 0; i < line.length(); i++)
      if (mapping.containsKey(line.charAt(i)))
        newLine += mapping.get(line.charAt(i));
      else
        newLine += "<" + line.charAt(i) + ">";
    
    return "Case #" + caseNumber + ": " + newLine;
  }
}
