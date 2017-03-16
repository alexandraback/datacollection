import java.util.Scanner;


public class B {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        
        int cases;
        cases = in.nextInt();
        in.nextLine();
        
        for(int i = 0; i < cases; i ++ ) {
            int n = in.nextInt();
            int surprises = in.nextInt();
            int threshold = in.nextInt();
            
            int passed = 0;
            for( int j = 0; j < n; j ++ )  {
                int score = in.nextInt();
                if( score/3.0 >= threshold) {
                    passed++;
                    continue;
                }
                score -= threshold;
                if( score < 0 ) {
                    continue;
                }
                int test1 = score - ( threshold - 1 );
                if( test1 >= 0 ) {
                    if( test1 >= ( threshold - 1 ) && test1 <= ( threshold + 1 ) ) {
                        passed++;
                        continue;
                    }
                }
                test1++;
                if( test1 < 0 ) {
                    continue;
                }
                if( test1 >= ( threshold - 2 ) && test1 <= ( threshold + 2 ) ) {
                    if( surprises > 0 ) {
                        passed++;
                        surprises--;
                        continue;
                    }
                }
            }
            System.out.println("Case #" + (i+1) + ": " + passed);
        }
    }
}
