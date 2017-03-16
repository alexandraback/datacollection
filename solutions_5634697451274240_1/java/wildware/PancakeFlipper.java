package software.wild.qualification.pancake;


import org.testng.annotations.Test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

import static java.lang.Integer.parseInt;
import static org.testng.Assert.assertEquals;

public class PancakeFlipper {

    public static void main(String[] args) throws Exception {
        String baseURL = args[0];
        String inFileName = "pancake_large.in";

        consumeInput(baseURL, inFileName);
    }

    public static void consumeInput(String baseURL, String inFileName) throws Exception {
        String outFileNAme = inFileName.split("\\.")[0] + ".out";
        try (
                BufferedReader reader = new BufferedReader(new FileReader(new File(baseURL, inFileName)));
                PrintWriter writer = new PrintWriter(new File(baseURL, outFileNAme))
        ) {
            Integer numTests = parseInt(reader.readLine());
            for(int i=0; i<numTests; i++) {
                String stack = reader.readLine();
                String answer = solve(stack);
                writer.println(String.format("Case #%d: %s", i+1, answer));
            }
        }
    }

    @Test
    public void testSolver() {
        assertEquals(solve("-"), "1");
        assertEquals(solve("-+"), "1");
        assertEquals(solve("+-"), "2");
        assertEquals(solve("+++"), "0");
        assertEquals(solve("--+-"), "3");
        assertEquals(solve("+-------------"), "2");
        assertEquals(solve("-------------+"), "1");
        assertEquals(solve("-----+--------"), "3");
        assertEquals(solve("+++++-++++++++++"), "2");
        assertEquals(solve("+-++++++++++++++"), "2");
        assertEquals(solve("-+++++++++++++++"), "1");
        assertEquals(solve("+++++++++++++++-"), "2");
        assertEquals(solve("-+-+-"), "5");
        assertEquals(solve("-+-+-+"), "5");
        assertEquals(solve("-+---+"), "3");
        assertEquals(solve("-+---+-"), "5");
        assertEquals(solve("+-----+-"), "4");
        assertEquals(solve("+---+----+"), "4");
        assertEquals(solve("--+++-+"), "3");
    }

    public static String solve(String stack) {
        Integer flips = calculateMinFlips(stack);
        return flips.toString();
    }

    public static Integer calculateMinFlips(String stack) {
        int len = stack.length();
        if(len == 0 || !stack.contains("-"))
            return 0;
        else if(!stack.contains("+"))
            return 1;

        if(len == 2) {
            return stack.startsWith("+") ? 2: 1;
        }

        char d = stack.charAt(0) == '+' ? '-' : '+';

        int splitPoint = stack.indexOf(d);
        return 1 + calculateMinFlips(stack.substring(splitPoint));
    }
}
