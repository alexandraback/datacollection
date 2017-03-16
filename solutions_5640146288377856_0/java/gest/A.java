package round1C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class A {

    public static void run() throws Exception {
        init("A-small-attempt2");

        int T = INT();

        for (int t = 0; t < T; t++) {
            int R = INT();
            int C = INT();
            int W = INT();
            int answer = 0;

            for (int i = 0; i < R; i++) {
                answer += C / W;
            }
            if (C % W != 0) {
                answer += 1;
            }
            answer += (W - 1);

            printResult(t + 1, answer);
        }

    }

    private static void printResult(int caseNumber, int i) throws IOException {
        println("Case #" + caseNumber + ": " + i);
    }

    // *************************************************************************************
    // *********************************** FRAMEWORK
    // ***************************************
    // *************************************************************************************

    public static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    public static boolean isStandardInput = false;

    public static File input;
    public static FileReader inputReader;
    public static BufferedReader in;

    public static File output;
    public static FileWriter outputWriter;
    public static BufferedWriter out;

    public static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        doSTDIN(true);
        setOutput("test.out");
        run();
        close();
    }

    public static void init(String problemName) throws Exception {
        doSTDIN(false);
        setInput(problemName + ".in");
        setOutput(problemName + ".out");
    }

    // **************** PRINT METHODS ****************

    public static void println() throws IOException {
        out.write("\n");
        System.out.println();
    }

    public static void println(Object obj) throws IOException {
        out.write(obj.toString());
        out.write("\n");
        System.out.println(obj.toString());
    }

    public static void print(Object obj) throws IOException {
        out.write(obj.toString());
        System.out.print(obj.toString());
    }

    public static void println(long number) throws IOException {
        out.write(Long.toString(number));
        out.write("\n");
        System.out.println(number);
    }

    public static void print(long number) throws IOException {
        out.write(Long.toString(number));
        System.out.print(number);
    }

    public static void println(char c) throws IOException {
        out.write(Character.toString(c));
        out.write("\n");
        System.out.println(c);
    }

    public static void print(char c) throws IOException {
        out.write(Character.toString(c));
        System.out.print(c);
    }

    public static void println(String line) throws IOException {
        out.write(line);
        out.write("\n");
        System.out.println(line);
    }

    public static void print(String line) throws IOException {
        out.write(line);
        System.out.print(line);
    }

    // **************** INPUT DECLARATION ****************

    public static void doSTDIN(boolean standard) {
        isStandardInput = standard;
    }

    public static void setInput(String filename) throws IOException {
        input = new File(filename);
        inputReader = new FileReader(input);
        in = new BufferedReader(inputReader);
    }

    public static void setOutput(String filename) throws IOException {
        output = new File(filename);
        outputWriter = new FileWriter(output);
        out = new BufferedWriter(outputWriter);
    }

    public static void close() throws IOException {
        if (in != null)
            in.close();
        if (inputReader != null)
            inputReader.close();

        if (out != null)
            out.flush();
        if (out != null)
            out.close();
        if (outputWriter != null)
            outputWriter.close();
    }

    // **************** INPUT READING ****************

    static String LINE() throws IOException {
        return isStandardInput ? stdin.readLine() : in.readLine();
    }

    static String TOKEN() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(LINE());
        return st.nextToken();
    }

    static int INT() throws IOException {
        return Integer.parseInt(TOKEN());
    }

    static long LONG() throws IOException {
        return Long.parseLong(TOKEN());
    }

    static double DOUBLE() throws IOException {
        return Double.parseDouble(TOKEN());
    }

    static BigInteger BIGINT() throws IOException {
        return new BigInteger(TOKEN());
    }
}
