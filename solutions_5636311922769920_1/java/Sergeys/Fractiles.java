package by.home.sss.google.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.*;

/**
 * Created by Sergey on 4/10/2016.
 */
public class Fractiles {

    private static final String CHARSET_NAME = "US-ASCII";
    private List<TestCase> testCases;
    private List<Result> results;

    private class Result {
        private List<BigInteger> tiles = new ArrayList<BigInteger>();
    }

    private class TestCase{
        private final int originalTiles;
        private final int complexity;
        private final int students;

        public TestCase(int originalTiles, int complexity, int students) {
            this.originalTiles = originalTiles;
            this.complexity = complexity;
            this.students = students;
        }
    }

    private void init() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("D-large.in"), CHARSET_NAME);
        try {
            if (scanner.hasNext()) {
                int numberOfTest = scanner.nextInt();
                testCases = new ArrayList<TestCase>(numberOfTest);
                results = new ArrayList<Result>(numberOfTest);
                for (int i = 0;i < numberOfTest; i++){
                    if (scanner.hasNext()) {
                        testCases.add(new TestCase(scanner.nextInt(), scanner.nextInt(), scanner.nextInt()));
                    }
                }
            }
        }
        finally {
            scanner.close();
        }
    }

    private void solve() {
        for (TestCase testCase: testCases){
            if (testCase.complexity*testCase.students <testCase.originalTiles) {
                results.add(new Result());
                //impossible
            } else {
                Map<Integer, BigInteger> map = new HashMap<Integer, BigInteger>();
                for (int i = 0;i < testCase.originalTiles;i++) {
                    int key = i / testCase.complexity;
                    BigInteger bigInteger = map.get(key);
                    if (bigInteger == null){
                        bigInteger = BigInteger.ONE;
                    }
                    bigInteger = bigInteger.add(BigInteger.valueOf(i).multiply(BigInteger.valueOf(testCase.originalTiles).pow(i%testCase.complexity)));
                    map.put(key, bigInteger);
                }

                Result result = new Result();
                result.tiles.addAll(map.values());
                results.add(result);
            }
        }
    }

    private void checkCorrect(int originalTiles, int complexity, List <BigInteger> tiles) {
        for (int i = 0;i<originalTiles; i++){
            boolean initialArray[] = new boolean[originalTiles];
            initialArray[i] = true;
            boolean currentArray[] = new boolean[originalTiles];
            System.arraycopy(initialArray, 0, currentArray, 0, initialArray.length);
            for (int j = 0 ; j< complexity-1;j++){
                boolean newArray[] = new boolean[currentArray.length*originalTiles];
                for (int k = 0; k < currentArray.length; k++){
                    if (currentArray[k]) {
                        for (int x =0; x<originalTiles; x++){
                            newArray[k*originalTiles+x] = true;
                        }
                    } else {
                        for (int x =0; x<originalTiles; x++){
                            newArray[k*originalTiles+x] = initialArray[x];
                        }
                    }
                }
                currentArray = new boolean[newArray.length];
                System.arraycopy(newArray, 0, currentArray, 0, newArray.length);
            }
            boolean correct = false;
            for (BigInteger tile: tiles) {
                if (currentArray[tile.intValue()-1]) {
                    correct = true;
                    break;

                }
            }
            if (!correct) {
                System.out.println("Wrong solution. originalTiles=" + originalTiles + ", complexity="+complexity+", tiles=" + Arrays.toString(tiles.toArray()));
            } else {
                System.out.println("Correct. originalTiles=" + originalTiles + ", complexity="+complexity+", tiles=" + Arrays.toString(tiles.toArray()));
            }

        }


    }

    private void saveResults () throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter("output.txt",CHARSET_NAME);
        try {
            for (int i = 0; i < results.size(); i++) {
                StringBuilder sb = new StringBuilder();
                sb.append("Case #");
                sb.append(i+1);
                sb.append(":");
                List<BigInteger> tiles = results.get(i).tiles;
                if (tiles.isEmpty()) {
                    sb.append(" IMPOSSIBLE");
                } else {
                    for (BigInteger tileNUmber: tiles) {
                        sb.append(" ");
                        sb.append(tileNUmber);
                    }
                }
                writer.println(sb.toString());
            }
        }
        finally {
            writer.close();
        }

    }


    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Fractiles problem = new Fractiles();
//        problem.genInput();
        long start = System.currentTimeMillis();
        problem.init();
        problem.solve();
        problem.saveResults();
        System.out.println(System.currentTimeMillis()-start);
//        problem.test();

    }

    private void test() {
        for (int i = 0 ; i < testCases.size(); i++){
            TestCase testCase = testCases.get(i);
            if (!results.get(i).tiles.isEmpty()) {
                checkCorrect(testCase.originalTiles, testCase.complexity, results.get(i).tiles);
            }
        }
    }
}
