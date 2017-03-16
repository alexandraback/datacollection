package gcj;

/*
 * Problem C. Fair and Square
Confused? Read the quick-start guide.
Small input
10 points 
Solve C-small
You may try multiple times, with penalties for wrong submissions.
Large input 1
35 points 
You must solve the small input first.
You will have 8 minutes to solve 1 input file. (Judged after contest.)
Large input 2
55 points 
You must solve the small input first.
You will have 8 minutes to solve 1 input file. (Judged after contest.)
Problem

Little John likes palindromes, and thinks them to be fair (which is a fancy word for nice). A palindrome is just a number that reads the same backwards and forwards - so 6, 11 and 121 are all palindromes, while 12, 223 and 2244 are not.

He recently became interested in squares as well, and formed the definition of a fair and square number - it is a number that is a palindrome and a square of a palindrome at the same time. For instance, 1, 9 and 121 are fair and square (being palindromes and squares, respectively, of 1, 3 and 11), while 16, 22 and 676 are not fair and square - the first is not a palindrome, the second is not a square, and the third is a square, but not a square of a palindrome.

Now he wants to search for bigger fair and square numbers. Your task is, given an interval Little John is searching through, to tell him how many fair and square numbers are there in the interval, so he knows when he has found them all.

Solving this problem

Usually, Google Code Jam problems have 1 Small input and 1 Large input. This problem has 1 Small input and 2 Large inputs. Once you have solved the Small input, you will be able to download any of the two Large inputs. As usual, you will be able to retry the Small input (with a time penalty), while you will get only one chance at each of the Large inputs.

Input

The first line of the input gives the number of test cases, T. T lines follow. Each lines contains two numbers, A and B - the endpoints of the interval Little John is looking at.

Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the number of fair and square numbers greater or equal to A and smaller or equal than B.

Limits

Small dataset

1 ² T ² 100.
1 ² A ² B ² 1000.

First large dataset

1 ² T ² 10000.
1 ² A ² B ² 1014.

Second large dataset

1 ² T ² 1000.
1 ² A ² B ² 10100.

Sample


Input 
  
Output 
 
3
1 4
10 120
100 1000
Case #1: 2
Case #2: 0
Case #3: 2


 */
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class GCJ2013RQC {
  public static void main(String[] args) throws Exception {
    final String FILE_DIR = "/Users/jhorwitz/Downloads/";
    File inFile = new File(FILE_DIR + "C-large-1.in");
    File outFile = new File(FILE_DIR + "gcj2013-rq-C-l1.txt");
    Writer w = new FileWriter(outFile);
    Scanner s = new Scanner(inFile);

    int T = s.nextInt();
    for (int t = 1; t <= T; ++t) {
      int outputVal = 0;
      long A = s.nextLong();
      long B = s.nextLong();
      long sqrtA = (int)Math.sqrt(A);
      long sqrtB = (int)Math.sqrt(B);
      if (sqrtA*sqrtA < A) ++sqrtA; // round up if not perfect square
      for (long i = sqrtA; i <= sqrtB; ++i) {
        if (isPalindrome(i) && isPalindrome(i*i)) {
          ++outputVal;
        }
      }
      output(w, t, Integer.toString(outputVal));
    }
    s.close();
    w.close();
  }

  private static boolean isPalindrome(long n) {
    long origN = n;
    long rev = 0;
    while (n > 0) {
      long r = n % 10;
      n = n / 10;
      rev = rev * 10 + r;
    }
    return (origN == rev);
  }

  public static void output(Writer w, int t, String s) throws IOException {
    w.write("Case #" + t + ": " + s + "\n");
    System.out.println("Case #" + t + ": " + s);
  }
}