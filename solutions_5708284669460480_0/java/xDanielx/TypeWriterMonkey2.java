package typewriter;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TypeWriterMonkey2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int numTestCases = sc.nextInt();
    for (int testCase = 1; testCase <= numTestCases; ++testCase) {
      int k = sc.nextInt(), l = sc.nextInt(), s = sc.nextInt();
      char[] keyboard = sc.next().toCharArray();
      char[] target = sc.next().toCharArray();
      System.out.printf("Case #%d: %.8f\n", testCase,
          getExpectedBananasLeft(s, keyboard, target));
    }
  }

  private static double getExpectedBananasLeft(int keystrokes, char[] keyboard, char[] target) {
    for (char c : target) {
      boolean available = false;
      for (char key : keyboard)
        available |= key == c;
      if (!available) return 0;
    }
    return getMaxInstances(keystrokes, target) - getExpectedInstances(keystrokes, keyboard, target);
  }

  private static int getMaxInstances(int keystrokes, char[] target) {
    int[] maxInstancesWithTargetPosition = new int[target.length];
    Arrays.fill(maxInstancesWithTargetPosition, Integer.MIN_VALUE);
    maxInstancesWithTargetPosition[0] = 0;
    for (int i = 0; i < keystrokes; ++i) {
      int[] next = new int[target.length];
      Arrays.fill(next, Integer.MIN_VALUE);
      for (int j = 0; j < target.length; ++j) {
        int instances = maxInstancesWithTargetPosition[j];
        if (j + 1 == target.length) {
          int newPos = getResetPos(target);
          next[newPos] = Math.max(next[newPos], instances + 1);
        } else {
          next[j + 1] = Math.max(next[j + 1], instances);
        }
      }
      maxInstancesWithTargetPosition = next;
    }
    return Arrays.stream(maxInstancesWithTargetPosition).max().getAsInt();
  }

  private static double getExpectedInstances(int keystrokes, char[] keyboard, char[] target) {
    List<String> strings = new ArrayList<>();
    strings.add("");
    for (int i = 0; i < keystrokes; ++i) {
      List<String> newStrings = new ArrayList<>();
      for (String s : strings) {
        for (char key : keyboard) {
          newStrings.add(s + key);
        }
      }
      strings = newStrings;
    }

    double total = 0;
    for (String s : strings) {
      double p = 1.0 / strings.size();
      total += p * count(s.toCharArray(), target);
    }
    return total;
  }

  static int count(char[] source, char[] target) {
    int n = 0;
    for (int i = 0; i < source.length - target.length + 1; ++i) {
      boolean match = true;
      for (int j = 0; j < target.length; ++j) {
        match &= source[i + j] == target[j];
      }
      if (match)
        ++n;
    }
    return n;
  }

  static int getResetPos(char[] target) {
    int pos = 0;
    for (int i = 1; i < target.length; ++i) {
      char c = target[i];
      if (c == target[pos])
        ++pos;
      else
        pos = 0;
    }
    return pos;
  }
}
