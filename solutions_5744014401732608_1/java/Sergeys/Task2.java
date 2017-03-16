package by.home.sss;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by Sergey on 5/8/2016.
 */
public class Task2 {

    private static final String CHARSET_NAME = "US-ASCII";
    private List<TC> tcs;

    private static class TC {
        final int b;
        final long m;

        public TC(int b, long m) {
            this.b = b;
            this.m = m;
        }
    }


    private void init() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("input.txt"), CHARSET_NAME);
        try {
            if (scanner.hasNext()) {
                int numberOfTest = scanner.nextInt();
                tcs = new ArrayList<TC>(numberOfTest);
                for (int i = 0;i < numberOfTest; i++){
                    if (scanner.hasNext()) {
                        int b = scanner.nextInt();
                        long m = scanner.nextLong();
                        tcs.add(new TC(b,m));
                    }
                }
            }
        }
        finally {
            scanner.close();
        }
    }

    private void saveResults () throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter("output.txt",CHARSET_NAME);
        try {
            for (int i = 0; i < tcs.size(); i++) {
                writer.print(String.format("Case #%d: ", i+1));
                TC tc = tcs.get(i);
                long comp;
                if (tc.b-3 >= 0){
                    comp =2L << (tc.b-3);
                } else {
                    comp = 1;
                }
                if ( comp>= tc.m && tc.b != 2 ) {
                    writer.println("POSSIBLE");
                    String s = Long.toBinaryString(( tc.m-1 ));
                    writer.println(new String(new char[tc.b - s.length()-1]).replace("\0", "0") + s + "1" );
                    for (int  j = 1; j< tc.b; j++){
                        writer.println(new String(new char[j+1]).replace("\0", "0") + new String(new char[tc.b-j-1]).replace("\0", "1"));
                    }
                } else if (tc.b == 2 && tc.m == 1) {
                    writer.println("POSSIBLE");
                    writer.println("01");
                    writer.println("00");
                }
                else {
                    writer.println("IMPOSSIBLE");
                }

            }
        }
        finally {
            writer.close();
        }

    }

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Task2 problem = new Task2();
//        problem.genInput();
        long start = System.currentTimeMillis();
        problem.init();
//        problem.solve();
        problem.saveResults();
//        System.out.println(System.currentTimeMillis()-start);

    }
}
