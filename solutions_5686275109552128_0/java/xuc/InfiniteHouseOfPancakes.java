package InfiniteHouseOfPancakes;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by xuchen on 4/10/15.
 */
public class InfiniteHouseOfPancakes {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("src/InfiniteHouseOfPancakes/B-small-attempt3.in"));
            PrintWriter writer = new PrintWriter(new File("src/InfiniteHouseOfPancakes/result1.txt"));

            int caseCnt = scanner.nextInt();

            for (int i = 0; i < caseCnt; i++){

                int peopleCnt = scanner.nextInt();
                int timeCnt = Integer.MAX_VALUE;

                List<Integer> list = new ArrayList<Integer>();

                for (int j = 0; j < peopleCnt; j++){
                    list.add(scanner.nextInt());
                }

                for (int cakeNum = 1; cakeNum <= 1000; cakeNum++){

                    int cnt = cakeNum;

                    for (int m = 1; m <= peopleCnt; m++){

                        cnt += (int)Math.ceil(list.get(m - 1) / (float)cakeNum) - 1;

                    }

                    timeCnt = Math.min(timeCnt,cnt);
                }

                writer.println("Case #" + (i + 1) + ": " + timeCnt);
            }

            writer.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
