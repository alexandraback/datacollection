package codejam2016;

import java.util.*;
import java.io.*;

public class B {

    private static Scanner in;

    public static void main(String[] args) throws FileNotFoundException
    {
        //final File file = new File("D:\\Projects\\CodeJamPrep\\src\\input.txt");
        final File file = new File("C:\\Users\\Ilyes\\Downloads\\B-small-attempt1.in");
        //final File file = new File(args[0]);

        in = new Scanner(file);
        //Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        final int t = in.nextInt();

        for (int i = 0; i < t; i++) {
            final int b = in.nextInt();
            final int m = in.nextInt();
            System.out.print("Case #" + (i + 1) + ": ");
            calc(b, m);
            
        }  
    }

    private static void calc(final int b, final int m)
    {
        final int[][] map = new int[b][b];
        if (b == 2)
        {
            if (m > 1)
                System.out.println("IMPOSSIBLE");
            else if (m == 1)
            {
                map[0][1] = 1;
                System.out.println("POSSIBLE");
                printMap(map);
            }
            else
            {
                System.out.println("POSSIBLE");
                printMap(map);
            }
            
            return;
        }
        
        // b >= 3
        int k = 3;
        int remWays = m;
        
        if (remWays > 0)
        {
            remWays--;
            map[0][1] = 1;
            map[1][2] = 1;
        }
        
        if (remWays == 0)
        {
            System.out.println("POSSIBLE");
            printMap(map);
            return;
        }

        if (b >= 4)
        {
            if (remWays > 0)
            {
                remWays--;
                map[1][2] = 1;
            }
            if (remWays > 0)
            {
                remWays--;
                map[0][2] = 1;
            }
            if (remWays == 0)
            {
                System.out.println("POSSIBLE");
                printMap(map);
                return;
            }
        }

        if (b >= 5)
        {
            if (remWays > 0)
            {
                remWays--;
                map[0][3] = 1;
            }
            if (remWays == 2 || remWays >= 3)
            {
                remWays-=2;
                map[2][3] = 1;
            }
            if (remWays > 0)
            {
                remWays--;
                map[1][3] = 1;
            }
            if (remWays == 0)
            {
                System.out.println("POSSIBLE");
                printMap(map);
                return;
            }
        }

        if (b >= 6)
        {
            if (remWays == 7)
            {
                remWays--;
                map[1][4] = 1;
            }
            if (remWays == 1 || remWays == 4 || remWays >= 6)
            {
                remWays--;
                map[0][4] = 1;
            }
            if (remWays == 2 || remWays == 5 || remWays >= 6)
            {
                remWays-=2;
                map[2][4] = 1;
            }
            if (remWays == 3 || remWays == 4 || remWays == 5 || remWays >= 6)
            {
                remWays-=3;
                map[3][4] = 1;
            }
            if (remWays == 0)
            {
                System.out.println("POSSIBLE");
                printMap(map);
                return;
            }
        }

        System.out.println("IMPOSSIBLE");

        // calculate max possible ways
//        int fact = 1;
//        for (int i = 2; i <= b - 2; i++)
//        {
//            fact = (fact + 1) * i;
//        }
//        final int possibilities = fact + 1;
//        System.out.println( m <= possibilities ? "POSSIBLE" : "IMPOSSIBLE");
//        if (m <= possibilities)
//            printAllSlides(b);
    }

    private static void printMap(final int[][] map)
    {
        for (int i = 0; i < map.length; i++)
        {
            for (int j = 0; j < map[i].length; j++)
            {
                System.out.print("" + map[i][j]);
            }
            System.out.println();
        }
    }
}
