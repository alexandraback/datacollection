/**
 * Deceitful War response for the Google code gem Qualification Round 2014.
 * 
 * Idea of my solution:
 * 1. Sort the masses of all the blocks of both players.
 * 2. Naomi's strategy to deceive:
 *    a) Find his first block which is bigger than the lightest block of Ken's;
 *    b) Claim its weight as any number which is higher than the heaviest block of Ken's;
 *    c) Then Ken will compete with his lightest block (he could not win, so use the lightest block
 *       to save the heavy blocks to win the next rounds);
 *    Naomi repeat step a) - c) to maximize her deceitful war points until she could not find any 
 *    more blocks which is heavier than any of Ken's block.
 * 3. Naomi's strategy of optimal:
 *    Just one by one compete at any order. Claim the true weight of each blocks and Ken will compete 
 *    with his strategy: He always finds the lightest block which can beat Naomi's block. If he couldn't,
 *    he will pick the lightest block to "save energy" (mentioned in 2.c above). 
 */


import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;


public class DeceitfulWar {

    /**
     * @param args
     */
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please add the file name as the first parameter");
        }
        
        try {
            BufferedReader in = new BufferedReader(new FileReader(args[0]));
            int caseCount = Integer.parseInt(in.readLine());
            
            String[] inputNaomi = null;
            String[] inputKen = null;
            
            // The data read from line input
            double[] dataNaomi = null;
            double[] dataKen = null;
            
            int y, z;
            for (int caseNo = 1; caseNo <= caseCount; caseNo++) {
                // get test case data count
                int dataCount = Integer.parseInt(in.readLine());
                inputNaomi = in.readLine().split("\\s");
                inputKen = in.readLine().split("\\s");
                
                dataNaomi = new double[dataCount];
                dataKen = new double[dataCount];
                
                for (int i = 0; i < dataCount; i++) {
                    dataNaomi[i] = Double.parseDouble(inputNaomi[i]);
                    dataKen[i] = Double.parseDouble(inputKen[i]);
                }
                
                // Sort the data
                Arrays.sort(dataNaomi);
                Arrays.sort(dataKen);
                
                y = getDeceitfulPoints(dataNaomi, dataKen, dataCount);
                z = getOptimalPoints(dataNaomi, dataKen, dataCount);
                
                System.out.format("Case #%d: %d %d\n", caseNo, y, z);
            }
            
            in.close();
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    

    /**
     *  * 2. Naomi's strategy to deceive:
 *    a) Find his first block which is bigger than the lightest block of Ken's;
 *    b) Claim its weight as any number which is higher than the heaviest block of Ken's;
 *    c) Then Ken will compete with his lightest block (he could not win, so use the lightest block
 *       to save the heavy blocks to win the next rounds);
 *    Naomi repeat step a) - c) to maximize her deceitful war points until she could not find any 
 *    more blocks which is heavier than any of Ken's block.

     * @param dataN
     * @param dataK
     * @param count
     * @return the points Naomi earns
     */
    private static int getDeceitfulPoints(double[] dataN, double[] dataK, int count) {
        int posN = 0, posK = 0;
        int points = 0;
        while (posN < count && posK < count) {
            while (posN < count && dataN[posN] < dataK[posK]) {
                posN++;
            }
            if (posN < count) {
                // earn one point by deceitful war
                points++;
                posN++; posK++;
            } else {
                break;
            }
        }
        return points;
    }
    
    
    /**
     * Ken tries to win each round he can win. 
     * @param dataN
     * @param dataK
     * @param count
     * @return the points Naomi earns
     */
    private static int getOptimalPoints(double[] dataN, double[] dataK, int count) {
        int posN = 0, posK = 0;
        int points = 0; // points Ken wins
        while (posN < count && posK < count) {
            while (posK < count && dataN[posN] > dataK[posK]) {
                posK++;
            }
            if (posK < count) {
                // Ken earns one point by his strategy
                points++;
                posN++; posK++;
            } else {
                break;
            }
        }
        return count - points; // return points Naomi wins
    }
    
}
