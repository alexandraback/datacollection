#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory>
#include <cassert>
#include <set>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;

#define ALL(x) begin(x), end(x)

#define FORI(i,a,b)   for (decay_t<decltype(b)> i=a, _b=b; i <  _b; ++i)
#define FORLE(i,a,b)  for (decay_t<decltype(b)> i=a, _b=b; i <= _b; ++i)
#define FORD(i,a,b)   for (decay_t<decltype(a)> i=a, _b=b; i >  _b; --i)
#define FORGE(i,a,b)  for (decay_t<decltype(a)> i=a, _b=b; i >= _b; --i)
#define FREACH(x, A)  for (auto &x : A)

#define DISCARD_LINE do { char buf[32]; fin.getline(buf, 32); } while(0)

template <typename T> T read_var() { T var; fin >> var; return var; }

//#define READI(var)   int var;       fin >> var
//#define READLL(var)  long long var; fin >> var
//#define READSTR(var) string var;    fin >> var

#define READI(var)   auto var = read_var<int>()
#define READLL(var)  auto var = read_var<long long>()
#define READSTR(var) auto var = read_var<string>()

#define DPF(...) do { fprintf(fout, __VA_ARGS__); printf(__VA_ARGS__); } while(0)

/* memoization stuff */
template <class RetType, class... Args> struct Memoize { template <class... KeyArgs> static std::map<std::tuple<KeyArgs...>, RetType> make_memoize_cache(KeyArgs... args); }; template <class RetType, class... Args> Memoize<RetType, Args...> make_memoize(RetType(*func)(Args...));
#define MEMOIZATION_HEADER(isLocalCache, funcName, ...) using funcName##_Memoize_Cache = decltype(decltype(make_memoize(funcName))::make_memoize_cache(__VA_ARGS__)); static funcName##_Memoize_Cache _memoizeCache; static int _memoizeLevel = 0; if ((isLocalCache) && _memoizeLevel == 0) _memoizeCache.clear(); funcName##_Memoize_Cache::key_type _memoizeKey{ __VA_ARGS__ }; auto itr = _memoizeCache.find(_memoizeKey); if (itr != end(_memoizeCache)) return itr->second; ++_memoizeLevel; auto& _memoizeReturnValue = _memoizeCache[_memoizeKey]
#define MEMOIZATION_RETURN(retValue) { _memoizeReturnValue = retValue; --_memoizeLevel; return _memoizeReturnValue; }

using dword = unsigned int;
using qword = unsigned long long;

using int32 = int;
#define int long long

using lb = list<bool>;
using lc = list<char>;
using li = list<int>;
using ld = list<double>;
using ls = list<string>;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vll = vector<long long>;

using vdw = vector<dword>;
using vqw = vector<qword>;

using pii = pair<int, int>;

FILE* fout; ifstream fin;
void parse_cmd_line(int32 argc, char *argv[]){ fin.open((argc < 2 ? "in.txt" : argv[1])); fopen_s(&fout, (argc < 3 ? "out.txt" : argv[2]), "w"); }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void process()
{
    READI(J);
    READI(P);
    READI(S);
    READI(K);

    map<pii, int> jpMap, jsMap, psMap;

    vector<tuple<int, int, int>> ans;

    FORLE(j, 1, J)
    {
        FORLE(p, 1, P)
        {
            FORLE(s, 1, S)
            {
                auto &jp = jpMap[{j, p}];
                auto &js = jsMap[{j, s}];
                auto &ps = psMap[{p, s}];

                if (jp >= K || js >= K || ps >= K)
                {
                    continue;
                }

                ans.push_back({ j, p, s });

                ++jp;
                ++js;
                ++ps;
            }
        }
    }

    int a = ans.size();
    DPF("%lld", a);
    FREACH(x, ans)
    {
        DPF("\n%lld %lld %lld", get<0>(x), get<1>(x), get<2>(x));
    }
}

int32 main(int32 argc, char *argv[])
{
    parse_cmd_line(argc, argv);

    READI(nCases);
    DISCARD_LINE;

    FORLE(i, 1, nCases)
    {
        DPF("Case #%d: ", i);

        process();

        DPF("\n");
    }

    return 0;
}