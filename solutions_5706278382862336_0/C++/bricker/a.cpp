#include <stdio.h>
#include <iostream>

using namespace std;

long long int table[40]={0};

long long int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}


int main()
{
    int round;
    int count =1;
    long long int up;
    long long int down;
    int i;
    //float num;
    int result;
    cin >> round;
    long long int k = 2;
    for(int i=0; i<40; i++)
    {
        table[i] = k;
        k *= 2;
    }

    while(count <= round)
    {
        result = 0;
        scanf("%lld/%lld", &up, &down);
        long long int common  = gcd(up, down);
        //cout << "GCD: "<< common << endl;
        if(common != 1)
        { up /= common; down /= common;}
        if(down % 2 != 0)
            result = -1;
        if(result != -1)
        {
            for(i=0; i<40; i++)
            {
                if(down == table[i])
                    break;
            }
            if(i == 40)
            {result = -1;}
        }

        if(result != -1)
        {
            while(result <= 40)
            {
                if(up >= down)
                {
                    break;
                }
                else
                {
                    result++;
                    up *= 2;
                }
            }
        }
        if (result == -1)
            cout << "Case #" << count << ": impossible" << endl;
        else
            cout << "Case #" << count << ": " << result << endl;
        count++;
    }
    return 0;
}
