
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class DancingWithTheGooglers
{
    static HashMap<Integer, Integer[]> absoluteMap = new HashMap<Integer, Integer[]>();
    static HashMap<Integer, Integer[]> surpriseMap = new HashMap<Integer, Integer[]>();

    static class TestCaseData
    {
        int numberOfGooglers;
        int surprisingTripletsOfScores;
        int minBestResult;
        int[] scores;
        
        int minBestResultCount;
        
        static TestCaseData readTestCaseData(BufferedReader IN) throws IOException
        {
            TestCaseData result = new TestCaseData();
            String[] words = IN.readLine().split(" ");
            
            result.numberOfGooglers = Integer.parseInt(words[0]);
            result.surprisingTripletsOfScores = Integer.parseInt(words[1]);
            result.minBestResult = Integer.parseInt(words[2]);
            
            result.scores = new int[result.numberOfGooglers];
            
            for (int i = 0; i < result.scores.length; i++)
            {
                result.scores[i] = Integer.parseInt(words[3+i]);
            }
            
            return result;
        }
    }

    public static void computeMaps()
    {
        HashSet<List<Integer>> absIntSet = new HashSet<List<Integer>>();
        HashSet<List<Integer>> surpriseIntSet = new HashSet<List<Integer>>();
        
        for (int i = 0; i <= 10; i++)
        {
            int pos1 = i;
            for (int j = -1; j <= 1; j++)
            {
                int pos2 = pos1+j;
                if (pos2 < 0 || pos2 > 10) continue;
                
                int low, high;
                if (pos1 == pos2) {
                    low = -1;
                    high = 1;
                }
                else if (pos1 < pos2) {
                    low = 0;
                    high = 1;
                }
                else {
                    low = -1;
                    high = 0;
                }
                
                for (int k = low; k <= high ; k++)
                {
                    int pos3 = pos1+k;
                    if (pos3 < 0 || pos3 > 10) continue;
                    int fourSum = pos1 + pos2 + pos3;
                    Integer[] triplet = {pos1, pos2, pos3};
                    Arrays.sort(triplet);
                    if (absIntSet.add(Arrays.asList(triplet))) {
                        //printLn("[%d, %d, %d] = %d", triplet[0], triplet[1], triplet[2], fourSum);
                        absoluteMap.put(fourSum, triplet);
                    }
                }
            }
        }
        
        for (int i = 0; i <= 10; i++)
        {
            int pos1 = i;
            for (int j = -2; j <= 2; j++)
            {
                int pos2 = pos1+j;
                if (pos2 < 0 || pos2 > 10) continue;

                int low, high;
                if (pos1 == pos2) {
                    low = -2;
                    high = 2;
                }
                else if (pos1 < pos2) {
                    low = 2-j;
                    high = 2;
                }
                else {
                    low = -2;
                    high = -2-j;
                }
                
                for (int k = low; k <= high ; k++)
                {
                    int pos3 = pos1+k;
                    if (pos3 < 0 || pos3 > 10) continue;
                    int fourSum = pos1 + pos2 + pos3;
                    Integer[] triplet = {pos1, pos2, pos3};
                    Arrays.sort(triplet);
                    List<Integer> tripletList = Arrays.asList(triplet);
                    if (!absIntSet.contains(tripletList) && ! surpriseIntSet.contains(tripletList)) {
                        surpriseIntSet.add(tripletList);
                        surpriseMap.put(fourSum, triplet);
                        //printLn("[%d, %d, %d] = %d", triplet[0], triplet[1], triplet[2], fourSum);
                    }
                }
            }
        }
        
        surpriseMap.put(0, absoluteMap.get(0));
    }
    
    /**
     * @param args
     * @throws IOException 
     */
    public static void main(String[] args) throws IOException
    {
        computeMaps();
        BufferedReader IN = new BufferedReader(new InputStreamReader(System.in));
        
        int testCaseCount;
        try
        {
            String input = IN.readLine();
            testCaseCount = Integer.parseInt(input);
        }
        catch (Exception e)
        {
            testCaseCount = 0;
        }

        if (testCaseCount > 0)
        {
            TestCaseData[] testCaseData = new TestCaseData[testCaseCount];
            for (int i = 0; i < testCaseData.length; i++)
            {
                testCaseData[i] = TestCaseData.readTestCaseData(IN);
            }

            for (int i = 0; i < testCaseData.length; i++)
            {
                testCaseData[i].minBestResultCount = processTestCase(testCaseData[i]);
                printLn("Case #%d: %d", i + 1, testCaseData[i].minBestResultCount);
            }
            
        }
        
        IN.close();
    }

    protected static int processTestCase(TestCaseData testCaseData)
    {
        int absoulteBSCount = 0;
        int surpriseBSCount = 0;
        int best = testCaseData.minBestResult;
        
        for (int i = 0; i < testCaseData.numberOfGooglers; i++)
        {
            int score = testCaseData.scores[i];
            Integer[] triplet = absoluteMap.get(score);
            if (triplet[2] >= best) {
                absoulteBSCount++;
            }
            else
            {
                triplet = surpriseMap.get(score);
                if (triplet != null && triplet[2] >= best) {
                    surpriseBSCount++;
                }
            }
        }
        
        return absoulteBSCount + Math.min(testCaseData.surprisingTripletsOfScores, surpriseBSCount);
    }

    //  to ensure that '\n' is used as EOL on my Windows Machine, just to be sure ;)
    //
    static void printLn(String val)
    {
        System.out.print(val);
        System.out.print('\n');
    }
    static void printLn(String format, Object ... args)
    {
        System.out.print(String.format(format, args));
        System.out.print('\n');
    }
}
