import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

import static java.lang.System.exit;

/**
 * Created with IntelliJ IDEA.
 * User: Tanner
 * Date: 4/13/13
 * Time: 1:40 PM
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam {

    static final double PI = Math.PI;

    public static void main(String[] args) {

        if (args.length == 0) {
            System.out.println("Need input file.");
            exit(0);
        }
        BufferedReader breader = null;
        BufferedWriter bwriter = null;


        try {
            breader = new BufferedReader(new FileReader(args[0]));
            bwriter = new BufferedWriter(new FileWriter(args[0].replace(".in",".out")));

            int cases = Integer.parseInt(breader.readLine());

            for (int c = 1; c<=cases; c++) {

                String[] input = breader.readLine().split(" ");
                int mote = Integer.parseInt(input[0]);
                int numOfOthers = Integer.parseInt(input[1]);

                input = breader.readLine().split(" ");
                ArrayList<Integer> others = new ArrayList<Integer>();
                for (String s : input) {
                    others.add(Integer.parseInt(s));
                }
                Collections.sort(others);

                int count = 0;
                boolean first = true;
                int index = 0;
                for (int i = 0; i<numOfOthers; i++) {
                    if (others.get(i) < mote) {
                        mote += others.get(i);
                    } else if (others.get(i) >= mote) {
                        if (first) {
                            index = i;
                            first = false;
                        }
                        int tempCount = 0;
                        while (mote <= others.get(i)) {
                            if (mote -1 == 0) {
                                tempCount = 10000000;
                                break;
                            }
                            mote += mote - 1;
                            tempCount++;
                        }
                        mote += others.get(i);
                        if (tempCount < numOfOthers - i) {
                            count += tempCount;
                        } else {
                            count += numOfOthers - i;
                            break;
                        }
                    }
                }
                if (numOfOthers - index < count) {
                    count = numOfOthers - index;
                }
                bwriter.write("Case #" + c + ": " + count + "\n");

            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                bwriter.close();
                breader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
