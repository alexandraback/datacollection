import java.io.*;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * @author ayzen
 */
public class Osmos {

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(new File("/home/ayzen/in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("/home/ayzen/out"));

        int count = in.nextInt();
        for (int index = 1; index <= count; index++) {
            long aSize = in.nextLong();
            int otherNum = in.nextInt();

            long[] other = new long[otherNum];
            for (int j = 0; j < otherNum; j++)
                other[j] = in.nextLong();

            Arrays.sort(other);

            int pointer = 0;
            long times = 0;
            PriorityQueue<Long> answers = new PriorityQueue<Long>();

            while (pointer < otherNum) {
                if (aSize > other[pointer])
                    aSize += other[pointer++];
                else {
                    if (aSize + aSize - 1 > other[pointer]) {
                        aSize += aSize - 1 + other[pointer++];
                        times++;
                    }
                    else {
                        answers.add(times + otherNum - pointer);
                        if (aSize <= 1)
                            break;

                        aSize += aSize - 1;
                        times++;
                    }
                }
            }
            if (aSize != 1)
                answers.add(times);

            out.write("Case #" + index + ": " + answers.poll() + '\n');
        }
        out.close();
    }

}
