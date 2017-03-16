import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.*;

public class Problem2 {

  private static String calculate(int qtd, String[] lines) {

    int[] qtds = new int[2500];

    for (String line : lines) {

      String[] values = line.split(" ");

      for (String value : values) {

        int val = Integer.parseInt(value);
        qtds[val-1]++;

      }

    }

    ArrayList<Integer> results = new ArrayList<>();

    for (int i = 0; i < qtds.length; i++) {

      if (qtds[i]%2 != 0) {

        results.add(i+1);

      }

    }

    Object[] ints = results.toArray();
    Arrays.sort(ints);

    String result = "";
    for (int i = 0; i < results.size(); i++) {

      if (i != 0) result = result + " ";
      result = result + ints[i];

    }

    return result;

  }

  public static void main(String[] args) {

    Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    int i = 0;
    int cases = Integer.parseInt(sc.nextLine());

    while (i < cases) {

      String line = sc.nextLine();
      int qtd = Integer.parseInt(line);

      String[] lines = new String[(qtd*2)-1];
      for (int j = 0; j < (qtd*2)-1; j++) lines[j] = sc.nextLine();

      String result = calculate(qtd, lines);
      i++;

      System.out.println("Case #" + i + ": " + result);

    }

  }

}
