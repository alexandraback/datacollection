package by.home.sss;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.*;

/**
 * Created by Sergey on 5/8/2016.
 */
public class Task3 {

    private static final String CHARSET_NAME = "US-ASCII";
    private List<TC> tcs;

    private static class TC {
        final int j;
        final int p;
        final int s;
        final int k;

        public TC(int j, int p, int s, int k) {
            this.j = j;
            this.p = p;
            this.s = s;
            this.k = k;
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
                        int j = scanner.nextInt();
                        int p = scanner.nextInt();
                        int s = scanner.nextInt();
                        int k = scanner.nextInt();
                        tcs.add(new TC(j,p,s,k));
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
                HashMap <String, Integer> abMap = new HashMap<String, Integer>();
                HashMap <String, Integer> acMap = new HashMap<String, Integer>();
                HashMap <String, Integer> bcMap = new HashMap<String, Integer>();
                List<String > result = new LinkedList<String>();
                for (int i1 = 0; i1< tc.j;i1++){
                    for (int i2 = 0; i2< tc.p;i2++){
                        for (int i3 = 0; i3< tc.s;i3++){
                            String ab = "" + i1+i2;
                            String ac = "" + i1+i3;
                            String bc = "" + i2+i3;
                            if ((abMap.get(ab) == null || abMap.get(ab) < tc.k) &&
                                    (acMap.get(ac) == null || acMap.get(ac) < tc.k) &&
                                    (bcMap.get(bc) == null || bcMap.get(bc) < tc.k)) {
                                if (abMap.get(ab) == null){
                                    abMap.put(ab,1);
                                } else {
                                    abMap.put(ab,abMap.get(ab)+1);
                                }
                                if (acMap.get(ac) == null){
                                    acMap.put(ac,1);
                                } else {
                                    acMap.put(ac,acMap.get(ac)+1);
                                }
                                if (bcMap.get(bc) == null){
                                    bcMap.put(bc,1);
                                } else {
                                    bcMap.put(bc,bcMap.get(bc)+1);
                                }
                                result.add("" + (i1+1) +" "+(i2+1) +" "+(i3+1));
                            }

                        }
                    }
                }
                writer.println(result.size());
                for (String s: result) {
                    writer.println(s);
                }
            }
        }
        finally {
            writer.close();
        }

    }

    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Task3 problem = new Task3();
//        problem.genInput();
        long start = System.currentTimeMillis();
        problem.init();
//        problem.solve();
        problem.saveResults();
//        System.out.println(System.currentTimeMillis()-start);

    }
}
