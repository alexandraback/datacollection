#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long long int get_number_in_base(long long int number, int base)
{
    long long int ans = 0;
    int j = 0;
    while(number != 0)
    {
        ans += (number&1)*pow(base,j);
        number = number >> 1;
        j++;
    }
    return ans;
}

string binary(long long int num)
{
    string bin = "";
    while(num!=0)
    {
        num%2 == 0 ? bin.insert(bin.begin(),'0') : bin.insert(bin.begin(),'1');
        num /= 2;
    }
    return bin;
}

long long int check_prime(long long int number)
{
    //check if number is prime
    long long int lim = (long long int) ceil(sqrt(number));
    for(long long int i=2; i<=lim; i++)
        if(number%i == 0)
            return i;
    return -1;
}

void find_jams(int N, int J)
{
    long long int upper_limit = 1;
    for(int i=1; i<N; i++)
        upper_limit = (upper_limit << 1) + 1;
    long long int lower_limit = 1 << (N-1);
    long long int num_base = 0;
    int num_jams = 0;
    long long int divisors[9];
    bool flag = false;
    for(long long int i=lower_limit; i<=upper_limit; i++)
    {
        if(num_jams == J)
            return;
        if(i%2 == 0) continue;
        flag = false;
        for(int j=2; j<=10; j++)
        {
            num_base = get_number_in_base(i,j);
            divisors[j-2] = check_prime(num_base);
            if(divisors[j-2]<0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        num_jams++;
        cout << binary((i << N) + i) << " ";
        for(int j=0; j<9; j++)
            cout << divisors[j] << " ";
        cout << endl;
    }
}

int main()
{
    int T, N, J;
    cin >> T >> N >> J;
    cout << "Case #1:" << endl;
    find_jams(N/2,J);
}

