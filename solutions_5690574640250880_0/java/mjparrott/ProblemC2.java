// Minesweeper Master
import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;
class Node
{
    public int r;
    public int c;
    public Node(int rr, int cc) { r = rr; c = cc; }
}
public class ProblemC2
{
    
    public static int[] dr = { -1, -1, 0, 1, 1, 1, 0, -1 };
    public static int[] dc = { 0, 1, 1, 1, 0, -1, -1, -1 };
    public static int[] nsewR = {-1, 0, 1, 0};
    public static int[] nsewC = {0, 1, 0, -1};
    public static int r;
    public static int c;
    public static Node foundNode = null;
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        for(int i = 0; i < t; i++)
        {
            foundNode = null;
            r = in.nextInt();
            c = in.nextInt();
            int m = in.nextInt();

            char[][] arr = new char[r][c];
            for(int j = 0; j < r; j++)
            {
                Arrays.fill(arr[j], '.');
            }
            for(int rr = 0; rr < r; rr++)
            {
                for(int cc = 0; cc < c; cc++)
                {
                    if(foundNode == null)
                    {
                        recurse(m, arr, rr, cc);
                    }
                }
            }
            System.out.printf("Case #%d:\n", i + 1);
            if(foundNode == null)
            {
                System.out.println("Impossible");
            }
            else
            {
                arr[foundNode.r][foundNode.c] = 'c';
                printCharGrid(arr);
            }
        }

        in.close();
    }

    public static void recurse(int m, char[][] arr, int curR, int curC)
    {
        if(curR < 0 || curR >= r || curC < 0 || curC >= c)
            return;
        if(arr[curR][curC] == '*')
            return;
        if(foundNode != null)
        {
            return;
        }
        if(m == 0)
        {
            int[][] counts = new int[r][c];
            for(int rr = 0; rr < r; rr++)
            {
                for(int cc = 0; cc < c; cc++)
                {
                    if(arr[rr][cc] == '*')
                    {
                        for(int i = 0; i < dr.length; i++)
                        {
                            int newR = rr + dr[i];
                            int newC = cc + dc[i];
                            if(!(newR < 0 || newR >= r || newC < 0 || newC >= c))
                            {
                                counts[newR][newC]++;
                            }
                        }
                    }
                }
            }
            Node n = checkArr(arr, counts);
            if(n != null)
            {
                foundNode = n;
                return;
            }
        }
        arr[curR][curC] = '*';
        for(int i = 0; i < 4 && foundNode == null; i++)
        {
            recurse(m - 1, arr, curR + nsewR[i], curC + nsewC[i]);
        }
        if(foundNode == null)
            arr[curR][curC] = '.';
    }

    public static Node checkArr(char[][] arr, int[][] counts)
    {
        for(int rr = 0; rr < r; rr++)
        {
            for(int cc = 0; cc < c; cc++)
            {
                if(arr[rr][cc] != '*')
                {
                    boolean[][] visited = new boolean[r][c];
                    LinkedList<Node> ll = new LinkedList<Node>();
                    ll.addFirst(new Node(rr, cc));
                    while(ll.size() != 0)
                    {
                        Node curN = ll.removeLast();
                        if(curN.r < 0 || curN.r >= r || curN.c < 0 || curN.c >= c)
                            continue;
                        if(arr[curN.r][curN.c] == '*')
                            continue;
                        if(visited[curN.r][curN.c])
                            continue;
                        visited[curN.r][curN.c] = true;
                        if(counts[curN.r][curN.c] == 0)
                        {
                            for(int i = 0; i < dr.length; i++)
                            {
                                ll.addFirst(new Node(curN.r + dr[i], curN.c + dc[i]));
                            }
                        }
                    }

                    boolean valid = true;
                    for(int rrr = 0; rrr < r; rrr++)
                    {
                        for(int ccc = 0; ccc < c; ccc++)
                        {
                            if(arr[rrr][ccc] == '.')
                            {
                                if(!visited[rrr][ccc])
                                    valid = false;
                            }
                        }
                    }
                    if(valid)
                        return new Node(rr, cc);
                }
            }
        }

        return null;
    }

    public static void printCharGrid(char[][] arr)
    {
        for(int i = 0; i < arr.length; i++)
        {
            System.out.println(new String(arr[i]));
        }
    }
}
