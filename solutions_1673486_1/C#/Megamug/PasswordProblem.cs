using System.Collections.Generic;
using System;

class PasswordProblem
{
    FileUtil file;

    public PasswordProblem()
    {
        file = new FileUtil("in.txt", "out.txt");
    }

    public void solve()
    {
        int numTests = file.readInt();

        for (int i = 0; i < numTests; i++)
        {
            solveTest(i + 1);
        }

        file.close();
    }

    public void solveTest(int testNumber)
    {
        long A = file.readLong();
        long B = file.readLong();

        List<double> probs = new List<double>();
        for (long a = 0; a < A; a++)
        {
            probs.Add(file.readDouble());
        }

        List<double> costs = new List<double>();
        for (long bksp = 0; bksp < A; bksp++)
        {
            costs.Add(getExpectedCost(A, bksp, B, probs));
        }

        //add an extra for pressing enter immediatly
        costs.Add(B + 2);

        double min = double.MaxValue;

        foreach (double cost in costs)
        {
            min = Math.Min(min, cost);
        }

        file.writeCase(testNumber);
        file.writeDoubleLine(min);
    }

    public double getExpectedCost(long entered, long bksp, long length, List<double> probs)
    {
        long numRight = entered - bksp;
        double rightProb = 1;
        for (int i = 0; i < numRight; i++)
        {
            rightProb *= probs[i];
        }

        double wrongProb = 1.0 - rightProb;

        double rightCost = bksp * 2 + (length - entered) + 1;
        double wrongCost = bksp * 2 + (length - entered) + length + 2;

        return rightProb * rightCost + wrongProb * wrongCost;
    }
}
