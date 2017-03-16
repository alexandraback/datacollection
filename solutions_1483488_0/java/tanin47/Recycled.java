import java.io.*;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: tanin
 * Date: 4/14/12
 * Time: 9:54 AM
 * To change this template use File | Settings | File Templates.
 */
public class Recycled {


    public static void main(String[] args) throws Exception {

        String filename = "Recycled/recycled";
        String outFilename = filename + "_out";

        FileInputStream fis = new FileInputStream(new File(filename));
        Scanner input = new Scanner(new BufferedInputStream(fis));

        FileOutputStream fOut = new FileOutputStream(new File(outFilename));
        BufferedOutputStream bOut = new BufferedOutputStream(fOut);
        DataOutputStream out = new DataOutputStream(bOut);

        int numCases = input.nextInt();
        input.nextLine();

        for (int caseNumber=0;caseNumber<numCases;caseNumber++) {

            int a = input.nextInt();
            int b = input.nextInt();
            out.writeBytes("Case #" + (caseNumber+1) + ": " + solve(a, b) + "\n");
        }

        out.flush();
        out.close();

        bOut.flush();
        bOut.close();

        fOut.flush();
        fOut.close();
    }

    static boolean[] checked = new boolean[2000001];
    public static long solve(int a, int b) {

        for (int i=0;i<checked.length;i++) {
            checked[i] = false;
        }
        
        long count = 0;

        for (int number=a;number<=b;number++) {
        
            if (checked[number] == true) continue;

            int multiple = getMultiple(number);
            checked[number] = true;
            int countValid = 1;
            
            int run = next(number, multiple);
            while (run != number) {

                if (run >= multiple && a <= run && run <= b) {
                    checked[run] = true;
                    countValid++;
                    
                    //System.out.println(run);
                }
                
                run = next(run, multiple);
            }
            
            if (countValid == 1) continue;
            //System.out.println(number);
            
            count += countValid * (countValid - 1) / 2;
        }

        return count;
    }
    
    public static int getMultiple(int s)  {
        if (s < 10) return 1;
        else if (s < 100) return 10;
        else if (s < 1000) return 100;
        else if (s < 10000) return 1000;
        else if (s < 100000) return 10000;
        else if (s < 1000000) return 100000;
        else if (s < 10000000) return 1000000;
        else {
            System.out.println("Fuck you");
            return -100000000;
        }
    }
    
    public static int next(int s, int multiple) {
        int residue = s % 10;
        return residue * multiple + s / 10;
    }

}
