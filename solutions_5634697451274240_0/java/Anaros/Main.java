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
    Scanner sc = new Scanner(new File("inSmallReal"));
    int numCases = Integer.valueOf(sc.nextLine());
    List<String> answers = new ArrayList<String>();

    cases:
    for (int test = 1; test <= numCases; test++) {
      String line = sc.nextLine();
      int flips = 0;
      while (true) {
        char top = line.charAt(0);
        int otherIndex = line.indexOf(other(top));
        if (otherIndex == -1) {
          if (top == '+') {
            break;
          } else {
            flips += 1;
            break;
          }
        }
        line = line.substring(otherIndex);
        flips++;
      }
      answers.add(Integer.toString(flips));
    }

    for (int i = 0; i < numCases; i++) {
      output.write(String.format("Case #%d: %s", i + 1, answers.get(i)));
      output.newLine();
      output.flush();
    }

  }

  static char other(char c) {
    return c == '+'? '-' : '+';
  }
}
