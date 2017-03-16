package com.tzafrir.codeJam.contest2014.round1C;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * a solver interface for google contest riddles
 * @author tzafrir
 *
 */
public class B {

    public static void main(String[] args) throws Exception {

        //solve one case for test purpose
        //        String input = "3\n" +
        //                "ab bbbc cd";
        //        Scanner scanner = new Scanner(new ByteArrayInputStream(input.getBytes()));
        //        new B().solveCase(scanner);

        InputStream is = new BufferedInputStream(new FileInputStream(args[0]+".in"));
        System.setOut(new PrintStream(args[0]+".out"));
        Scanner scanner = new Scanner(is);
        new B().solve(scanner);

        scanner.close();
    }

    private List<String> getAllMatchingWords(List<String> words, char charAt) {
        List<String> ret = new ArrayList<String>();
        String lookFor = String.valueOf(charAt);
        for (String word : words)
            if (word.startsWith(lookFor))
                ret.add(word);
        if (ret.isEmpty())
            for (String word : words)
                if (!word.isEmpty())
                    ret.add(word);
        return ret;
    };

    private List<String> getAllValidWords(List<String> words,String currentWord) {
        List<String> res = new ArrayList<String>();
        if (noMoreWords(words)) {
            res.add(currentWord);
            return res;
        }
        List<String> allMatchingWords = getAllMatchingWords(words,currentWord.charAt(currentWord.length()-1));
        for (String word : allMatchingWords) {
            if (isValidWord(currentWord+word)) {
                int index = words.indexOf(word);
                words.set(index, "");
                res.addAll(getAllValidWords(words, currentWord+word));
                words.set(index, word);
            }
        }
        return res;
    }

    private boolean isValidWord(String word) {
        List<String> setChars = new ArrayList<String>();
        char last=word.charAt(0);
        setChars.add(String.valueOf(last));
        for (int i=0;i<word.length();i++) {
            char current = word.charAt(i);
            if (current==last)
                continue;
            last=current;
            if (setChars.contains(String.valueOf(last)))
                return false;
            setChars.add(String.valueOf(last));
        }
        return true;
    }

    private boolean noMoreWords(List<String> words) {
        for (String word : words)
            if (!word.isEmpty())
                return false;
        return true;
    }

    private String reducedWord(String word) {
        StringBuilder builder = new StringBuilder();
        char last=word.charAt(0);
        builder.append(last);
        for (int i=1;i<word.length();i++) {
            char current = word.charAt(i);
            if (current==last)
                continue;
            last=current;
            builder.append(String.valueOf(last));
        }
        return builder.toString();
    }

    /**
     * solve the given riddle
     * first read the amount of riddles in the data, then solve each of it
     * @param scanner to read the input data from
     */
    public void solve(Scanner scanner) {
        int numCases = scanner.nextInt();
        //        long time = System.currentTimeMillis();
        for (int i = 1; i <= numCases; i++) {
            System.out.print("Case #" + i + ": ");
            solveCase(scanner);
        }
        //        System.out.println("took "+(System.currentTimeMillis()-time));
    }

    /**
     * solve a given case of the underlying riddle
     * @param scanner to get the input data from
     */
    public void solveCase(Scanner scanner) {
        int n = scanner.nextInt();
        List<String> words = new ArrayList<String>(n);
        for (int i=0;i<n;i++)
            words.add(reducedWord(scanner.next()));
        List<String> res = new ArrayList<String>();
        String current;
        for (int i=0;i<n;i++) {
            current = words.get(i);
            words.set(i, "");
            res.addAll(getAllValidWords(words, current));
            words.set(i, current);
        }
        System.out.println(res.size());
    }

}
