package com.denodev.tour1b.a;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Iterator;
import java.util.List;

/**
 * @author Arnaud DENOYELLE
 *
 *         Le 30 avr. 2016
 */
public class ProblemA {

  public static final String WORKSPACE = "/home/adenoyelle/gcj";
  public static final String OUTPUT = "output.txt";

  public static void main(String[] args) throws Exception {
    Path outputFilePath = Paths.get(WORKSPACE, OUTPUT);
    Files.deleteIfExists(outputFilePath);
    Files.createFile(outputFilePath);

    Path inputFilePath = Files.list(Paths.get(WORKSPACE))
        .filter(path -> path.toString().endsWith(".in"))
        .findFirst().get();

    List<String> lines = Files.readAllLines(inputFilePath);
    Iterator<String> iterator = lines.iterator();

    int nbPbs = Integer.valueOf(iterator.next());

    for (int testCase = 1; testCase <= nbPbs; testCase++) {
      int n = Integer.valueOf(iterator.next());
      String line = iterator.next();
      writeSol(outputFilePath, testCase, "" + go(line));
    }
  }

  public static void writeSol(Path outputFile, int testCase, String solution) throws Exception {
    Files.write(outputFile, String.format("Case #%d: %s\n", testCase, solution).getBytes(), StandardOpenOption.APPEND);
  }

  public static String go(String line) {
    return "";
  }
}