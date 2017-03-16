#include <bits/stdc++.h>

using namespace std;

template<typename T>
ostream& operator << (ostream& o, vector<T>& v)
{
    o << "[";
    for(size_t i = 0; i < v.size(); i++)
    {
        o << v[i];
        if(i != v.size() - 1)
            o << ", ";
    }
    o << "]";
    return o;
}

long long int rev_int(long long int n)
{
    char buffer[4096];
    snprintf(buffer, 4096, "%lld", n);
    reverse(buffer, buffer + strlen(buffer));
    long long int tmp;
    sscanf(buffer, "%lld", &tmp);
    return tmp;
}

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int n_casi;
    cin >> n_casi;
    long long int input[n_casi + 1];
    long long int soluzione[n_casi + 1];
    for(int caso = 1; caso <= n_casi; caso++)
        cin >> input[caso];
    #pragma omp parallel for schedule(dynamic)
    for(int caso = 1; caso <= n_casi; caso++)
    {
        long long int n = input[caso];
        vector<long long int> occ;
        occ.resize(n+1, LLONG_MAX);
        occ[1] = 1;
        queue<long long int> next_eval;
        next_eval.push(1);
        while(!next_eval.empty())
        {
            long long int tmp = next_eval.front();
            next_eval.pop();
            if(tmp + 1LL <= n && occ[tmp + 1LL] > occ[tmp] + 1LL)
            {
                occ[tmp + 1LL] = occ[tmp] + 1LL;
                next_eval.push(tmp + 1LL);
            }
            long long int rev = rev_int(tmp);
            if(rev <= n && occ[rev] > occ[tmp] + 1LL)
            {
                occ[rev] = occ[tmp] + 1LL;
                next_eval.push(rev);
            }
        }
        soluzione[caso] = occ[n];
        cerr << "Case #" << caso << ": " << soluzione[caso] << endl;
    }
    for(int caso = 1; caso <= n_casi; caso++)
        cout << "Case #" << caso << ": " << soluzione[caso] << endl;
    return EXIT_SUCCESS;
}
