package by.home.sss.google.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Sergey on 4/9/2016.
 */
public class RevengeOfThePancakes {
    private static final String CHARSET_NAME = "UTF-8";

    private List<String> testCases;
    private List<Integer> results;

    private void init() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("B-large.in"), CHARSET_NAME);
        try {
            if (scanner.hasNext()) {
                int numberOfTest = scanner.nextInt();
                testCases = new ArrayList<String>(numberOfTest);
                results = new ArrayList<Integer>(numberOfTest);
                for (int i = 0;i < numberOfTest; i++){
                    if (scanner.hasNext()) {
                        testCases.add(scanner.next());
                    }
                }
            }
        }
        finally {
            scanner.close();
        }
    }

    private void solve() {
        for (String testCast: testCases){
            int result = 0;
            char inChar = '+';
            for (int i = testCast.length()-1; i >=0 ;i-- ) {
                char c = testCast.charAt(i);
                if (c != inChar){
                    result++;
                    inChar = c;
                }
            }
            results.add(result);
        }
    }

    private void saveResults () throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter("output.txt",CHARSET_NAME);
        try {
            for (int i = 0; i < results.size(); i++) {
                writer.println(String.format("Case #%d: %d", i+1,results.get(i)));
            }
        }
        finally {
            writer.close();
        }

    }

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        RevengeOfThePancakes problem = new RevengeOfThePancakes();
        problem.init();
        problem.solve();
        problem.saveResults();
    }
}
