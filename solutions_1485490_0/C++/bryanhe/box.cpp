#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Production
{
public:
    long long number;
    long long type;

    Production()
    {
        number = -1;
        type = -1;
    }
    
    Production(long long number, long long type)
    {
        this->number = number;
        this->type = type;
    }
};

long long solve(vector<Production> boxes, vector<Production> toys);

int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    for(int counter = 1; counter <= T; counter++)
    {
        int N, M;
        cin >> N >> M;

        vector<Production> boxes;
        vector<Production> toys;
        for(int n = 0; n < N; n++)
        {
            long long a, A;
            cin >> a >> A;
            boxes.push_back(Production(a,A));
        }
        for(int m = 0; m < M; m++)
        {
            long long b, B;
            cin >> b >> B;
            toys.push_back(Production(b,B));
        }

        cout << "Case #" << counter << ": " << solve(boxes, toys) << "\n";
    }

    return 0;
}

long long solve(vector<Production> boxes, vector<Production> toys)
{
    if((int)boxes.size() == 0 || (int)toys.size() == 0)
    {
        return 0;
    }

    if(boxes[0].type == toys[0].type)
    {
        long long ans = min(boxes[0].number, toys[0].number);
        boxes[0].number -= ans;
        toys[0].number -= ans;
        if(boxes[0].number == 0)
        {
            boxes.erase(boxes.begin());
        }
        if(toys[0].number == 0)
        {
            toys.erase(toys.begin());
        }

        return ans + solve(boxes, toys);
    }

    Production temp = boxes[0];
    boxes.erase(boxes.begin());
    long long a = solve(boxes, toys);
    boxes.insert(boxes.begin(), temp);
    toys.erase(toys.begin());
    long long b = solve(boxes, toys);
    return max(a, b);
}

