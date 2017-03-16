package passwordproblem;


public class PasswordProblem {

    static SimpleReader reader;
    static SimpleWriter writer;
    
    static int typed;
    static int total;
    static double[] chanceCorrect;

    public static void main(String[] args) {
        if (args.length != 1) {
            reader = new SimpleReader();
            writer = new SimpleWriter();
        } else {
            reader = new SimpleReader(args[0]);
            writer = new SimpleWriter(args[1]);
        }
        int cases = reader.readInt();
        for (int i = 0; i < cases; i++) {
            int[] read = reader.readIntArray();
            typed = read[0];
            total = read[1];
            chanceCorrect = reader.readDoubleArray();
            
            solve(i + 1);
            System.out.println("Case " + (i + 1) + " done");
        }
        writer.flush();
        System.out.println("Done");
    }
    
    private static void solve(int caseNo) {
        double chanceAllCorrect = 1;
        for (int i = 0; i < typed; i++) {
            chanceAllCorrect *= chanceCorrect[i];
        }
        double keepTyping = (total - typed + 1) * chanceAllCorrect + 
                (total + (total - typed) + 2) * (1 - chanceAllCorrect);
        System.out.println("keep typing: " + keepTyping);
        
        double pressEnter;
        if (typed == total) {
            pressEnter = total + 2 * (1 - chanceAllCorrect);
        } else {
            pressEnter = total + 2;
        }
        System.out.println("press enter: " + pressEnter);
        
        double[] backspace = new double[typed];
        for (int i = 0; i < typed; i++) {
            // pressing backspace i + 1 times
            double chanceAllCorrectUpToi = 1;
            for (int j = 0; j < typed - 1 - i; j++) {
                chanceAllCorrectUpToi *= chanceCorrect[j];
            }
            backspace[i] = (i + 1) + (total - typed + i + 1) + 1 + 
                    (1 - chanceAllCorrectUpToi) * (total + 1);
            System.out.println("backspace " + (i + 1) + ": " + backspace[i]);
        }
        
        double min = Math.min(keepTyping, pressEnter);
        for (int i = 0; i < typed; i++) {
            if (backspace[i] < min) {
                min = backspace[i];
            }
        }
        
        writer.writeLine("Case #" + caseNo + ": " + min);
    }
}
