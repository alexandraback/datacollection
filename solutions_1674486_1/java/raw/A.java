import java.util.Scanner;

class A
{
    boolean[][] inherits;

    void read(Scanner sc)
    {
        int n = sc.nextInt();
        inherits = new boolean[n][n];
        for (int i = 0; i < n; i++)
        {
            int m = sc.nextInt();
            for (int j = 0; j < m; j++)
            {
                inherits[i][sc.nextInt()-1] = true;
            }
        }
    }

    boolean solve()
    {
        for (int k = 0; k < inherits.length; k++)
        {
            for (int i = 0; i < inherits.length; i++)
            {
                for (int j = 0; j < inherits.length; j++)
                {
                    if (i != j && inherits[i][k] && inherits[k][j])
                    {
                        if (inherits[i][j])
                        {
                            return true;
                        }
                        inherits[i][j] = true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        A solver = new A();
        int numCases = sc.nextInt();
        for (int i = 0; i < numCases; i++)
        {
            solver.read(sc);
            System.out.print("Case #" + (i+1) + ": ");
            System.out.println(solver.solve() ? "Yes" : "No");
        }
    }
}
