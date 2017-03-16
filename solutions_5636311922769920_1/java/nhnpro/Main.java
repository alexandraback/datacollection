package gcj16.nhnpro.problem1;

import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
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
                fileWriter.write(SolveD(i + 1, in));
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
    



    public static int[] primeNumbers = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    public static String SolveC(int caseNumber, Scanner in) {
        String result = "Case #" + caseNumber + ":\n";
        if (in.hasNext()) {
            println("Case #" + caseNumber + ": ");
            int N = in.nextInt(), J = in.nextInt();
            println("N :" + N + " J:" + J);

            HashMap<String, Boolean> map = new HashMap<>();
            while (J > 0) {

                BigInteger bi;
                boolean found = false;
                while (!found) {
                    String s = "";
                    for (int i = 1; i < N - 1; i++) {
                        s += (Math.random()*10 > 5) ? "1" : "0";
                    }

                    s = "1" + s + "1";
                    if(!map.containsKey(s)) {
                        int j = 2;
                        BigInteger[] rs = new BigInteger[9];
                        BigInteger[] findDivisor = new BigInteger[9];
                        for (j = 2; j <= 10; j++) {
                            //bi = Long.parseLong(s, j);
                            bi = new BigInteger(s, j);
                            rs[j-2] = bi;
                            boolean isPrime = true;
                            for (int k = 0; k < primeNumbers.length; k++) {
                                BigInteger bprime = new BigInteger("" + primeNumbers[k]);
                                //if (primeNumbers[k] < bi)
                                {
                                    BigInteger m = bi.mod(bprime);
                                    if (m.compareTo(BigInteger.ZERO) == 0) {
                                        isPrime = false;
                                        findDivisor[j - 2] = bprime;
                                        break;
                                    }
                                }
                                //else
                                 //   break;
                            }
                            if (isPrime) break;

                        }

                        if (j > 10) {
                            result += s;
                            for (j = 0; j < 9; j++) {
                                result += " " + findDivisor[j];
                            }
                            result += "\n";
                            found = true;
                            map.put(s, true);
                        }
                        else
                            map.put(s, false);
                    }
                }

                J--;
            }

        }

        return result +"";
    }

    public static String[] getAllLists(String[] elements, int lengthOfList)
    {
        //initialize our returned list with the number of elements calculated above
        String[] allLists = new String[(int)Math.pow(elements.length, lengthOfList)];

        //lists of length 1 are just the original elements
        if(lengthOfList == 1) return elements;
        else {
            //the recursion--get all lists of length 3, length 2, all the way up to 1
            String[] allSublists = getAllLists(elements, lengthOfList - 1);

            //append the sublists to each element
            int arrayIndex = 0;

            for(int i = 0; i < elements.length; i++){
                for(int j = 0; j < allSublists.length; j++){
                    //add the newly appended combination to the list
                    allLists[arrayIndex] = elements[i] + allSublists[j];
                    arrayIndex++;
                }
            }
            return allLists;
        }
    }

    public  static  String chainGL(String s, int c, int k)
    {
        String chained = s;
        for (int i = 2; i <= c; i++) {
            String newStr = "";
            for (int j = 0; j < chained.length(); j++) {
                if(chained.charAt(j) == 'G')
                {
                    for (int l = 0; l < k; l++) {
                        newStr += 'G';
                    }
                }
                else
                    newStr += s;
            }
            chained = newStr;
        }
        return chained;
    }

    public static String SolveD(int caseNumber, Scanner in) {
        String result = "Case #" + caseNumber + ": ";
        if (in.hasNext()) {
            int K = in.nextInt(), C = in.nextInt(), S = in.nextInt();
            println(" K :" +  K + " C:" +  C + " S:" + S);

            if(K == 1)
                result += K;
            else {
                if(C == 1)
                {
                    for (int i = 1; i < K ; i++)
                        result += i + " ";
                    result += K;
                }
                else
                {
                    //K > 1 && C > 1 && S < K
                    ArrayList<Long> ans = new ArrayList<>();
                    long pos = Math.min(K, 2);
                    for (int i = 0; i < K; i += 2)
                    {
                        ans.add(pos);
                        pos += Math.min(2, K - i - 2);
                        pos += K * 2;
                    }

                    if (ans.size() > S)
                        result += "IMPOSSIBLE";
                    else
                    {
                        for (int i = 0; i < ans.size() - 1; i++)
                            result += ans.get(i) + " ";
                        result += ans.get(ans.size() - 1);
                    }
                }
            }
        }

        println(result);

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
