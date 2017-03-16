import java.util.HashSet;
import java.util.Scanner;


public class C {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        
        int cases;
        cases = in.nextInt();
        in.nextLine();
        
        for(int i = 0; i < cases; i ++ ) {
            int a = in.nextInt();
            int b = in.nextInt();
            HashSet<Integer> found = new HashSet<Integer>();
            int total = 0;
            if( b >= 10) {
                if( a < 10 ) {
                    a = 10;
                }
                for( int j = a; j <= b; j++ ) {
                    if( !found.contains(j) ) {
                        String theNum = String.valueOf(j);
                        int morphed;
                        theNum = theNum.charAt(theNum.length() -1) + theNum.substring(0, theNum.length()-1);
                        morphed = Integer.valueOf(theNum);
                        while( morphed != j ) {
                            if( !found.contains(morphed) &&
                                    morphed >=a && morphed <=b ) {
                                total ++;
                                found.add(j);
                            }
                            theNum = theNum.charAt(theNum.length() -1) + theNum.substring(0, theNum.length()-1);
                            morphed = Integer.valueOf(theNum);
                        }
                    }
                }
            }
            System.out.println("Case #" + (i+1) + ": " + total );
        }
    }
}
