
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class CloseMatch {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int numCases = scanner.nextInt();
    for (int i = 1; i <= numCases; ++i)
      System.out.printf("Case #%d: %s\n", i, getScores(scanner.next(), scanner.next()));
  }

  private static String getScores(String codersChars, String jammersChars) {
    int l = codersChars.length();
    List<Scores> possibleScores = new ArrayList<>();
    possibleScores.add(new Scores(0, 0));
    for (int i = 0; i < l; ++i) {
      char codersChar = codersChars.charAt(i), jammersChar = jammersChars.charAt(i);
      boolean codersUnknown = codersChar == '?', jammersUnknown = jammersChar == '?';
      List<Scores> newPossibleScores = new ArrayList<>();
      for (Scores scores : possibleScores) {
        if (codersUnknown && jammersUnknown) {
          if (scores.jammersScore < scores.codersScore) {
            newPossibleScores.add(scores.extend(0, 9));
          } else if (scores.codersScore < scores.jammersScore) {
            newPossibleScores.add(scores.extend(9, 0));
          } else {
            newPossibleScores.add(scores.extend(0, 0));
            newPossibleScores.add(scores.extend(1, 0));
            newPossibleScores.add(scores.extend(0, 1));
          }
        } else if (codersUnknown) {
          int jammersDigit = Character.digit(jammersChar, 10);
          if (scores.jammersScore < scores.codersScore) {
            newPossibleScores.add(scores.extend(0, jammersDigit));
          } else if (scores.codersScore < scores.jammersScore) {
            newPossibleScores.add(scores.extend(9, jammersDigit));
          } else {
            newPossibleScores.add(scores.extend(jammersDigit, jammersDigit));
            if (jammersDigit > 0)
              newPossibleScores.add(scores.extend(jammersDigit - 1, jammersDigit));
            if (jammersDigit < 9)
              newPossibleScores.add(scores.extend(jammersDigit + 1, jammersDigit));
          }
        } else if (jammersUnknown) {
          int codersDigit = Character.digit(codersChar, 10);
          if (scores.jammersScore < scores.codersScore) {
            newPossibleScores.add(scores.extend(codersDigit, 9));
          } else if (scores.codersScore < scores.jammersScore) {
            newPossibleScores.add(scores.extend(codersDigit, 0));
          } else {
            newPossibleScores.add(scores.extend(codersDigit, codersDigit));
            if (codersDigit > 0)
              newPossibleScores.add(scores.extend(codersDigit, codersDigit - 1));
            if (codersDigit < 9)
              newPossibleScores.add(scores.extend(codersDigit, codersDigit + 1));
          }
        } else { // both known
//          System.err.println(Character.digit(codersChar, 10) + " " + Character.digit(jammersChar, 10));
//          System.err.println("before: " + newPossibleScores);
          newPossibleScores.add(scores.extend(
              Character.digit(codersChar, 10), Character.digit(jammersChar, 10)));
//          System.err.println("after: " + newPossibleScores);
        }
      }
      possibleScores = newPossibleScores;
//      System.err.println(possibleScores);
    }
    Scores bestScores = Collections.min(possibleScores, new ScoresComparator());
    return bestScores.toString(l);
  }

  private static class Scores {
    final long codersScore, jammersScore;

    Scores(long codersScore, long jammersScore) {
      this.codersScore = codersScore;
      this.jammersScore = jammersScore;
    }

    Scores extend(int codersDigit, int jammersDigit) {
      return new Scores(codersScore * 10 + codersDigit, jammersScore * 10 + jammersDigit);
    }

    long getDelta() {
      return Math.abs(codersScore - jammersScore);
    }

    @Override
    public String toString() {
      return toString(0);
    }

    String toString(int length) {
      return pad(codersScore, length) + " " + pad(jammersScore, length);
    }

    private static String pad(long score, long length) {
      String s = Long.toString(score);
      while (s.length() < length)
        s = "0" + s;
      return s;
    }
  }

  private static class ScoresComparator implements Comparator<Scores> {
    @Override
    public int compare(Scores a, Scores b) {
      long deltaDiff = a.getDelta() - b.getDelta();
      if (deltaDiff != 0)
        return deltaDiff < 0 ? -1 : 1;

      long codersDiff = a.codersScore - b.codersScore;
      if (codersDiff != 0)
        return codersDiff < 0 ? -1 : 1;

      long jammersDiff = a.jammersScore - b.jammersScore;
      if (jammersDiff != 0)
        return jammersDiff < 0 ? -1 : 1;

      return System.identityHashCode(a) - System.identityHashCode(b);
    }
  }
}
