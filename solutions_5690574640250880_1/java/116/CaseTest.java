package problem3;

import java.util.Random;

import org.junit.Assert;
import org.junit.Test;

public class CaseTest
{
    
    private void check(Case c, Object solution)
    {
        int q = c.getX() * c.getY() - c.getM();
        
        switch (Math.min(c.getX(), c.getY()))
        {
            case 1:
                check2(c, solution);
                break;
            
            case 2:
                if (q == 2)
                {
                    Assert.assertEquals("Impossible", solution);
                    return;
                }
                if (q == 1)
                {
                    check2(c, solution);
                    return;
                }
                
                if (c.getM() % 2 == 0)
                {
                    check2(c, solution);
                }
                else
                {
                    Assert.assertEquals("Impossible", solution);
                }
                break;
            
            default:
                switch (q)
                {
                    case 2:
                    case 3:
                    case 5:
                    case 7:
                        Assert.assertEquals("Impossible", solution);
                        break;
                    
                    case 1:
                    case 4:
                    case 6:
                    case 8:
                    case 9:
                    default:
                        check2(c, solution);
                }
                break;
        }
    }
    
    private void check2(Case c, Object solution)
    {
        if (solution instanceof Answer)
        {
            Assert.assertTrue(c.toString() + "\n" + solution.toString(), ((Answer) solution).validSolution());
            Assert.assertEquals(c.getM(), ((Answer) solution).count('*'));
        }
        else
        {
            Assert.fail("Expected a solution for " + c);
        }
    }
    
    @Test
    public void testEmpty()
    {
        Case c = new Case(5, 5, 0);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void testFull()
    {
        Case c = new Case(5, 5, 24);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void test1Line()
    {
        Case c = new Case(1, 5, 3);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void test1Col()
    {
        Case c = new Case(5, 1, 3);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void test3by3_0()
    {
        Case c = new Case(3, 3, 0);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void p38_40_1093()
    {
        Case c = new Case(38, 40, 1093);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void p9_13_87()
    {
        Case c = new Case(9, 13, 87);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void p10_2_3()
    {
        Case c = new Case(9, 13, 87);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void p3_6_9()
    {
        Case c = new Case(9, 13, 87);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void p5_30_95()
    {
        Case c = new Case(5, 30, 95);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void p14_2_26()
    {
        Case c = new Case(14, 2, 26);
        Object solution = c.solve();
        check(c, solution);
    }
    
    @Test
    public void random()
    {
        int samples = 100_000;
        long seed = System.currentTimeMillis();
        System.out.println("seed=" + seed);
        Random r = new Random(seed);
        
        for (int i = 0; i < samples; ++i)
        {
            int x = r.nextInt(49) + 1;
            int y = r.nextInt(49) + 1;
            int m = r.nextInt(x * y);
            Case c = new Case(x, y, m);
            Object solution = c.solve();
            check(c, solution);
        }
    }
}
