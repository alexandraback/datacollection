package gcj;

/*
 * Problem B. Lawnmower
Confused? Read the quick-start guide.
Small input
10 points 
Solve B-small
You may try multiple times, with penalties for wrong submissions.
Large input
30 points 
You must solve the small input first.
You will have 8 minutes to solve 1 input file. (Judged after contest.)
Problem

Alice and Bob have a lawn in front of their house, shaped as a rectangle of N by M metres. Each year, they try to cut the lawn in some interesting pattern. So far, they had to do it with shears, which was very time-consuming, but now they have a new automatic lawnmower with multiple settings, and they want to try it out.

The new lawnmower has a height setting - you can set it to any height h between 1 and 100 millimetres, and it will cut all the grass higher than h it encounters to height h. You run it by entering the lawn at any part of the edge of the lawn, and the lawnmower goes in a straight line, perpendicular to the edge of the lawn it entered, cutting grass in a swath 1m wide, until it exits the lawn on the other side.

Alice and Bob have a number of various patterns of grass that they could have on their lawn. For each of those, they want to know whether it's possible to cut the grass into this pattern with their new lawnmower. Each pattern is described by specifying the height of the grass on each 1m x 1m square of the lawn.

The grass is 100mm high on the whole lawn initially.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing two numbers: N and M. Next follow N lines, with the ith line containing M numbers ai,j each, the number ai,j describing the desired height of the grass in the jth square of the ith row.

Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is either the word "YES" if it's possible to get the x-th pattern using the lawnmower, or "NO", if it's impossible (quotes for clarity only).

Limits

1 ² T ² 100.

Small dataset

1 ² N, M ² 10.
1 ² ai,j ² 2.
Large dataset

1 ² N, M ² 100.
1 ² ai,j ² 100.
Sample


Input 
  
Output 
 
3
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
1 3
1 2 1
Case #1: YES
Case #2: NO
Case #3: YES


 */
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class GCJ2013RQB {
  public static void main(String[] args) throws Exception {
    final String FILE_DIR = "/Users/jhorwitz/Downloads/";
    File inFile = new File(FILE_DIR + "B-small-attempt0.in");
    File outFile = new File(FILE_DIR + "gcj2013-rq-B-s.txt");
    Writer w = new FileWriter(outFile);
    Scanner s = new Scanner(inFile);

    int T = s.nextInt();
    for (int t = 1; t <= T; ++t) {
      int N = s.nextInt();
      int M = s.nextInt();
      int[][] patternHeight = new int[N][M];
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          patternHeight[i][j] = s.nextInt();
        }
      }
      output(w, t, isSolvable(patternHeight, N, M) ? "YES" : "NO");
    }
    s.close();
    w.close();
  }

  private static boolean isSolvable(int[][] patternHeight, int N, int M) {
    int rowMax[] = new int[N];
    for (int i = 0; i < N; ++i) {
      rowMax[i] = 0;
      for (int j = 0; j < M; ++j) {
        if (patternHeight[i][j] > rowMax[i]) rowMax[i] = patternHeight[i][j];
      }
    }

    int colMax[] = new int[M];
    for (int j = 0; j < M; ++j) {
      colMax[j] = 0;
      for (int i = 0; i < N; ++i) {
        if (patternHeight[i][j] > colMax[j]) colMax[j] = patternHeight[i][j];
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
//        if (patternHeight[i][j] < rowMax[i] && patternHeight[i][j] < colMax[j]) return false;
        if ( !(patternHeight[i][j] == rowMax[i] || patternHeight[i][j] == colMax[j]) ) return false;
      }
    }

    return true;
  }

  public static void output(Writer w, int t, String s) throws IOException {
    w.write("Case #" + t + ": " + s + "\n");
    System.out.println("Case #" + t + ": " + s);
  }
}