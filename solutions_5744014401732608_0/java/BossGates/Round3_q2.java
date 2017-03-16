import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by BG2Air on 5/8/16.
 */
public class Round3_q2 {

    public static ArrayList<Integer> subset_index;
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();

        for(int t=1;t<=T;t++)
        {
            int B = scanner.nextInt();
            long M = scanner.nextLong();
            subset_index = new ArrayList<>();


            long[] num = new long[B];
            num[0] = 1;
            num[1] = 1;
            for(int i=2;i<B-1;i++) {
                for(int j=1;j<i;j++)
                    num[i] += num[j];

                num[i] = num[i]+1;
            }
            num[B-1] = 999999999;

            // Find sum of M in num
            boolean isFound = SubsetSum(num, B, M, 0, new int[B]);

            if(!isFound)
                System.out.printf("Case #%d: IMPOSSIBLE\n",t);
            else
            {
                // line 1
                System.out.printf("Case #%d: POSSIBLE\n", t);
                for(int i=0;i<B;i++)
                {
                    if(subset_index.contains(B-i-1))
                        System.out.print('1');
                    else
                        System.out.print('0');
                }
                System.out.println();

                for(int i=1;i<B-1;i++)
                {
                    for(int j=0;j<B;j++)
                    {
                        if(j > i)
                            System.out.print('1');
                        else
                            System.out.print('0');
                    }

                    System.out.println();
                }

                // last line
                for(int i=0;i<B;i++) {
                    System.out.print('0');
                }
                System.out.println();

            }
        }
    }

    public static boolean SubsetSum(long[] set, int n, long sum, int count, int[] list)
    {
        if (sum == 0) {
            for(int i=0;i<count;i++)
                subset_index.add(list[i]);
            return true;
        }
        if (n == 0 && sum != 0)
            return false;

        if (set[n-1] > sum)
            return SubsetSum(set, n-1, sum, count, list);

        boolean isFound = false;
        isFound = SubsetSum(set, n-1, sum, count, list);
        if(!isFound) {
            list[count] = n - 1;
            isFound = SubsetSum(set, n - 1, sum - set[n - 1], count + 1, list);
        }
        return isFound;
    }
}
