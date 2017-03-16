package codejam.is;

/**
 * Created with IntelliJ IDEA.
 * User: ofer
 * Date: 4/13/12
 * Time: 8:49 PM
 * To change this template use File | Settings | File Templates.
 */
public abstract class TestAbstract implements Test {

    private final static String newline = System.getProperty("line.separator");

    @Override
    public String getOutput(int testNum) {
        return "Case #" + testNum + ": " + getTestResult() + newline;
    }

    protected abstract String getTestResult();
}
