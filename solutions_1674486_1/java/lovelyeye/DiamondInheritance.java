import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;


public class DiamondInheritance
{
    static class Class
    {
        int i;
        boolean visited = false;
        Class[] inheritsFrom = null;
        @Override
        public String toString()
        {
            return "[i" + i + "]";
        }
        
    }

    static class TestCaseData
    {
        Class[] classes;
        
        static TestCaseData readTestCaseData(BufferedReader IN) throws IOException
        {
            TestCaseData result = new TestCaseData();
            int classNum = Integer.parseInt(IN.readLine());
            result.classes = new Class[classNum+1];
            for (int i = 1; i <= classNum; i++)
            {
                result.classes[i] = new Class();
                result.classes[i].i = i;
            }
            
            for (int i = 1; i <= classNum; i++)
            {
                String[] words = IN.readLine().split(" ");
                int numOfInheritence = Integer.parseInt(words[0]);
                result.classes[i].inheritsFrom = new Class[numOfInheritence];
                for (int j = 0; j < numOfInheritence; j++)
                {
                    result.classes[i].inheritsFrom[j] = result.classes[Integer.parseInt(words[j+1])];
                }
            }
            
            return result;
        }
    }

    
    /**
     * @param args
     * @throws IOException 
     */
    public static void main(String[] args) throws IOException
    {
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
            //System.out.println();
            for (int i = 0; i < testCaseData.length; i++)
            {
                System.out.println("Case #"+(i+1)+ (isDiamond(testCaseData[i])? ": Yes" : ": No"));
            }
        }        
    }


    public static boolean isDiamond(TestCaseData testCaseData)
    {
        HashSet<Class> seen = new HashSet<DiamondInheritance.Class>();
        
        for (int i = 1; i < testCaseData.classes.length; i++)
        {
            seen.clear();
            if (!testCaseData.classes[i].visited) 
            {
                if (dfsWalk(testCaseData.classes[i], seen)) {
                    return true;
                }
            }
        }
        
        return false;
    }


    public static boolean dfsWalk(Class cls, HashSet<Class> seen)
    {
        for (Class dep : cls.inheritsFrom)
        {
            dep.visited = true;
            if (seen.contains(dep)) {
                return true;
            }
            else {
                seen.add(dep);
                if (dfsWalk(dep, seen)) {
                    return true;
                }
            }
        }
        return false;
    }
}
