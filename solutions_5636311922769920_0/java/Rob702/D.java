import java.util.*;

public class D {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        for(int thisNum = 1; thisNum <= numCases; thisNum++) {
            int K = in.nextInt();
            int C = in.nextInt();
            int S = in.nextInt();
            String output = "";
            if ( S >= K ) {
                for ( int i = 1; i <= K; i++ ) {
                    output += i;
                    output += " ";
                }
            } else {
                output = "IMPOSSIBLE";
            }
            // Print results
            System.out.format("Case #%d: %s\n", thisNum, output.trim() );
        }
    }

}
