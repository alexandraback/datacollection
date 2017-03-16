#include <bits/stdc++.h>
#include <gmpxx.h>

using namespace std;

typedef mpz_class mpz;

mpz first_factor(const mpz& i)
{
    time_t start = time(nullptr);
    if(i % 2 == 0)
        return 2;
    mpz sq = sqrt(i) + 4_mpz;
    for(mpz j = 3; j < sq; j++)
    {
        if(i % j == 0)
            return j;
        if(time(nullptr) - start > 1)
            return i;
    }
    return i;
}

int main()
{
    const long long int n = 32;
    long long int j = 500;
    long long int num = (1LL << (n - 1)) + 1;
    vector<mpz> sol;
    while(sol.size() / 10 < j)
    {
        vector<mpz> v(9, 0_mpz);
        bitset<n> b(num);
        #pragma omp parallel for schedule(dynamic)
        for(long long int i = 2; i <= 10; i++)
        {
            mpz local_num(b.to_string(), i);
            if(mpz_probab_prime_p(local_num.get_mpz_t(), 30))
            {
                v[i - 2] = 0_mpz;
                continue;
            }
            auto ret = first_factor(local_num);
            if(ret == local_num)
                v[i - 2] = 0_mpz;
            else
                v[i - 2] = ret;
        }
        if(count(v.begin(), v.end(), 0_mpz) == 0)
        {
            sol.push_back(mpz(to_string(num)));
            for(auto& i: v)
                sol.push_back(i);
        }
        cerr << "Found " << sol.size() / 10 << "/" << j << endl;
        num += 2;
    }
    cout << "Case #1:" << endl;
    for(long long int i = 0; i < (long long int)sol.size() / 10; i++)
    {
        bitset<n> b(sol[i * 10].get_ui());
        cout << b.to_string() << " ";
        for(long long int j = (i * 10) + 1; j < (i + 1) * 10; j++)
            cout << sol[j] << " ";
        cout << endl;
    }
    return 0;
}
