import java.util.Scanner;

public class ProblemA {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int numCases = input.nextInt();
        input.nextLine();
        
        for (int i = 1; i <= numCases; i++) {
            
            String S = input.nextLine();
            char[] charArray = S.toCharArray();
            StringBuilder sb = new StringBuilder();
            sb.append(charArray[0]);
            for (int k = 1; k < charArray.length; k++) {
                if (charArray[k] >= sb.charAt(0)) {
                    sb.insert(0, charArray[k]);
                } else {
                    sb.append(charArray[k]);
                }
            }
            System.out.println(String.format("Case #%d: %s", i, sb.toString()));
            
        }
        
        input.close();
    }

}
