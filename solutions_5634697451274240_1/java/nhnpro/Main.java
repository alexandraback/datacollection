package gcj16.nhnpro.problem1;

import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;


public class Main {

    public static void main(String[] args) {
        String inputFilePath = "problem1.in";
        String outputFilePath = "problem1.out";
        if (args.length >= 1) inputFilePath = args[0];
        if (args.length >= 2) outputFilePath = args[1];

        try {
            FileReader fileReader = new FileReader(inputFilePath);
            FileWriter fileWriter = new FileWriter(outputFilePath);

            Scanner in = new Scanner(fileReader);
            int numCases = in.nextInt();
            in.nextLine();
            for (int i = 0; i < numCases; i++) {
                fileWriter.write(SolveB(i + 1, in));
            }

            fileReader.close();
            fileWriter.close();
        } catch (Exception ex) {
            println("Exception: " + ex.toString());
        }
    }

    public static String SolveA(int caseNumber, Scanner in) {
        String result = "Case #" + caseNumber + ": ";
        if (in.hasNext()) {
            println("Case #" + caseNumber + ": ");
            int N = in.nextInt();
            println("" + N);

            if(N == 0)
            {
                result += "INSOMNIA";
            }
            else {
                int[] arr = new int[10];
                int count = 0, i = 1;
                while (count < 10)
                {
                    long K = N*i;
                    if(K < 10)
                    {
                        if(arr[(int)K] == 0)
                        {
                            arr[(int)K] = 1;
                            count++;
                        }

                    }
                    while (K > 0)
                    {
                        long X = K%10;
                        K = (long)Math.floor(K/10);
                        if(arr[(int)X] == 0)
                        {
                            arr[(int)X] = 1;
                            count++;
                            if(count >= 10)
                             break;
                        }

                    }
                    if(count < 10)
                        i++;
                }
                result += N*i;
            }
        }
        return result +"\n";
    }


    public static String SolveB(int caseNumber, Scanner in) {
        String result = "Case #" + caseNumber + ": ";
        if (in.hasNext()) {
            println("Case #" + caseNumber + ": ");
            String s = in.nextLine();
            println(s);


            int endIndex = s.length() - 1;
            while ( endIndex >= 0 && s.charAt(endIndex) == '+')endIndex--;

            int num = 0;
            if(endIndex >= 0)
            {
                num = 1;
                int currChar = s.charAt(0);
                for (int i = 1; i <= endIndex; i++) {
                    if(s.charAt(i) != currChar)
                    {
                        num++; currChar = s.charAt(i);
                    }
                }
            }
            result += num;

        }
        return result +"\n";
    }

    public static String SolveC(int caseNumber, Scanner in) {
        String result = "Case #" + caseNumber + ":\n";
        if (in.hasNext()) {
            println("Case #" + caseNumber + ": ");
            int N = in.nextInt(), J = in.nextInt();
            println("N :" + N + " J:" + J);
            int[] arr = new int[N];
            arr[0] = 1; arr[N -1] = 1;
            for (int i = 1; i < N - 1; i++) {

                
            }

        }

        return result +"\n";
    }

    public static void print(String s) {
        System.out.print(s);
    }

    public static void println(String s) {
        System.out.println(s);
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            print(arr[i] + " ");
        }
        println("");
    }

    public static void printArray(String[] arr) {
        for (int i = 0; i < arr.length; i++) {
            print("" + arr[i] + " ");
        }
        println("");
    }
}
