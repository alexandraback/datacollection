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
        int[][] arr = new int[][]{{1, 1, 1}, {1, 2, 1}, {1, 1, 1}};
        s.setBoard(arr);
        String msg = s.solve(1);
        Assert.assertEquals("Case #1: YES", msg);
    }

    @org.junit.Test
    public void testSolve2() throws Exception {
        int[][] arr = new int[][]{{1, 2, 1}, {1, 1, 1}, {1, 1, 2}};
        s.setBoard(arr);
        String msg = s.solve(1);
        Assert.assertEquals("Case #1: NO", msg);
    }


    @org.junit.Test
    public void testSolve3() throws Exception {
        int[][] arr = new int[][]{{1, 1, 1}, {1, 2, 1}, {1, 3, 1}};
        s.setBoard(arr);
        String msg = s.solve(1);
        Assert.assertEquals("Case #1: YES", msg);
    }

    @org.junit.Test
    public void testSolve4() throws Exception {
        int[][] arr = new int[][]{{100, 100}};
        s.setBoard(arr);
        String msg = s.solve(1);
        Assert.assertEquals("Case #1: YES", msg);
    }


    @org.junit.Test
    public void testSolve5() throws Exception {
        int[][] arr = new int[][]{{1, 100}, {100, 1}};
        s.setBoard(arr);
        String msg = s.solve(1);
        Assert.assertEquals("Case #1: NO", msg);
    }


}
