package Round1A;

import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import com.google.common.collect.Maps;

class Numbers {
    
}
public class C {
    public static String filename = "C-small-1-attempt0";
    public static Scanner scanner;
    public static PrintWriter writer;
    
    public static void main(String[] args) throws Exception {
        scanner = new Scanner(new File(filename + ".in"));
        writer = new PrintWriter(filename + ".out");
        int iterations = scanner.nextInt();
        scanner.nextLine();
        int N = 3;
        int M = 5;
        for (int iter = 1; iter <= iterations; iter++) {
            println("Case #" + iter + ": ");
            solve(generate(N, M));
            flush();
        }
    }
    
    public static Map<Integer, Map<String, Double>> generate(int N, int M) {
        Map<Integer, Map<String, Double>> numProdProbs = new HashMap<Integer, Map<String, Double>>();
        String[] strings = getStrings(N, M);
        for (int a = 2; a <= M; a++) {
            for (int b = 2; b <= M; b++) {
                for (int c = 2; c <= M; c++) {
                    Map<Integer, Integer> prodCount = new HashMap<Integer, Integer>();
                    String string = "" + a + b + c;
                    int[] arr = {a,b,c};
                    for (int i = 0; i < Math.pow(2,N); i++) {
                        String binary = Integer.toBinaryString(i);
                        int prod = 1;
                        for (int ind = 0; ind < binary.length(); ind++) {
                            if (binary.charAt(ind)=='1') {
                                prod*=arr[(N-binary.length()) + ind];
                            }
                        }
                        if (!prodCount.containsKey(prod)) {
                            prodCount.put(prod,0);
                        }
                        prodCount.put(prod,prodCount.get(prod)+1);
                    }
                    for (int product: prodCount.keySet()) {
                        if (!numProdProbs.containsKey(product)) {
                            Map<String, Double> map = new HashMap<String, Double>();
                            
                            for (String s: strings) {
                                map.put(s, 0.0);
                            }
                            numProdProbs.put(product, map);
                        }
                        numProdProbs.get(product).put(string, prodCount.get(product)/8.0);                            
                    }
                }
            }
        }
        
        for (int product: numProdProbs.keySet()) {
//            System.out.println(product + " " + numProdProbs.get(product));
        }
        return numProdProbs;
    }
    
    public static String[] getStrings(int N, int M) {
//        System.out.println(N + " " + M);
        String[] array = new String[(int) Math.pow(M-1, N)];
        int index = 0;
        for (int a = 2; a <= M; a++) {
            for (int b = 2; b <= M; b++) {
                for (int c = 2; c <= M; c++) {
//                    System.out.println(""+ a + b + c);
                    array[index++] = ""+ a + b + c;
                }
            }
        }
        return array; 
    }
    
    public static void solve(Map<Integer, Map<String, Double>> numProdProbs) {
        int R = scanner.nextInt();
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int K = scanner.nextInt();
        
        for (int iter = 0; iter < R; iter++) {
            Map<String, Double> initProbs = Maps.newHashMap();

            int[] prods = new int[K];
            for (int i = 0; i < K; i++) {
                prods[i] = scanner.nextInt();
            }
            for (int product: prods) {
                Map<String, Double> prodProb = numProdProbs.get(product);
                for (String string: prodProb.keySet()) {
                    if (!initProbs.containsKey(string)) {
                        initProbs.put(string, 1.0);
                    }
                    initProbs.put(string, initProbs.get(string)*prodProb.get(string));
                }
            }
            String best = "";
            double bestProb = -1;
            for (String string: initProbs.keySet()) {
                if (initProbs.get(string) > bestProb) {
                    best = string;
                    bestProb = initProbs.get(string);
                }
            }
            println(best);
        }
    }
    
    public static void print(String string) {
        System.out.print(string);
        writer.print(string);
    }
    
    public static void println(String string) {
        System.out.println(string);
        writer.println(string);
    }
    
    public static void flush() {
        System.out.flush();
        writer.flush();
    }
}
