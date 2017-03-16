import java.math.BigInteger;
import java.util.Scanner;

public
class ProblemA implements ProblemRunner.Problem
{
    private BigInteger r;
    private BigInteger t;

    public
    void parse(Scanner scanner)
    {
        r = scanner.nextBigInteger();
        t = scanner.nextBigInteger();
    }

    public
    String solve()
    {
        int i =0;

        BigInteger inner = r;
        BigInteger outer = r.add(BigInteger.ONE);


        final BigInteger two = new BigInteger("2");

        BigInteger trem = t;


        while(true)
        {
            BigInteger innerSquared = inner.multiply(inner);
            BigInteger outerSquared = outer.multiply(outer);
            BigInteger diff = outerSquared.subtract(innerSquared);
            System.out.println("diff = " + diff);

            if(diff.compareTo(trem)>0)
            {
                break;
            }
            else
            {
                i++;
                System.out.println("i = " + i);
                trem =trem.subtract(diff);

                inner=inner.add(two);
                outer=outer.add(two);
            }
        }

        return String.valueOf(i);
    }

    public static
    void main(String[] args) throws Exception
    {
        ProblemRunner.run(args, ProblemA.class, 0);
    }
}
