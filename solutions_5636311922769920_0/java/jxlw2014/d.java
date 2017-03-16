import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;



public class Main 
{
    private static BigInteger getValue(int k , int c)
    {
        // k ^ (c - 1) + k ^ (c - 2) + .... + 1
        BigInteger ans = new BigInteger(Integer.toString(k));
        ans = ans.pow(c);
        ans = ans.subtract(BigInteger.ONE);
        BigInteger temp = new BigInteger(Integer.toString(k - 1));
        ans = ans.divide(temp);
        return ans;
    }
    
    public static void main(String[] args) throws Exception
    {
//        System.setIn(new FileInputStream("E:\\D-small-attempt0.in"));
//        PrintStream ps = new PrintStream(new File("E:\\out.txt"));
//        System.setOut(ps);
        
        Scanner scan = new Scanner(System.in);
        int i , j , t , k , c , s , caseNum = 1;
        t = scan.nextInt();
        while (t > 0)
        {
            k = scan.nextInt();
            c = scan.nextInt();
            s = scan.nextInt();
            // if k equals one
            if (k == 1)
            {
                String output = String.format("Case #%d: 1" , caseNum);
                System.out.println(output);
            }
            // k is bigger than one
            else
            {
                BigInteger value = getValue(k , c);
                StringBuilder builder = new StringBuilder();
                builder.append(String.format("Case #%d:" , caseNum));
                for (i = 1;i <= s;i ++)
                {
                    builder.append(" ");
                    // value * (i - 1) + 1
                    BigInteger temp = new BigInteger(Integer.toString(i - 1)).multiply(value).add(BigInteger.ONE);
                    builder.append(temp.toString());
                }
                System.out.println(builder.toString());
            }
            t --;
            caseNum ++;
        }
    }
    
}









