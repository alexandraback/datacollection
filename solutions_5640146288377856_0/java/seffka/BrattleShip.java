import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class BrattleShip
{
    private int R, C, W;

    public BrattleShip(int r, int c, int w)
    {
        R = r;
        C = c;
        W = w;
    }

    public int findMin()
    {
        PriorityQueue<Integer> heap = new PriorityQueue<>();

        int tries = 0;
        for (int i = W - 1; i < C; i += W)
        {
            tries++;

            if (i < (C - 1))
                heap.add( -(tries + W));
            else
                heap.add( -(tries + W - 1));
        }

        return -heap.element();
    }

    public static void main(String[] args)
        throws Exception
    {
        try (Scanner sc = new Scanner(new File(args[0]));
             BufferedWriter writer = new BufferedWriter(new FileWriter(args[0] + ".out")))
        {
            int T = sc.nextInt();

            for (int i = 1; i <= T; i++)
            {
                int R = sc.nextInt();
                int C = sc.nextInt();
                int W = sc.nextInt();
                System.out.println(i);
                writer.write("Case #" + i + ": " + new BrattleShip(R, C, W).findMin());
                writer.newLine();
            }
        }
    }
}
