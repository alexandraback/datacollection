import junit.framework.Assert;
import org.junit.Ignore;

/**
 * Created with IntelliJ IDEA.
 * User: Qba
 * Date: 13.04.13
 * Time: 16:32
 * To change this template use File | Settings | File Templates.
 */
public class SolutionTest {

    Solution s;

    @org.junit.Before
    public void setUp() throws Exception {
        s = new Solution();
    }

    @org.junit.Test
    public void testSolve1() throws Exception {
        long result = s.solve(1, 4);
        Assert.assertEquals(2, result);
    }

    @org.junit.Test
    public void testSolve2() throws Exception {
        long result = s.solve(10, 120);
        Assert.assertEquals(0, result);
    }

    @org.junit.Test
    public void testSolve3() throws Exception {
        long result = s.solve(100, 1000);
        Assert.assertEquals(2, result);
    }


    @org.junit.Test
    public void testSolve_largeSum() throws Exception {
        long result1 = s.solve(10000000000L, 100000000000000L);
        long result2 = s.solve(100000L, 9999999999L);
        long result3 = s.solve(1, 99999);

        long sumResult = s.solve(1, 100000000000000L);

        Assert.assertEquals(sumResult, result1 + result2 + result3);
    }


}
