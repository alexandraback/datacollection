import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
    private Scanner in;
    private PrintWriter out;
    private int numCases;

    public Osmos() {
        initIO();
        numCases = in.nextInt();
        in.nextLine();
        for (int i = 0; i < numCases; i++) {
            out.printf("Case #%d: ", i + 1);
            solve();
            out.println();
        }
    }

    private void solve() {
        long size = in.nextInt();
        int numMotes = in.nextInt();
        int[] motes = new int[numMotes];
        for (int i = 0; i < numMotes; i++) {
            motes[i] = in.nextInt();
        }
        Arrays.sort(motes);
        int numOperations = 0;
        //if the mote is bigger than all other motes no change needs to be made
        if (size > motes[numMotes - 1]) {
            out.print(numOperations);
        } else {
            int i = 0;
            //get i to the point where motes[i] > size
            while (i < numMotes && size > motes[i]) {
                size += motes[i];
                ++i;
            }
            //handle motes larger than size
            while (i < numMotes) {
                if (size > motes[i]) {
                    size += motes[i];
                    i++;
                } else if (size <= motes[i] && size * 2 - 1 > motes[i]) {
                    size *= 2;
                    numOperations++;
                } else if (size <= motes[i] && size * 2 - 1 <= motes[i]) {
                    int numSteps = 0; //number of steps required to make size > motes[i]
                    boolean failed = false; //has size been less than any of the motes along the way
                    long tempSize = size;
                    while (tempSize <= motes[i] && !failed) {
                        tempSize += tempSize - 1;
                        numSteps++;
                        if (i + numSteps >= numMotes) {
                            failed = true;
                            motes[i] = 0;
                            numOperations++;
                        }
                    }
                    if (!failed) {
                        for (int j = 0; j < numSteps; j++) {
                            tempSize += motes[i + j];
                        }
                        if (tempSize <= motes[i + numSteps]){ //was not worth it to increase size
                            failed = true;
                            motes[i] = 0;
                            numOperations++;
                        }
                    }
                    if (!failed) {
                        for (int j = 0; j < numSteps; j++) {
                            size += size - 1;
                            numOperations++;
                        }
                    }
                }
            }
            out.print(numOperations);
        }
    }

    private void initIO() {
        in = new Scanner(System.in);
        try {
            String desktopPath = System.getProperty("user.home") + "/Desktop/output.txt";
            out = new PrintWriter(new BufferedWriter(new FileWriter(desktopPath)),
                    true);
        } catch (IOException ignored) {
        }
    }

    public static void main(String[] args) {
        new Osmos();
    }
}
