#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long int get_number_in_base(long int number, int base)
{
    long int ans = 0;
    int j = 0;
    while(number != 0)
    {
        ans += (number&1)*pow(base,j);
        number = number >> 1;
        j++;
    }
    return ans;
}

string binary(int num)
{
    string bin = "";
    while(num!=0)
    {
        num%2 == 0 ? bin.insert(bin.begin(),'0') : bin.insert(bin.begin(),'1');
        num /= 2;
    }
    return bin;
}

long int check_prime(long int number)
{
    //check if number is prime
    long int lim = (int) ceil(sqrt(number));
    for(long int i=2; i<=lim; i++)
        if(number%i == 0)
            return i;
    return -1;
}

void find_jams(int N, int J)
{
    long int upper_limit = 1;
    for(long int i=1; i<N; i++)
        upper_limit = (upper_limit << 1) + 1;
    long int lower_limit = 1 << (N-1);
    long int num_base = 0;
    int num_jams = 0;
    long int divisors[9];
    bool flag = false;
    //cout << upper_limit << " " << lower_limit << endl;
    //cout << lower_limit << " " << binary(lower_limit) << endl;
    for(long int i=lower_limit; i<=upper_limit; i++)
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
        cout << binary(i) << " ";
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
    find_jams(N,J);
}

