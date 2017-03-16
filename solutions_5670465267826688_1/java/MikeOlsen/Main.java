package jam;

import java.io.*;
import java.util.Scanner;

public class Main {
    static String inputfile = "qual_c.in";
    static String outputfile = "qual_c.out";
    static String answer;
    static BufferedWriter writer;
    static Scanner scanner;

    public static void writeAnswer(int caseNum) throws Exception {
        //System.out.println("Case #" + caseNum + ": " + answer);
        writer.write("Case #" + caseNum + ": " + answer);
        writer.newLine();
    }

    public static void main(String[] args) throws Exception {
        scanner = new Scanner(new File(inputfile));
        writer = new BufferedWriter(new FileWriter(outputfile));

        //Case loop:
        int numCases = scanner.nextInt();
        for(int caseNum = 1; caseNum <= numCases; caseNum++) {
            //System.out.println("starting case num: " + caseNum);
            answer = "";
            solve();
            writeAnswer(caseNum);
        }

        //Cleanup:
        scanner.close();
        writer.close();
    }

    public static void solve() {
        // get input from scanner
        // write answer to answer

        sLength = scanner.nextInt();
        times = scanner.nextLong();
        s = scanner.next();
        ////System.out.println("scanned: " + s);
        product = eatString('l', s);
        //System.out.println("product: " + product);
        idx = 0;

        if(!isValid()) {
            ////System.out.println("not valid. product:" + product);
            answer = "NO";
            return;
        }

        String newS = "";
        for(int i = 0; i < Math.min(12, times); i++) newS += s;
        s = newS;
        sLength = s.length();

        times = times > 12 ? times - 12 : 0;

        //System.out.println("new s: " + s);
        //System.out.println("new times: " + times);
        //System.out.println("new sLength: " + sLength);

        if(find('i') &&
                find('j') &&
                find('k') &&
                isRemainderOne()) {
            answer = "YES";
        }
        else answer = "NO";
    }

    static int sLength;
    static long times;
    static int idx = 0;
    static String s;
    static char product;

    // l = 1
    // m = -i
    // n = -j
    // o = -k
    // p = -1

    static boolean find(char goal) {
        char curChar = 'l';
        while(idx < sLength && curChar != goal) {
            char next = s.charAt(idx);
            //System.out.print("eating idx " + idx + ": " + curChar + " + " + next + " = ");
            curChar = eat(curChar, next);
            //System.out.println(curChar);
            idx++;
        }
        return curChar == goal;
    }

    static boolean isValid() {
        //System.out.println("isValid called");
        char result = 'l';
        for(int i = 0; i < times % 4; i++) {
            //System.out.print("eating idx " + idx + ": " + result+ " + " + product + " = ");
            result = eat(result, product);
            //System.out.println(result);
        }
        return result == 'p';
    }

    static boolean isRemainderOne() {
        //System.out.println("isRemainderOne called. idx: " + idx + "; times: " + times);
        char curRemainder = eatString('l', s, idx);
        //System.out.println("rest of string: " + curRemainder);
        times = times % 4;
        for (int i = 0; i < times; i++) curRemainder = eat(curRemainder, product);

        boolean result = curRemainder == 'l';
        //System.out.println("returning " + result);
        return result;
    }

    static char eatString(char val, String s) {
        return eatString(val, s, 0, s.length());
    }

    static char eatString(char val, String s, int start) {
        return eatString(val, s, start, s.length());
    }

    static char eatString(char val, String s, int start, int end) {
        for(int i = start; i < end; i++) {
            val = eat(val, s.charAt(i));
        }
        return val;
    }

    static boolean isNegative(char val) {
        return val > 'l';
    }

    static char flipNegative(char val) {
        if(isNegative(val)) val -= 4;
        else val += 4;
        return val;
    }

    static char flipNegative(char val, boolean doIt) {
        if(doIt) return flipNegative(val);
        return val;
    }

    static char abs(char val) {
        if(isNegative(val)) val = flipNegative(val);
        return val;
    }

    static char eat(char val, char next) {
        boolean negative = isNegative(val);
        val = abs(val);
        negative = isNegative(next) ? !negative : negative;
        next = abs(next);

        char result = next;

        switch(val) {
            case 'i' :
                switch(next) {
                    case 'i' :
                        negative = !negative;
                        result = 'l';
                        break;
                    case 'j' :
                        result = 'k';
                        break;
                    case 'k' :
                        negative = !negative;
                        result = 'j';
                        break;
                }
                break;
            case 'j' :
                switch(next) {
                    case 'j' :
                        negative = !negative;
                        result = 'l';
                        break;
                    case 'k' :
                        result = 'i';
                        break;
                    case 'i' :
                        negative = !negative;
                        result = 'k';
                        break;
                }
                break;
            case 'k' :
                switch(next) {
                    case 'k' :
                        negative = !negative;
                        result = 'l';
                        break;
                    case 'i' :
                        result = 'j';
                        break;
                    case 'j' :
                        negative = !negative;
                        result = 'i';
                        break;
                }
                break;
        }

        return flipNegative(result, negative);
    }
}

