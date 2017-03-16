import java.util.Scanner;

public class Elf
{   
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        
        int tests, ans; // number of tests and answers
        tests = Integer.parseInt(s);
      
        
        for (int i = 0; i < tests; i++)
        {
            s = sc.nextLine();
            String[] numbers = s.split("/");
            int num = Integer.parseInt(numbers[0]);
            int den = Integer.parseInt(numbers[1]);
            int count = 0;
            
            if (den == 0)
                System.out.println("Case #" + (i + 1) + ": impossible");            
            else if ((den & (den - 1)) != 0)
                System.out.println("Case #" + (i + 1) + ": impossible");
            else
                while (den != 0)
            {
                den = den/2;
                count++;
                if (den <= num)
                {
                    System.out.println("Case #" + (i + 1) + ": " + count);
                    break;
                }
            }
        }
    }
}