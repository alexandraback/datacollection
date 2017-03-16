
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;


public class CodejamQ1 {

  private static String inputFilename = "A-small-attempt0.in";
  private static String outputFilename = "";
  private static Map<Integer, Integer> dt = new HashMap<Integer, Integer>();
  private static ArrayList<Integer> nums;

  /**
   * Forgive me for my sins. I haven't woken up yet.
   * @param args
   */
  public static void main(String[] args) {
    Scanner sc = null, line = null;
    BufferedWriter out = null;
    outputFilename = inputFilename.substring(0, inputFilename.length() - 2)
        + "out";
    try {
      sc = new Scanner(new File(inputFilename));
      out = new BufferedWriter(new FileWriter(new File(outputFilename)));
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
    line = new Scanner(sc.nextLine());
    int runs = line.nextInt();

    try {
      for (int i = 1; i <= runs; ++i) {
        String input = sc.next();
        int n = sc.nextInt();
        out.write("Case #" + i + ": ");
        String result = attempt(input, n); 
        System.out.println("Case #" + i + ": " + result);
        out.write(result);
        out.newLine();
        if (sc.hasNextLine()) {
          sc.nextLine();
        }
      }
      out.close();

    } catch (IOException e) {
      e.printStackTrace();
    }
  }
  
  private static String attempt(String input, int n) {
    int pos = 0;
    int start = 0;
    int count = 0;
    while(pos < input.length() - n + 1) {
      if (isVowel(input.charAt(pos))) {
        ++pos;
        continue;
      }
      if (isConsecutiveN(pos, input, n)) {
        count += (pos - start + 1) * (input.length() - pos - n + 1);
        start = pos + 1;
      }
      ++pos;
    }
    return String.valueOf(count);
  }
  
  private static boolean isVowel(char c) {
    switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
    default:
        return false;
    }
  }
  
  private static boolean isConsecutiveN(int start, String input, int n) {
    if (start + n > input.length()) {
      return false;
    }
    for (int i = 0; i < n; ++i) {
      if (isVowel(input.charAt(start + i))) {
        return false;
      }
    }
    return true;
  }
  
}
