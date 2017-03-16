package Dijkstra;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by xuchen on 4/10/15.
 */
public class Dijkstra {

    static HashMap<Character,Integer> cMap = new HashMap<Character,Integer>();

    static {
        cMap.put('1',1);
        cMap.put('i',2);
        cMap.put('j',3);
        cMap.put('k',4);
    }

    static int[][] multTable = {
            {1,2,3,4},
            {2,-1,4,-3},
            {3,-4,-1,2},
            {4,3,-2,-1}};

    static int[][] divTable = {
            {1,-2,-3,-4},
            {2,1,4,-3},
            {3,-4,1,2},
            {4,3,-2,1}};

    public static int mult(int a, int b){

        if (a * b > 0){
            return multTable[Math.abs(a)-1][Math.abs(b)-1];
        }
        return -multTable[Math.abs(a)-1][Math.abs(b)-1];
    }

    public static int div(int a, int b){

        if (a * b > 0){
            return divTable[Math.abs(a)-1][Math.abs(b)-1];
        }
        return -divTable[Math.abs(a)-1][Math.abs(b)-1];
    }

    public static boolean checkValid(String str, int strLen, int totalLen){
        int[] H = new int[totalLen];
        H[0] = cMap.get(str.charAt(0));

        for (int i = 1; i < totalLen; i++){
            H[i] = mult(H[i-1],cMap.get(str.charAt(i % strLen)));
        }

        for (int indexI = 0; indexI < totalLen; indexI++){

            if (H[indexI] == 2){

                for (int indexJ = indexI + 1; indexJ < totalLen; indexJ++){

                    if (div(H[indexJ],H[indexI]) == 3){

                        if (indexJ < totalLen && div(H[totalLen - 1], H[indexJ]) == 4) return true;

                    }

                }

            }

        }

        return false;
    }

    public static void main(String[] args) {

        try {
            Scanner scanner = new Scanner(new File("src/Dijkstra/C-small-attempt1.in"));
            PrintWriter writer = new PrintWriter(new File("src/Dijkstra/result.txt"));

            int caseCnt = scanner.nextInt();

            for (int i = 0; i < caseCnt; i++){

                int strLen = scanner.nextInt();
                int repeatTimes = scanner.nextInt();
                String str = scanner.next();

                if (checkValid(str,strLen,strLen*repeatTimes)){
                    writer.println("Case #" + (i+1) + ": YES");
                }else {
                    writer.println("Case #" + (i+1) + ": NO");
                }

            }

            writer.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
