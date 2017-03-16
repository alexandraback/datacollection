
import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemB {

    public static void main(String[] args) throws Exception {

        String inFile = "B-large-attempt0.in";
        String outFile = "B-large-attempt0.out";

        Scanner sc = new Scanner(new File(inFile));
        PrintWriter writer = new PrintWriter(outFile);
        int numTest = sc.nextInt();
        for (int test = 1; test <= numTest; test++) {
            writer.println("Case #" + test + ": " + solution(sc));
        }
        writer.close();
    }

    private static String solution(Scanner sc) {
        double cost=sc.nextDouble();
        double speedGain=sc.nextDouble();
        double objective=sc.nextDouble();
        
        double currentSpeed=2;
        
        double T=0;
        
        while ((objective-cost)/currentSpeed > objective/(currentSpeed+speedGain)) {
            T+=cost/currentSpeed;
            currentSpeed+=speedGain;
        }
        
        T+=objective/currentSpeed;
        
        return T+"";
    }

}
