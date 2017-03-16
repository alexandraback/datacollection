import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Consonants {
    
    static BigInteger TWO = BigInteger.valueOf(2l);

    public static void main(String[] args) throws IOException {
        // Input and output files
        File inputFile = new File(args[0]);
        File outputFile = new File(inputFile.getAbsolutePath() + ".output");
        if (outputFile.exists()) {
            System.out.println("Warning, output file already exists. Deleting");
            outputFile.delete();
        }
        outputFile.createNewFile();
        PrintWriter writer = new PrintWriter(outputFile);
        Scanner s = new Scanner(inputFile);
        int testCases = s.nextInt();
        s.useDelimiter("(?<=[\\s\\S])");  
        for (int testCase = 1; testCase <= testCases; testCase++) {
            s.useDelimiter("(?<=[\\s\\S])");  
            List<BigInteger> lengths = new LinkedList<BigInteger>();
            BigInteger totalSize = BigInteger.ONE;
            BigInteger current = BigInteger.ONE;
            boolean isStartVowel = false;
            boolean currentVowel = false;
            String next = s.next();
            while (next.isEmpty() || isWhitespace(next.charAt(0))) {
                next = s.next();
            }
            if (isVowel(next.charAt(0))) {
                isStartVowel = true;
                currentVowel = true;
            }
            char nextChar;
            while (!isWhitespace(nextChar = s.next().charAt(0))) {
                if (isVowel(nextChar) != currentVowel) {
                    currentVowel = !currentVowel;
                    lengths.add(current);
                    current = BigInteger.ONE;
                } else {
                    current = current.add(BigInteger.ONE);
                }
                totalSize = totalSize.add(BigInteger.ONE);
            }
            lengths.add(current);
            s.reset();
            BigInteger n = s.nextBigInteger();
            BigInteger nValue = BigInteger.ZERO;

            BigInteger lastIndex = BigInteger.ZERO;
            BigInteger currentIndex = BigInteger.ZERO;
            currentVowel = isStartVowel;
            for (BigInteger nextSubstring : lengths) {
                if (!currentVowel && nextSubstring.compareTo(n) >= 0) {
                    BigInteger extraSubstrings = nextSubstring.subtract(n);
                    BigInteger previousInvalidCharacters = currentIndex.subtract(lastIndex);
                    if(lastIndex.equals(BigInteger.ZERO)){
                        previousInvalidCharacters = previousInvalidCharacters.add(BigInteger.ONE);
                    } else {
                        previousInvalidCharacters = previousInvalidCharacters.add(n);
                    }
                    BigInteger futureCharacters = totalSize.subtract(currentIndex).subtract(n).add(BigInteger.ONE);
                    nValue = nValue.add(previousInvalidCharacters.multiply(futureCharacters));
                    if (!extraSubstrings.equals(BigInteger.ZERO)) {
                        BigInteger sum = extraSubstrings.multiply(extraSubstrings.add(BigInteger.ONE)).divide(TWO);
                        nValue = nValue.add(futureCharacters.multiply(extraSubstrings).subtract(sum));
                    }
                    lastIndex = currentIndex.add(nextSubstring);
                }
                currentIndex = currentIndex.add(nextSubstring);
                currentVowel = !currentVowel;
            }
            writer.println("Case #" + testCase + ": " + nValue);
        }
        writer.close();
    }

    private static boolean isWhitespace(char nextChar) {
        return Character.isWhitespace(nextChar);
    }

    private static boolean isVowel(char charAt) {
        switch (charAt) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
    }
}
