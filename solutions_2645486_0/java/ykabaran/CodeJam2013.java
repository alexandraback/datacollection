package codejam2013;

import java.io.IOException;

abstract public class CodeJam2013 {

    abstract public void solveCases(String inputSize) throws IOException;

    public static void main(String[] args) {
        String inputSize = "s";
        Round1AB.main(inputSize);
    }
}
