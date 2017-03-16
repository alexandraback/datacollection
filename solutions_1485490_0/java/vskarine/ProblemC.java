package contests.GoogleCodeJam.GCJ2012.round1C;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 */
public class ProblemC {

    static class Pair implements Comparable<Pair> {
        public long left, right;

        public Pair(long anlong, long anlong1) {
            left = anlong;
            right = anlong1;
        }

        @Override
        public int compareTo(Pair pair) {
            if (pair.left < left)
                return 1;
            if (pair.left > left)
                return -1;

            if (pair.right < right)
                return -1;
            if (pair.right > right)
                return 1;

            return 0;
        }
    }

    public static long total;
    public static long bestSum;

    public static void solve(List<Pair> boxList, List<Pair> toyList, int numBox, int numToy, long sum){
        if(numBox == total){
            if(bestSum < sum)
                bestSum=sum;
            return ;
        }

        //skip
        solve(boxList, toyList, numBox+1,numToy,sum);

        List<Pair> tempToyList = new ArrayList<Pair>();
        for(int t = 0;t <toyList.size(); t++)
            tempToyList.add(new Pair(toyList.get(t).left, toyList.get(t).right));

        long boxesLeft = boxList.get(numBox).left;
        long box = boxList.get(numBox).right;

        for(;numToy < tempToyList.size(); numToy++){
            if(tempToyList.get(numToy).right == box){
                long delta = Math.min(tempToyList.get(numToy).left, boxesLeft);
                sum += delta;
                boxesLeft -= delta;
                tempToyList.get(numToy).left-=delta;

                solve(boxList, tempToyList, numBox+1, numToy, sum);
                if(boxesLeft == 0)
                    break;
            }
        }
    }



    public static void main(String args[]) throws FileNotFoundException {
        Scanner scanner = new Scanner(ProblemC.class.getResourceAsStream("c_small.in"));

        long tests = scanner.nextLong();

        for (long test = 1; test <= tests; test++) {
            long n = scanner.nextLong();
            total = n;
            long m = scanner.nextLong();

            bestSum = 0;

            List<Pair> boxList = new ArrayList<Pair>();
            for(long i = 0; i < n; i++)
                boxList.add(new Pair(scanner.nextLong(), scanner.nextLong()));

            List<Pair> toyList = new ArrayList<Pair>();
            for(long i = 0; i < m; i++)
                toyList.add(new Pair(scanner.nextLong(), scanner.nextLong()));

            solve(boxList,toyList,0,0,0);

            System.out.println("Case #" + test + ": " + bestSum );
        }

    }
}


