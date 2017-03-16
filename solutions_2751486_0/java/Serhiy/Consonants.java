package mp.kotter.challenges.gcj.round1c;

import mp.kotter.challenges.utils.LineCaseSolution;

public class Consonants extends LineCaseSolution {

    public static void main(final String[] args) throws Exception {
        (new Consonants()).run(args);
    }

    @Override
    protected String solveLine(final String line) {
        final String[] input = line.split(" ");
        final String str = input[0];
        final int n = Integer.parseInt(input[1]);

        int cStart = 0;
        int cPtr = 0;
        int sPtr = 0;

        long result = 0;

        while(cPtr <= str.length()) {
            if (cPtr - cStart < n || sPtr > cStart) {
                if (cPtr == str.length()) {
                    break;
                }
                if (!isConsonant(str.charAt(cPtr))) {
                    cStart = cPtr + 1;
                }
                cPtr++;
                if (cPtr - cStart> n) {
                    cStart = cPtr - n;
                }
            } else {
                result += (str.length() - cPtr + 1);
                sPtr++;
            }
        }

        return "" + result;
    }

    private boolean isConsonant(final char c) {
        return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
    }


}
