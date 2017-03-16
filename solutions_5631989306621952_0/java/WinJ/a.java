import java.util.*;

public class a {
    private static int flipCount;
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int caseNumber = in.nextInt();
        
        for(int i = 0; i < caseNumber; i++) {
            String input = in.next();
            
            StringBuilder sb = new StringBuilder();
            
            for(int j = 0; j < input.length(); j++) {
                char c = input.charAt(j);
                if(sb.length() == 0 || c < sb.charAt(0)) sb.append(c);
                else sb.insert(0, c);
            }
            
            System.out.print("Case #" + (i+1) + ": ");
            System.out.println(sb.toString());
        }
    }
    
}