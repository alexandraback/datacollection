import java.util.*;

public class B {
  
  public static final long MOD = 1000000007;
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    long[] factorial = new long[101];
    factorial[0] = 1;
    for (int i = 1; i < factorial.length; ++i) {
      factorial[i] = factorial[i-1] * i;
      factorial[i] %= MOD;
    }
    for (int testnum = 1; testnum <= t; ++testnum) {
      System.out.printf("Case #%d: ", testnum);
      int n = in.nextInt();
      int[][] occurs = new int[26][26];
      int[] bound = new int[26];
      boolean possible = true;
      for (int i = 0; i < n; ++i) {
        String train = in.next();
        char begin = train.charAt(0);
        char end = train.charAt(train.length()-1);
        char cur = begin;
        int switchCount = 0;
        for (int j = 1; j < train.length(); ++j) {
          char next = train.charAt(j);
          if (next != cur) {
            ++switchCount;
            if (switchCount >= 2) {
              bound[v(cur)]++;
            }
            cur = next;
          }
        }
        occurs[v(begin)][v(end)]++;
        if (switchCount > 0 && begin == end) {
          //System.err.println("False1");
          possible = false;
        }
      }
      
      // check if a letter is bound badly
      for (char cur = 'a'; cur <= 'z'; ++cur) {
        if (bound[v(cur)] == 0) continue;
        if (bound[v(cur)] >= 2) possible = false;
        if (bound[v(cur)] >= 2) 
          //System.err.println("False2");
        for (char other = 'a'; other <= 'z'; ++other) {
          if (occurs[v(cur)][v(other)] > 0 || occurs[v(other)][v(cur)] > 0) {
            possible = false;
          //System.err.println("False3");
            break;
          }
        }
      }
      
      // check if more than 1 preceeds, or more than 1 succeeds any letter
      // ignoring singles
      // this means that any row or col in occurs must have sum <= 1 (ignoring diag)
      for (char begin = 'a'; begin <= 'z'; ++begin) {
        int rowSum = 0;
        int colSum = 0;
        for (char end = 'a'; end <= 'z'; ++end) {
          if (begin == end) continue;
          rowSum += occurs[v(begin)][v(end)];
          colSum += occurs[v(end)][v(begin)];
        }
        if (rowSum > 1 || colSum > 1) {
          possible = false;
          //System.err.println("False4");
        }
      }
      
      // check for any cycles -> ab ba
      for (char begin = 'a'; begin <= 'z'; ++begin) {
        int cycleLen = 1;
        char cur = begin;
        do {
          boolean notFound = true;
          for (char next = 'a'; next <= 'z'; ++next) {
            if (next == cur) continue;
            if (occurs[v(cur)][v(next)] == 0) continue;
            cur = next;
            ++cycleLen;
            notFound = false;
            break;
          }
          if (cycleLen > 26)
            break;
          if (notFound)
            break;
        } while (cur != begin);
        if (cur == begin && cycleLen > 1) {
          possible = false;
          //System.err.println("False5");
        }
      }
      //System.err.println();
      if (!possible) {
        System.out.printf("0\n");
        continue;
      }
      long total = 1L;
      for (char cur = 'a'; cur <= 'z'; ++cur) {
        total *= factorial[occurs[v(cur)][v(cur)]];
        total %= MOD;
      }
      int groupCount = 0;
      boolean[] used = new boolean[26];
      for (char begin = 'a'; begin <= 'z'; ++begin) {
        if (used[v(begin)]) continue;
        int rowSum = 0;
        for (char end = 'a'; end <= 'z'; ++end) {
          rowSum += occurs[v(begin)][v(end)];
        }
        if (rowSum == 0) continue;
        Queue<Character> queue = new LinkedList<Character>();
        queue.offer(begin);
        boolean newpath = true;
        while (!queue.isEmpty()) {
          char cur = queue.poll();
          if (used[v(cur)]) {
            newpath = false;
            break;
          }
          used[v(cur)] = true;
          for (char next = 'a'; next <= 'z'; ++next) {
            if (cur != next && occurs[v(cur)][v(next)] > 0) {
              queue.offer(next);
              break;
            }
          }
        }
        if (newpath)
          ++groupCount;
      }
      total *= factorial[groupCount];
      total %= MOD;
      System.out.printf("%d\n", total);
    }
  }
  
  public static int v(char c) {
    return c - 'a';
  }
}