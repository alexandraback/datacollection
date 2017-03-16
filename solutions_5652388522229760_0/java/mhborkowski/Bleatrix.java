import java.util.Scanner;

public class Bleatrix {
    
    public static boolean done(boolean[] digits) {
        for (int i=0; i<digits.length; ++i)
            if (! digits[i]) 
                return false;
        return true;
    }
    
    public static void main(String[] args) {
        
        Scanner inFile = new Scanner(System.in);
        int problems = Integer.parseInt(inFile.nextLine());
        
        for (int caseNum=0; caseNum < problems; caseNum++) {
            
            int n = inFile.nextInt();
            int j = 0;
            boolean broken = false;
            boolean[] digits = new boolean[10];
            
            while (! done(digits) ) {
                ++j;
                long m = j * ((long) n);
                String nStr = String.valueOf(m);
                for (int i=0; i<nStr.length(); i++) {
                    int digit = Character.digit(nStr.charAt(i),10);
                    digits[digit] = true;
                }
                if (j > 100000) {
                    System.out.printf("Case #%d: INSOMNIA\n", caseNum+1);
                    broken = true;
                    break;
                }
            }
            if (! broken)
                System.out.printf("Case #%d: %d\n", caseNum+1, j*((long) n));
        }
        inFile.close();
    }
}