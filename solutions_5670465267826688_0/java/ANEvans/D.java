import java.io.*;
import java.util.*;

public class D
{
    public static final int ONE = 0;
    public static final int I = 1;
    public static final int J = 2;
    public static final int K = 3;
    public static final int NEGONE = 4;
    public static final int NEGI = 5;
    public static final int NEGJ = 6;
    public static final int NEGK = 7;
                                        
    public static final int[][] mult = {{ONE,    I,      J,      K,      NEGONE, NEGI,   NEGJ,   NEGK},
                                        {I,       NEGONE, K,      NEGJ,   NEGI,   ONE,    NEGK,   J},
                                        {J,       NEGK,   NEGONE, I,      NEGJ,   K,      ONE,    NEGI},
                                        {K,       J,      NEGI,   NEGONE, NEGK,   J,      I,      ONE},
                                        
                                        {NEGONE,  NEGI,   NEGJ,   NEGK,   ONE,    I,      J,      K},
                                        {NEGI,    ONE,    NEGK,   J,      I,      NEGONE, K,      NEGJ},
                                        {NEGJ,    K,      ONE,    NEGI,   J,      NEGK,   NEGONE, I},
                                        {NEGK,    NEGJ,   I,      ONE,    K,      NEGJ,   NEGI,   NEGONE}};
    
    public static void main(String[] args) throws Exception
    {
        long start = System.currentTimeMillis();
        Scanner in = new Scanner(System.in);
        int nData = in.nextInt();
        
        for (int asdf = 0; asdf < nData; asdf++)
        {
            int l = in.nextInt();
            long x = in.nextLong();
            in.nextLine();
            
            char[] string = in.nextLine().toCharArray();
            int[] array = new int[string.length];
            
            for (int i = 0; i < array.length; i++)
            {
                if (string[i] == 'i') array[i] = I;
                if (string[i] == 'j') array[i] = J;
                if (string[i] == 'k') array[i] = K;
            }
            
            boolean answer = solve(x, l, array);
            
            System.out.println("Case #" + (asdf+1) + ": " + (answer ? "YES" : "NO"));
        }
        
//        System.out.println("total time=" + (System.currentTimeMillis() - start));
    }
    
    public static boolean solve(long x, int l, int[] s)
    {
        if ((l * x) < 3) return false;  //make sure the string is long enough to work
        
        boolean[] unables = new boolean[l];
        
        //----------------------------------------------------------
        //find the sequence's results at each split
        int sequenceCost = ONE;
        for (int i = 0; i < l; i++)
        {
            sequenceCost = mult[sequenceCost][s[i]];
        }
        
        //----------------------------------------------------------
        //calculate the values for the looping of the sequence
        int[] loopResults = {1, 0, 0, 0};
        
        loopResults[1] = mult[loopResults[0]][sequenceCost];
        loopResults[2] = mult[loopResults[1]][sequenceCost];
        loopResults[3] = mult[loopResults[2]][sequenceCost];
        
        //----------------------------------------------------------
        //use the splitting results to calcuate what splits work (if any)
        int result = ONE;
        long numLetters = x * l;
        int section1max = 4 * l;   //only 4*l ijk's are allowed per condensed section
        section1max = (int)(numLetters < section1max ? numLetters : section1max);
        
        //check if the 'i' is possible
        for (int i = 1; i < section1max; i++)
        {
            result = mult[result][s[(i - 1) % l]];
            
            if (result == I)  //if 'i' is possible
            {
                if (unables[i % l])
                {
                    continue;
                }
                
                int section2Max = 4 * l;
                section2Max = (int)(numLetters - i < section2Max ? numLetters - i : section2Max);
                int result2 = ONE;
                boolean foundj = false;
                
                for (int j = 1; j < section2Max; j++)
                {
                    result2 = mult[result2][s[(i + j - 1) % l]];
                   
                    if (result2 == J)  //if 'j' is possible
                    {
                        foundj = true;
                        int leftover = (int)((numLetters - (i + j)) % (4 * l));
                        int result3 = ONE;
                        
                        for (int k = 1; k <= leftover; k++)
                        {
                            result3 = mult[result3][s[(i + j + k - 1) % l]];
                        }
                        
                        if (result3 == K)  //if 'k' is possible
                        {
                            return true;
                        }
                    }
                }
                
                if (!foundj)
                {
                    unables[i % l] = true;
                }
            }
        }
        
        return false;
    }
}























