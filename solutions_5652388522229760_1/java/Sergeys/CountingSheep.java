package by.home.sss.google.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by Sergey on 4/9/2016.
 */
public class CountingSheep {
    private static final String CHARSET_NAME = "UTF-8";
    private static final int MAX_ATTEMPT = 100;
    private List<Integer> testCases;
    private List<String> results;

    private void init() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("A-large.in"), CHARSET_NAME);
        try {
            if (scanner.hasNext()) {
                int numberOfTest = scanner.nextInt();
                testCases = new ArrayList<Integer>(numberOfTest);
                results = new ArrayList<String>(numberOfTest);
                for (int i = 0;i < numberOfTest; i++){
                    if (scanner.hasNext()) {
                        testCases.add(scanner.nextInt());
                    }
                }
            }
        }
        finally {
            scanner.close();
        }
    }

    private void solve() {
        for (Integer testCast: testCases){
            if (testCast <= 0){
                results.add("INSOMNIA");
            } else {
                boolean numbers[] = new boolean[10];
                boolean ready=true;
                for (int i = 1; i < MAX_ATTEMPT;i++ ){
                    int current = testCast * i;
                    while (current>0){
                        numbers[current%10] = true;
                        current/=10;
                    }
                    ready = true;
                    for (int j = 0; j< 10; j++){
                        if (!numbers[j]) {
                            ready =false;
                            break;
                        }
                    }
                    if (ready){
                        results.add(String.valueOf(testCast * i));
                        break;
                    }
                }
                if (!ready) {
                    results.add(String.valueOf("INSOMNIA"));
                }
            }
        }
    }

    private void saveResults () throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter("output.txt",CHARSET_NAME);
        try {
            for (int i = 0; i < results.size(); i++) {
                writer.println(String.format("Case #%d: %s", i+1,results.get(i)));
            }
        }
        finally {
            writer.close();
        }

    }

    private void genInput() throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter("input.txt",CHARSET_NAME);
        try {
            writer.println(1000000);
            for (int i = 0; i < 1000000; i++) {
                writer.println(new Random().nextInt(100)+1);
            }
        }
        finally {
            writer.close();
        }
    }

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        CountingSheep problem = new CountingSheep();
//        problem.genInput();
        long start = System.currentTimeMillis();
        problem.init();
        problem.solve();
        problem.saveResults();
        System.out.println(System.currentTimeMillis()-start);

    }


}
