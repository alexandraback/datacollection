#include <iostream>
using namespace std;



int minimumWithExtra(int extra, int numberOfDiners, int* pancakes)
{
    int minimumPancakesWithExtra = 1000;

    int left = 1, right = 1000, mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        int needExtra = 0;
        for (int i = 1; i <= numberOfDiners; ++i)
            if (pancakes[i] > mid)
            {
                needExtra += (pancakes[i] + mid - 1) / mid - 1;
            }
        if (needExtra <= extra)
        {
            minimumPancakesWithExtra = minimumPancakesWithExtra < mid ? minimumPancakesWithExtra : mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return minimumPancakesWithExtra + extra;
}

int calculate(int numberOfDiners, int* pancakes)
{
    int best = 1000, maximumPancakes = pancakes[1];
    for (int i = 2; i <= numberOfDiners; ++i)
        if (maximumPancakes < pancakes[i])
            maximumPancakes = pancakes[i];
    best = maximumPancakes;

    for (int extra = 1; extra <= 1000; ++extra)
    {
        int needed = minimumWithExtra(extra, numberOfDiners, pancakes);
        if (needed < best)
            best = needed;
    }

    return best;
}

int main()
{
    int cases;
    cin >> cases;
    for (int t = 1; t <= cases; ++t)
    {
        int numberOfDiners, pancakes[2001];
        cin >> numberOfDiners;
        for (int i = 1; i <= numberOfDiners; ++i)
            cin >> pancakes[i];
        cout <<"Case #"<< t <<": "<< calculate(numberOfDiners, pancakes) << endl;
    }
    return 0;
}