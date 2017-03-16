package codejam.is;

/**
 * Created with IntelliJ IDEA.
 * User: ofer
 * Date: 4/13/12
 * Time: 8:47 PM
 * To change this template use File | Settings | File Templates.
 */
public interface Test {

    /** Runs the test on the given input */
    public void run(String input);

    /** Returns the output of the test */
    public String getOutput(int testNum);

}
