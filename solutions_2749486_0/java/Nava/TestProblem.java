package com.google.code.jam.third;

import java.io.IOException;

/**
 * @author: nava
 * @date: 04.05.13
 */
public class TestProblem {

    private static String fileName = "B-small-attempt0";

    public static void main(String[] args) throws IOException {
        FileSupport.readFileLines(fileName);
        FileSupport.printResult(new ProblemBSolver(), fileName);
    }
}
