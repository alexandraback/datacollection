#include <iostream>

using namespace std;

// For <= 20:
    // num
// For > 20, < 100
// For >= 100:
    // 19 -> 91
// For >= 1000:
    // 109 -> 901
// For >= 10000:
    // 1099 -> 9901
// For >= 100000:
    // 10099 -> 99001
// Etc...

long long GetNext10Pow(long long num)
{
    long long ret = 1;
    
    while (num)
    {
        ret *= 10;
        num /= 10;
    }
    
    return ret;
}

int GetNumLen(long long num)
{
    int len = 0;
    while (num)
    {
        num /= 10;
        ++len;
    }
    
    return len;
}

long long Reverse(long long num)
{
    long long newNum = 0;
    
    while (num)
    {
        newNum = (newNum * 10 + num % 10);
        num /= 10;
    }
    
    return newNum;
}

void GoToTenPow(long long nextTenPow, long long &current, long long &cost)
{
    int len = GetNumLen(current);
    
    long long mult = 1;
    for (int i = 0; i < len / 2; ++i)
    {
        long long increase = mult * 9;
        current += increase;
        cost += increase;
        mult *= 10;
    }
    
    current = Reverse(current);
    
    // 1 is from the Reverse
    cost += 1 + nextTenPow - current;
    current = nextTenPow;
}

long long CalculateReversedDiffNonZero(long long wanted, long long current)
{
    // Know they have the same number of digits
    // Want to make the (reversed) last len / 2 digits of current equal reversed
    // of wanted
    long long reversedWanted = Reverse(wanted);
    
    long long len = GetNumLen(current);
    long long usedLen = len / 2;
    long long modVal = 1;
    
    while (usedLen)
    {
        modVal *= 10;
        --usedLen;
    }
    
    // The first len / 2 are corrects
    
    long long diff = (reversedWanted - current) % modVal;
    
    // Last len / 2 will be 0
    // Pretty sure they can be combined
    long long reversedCurrent = current - (current % modVal) + (reversedWanted % modVal);
    reversedCurrent = Reverse(reversedCurrent);
    return diff + 1 + wanted - reversedCurrent;
}

void GoToNum(long long wanted, long long &current, long long &cost)
{
    long long basicDiff = wanted - current;
    long long reversedDiff;
    
    if (wanted % 10 != 0)
        reversedDiff = CalculateReversedDiffNonZero(wanted, current);
    else
        reversedDiff = CalculateReversedDiffNonZero(wanted - 1, current) + 1;
    
    
    if (basicDiff < reversedDiff)
        cost += basicDiff;
    else
        cost += reversedDiff;
    
    current = wanted;
}

// Assumes current is a power of 10
void UpdateCurrentToNextBest(const long long wanted, long long &current, long long &cost)
{
    long long nextTenPow = GetNext10Pow(current);
    if (nextTenPow < wanted)
    {
        // Pointless to try to skip it
        GoToTenPow(nextTenPow, current, cost);
    }
    else
    {
        GoToNum(wanted, current, cost);
    }
}

int main()
{
    int T;
    
    cin >> T;
    
    
    for (int t = 1; t <= T; ++t)
    {
        long long num;
        cin >> num;
        long long cost = num;
        
        if (num > 20)
        {
            long long current = 10;
            cost = current;
            while (current != num)
            {
                UpdateCurrentToNextBest(num, current, cost);
            }
        }
        
        cout << "Case #" << t << ": " << cost << '\n';
    }
    
}