import java.util.Scanner;

public class R1A1
{
    public static void main(String[] args)
    {
        Scanner stdin = new Scanner(System.in);
        int numberOfCases = stdin.nextInt();
        
        for(int i = 0; i < numberOfCases; ++i)
        {
            String word = stdin.next();
            System.out.print("Case #" + (i + 1) + ": ");
            System.out.println(findLastPermutation(word));
        }
    }

    private static String findLastPermutation(String word)
    {
        StringBuilder sb = new StringBuilder();
        sb.append(word.charAt(0));
        
        for(int i = 1; i < word.length(); ++i)
        {
            if(word.charAt(i) >= sb.toString().charAt(0))
            {
                sb.insert(0, word.charAt(i));
            }
            else
            {
                sb.append(word.charAt(i));
            }
        }
        
        return sb.toString();
    }
}