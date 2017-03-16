import java.math.BigInteger;
import java.rmi.UnexpectedException;
import java.util.HashSet;

class FailedException extends Exception {
}
class CoinGenerator
{
    public CoinGenerator(int coinLength, int numberOfCoins)
    {
        this.coinLength = coinLength;
        this.numberOfCoins = numberOfCoins;
    }

    public void Generate()
    {
        while (generatedCoins.size() < numberOfCoins)
        {
            int binaryCandidate = GenerateBinaryCandidate();
            if (IsCoinJam(binaryCandidate) && !generatedCoins.contains(binaryCandidate)) {
                generatedCoins.add(binaryCandidate);
                //System.out.println(Integer.toBinaryString(binaryCandidate));
            }
        }
    }

    public void PrintAnswerToConsole() throws Exception
    {
        for (Integer generatedCoin : generatedCoins)
        {
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append(Integer.toBinaryString(generatedCoin));

            try {

                for (int base = 2; base <= 10; ++base) {
                    BigInteger number = CreateNumber(base, generatedCoin);
                    BigInteger divisor = GetNonTrivialDivisor2(number);
                    String numberString = number.toString();
                    String divisorString = divisor.toString();
                    if (number.mod(divisor) != BigInteger.ZERO)
                        throw new UnexpectedException("dupa");
                    stringBuilder.append(" " + divisor);
                }
            }
            catch(FailedException exception)
            {
                continue;
            }
            System.out.println(stringBuilder.toString());
        }
    }

    private String GetNonTrivialDivisor(BigInteger number) throws Exception{
        final BigInteger Two = BigInteger.ONE.add(BigInteger.ONE);
        if (number.mod(Two) == BigInteger.ZERO)
            return Two.toString();
        for (BigInteger i = Two.add(BigInteger.ONE); LeftIsLessThanOrEqualRight(i.multiply(i), number); i = i.add(Two))
        {
            if (number.mod(i).compareTo(BigInteger.ZERO) == 0)
                return i.toString();
        }

        throw new UnexpectedException("What?");
    }

    private BigInteger GetNonTrivialDivisor2(BigInteger number) throws Exception{
        final BigInteger Two = BigInteger.ONE.add(BigInteger.ONE);
        if (number.mod(Two) == BigInteger.ZERO)
            return Two;

        int numberOfSteps = 0;
        BigInteger nextProbablePrime = Two.nextProbablePrime();
        while (LeftIsLessThanOrEqualRight(nextProbablePrime.multiply(nextProbablePrime), number))
        {
            if (number.mod(nextProbablePrime).compareTo(BigInteger.ZERO) == 0)
                return nextProbablePrime;

            nextProbablePrime = nextProbablePrime.nextProbablePrime();
            if (numberOfSteps++ > 1000)
                throw new FailedException();
        }

        throw new UnexpectedException("What?");
    }

    private boolean IsCoinJam(int binaryCandidate) {
        for (int base = 2; base <= 10; ++base) {
            BigInteger numberToCheck = CreateNumber(base, binaryCandidate);
            if (numberToCheck.isProbablePrime(15) == true)
                return false;
        }

        return true;
    }

    private static boolean LeftIsLessThanOrEqualRight(BigInteger left, BigInteger right)
    {
        return left.compareTo(right) != 1;
    }

    private BigInteger CreateNumber(int base, int binaryCandidate) {
        BigInteger result = BigInteger.ZERO;
        BigInteger bigIntBase = BigInteger.valueOf(base);
        String stringBinaryCandidate = Integer.toBinaryString(binaryCandidate);
        for (int i = 0; i < coinLength; ++i) {
            if (stringBinaryCandidate.charAt(coinLength - 1 - i) == '1')
                result = result.add(bigIntBase.pow(i));
        }

        return result;
    }

    private int GenerateBinaryCandidate() {
        final int SmallestNumber = 1 << (coinLength - 1);
        int result = SmallestNumber | sead;

        sead += 2;
        return result;
    }

    private int coinLength;
    private int numberOfCoins;
    private HashSet<Integer> generatedCoins = new HashSet<Integer>();
    private int sead = 1;
}

public class Main
{
    public static void main(String[] args) throws Exception
    {
        CoinGenerator coinGenerator = new CoinGenerator(32, 1000);
        coinGenerator.Generate();
        System.out.println("Case #1:");
        coinGenerator.PrintAnswerToConsole();
    }
}
