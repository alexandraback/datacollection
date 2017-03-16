import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



public class Main 
{
    private static int check(long bitmap , int base)
    {
        BigInteger ans = BigInteger.ZERO;
        BigInteger temp = new BigInteger(Integer.toString(base));
        long i;
        for (i = 31;i >= 0;i --)
        {
            if ((bitmap & (1L << i)) != 0)
                ans = ans.multiply(temp).add(BigInteger.ONE);
            else
                ans = ans.multiply(temp);
        }
        if (ans.isProbablePrime(10))
            return - 1;
        
        for (i = 2;i <= 100000;i ++)
        {
            BigInteger value = new BigInteger(Long.toString(i));
            if (ans.mod(value).equals(BigInteger.ZERO))
                return (int) i;
        }
        return - 1;
    }
    
    public static void main(String[] args) throws Exception
    {
//        PrintStream ps = new PrintStream(new File("E:\\out.txt"));
//        System.setOut(ps);
        
        Scanner scan = new Scanner(System.in);
        long i , j , n , cnt = 0;
        int t;
        int base = 0;
        t = scan.nextInt();
        n = scan.nextLong();
        j = scan.nextLong();
        
        System.out.println("Case #1:");
        for (i = 0;i < (1L << n) && cnt < j;i ++)
        {
            if (((i & (1L << 0)) != 0) && (i & (1L << 31)) != 0)
            {
                List<Integer> ans = new ArrayList<Integer>();
                for (base = 2;base <= 10;base ++)
                {
                    int value = check(i , base);
                    if (value > 0)
                        ans.add(value);
                }
                if (ans.size() == 9)
                {
                    StringBuilder builder = new StringBuilder();
                    builder.append(Long.toBinaryString(i));
                    for (int value : ans)
                        builder.append(" " + value);
                    String output = String.format("%s" , builder.toString()); 
                    System.out.println(output);
                    cnt ++;
                }
            }
        }
    }
    
}



