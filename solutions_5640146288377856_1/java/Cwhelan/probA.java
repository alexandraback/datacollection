import java.util.*;

public class probA
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int tests = input.nextInt();
        for(int i = 1; i <= tests; i++)
        {
            int R = input.nextInt();
            int C = input.nextInt();
            int W = input.nextInt();

            System.out.printf("Case #%d: %d\n", i, minMoves(R, C, W));
        }
    }

    public static int minMoves(int R, int C, int W)
    {
        int moves = 0;
        moves += C/W;
        moves *= R;
        moves += W-1;
        if((C%W) != 0) moves++;
        return moves;
    }
}
