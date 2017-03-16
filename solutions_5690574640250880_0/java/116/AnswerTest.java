package problem3;

import java.util.ArrayList;
import java.util.List;

import org.junit.Assert;
import org.junit.Test;

public class AnswerTest
{
    @Test
    public void testEmpty()
    {
        List<String> grid = new ArrayList<>();
        grid.add("...");
        grid.add("...");
        grid.add("...");
        Answer c = new Answer(0, 0, grid);
        Assert.assertTrue(c.validSolution());
    }
    
    @Test
    public void testEasiest()
    {
        List<String> grid = new ArrayList<>();
        grid.add("...");
        grid.add("...");
        grid.add("..*");
        Answer c = new Answer(0, 0, grid);
        Assert.assertTrue(c.validSolution());
    }
    
    @Test
    public void testMineFirst()
    {
        List<String> grid = new ArrayList<>();
        grid.add("*..");
        grid.add("...");
        grid.add("...");
        Answer c = new Answer(0, 0, grid);
        Assert.assertFalse(c.validSolution());
    }
    
    @Test
    public void testStartNonZero()
    {
        List<String> grid = new ArrayList<>();
        grid.add("*..");
        grid.add("...");
        grid.add("...");
        Answer c = new Answer(1, 0, grid);
        Assert.assertFalse(c.validSolution());
    }
    
    @Test
    public void testImpossible()
    {
        List<String> grid = new ArrayList<>();
        grid.add("*..");
        grid.add("...");
        grid.add("..*");
        
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                Answer c = new Answer(i, j, grid);
                Assert.assertFalse(c.validSolution());
            }
        }
    }
    
    @Test
    public void test1line()
    {
        List<String> grid = new ArrayList<>();
        grid.add("***.c");
        Answer c = new Answer(4, 0, grid);
        Assert.assertFalse(c.validSolution());
    }
    
    @Test
    public void test1col()
    {
        List<String> grid = new ArrayList<>();
        grid.add("*");
        grid.add("*");
        grid.add("*");
        grid.add(".");
        grid.add("c");
        Answer c = new Answer(0, 4, grid);
        Assert.assertFalse(c.validSolution());
    }
}
