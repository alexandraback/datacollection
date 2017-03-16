import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;

public class RecycledNumbers
{
    public static final byte ZERO = 0;
    public static final byte BASE_TEN = 10;

    static BufferedReader IN = new BufferedReader(new InputStreamReader(System.in));
    static HashSet<Integer> numbers = new HashSet<Integer>();
    static BitSet numberBitmap = new BitSet(10000000);

    /**
     * @param args
     * @throws IOException
     * @throws NumberFormatException
     */
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        int testCaseCount;
        try
        {
            String input = IN.readLine();
            testCaseCount = Integer.parseInt(input);
        }
        catch (Exception e)
        {
            testCaseCount = 0;
        }

        if (testCaseCount > 0)
        {
            long start = System.currentTimeMillis();
            
            int[][] minMax = new int[testCaseCount][3]; 
            for (int i = 0; i < testCaseCount; i++)
            {
                String[] values = IN.readLine().split(" ");
                minMax[i][0] = Integer.parseInt(values[0]);
                minMax[i][1] = Integer.parseInt(values[1]);
            }
            for (int i = 0; i < testCaseCount; i++)
            {
                minMax[i][2] = findRecycledPairsCount(minMax[i][0], minMax[i][1]);
                printLn("Case #%d: %d", i + 1, minMax[i][2]);
            }

            long end = System.currentTimeMillis();
            //System.err.println((end - start));
        }
    }
    
    static int findRecycledPairsCount(int min, int max) throws NumberFormatException, IOException
    {
        HashMap<Integer, Byte> duplicateMap = new HashMap<Integer, Byte>();

        int digitCount = getNumberOfDigits(min);

        numberBitmap.clear();
        for (int number = min; number <= max; number++)
        {
            if (!numberBitmap.get(number))
            {
                RotatedNumbers rNumber = getRotatedNumbersInRange(number, digitCount, min, max);
                if (rNumber.count > 1)
                {
                    duplicateMap.put(rNumber.minimum, rNumber.count);
                }
            }
        }

        int count = 0;
        for (Byte b : duplicateMap.values())
        {
            if (b > 1)
            {
                count += b == 2 ? 1 : getNC2(b);
            }
        }

        return count;
    }

    static int getNC2(int n)
    {
        return (int) ((n / 2.0) * (n - 1));
    }

    static int getNumberOfDigits(int number)
    {
        int digitCount = 0;
        while (number > 0)
        {
            digitCount++;
            number /= 10;
        }
        return digitCount;
    }

    public static RotatedNumbers getRotatedNumbersInRange(int number, int digitCount, int min, int max)
    {
        int index = digitCount - 1;
        int[] digits = new int[digitCount];
        int temp = number;

        while (temp > 0)
        {
            digits[index--] = temp % 10;
            temp /= 10;
        }

        int minVal = number;
        numbers.clear();
        for (int start = 0; start < digitCount; start++)
        {
            int numVal = 0;
            for (int j = 0; j < digitCount; j++)
            {
                int digit = digits[(start + j) % digitCount];
                numVal *= 10;
                numVal += digit;
            }
            numberBitmap.set(numVal);
            if (numVal >= min && numVal <= max)
            {
                numbers.add(numVal);
            }
            if (numVal < minVal)
            {
                minVal = numVal;
            }
        }

        return new RotatedNumbers(minVal, (byte) numbers.size());        
    }
    
    //  to ensure that '\n' is used as EOL on my Windows Machine, just to be sure ;)
    //
    static void printLn(String val)
    {
        System.out.print(val);
        System.out.print('\n');
    }
    static void printLn(String format, Object ... args)
    {
        System.out.print(String.format(format, args));
        System.out.print('\n');
    }
    

    static class RotatedNumbers
    {
        public RotatedNumbers(int minimum, byte count)
        {
            this.minimum = minimum;
            this.count = count;
        }

        int minimum;
        byte count;
    }
}
