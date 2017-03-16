#include <bits/stdc++.h>

#define REP(i,x) for(uint64 i = 0 ; i < (x) ; i++)

#ifdef DEBUG_MODE
#define print(x) cout << #x << " = " << x << endl
#define debug(x) x
#else
#define print(x)
#define debug(x)
#endif

#define hash_map      unordered_map
#define hash_multimap unordered_multimap
#define hash_set      unordered_set
#define hash_multiset unordered_multiset


typedef unsigned long long uint64;

using namespace std;

class Application
{
public:
    inline void Run();
private:
    // Methods
    inline void LoadData();
    inline uint64 Solve();
    
    // Fields
    uint64 C, number_count, max_value;
    vector <uint64> nominals;
};

int main()
{
    ios_base::sync_with_stdio(false);
    Application app;
    app.Run();
}

inline void Application::LoadData()
{
    cin >> C >> number_count >> max_value;
    nominals.resize(number_count);
    
    REP(i, number_count)
    {
        cin >> nominals[i];
    }
}

inline uint64 Application::Solve()
{
    uint64 result = 0;
    uint64 act_nominal = 0;
    
    if(nominals[0] == 1)
        act_nominal = 1;
    else
        result = 1;
    
    uint64 seg_size = C;

    while(seg_size < max_value)
    {
        if(act_nominal < nominals.size() && nominals[act_nominal] - 1 <= seg_size)
        {
            seg_size += (nominals[act_nominal] * C);
            ++ act_nominal;
        } 
        else
        {
            seg_size += ((seg_size + 1) * C);
            ++ result;
        }
    }
    
    return result;
}

inline void Application::Run()
{
    uint64 test_number;
    cin >> test_number;
    
    REP(i, test_number)
    {
        LoadData();
        cout << "Case #" << i + 1 << ": " << Solve() << "\n";
    }
}
