package jam2012.numbers;

import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

import commons.FileUtilities;

public class Recycle {
    public static void main(String[] args) throws IOException {

        List<String> strings = FileUtilities.readFile(new File("C-small-attempt1.in"));

        int number = Integer.parseInt(strings.get(0));

        List<String> result = new LinkedList<String>();

        for (int i = 1; i <= number; i++) {

            Scanner s = new Scanner(strings.get(i));
            int lower = s.nextInt();
            int upper = s.nextInt();
            
            int[] lowerArray = createArray(lower);
            int[] upperArray = createArray(upper);
            
            int tresult = 0;
            
            for (int j = lower; j <= upper; j++) {
                int[] test = createArray(j);
                LinkedList<Integer> poss = new LinkedList<Integer>();
                for (int k = 1; k < test.length; k++) {
                    if (isBigger(test, k, lowerArray, 0) == 1
                            && isBigger(test, k, upperArray, 0) <= 0
                            && isBigger(test, k, test, 0) == 1) {
                        
                        boolean dup = false;
                        for (int l : poss) {
                            if (isBigger(test, k, test, l) == 0) {
                                dup = true;
                            }
                        }
                        if (!dup) {
                            tresult++;
                            poss.add(k);
                        }
                    }
                }
            }
            result.add(Integer.toString(tresult));
        }
        
        FileUtilities.writeFile(result, new File("C-small-attempt1.out"));

    }
    
    private static int isBigger(int[] a, int aStart, int[] b, int bStart) {
        for (int i = 0; i < a.length; i++) {
            int aPtr = a[(i+aStart)%a.length];
            int bPtr = b[(i+bStart)%b.length];
            if (aPtr > bPtr) {
                return 1;
            } else if (aPtr < bPtr) {
                return -1;
            }
        }
        return 0;
    }
    
    private static int[] createArray(int i) {
        String iS = Integer.toString(i);
        int[] iA = new int[iS.length()];
        for (int j = 0; j < iA.length; j++) {
            iA[j] = Character.getNumericValue(iS.charAt(j));
        }
        return iA;
    }
}
