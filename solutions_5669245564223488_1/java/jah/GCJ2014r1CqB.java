package gcj;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

import com.google.common.collect.Lists;
import com.google.common.collect.Maps;
import com.google.common.collect.Sets;
import com.google.common.collect.Sets.SetView;

/*
 * Problem

Yahya is a brilliant kid, so his mind raises a lot of interesting questions when he plays with his toys. Today's problem came about when his father brought him a set of train cars, where each car has a lowercase letter written on one side of the car.

When he first saw the gift, he was happy and started playing with them, connecting cars together without any particular goal. But after a while he got bored (as usual) from playing without having any goal. So, he decided to define a new interesting problem.

The problem is that he currently has N sets of connected cars. He can represent each set of connected cars as a string of lowercase letters. He wants to count the number of ways he can connect all N sets of cars to form one valid train. A train is valid if all occurrences of the same character are adjacent to each other.


The previous figure is one way Yahya could connect the cars "ab", "bc" and "cd" to make a valid train: "ab bc cd". If he had connected them in the order "cd ab bc", that would have been invalid: the "c" characters would not have been adjacent to each other.

You've surely noticed that this is not an easy problem for Yahya to solve, so he needs your help (and he is sure that you will give it!). That's it; go and help Yahya!

Note: letters are written only on one side of the cars, so you can not reverse them. For example, if a car has "ab" written on it, it could not be changed to read "ba".

Input

The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case contains a single integer N, the number of sets of connected cars. The following line contains N strings separated by a single space. Every given string represents a set of connected cars and is composed of lowercase English letters only.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the number of different ways of obtaining a valid train. As this number may be very big, output the number of ways modulo 1,000,000,007.

Limits

1 ≤ T ≤ 100.
1 ≤ Set of connected Cars' lengths ≤ 100.
Small dataset

1 ≤ N ≤ 10.
Large dataset

1 ≤ N ≤ 100.
Sample


Input 
    
Output 
 
3
3
ab bbbc cd
4
aa aa bc c
2
abc bcd

Case #1: 1
Case #2: 4
Case #3: 0
Sample Explanation

In the first case, there is only one way to form a valid train by joining string "ab" to "bbbc" to "cd" in this order.

While in the second case, there are 4 possible ways to form a valid train. Notice that there are two different sets of connected cars represented by the string "aa", so there are two different ways to order these two strings and to group them to be one set of connected cars "aaaa". Also there is only one way to order set of cars "bc" with "c" in only one way to be "bcc". After that you can order "aaaa" and "bcc" in two different ways. So totally there are 2*2 = 4 ways to form a valid train.

In the third sample case, there is no possible way to form a valid train, as if joined in any of the two ways "abc"+"bcd" or "bcd"+"abc", there will be two letters of "b" and "c" not consecutive.
 */
public class GCJ2014r1CqB {
    private static final long BIG_MODULUS = 1000000007;

    public static void main(String[] args) throws Exception {
        final String FILE_DIR = "/Users/jhorwitz/Downloads/";
      File inFile = new File(FILE_DIR + "B-large.in");
      File outFile = new File(FILE_DIR + "gcj2014R1C-qB-l.txt");
        Writer w = new FileWriter(outFile);
        Scanner s = new Scanner(inFile);

        int T = s.nextInt();
        for (int t = 1; t <= T; ++t) {
            int N = s.nextInt();
            List<String> carSets = Lists.newArrayListWithCapacity(N);
            for (int i = 1; i <= N; ++i) {
                carSets.add(s.next());
            }
            output(w, t, String.valueOf(solveModBigModulus(carSets)));
        }
        s.close();
        w.close();
    }

    private static long solveModBigModulus(List<String> carSets) {
        Map<Character, Character> carEndPairings = Maps.newHashMap();
        Set<Character> leftEndLetters = Sets.newHashSet();
        Set<Character> middleLetters = Sets.newHashSet(); // letters except for the 2 on the very ends of a car set
        Set<Character> rightEndLetters = Sets.newHashSet();
        int[] doubleLetterCount = new int[26]; // instead of going into leftEndLetters and rightEndLetters, track here when seeing (e.g.) aa or bb or cc ...; doubleLetterCount[0] = # of "aa"s, ... doubleLetterCount[25] = # of "zz"s
        Set<Character> allEndLetters = Sets.newHashSet(); // redundant with previous sets, but here for convenience
        for (String carSet : carSets) {
            // remove adjacent duplicates except if all are same, leave as 2 (same) chars
            char[] carSetAsCA = carSet.toCharArray();
            StringBuilder dupeFreeCarSetSB = new StringBuilder();
            dupeFreeCarSetSB.append(carSetAsCA[0]);
            for (int i = 1; i < carSetAsCA.length; ++i) {
                if (carSetAsCA[i] != carSetAsCA[i-1]) dupeFreeCarSetSB.append(carSetAsCA[i]);
            }
            char[] dupeFreeCarSetAsCA = dupeFreeCarSetSB.toString().toCharArray();
            if (dupeFreeCarSetAsCA.length == 1) dupeFreeCarSetAsCA = new char[] { dupeFreeCarSetAsCA[0], dupeFreeCarSetAsCA[0] }; // if we're left with (or even just started with) a 1-char set, make it a 2-char (duplicate chars) for convenience

            for (int i = 1; i < dupeFreeCarSetAsCA.length - 1; ++i) {
                if (!middleLetters.add(dupeFreeCarSetAsCA[i])) return 0; // if a letter shows up more than once (non-consecutively--we've removed consecutives...), there's no solution
            }
            char leftEnd = dupeFreeCarSetAsCA[0];
            char rightEnd = dupeFreeCarSetAsCA[dupeFreeCarSetAsCA.length - 1];
            if (leftEnd != rightEnd) {
                leftEndLetters.add(leftEnd);
                rightEndLetters.add(rightEnd);
                if (carEndPairings.put(leftEnd, rightEnd) != null) return 0; // can't have ab and ac (or even ab and ab)--if "a" was already a left end for someone, there's no solution
            } else {
                for (int i = 0; i < carSetAsCA.length; ++i) {
                    if (carSetAsCA[i] != leftEnd) return 0; // if left and right are the same, the car set must be all the same letter, otherwise there's no solution
                }
                ++(doubleLetterCount[leftEnd - 'a']);
            }
            allEndLetters.add(leftEnd); // counts ends of doubles, too
            allEndLetters.add(rightEnd); // counts ends of doubles, too

        }

        if (Sets.intersection(allEndLetters, middleLetters).size() > 0) return 0; // if a letter that shows up once in the middle (i.e., not an end) of a car also shows up at the end of a car (and we aren't talking about the same car with no different letters between the two instances noted here--we've removed consecutives), there's no solution


        int nSubtrains = 0;

        // TODO: clean up redundant sets in code (e.g., we don't need all of allEndLettersBuDupers, allEndLetters, leftEndLetters, etc.)
        Set<Character> allEndLettersButDupes = Sets.newHashSet();
        allEndLettersButDupes.addAll(leftEndLetters);
        allEndLettersButDupes.addAll(rightEndLetters);
        for (int i = 0; i < 26; ++i) {
            if (doubleLetterCount[i] > 0 && !allEndLettersButDupes.contains((char) ('a' + i))) {
                ++nSubtrains; // there's a subtrain of just (aa)^+ (or (bb)^+, etc.)
            }
        }

        while (!allEndLettersButDupes.isEmpty()) {
            SetView<Character> leftOnly = Sets.difference(leftEndLetters, rightEndLetters);
            if (leftOnly.isEmpty()) return 0; // no more lefts to start a new subtrain (i.e., connected component), but car sets remain

            ++nSubtrains;
            Character leftOfCurSetOfCurSubtrain = (Character) leftOnly.iterator().next(); // select an arbitrary element from the set of left ends that aren't right ends
            while (true) {
                leftEndLetters.remove(leftOfCurSetOfCurSubtrain);
                allEndLettersButDupes.remove(leftOfCurSetOfCurSubtrain);
                leftOfCurSetOfCurSubtrain = carEndPairings.get(leftOfCurSetOfCurSubtrain);
                if (leftOfCurSetOfCurSubtrain == null) break;
                rightEndLetters.remove(leftOfCurSetOfCurSubtrain);
            }
        }

        long retVal = 1;

        // aa aa aa can be ordered 3! ways (etc.); product principle over alphabet
        for (int i = 0; i < 26; ++i) {
            retVal = (retVal * modFactorial(doubleLetterCount[i], BIG_MODULUS)) % BIG_MODULUS;
        }

        // n subtrains (i.e., independent segments) can be ordered n! ways
        retVal = (retVal * modFactorial(nSubtrains, BIG_MODULUS)) % BIG_MODULUS;

        return retVal;
    }

    private static long modFactorial(int i, long modulus) {
        long retVal = 1;

        for (; i > 1; --i) {
            retVal = (retVal * i) % modulus;
        }

        return retVal;
    }

    private static void output(Writer w, int t, String s) throws IOException {
        w.write("Case #" + t + ": " + s + "\n");
        System.out.println("Case #" + t + ": " + s);
    }
}