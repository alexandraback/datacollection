package gcj16.nhnpro.round1;

//http://algorithms.tutorialhorizon.com/dynamic-programming-longest-increasing-subsequence/
import com.sun.xml.internal.ws.policy.spi.PolicyAssertionValidator;

import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        try {
            FileReader fRead= new FileReader("problem.in");
            FileWriter fWrite = new FileWriter("problem.out");

            Scanner in = new Scanner(fRead);
            int T = in.nextInt();
            in.nextLine();
            String resultOutput = "PLEASE CHOOSE A SOLVE FUNCTION\n";
            for (int i = 1; i <= T; i++) {
                //resultOutput = SolveProblemA(i, in);
                //resultOutput = SolveProblemB(i, in);
                resultOutput = SolveProblemC(i, in);
                fWrite.write(resultOutput);
            }

            fRead.close();
            fWrite.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    //3
    private static String SolveProblemA(int caseNumber, Scanner in)
    {
        println("[Problem A] Begin Solve Case #" + caseNumber);
        String result = "Case #" + caseNumber + ": ";
        if(in.hasNext())
        {
            //Read Input Here
            println("1.Read Input:");
            String S = in.nextLine();
            char[] chars = S.toCharArray();

            String res = "" + chars[0];

            for (int i = 1; i < chars.length; i++) {
                if(chars[i] >= res.charAt(0))
                    res = chars[i] + res;
                else
                    res += chars[i];
            }


            //Solve
            println("2.Solve....");

            //Return Answer
            println(result);
            result += res;
        }

        return result + "\n";
    }

    //3
    private static String SolveProblemB(int caseNumber, Scanner in)
    {
        println("[Problem B] Begin Solve Case #" + caseNumber);
        String result = "Case #" + caseNumber + ": ";
        if(in.hasNext())
        {
            //Read Input Here
            println("1.Read Input:");
            int N = in.nextInt();
            ArrayList<ArrayList<Integer>> table = new ArrayList<>();
            for (int i = 2 * N - 1; i > 0; i--)
            {
                ArrayList<Integer> row = new ArrayList<>();
                for (int j = N; j > 0; j--)
                    row.add(in.nextInt());
                table.add(row);
            }



            //Solve
            println("2.Solve:");
            final int MAX_HEIGHT = 4000 * 2;
            int[] counts = new int[MAX_HEIGHT];
            for (ArrayList<Integer> row : table)
                for (int height : row)
                    counts[height]++;
            for (int i = 0; i < MAX_HEIGHT; i++)
                if ((counts[i] & 1) != 0)
                    result += i + " ";


            //Return Answer
            println(result);
        }

        return result + "\n";
    }



    private static String SolveProblemC(int caseNumber, Scanner in)
    {
        println("[Problem C] Begin Solve Case #" + caseNumber);
        String result = "Case #" + caseNumber + ": ";
        if(in.hasNext())
        {
            //Read Input Here
            println("1.Read Input:");
            int N = in.nextInt();
            int[] BFF = new int[N];
            for (int i = 0; i < N; i++) {
                BFF[i] = in.nextInt() -1 ;
            }

            //Solve
            println("2.Solve:");

            Comparator<ArrayList<Integer>> comparator = new Comparator<ArrayList<Integer>>() {
                @Override
                public int compare(ArrayList a, ArrayList b) {
                    if (a.size() > b.size())
                            return  1;
                    if(a.size() == b.size())
                            return 0;
                    return  -1;
                }
            };


            int ans = 0;
            ArrayList<TreeSet<ArrayList<Integer>>> vs = new ArrayList<>();
            for (int i = 0; i < N; ++i) {
                vs.add(new TreeSet<>(comparator));
            }
            for (int i = 0; i < N; ++i) {
                int cur = i;
                int prev = -1;
                Boolean[] used = new Boolean[N];
                for (int j = 0; j < N; j++) {
                    used[j] = false;
                }
                used[cur] = true;
                int length = 1;
                ArrayList<Integer> c = new ArrayList<>();
                c.add(cur);
                while (!used[BFF[cur]])
                {
                    ++length;
                    prev = cur;
                    cur = BFF[cur];
                    c.add(cur);
                    used[cur] = true;
                }
                if (prev == BFF[cur])
                {
                    if( vs.get(prev) == null)
                        vs.get(prev).add(new ArrayList<>());
                    vs.get(prev).add(c);
                } else
                {
                    length = 1;
                    for (int cc =BFF[cur]; cc != cur; cc = BFF[cc])
                    {
                        ++length;
                    }
                }
                ans = Math.max(ans, length);
            }
            int length = 0;
            Boolean[] used = new Boolean[N];
            for (int j = 0; j < N; j++) {
                used[j] = false;
            }

            for (int i = 0; i < N; ++i)
            {
                if (!used[i] && !vs.get(i).isEmpty())
                {
                    length += vs.get(i).last().size();
                    if (!vs.get(BFF[i]).isEmpty())
                    {
                        used[BFF[i]] = true;
                        length += vs.get(BFF[i]).last().size() - 2;
                    }
                }
            }
            ans = Math.max(ans, length);


            result += ans;
            //Return Answer
            println(result);
        }

        return result + "\n";
    }

    //Algothrims Functions
    // will contain true or false values for the first 10,000 integers
    private static boolean[] IsPrimes = new boolean[10000];
    private static boolean isErathosPrimInited = false;
    private static void fillSieve() {
        Arrays.fill(IsPrimes,true);        // assume all integers are prime.
        IsPrimes[0] = IsPrimes[1]=false;       // we know 0 and 1 are not prime.
        for (int i = 2; i< IsPrimes.length; i++) {
            if(IsPrimes[i]) {
                for (int j = 2; i*j< IsPrimes.length; j++) {
                    IsPrimes[i*j]=false;
                }
            }
        }
        isErathosPrimInited = true;
    }

    private static boolean isPrime(int n) {
        if(!isErathosPrimInited)
            fillSieve();
        return IsPrimes[n]; //simple, huh?
    }

    private static boolean isPrime(long n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n%2 == 0 || n%3 == 0) return false;
        long sqrtN = (long)Math.sqrt(n)+1;
        for(long i = 6L; i <= sqrtN; i += 6) {
            if(n%(i-1) == 0 || n%(i+1) == 0) return false;
        }
        return true;
    }


    private static int GreatestCommonDivisor(int a, int b) {
        if (b != 0) {
            return GreatestCommonDivisor(b, a % b);
        }
        return Math.abs(a);
    }

    private static int LeastCommonDivisor(int a, int b) {
        return (a*b)/(GreatestCommonDivisor(a,b));
    }

    /**
     * Calculates n to the p power, where
     * p is a positive number.
     */
    private static int QuickPower(int n, int p) {
        if (p == 0) return 1;
        if (p == 1) return n;
        if (p%2 == 1)
            return n * QuickPower( n * n, (p - 1) / 2 );

        return QuickPower( n * n, p / 2 );
    }

    //Util Functions
    private static String Array2String(int[] arr, String len0Output)
    {
        if(arr.length == 0)
        {
            if(len0Output != null)
                return len0Output;
            else
                return "";
        }
        String result = "" + arr[0];
        for (int i = 1; i < arr.length; i++) {
            result += " " + arr[i];
        }
        return  result;
    }

    private static String Array2String(char[] arr, String len0Output)
    {
        if(arr.length == 0)
        {
            if(len0Output != null)
                return len0Output;
            else
                return "";
        }
        String result = "" + arr[0];
        for (int i = 1; i < arr.length; i++) {
            result += " " + arr[i];
        }
        return  result;
    }

    private static String Array2String(long[] arr, String len0Output)
    {
        if(arr.length == 0)
        {
            if(len0Output != null)
                return len0Output;
            else
                return "";
        }
        String result = "" + arr[0];
        for (int i = 1; i < arr.length; i++) {
            result += " " + arr[i];
        }
        return  result;
    }

    private static String Array2String(String[] arr, String len0Output)
    {
        if(arr.length == 0)
        {
            if(len0Output != null)
                return len0Output;
            else
                return "";
        }
        String result = arr[0];
        for (int i = 1; i < arr.length; i++) {
            result += " " + arr[i];
        }
        return  result;
    }

    private static void println(String s)
    {
        System.out.println(s);
    }

    private static void print(String s)
    {
        System.out.print(s);
    }
}