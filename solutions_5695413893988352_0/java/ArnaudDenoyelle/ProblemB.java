package com.denodev.tour1b.b;

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
public class ProblemB {

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
      String line = iterator.next();
      String go = go(line);
      writeSol(outputFilePath, testCase, "" + go);
    }
  }

  public static void writeSol(Path outputFile, int testCase, String solution) throws Exception {
    Files.write(outputFile, String.format("Case #%d: %s\n", testCase, solution).getBytes(), StandardOpenOption.APPEND);
  }

  public static String go(String line) {
    String[] games = line.split(" ");
    String coder = games[0];
    String jammer = games[1];
    char winner = 'o';
    int length = coder.length();

    StringBuilder resultCoder = new StringBuilder();
    StringBuilder resultJammer = new StringBuilder();


    for (int i = 0; i < length; i++) {
      char charCoder = coder.charAt(i);
      char charJammer = jammer.charAt(i);

      if (charCoder != '?' && charJammer != '?') {
        resultCoder.append(charCoder);
        resultJammer.append(charJammer);
      } else {
        //Au moins un des 2 est indéfini
        if ('C' == winner) {
          resultCoder.append(charCoder == '?' ? '0' : charCoder);
          resultJammer.append(charJammer == '?' ? '9' : charJammer);
        } else if ('J' == winner) {
          resultCoder.append(charCoder == '?' ? '9' : charCoder);
          resultJammer.append(charJammer == '?' ? '0' : charJammer);
        } else {
          //Au moins un des 2 est indéfini et il n'y a pas de gagnant.
          Integer nextDiff = nextDiff(coder, jammer, i+1);
          if(nextDiff == null) {
            resultCoder.append(charCoder != '?' ? charCoder : charJammer == '?'? '0' : charJammer);
            resultJammer.append(charJammer != '?' ? charJammer : charCoder == '?'? '0' : charCoder);
          } else {
            if(Math.abs(nextDiff) > 5) {
              if(nextDiff > 0) {
                resultCoder.append(charCoder != '?' ? charCoder : charJammer == '?'? '0' : charJammer);
                resultJammer.append(charJammer != '?' ? charJammer : charCoder == '?'? '1' : incChar(charCoder));
              } else {
                resultCoder.append(charCoder != '?' ? charCoder : charJammer == '?'? '1' : incChar(charJammer));
                resultJammer.append(charJammer != '?' ? charJammer : charCoder == '?'? '0' : charCoder);
              }
            } else if(Math.abs(nextDiff) == 5) {
              if(nextDiff > 0) {
                resultCoder.append(charCoder != '?' ? charCoder : charJammer == '?'? '0' : decChar(charJammer));
                resultJammer.append(charJammer != '?' ? charJammer : charCoder == '?'? '0' : charCoder);
              } else {
                resultCoder.append(charCoder != '?' ? charCoder : charJammer == '?'? '0' : charJammer);
                resultJammer.append(charJammer != '?' ? charJammer : charCoder == '?'? '0' : decChar(charCoder));
              }
            } else {
              resultCoder.append(charCoder != '?' ? charCoder : charJammer == '?'? '0' : charJammer);
              resultJammer.append(charJammer != '?' ? charJammer : charCoder == '?'? '0' : charCoder);
            }
          }
        }
      }
      winner = getWinner(resultCoder, resultJammer);
    }
    return resultCoder.toString() + " " + resultJammer.toString();
  }

  public static Integer nextDiff(String coder, String jammer, int offset) {
    for (int i = offset; i < coder.length(); i++) {
      char charCoder = coder.charAt(i);
      char charJammer = jammer.charAt(i);
      if (charCoder != '?' && charJammer != '?') {
        return Integer.valueOf(charCoder) - Integer.valueOf(charJammer);
      }
    }
    return null;
  }

  public static char getWinner(StringBuilder resultCoder, StringBuilder resultJammer) {
    int scoreCoder = Integer.valueOf(resultCoder.toString());
    int scoreJammer = Integer.valueOf(resultJammer.toString());
    if(scoreCoder > scoreJammer) {
      return 'C';
    }
    if(scoreCoder < scoreJammer) {
      return 'J';
    }
    return 'o';
  }

  public static char incChar(char c) {
    if(c == '9') {
      return '9';
    } else {
      return (char)(c + 1);
    }
  }


  public static char decChar(char c) {
    if(c == '0') {
      return '0';
    } else {
      return (char)(c - 1);
    }
  }
}