package com.company;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {

  public static void main(String[] args) throws IOException {
    File out = new File("out.out");
    out.createNewFile();
    BufferedWriter output = new BufferedWriter(new FileWriter(out));
    Scanner sc = new Scanner(new File("inRealSmall"));
    int numCases = sc.nextInt();
    List<String> answers = new ArrayList<String>();

    cases:
    for (int test = 1; test <= numCases; test++) {
      int num = sc.nextInt();
      HashSet<Integer> numbersToGet = new HashSet<Integer>();
      for (int i = 0; i < 10; i++) {
        numbersToGet.add(i);
      }
      if (num == 0) {
        answers.add("INSOMNIA");
        continue;
      }
      long accumulation = 0;
      for (int i = 0; i <= 100; i++) {
        accumulation += num;
        long copy = accumulation;
        while (copy > 0) {
          numbersToGet.remove((int) (copy % 10));
          if (numbersToGet.isEmpty()) {
            answers.add(Long.toString(accumulation));
            continue cases;
          }
          copy /= 10;
        }
      }
      /*int mag = magnitude(num);
      for (int i = 9; i >= 0; i-- ) {
        if (numbersToGet.contains(i)) {
          long must = i * 10 * (magnitude(num));
          long mult = must / num;
          if (must % num != 0) {
            mult += 1;
          }
          answers.add(Long.toString(mult * num));
          break;
        }
      } */


    }

    for (int i = 0; i < numCases; i++) {
      output.write(String.format("Case #%d: %s", i + 1, answers.get(i)));
      output.newLine();
      output.flush();
    }

  }

  static int magnitude(long num) {
    int result = 0;
    while (num > 0) {
      result++;
      num  /= 10;
    }
    return result;
  }
}
