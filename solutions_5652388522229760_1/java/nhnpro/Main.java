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
                fileWriter.write(SolveA(i + 1, in));
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


    public static String Solve(int caseNumber, Scanner in) {
        String result = "Case #" + caseNumber + ": ";
        if (in.hasNext()) {
            println("Case #" + caseNumber + ": ");
            String s = in.nextLine();
            println(s);


            int endIndex = s.length() - 1;
            while ( endIndex >= 0 && s.charAt(endIndex) == '+')endIndex--;

            int num = 0;
            if(endIndex == 0 || endIndex == 1)
            {
                num = endIndex + 1;
            }
            else if(endIndex > 1)
            {
                ArrayList<Integer> arr = new ArrayList<>();
                for (int i = 0; i <= endIndex; i++) {

                }
            }
            result += num;

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
