import sun.plugin2.message.SetAppletSizeMessage;

import java.io.File;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class cj6 {
  public static void main(String[] args) throws Exception {
    final Scanner scanner = new Scanner(new File("D:\\unsorted\\in.txt"));
    scanner.nextInt(); // T = 1
    System.out.println("Case #1:");

    final int R = scanner.nextInt();
    final int N = scanner.nextInt();
    final int M = scanner.nextInt();
    final int K = scanner.nextInt();

    List<List<Integer>> guesses = generateGuesses(M, N);
    List<Set<Integer>> results = new ArrayList<>();
    for (List<Integer> guess : guesses) {
      results.add(getPossibles(guess, 0));
    }


    for (int r = 1; r <= R; r++) {
      Set<Integer> result = new HashSet<>();
      for (int k = 0; k < K; k++)
        result.add(scanner.nextInt());

      int best = 0;
      for (int i = 0; i < guesses.size(); i++) {
        if (results.get(i).containsAll(result)) {
          best = i;
          break;
        }
      }
      System.out.println(convert(guesses.get(best)));
    }
  }

  private static String convert(List<Integer> guess) {
    String s = "";
    for (Integer i : guess) {
      s += i;
    }
    return s;
  }

  private static List<List<Integer>> generateGuesses(int M, int left) {
    List<List<Integer>> guesses = new ArrayList<>();
    if (left > 0) {
      for (List<Integer> guess : generateGuesses(M, left - 1)) {
        for (int i = 2; i <= M; i++) {
          List<Integer> newGuess = new ArrayList<>(guess);
          newGuess.add(i);
          guesses.add(newGuess);
        }
      }
    } else {
      guesses.add(new ArrayList<Integer>());
    }
    return guesses;
  }

  private static Set<Integer> getPossibles(List<Integer> guesses, int index) {
    Set<Integer> possibles = new HashSet<>();
    if (index == guesses.size()) {
      possibles.add(1);
    } else {
      for (Integer possible : getPossibles(guesses, index + 1)) {
        possibles.add(possible);
        possibles.add(possible * guesses.get(index));
      }
    }
    return possibles;
  }
}
