package com.google.code.jam.third;

import java.io.*;
import java.util.LinkedList;
import java.util.List;

public class FileSupport {
    private static String outFileDir = "C://output/";
    private static final String fileDir = "C://course/";

    private final static String in = ".in";
    private final static String out = ".out";
    private static LinesSupport linesSupport;

    public static void readFileLines(String fileName) throws IOException {
        FileInputStream fileStream = new FileInputStream(fileDir + fileName + in);
        DataInputStream in = new DataInputStream(fileStream);
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        List<String> lines = new LinkedList<String>();

        String line;
        while ((line = br.readLine()) != null) {
            lines.add(line);
        }
        //Close the input stream
        in.close();
        linesSupport = new LinesSupport(lines);
    }

    public static PrintWriter getOutputFile(String fileName) throws IOException {
        File outFile = new File(outFileDir + fileName + out);
        outFile.createNewFile();
        return new PrintWriter(outFile);
    }


    public static void printResult(ProblemSolver solver, String fileName) throws IOException {
        PrintWriter output = FileSupport.getOutputFile(fileName);
        int patternNumber = Integer.valueOf(linesSupport.getLine());
        int i = 1;
        while (patternNumber-- > 0) {
            String result = solver.getResult(linesSupport.getInput());
            printResult(i++, output, result);
        }
        output.close();
    }



    private static void printResult(int caseNumber, PrintWriter output, String result) {
        output.println("Case #" + caseNumber + ": " + result);
    }

}
