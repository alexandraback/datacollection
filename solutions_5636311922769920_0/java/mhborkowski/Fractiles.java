import java.util.Scanner;

public class Fractiles {
       
    public static void main(String[] args) {
        
        Scanner inFile = new Scanner(System.in);
        int problems = Integer.parseInt(inFile.nextLine());
        
        for (int caseNum=0; caseNum < problems; caseNum++) {
            
            int k = inFile.nextInt();
            int c = inFile.nextInt();
            int s = inFile.nextInt();
            
            int reqd = k / c + ( k % c !=0 ? 1 : 0);
            if (reqd > s) 
                System.out.printf("Case #%d: IMPOSSIBLE\n", caseNum+1);
            else {
                long[] choices = new long[reqd];
                for (int i=0; i<reqd; ++i) {
                    long choice = 0 ;
                    if ( true ) {
                        for (long j=c*i; j < c*(i+1) && j < k; ++j) {
                            long expn = c*(i+1) - j - 1;
                            choice += j * ((long) Math.pow(k, expn));
                        }
                    }
                    choices[i] = choice + 1; // index tiles from 1
                }   
                StringBuilder sb = new StringBuilder();
                for (int i=0; i<choices.length; i++) {
                    if (i>0) sb.append(" ");
                    sb.append(choices[i]);
                }
                String choiceStr = sb.toString();
                System.out.printf("Case #%d: %s\n", caseNum+1, choiceStr);
            }
        }
        inFile.close();
    }
}