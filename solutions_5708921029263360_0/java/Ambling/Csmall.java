package round1C;

import java.util.ArrayList;
import java.util.Scanner;

class Csmall {

  static class Conflict {
    int count[];

    public Conflict() {
      count = new int[3];
      for (int i = 0; i < 3; i++) {
        count[i] = 1;
      }
    }

    public Conflict(Conflict conf) {
      count = new int[3];
      for (int i = 0; i < 3; i++) {
        count[i] = conf.count[i];
      }
    }

    public void inc(int i) {
      if (i > 0) count[i-1] ++;
    }

    public boolean valid(int K) {
      for (int i: count) {
        if (i > K) return false;
      }
      return true;
    }

    public String toString() {
      return "conflict: " + count[0] + " " + count[1] + " " + count[2] + "\n";
    }
  }

  static class Fit {
    int j;
    int p;
    int s;

    public Fit(int jj, int pp, int ss) {
      j = jj;
      p = pp;
      s = ss;
    }

    public int conflict(Fit other) {
      if (other.j == j && other.p == p) return 1;
      if (other.j == j && other.s == s) return 2;
      if (other.p == p && other.s == s) return 3;
      return 0;
    }

    public String toString() {
      return "" + j + " " + p + " " + s + "\n";
    }
  }

  static int choose(int ch, int K, ArrayList<Fit> all, ArrayList<Fit> past, ArrayList<Fit> choices, int max) {
    if (ch >= all.size()) {
//      for (Fit fit: past) {
//        System.out.print(fit);
//      }
//      System.out.print("\n");

      if (past.size() > max) {
        max = past.size();
        choices.clear();
        for (Fit fit: past) {
          choices.add(fit);
        }
//        System.out.print(conflict);
      }
      return max;
    }

    Fit fit = all.get(ch);
    Conflict conf = new Conflict();
    for (Fit f: past) {
      conf.inc(f.conflict(fit));
    }

//    System.out.println();
//    for (Fit f: past) {
//      System.out.print(f);
//    }
//    System.out.print(fit);
//    System.out.print(conf);

    if (conf.valid(K)) {
      past.add(fit);
      max = choose(ch+1, K, all, past, choices, max);
      past.remove(fit);
    }

    max = choose(ch+1, K, all, past, choices, max);

    return max;
  }

  static void run(Scanner scanner, int testCase) {
    int J = scanner.nextInt();
    int P = scanner.nextInt();
    int S = scanner.nextInt();
    int K = scanner.nextInt();


    ArrayList<Fit> all = new ArrayList<Fit>(J * P * S);
    for (int j = 1; j <= J; ++ j) {
      for (int p = 1; p <= P; ++ p) {
        for (int s = 1; s <= S; ++ s) {
          all.add(new Fit(j, p, s));
        }
      }
    }

    ArrayList<Fit> choice = new ArrayList<Fit>();
    if (K < 3) {
      choose(0, K, all, new ArrayList<Fit>(), choice, 0);
    } else {
      choice = all;
    }


    System.out.printf("Case #%d: %d\n", testCase, choice.size());
    for (Fit fit: choice) {
      System.out.print(fit);
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();
    scanner.nextLine();
    for (int t = 1; t <= T; t++) {
      run(scanner, t);
    }
  }
}