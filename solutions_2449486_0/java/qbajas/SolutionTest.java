import junit.framework.Assert;

/**
 * Created with IntelliJ IDEA.
 * User: Qba
 * Date: 13.04.13
 * Time: 22:10
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
        boolean[][] arr = new boolean[][]{{true, true, true}, {true, false, true}, {true, true, true}};
        s.setCanGo(arr);
        String msg = s.solve(1);
        Assert.assertEquals("Case #1: YES",msg);
    }

    @org.junit.Test
    public void testSolve2() throws Exception {
        boolean[][] arr = new boolean[][]{{true, false, true}, {true, true, true}, {true, true, false}};
        s.setCanGo(arr);
        String msg = s.solve(1);
        Assert.assertEquals("Case #1: NO",msg);
    }
}
