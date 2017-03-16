import java.util.ArrayList;
import java.util.Scanner;


public class AA {
   
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        
        int cases;
        cases = in.nextInt();
        in.nextLine();
        
        for(int i = 0; i < cases; i ++ ) {
            double contestants = in.nextInt();
            
            int sum = 0;
            ArrayList<Integer> scores = new ArrayList<Integer>();
            for( int j = 0; j < contestants; j++) {
                int curs = in.nextInt();
                scores.add(curs);
                sum += curs;
            }

            int prevIgnore = -1;
            int ignores = 0;
            ArrayList<Boolean> ignore = new ArrayList<Boolean>();
            int origSum = sum;
            sum *= 2;
            double each = sum/contestants;
            while( ignores != prevIgnore ) {
                prevIgnore = ignores;
                for( int j = 0; j < contestants; j++ ) {
                    if( ignore.size() > j && ignore.get(j))
                        continue;
                    if( each < scores.get(j) ) {
                        sum -= scores.get(j);
                        ignore.add(true);
                        ignores++;
                    } else {
                        ignore.add(false);
                    }
                }
                each = sum/(contestants - ignores);
            }
            System.out.print("Case #" + (i+1) + ":");
            for( int j = 0; j < contestants; j++ ) {
                double score;
                if( ignore.get(j) ) {
                    score = 0.0;
                } else {
                    score = (each - scores.get(j) )/(origSum)* 100;
                }
//                System.out.printf(" (%f)", score * origSum /100 + scores.get(j));
                System.out.printf(" %f", score);
            }
            System.out.println();
        }
    }
}
