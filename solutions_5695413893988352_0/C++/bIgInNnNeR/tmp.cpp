#include <array>
#include <cstdio>
#include <functional>
#include <iterator>
#include <vector>
template<typename T> struct ScanfSpecifier{};
#define DEF(T,V) template<> struct ScanfSpecifier<T>{static constexpr const char* value = V;};
DEF(int,"%d")DEF(double,"%lf")DEF(float,"%f")DEF(char,"%c")DEF(const char*,"%s")DEF(unsigned long,"%lu")DEF(char*,"%s")
#ifdef _MSC_VER
DEF(long long int,"%I64d")
#else
DEF(long long int,"%lld")
#endif
#undef DEF
template<typename T> int RD(T& arg){return std::scanf(ScanfSpecifier<T>::value, &arg);}
template<int S> int RD(char (&arg)[S]){return std::scanf("%s", arg);}
template<> int RD<char*>(char*& arg){return std::scanf("%s", arg);}
template<> int RD<char>(char& arg){return std::scanf(" %c", &arg);}
template<typename T, typename... Args> int RD(T& arg1, Args&... args) {return RD(arg1) + RD(args...);}
template<typename It> void RDV(It begin, It end) { while(begin != end) RD(*begin++); }
template<typename C> void RDV(C& c) {RDV(std::begin(c), std::end(c));}
template<typename... Args> void WT(Args... args) { int alc = 0; int dummy[] = {((alc++? std::printf(" "): 0), std::printf(ScanfSpecifier<Args>::value, args), 0)...}; }
template<typename... Args> void WTL(Args... args) { WT(args...); std::printf("\n"); }
template<typename It> void WTV(It begin, It end) { int alc = 0; while(begin != end) (alc++? std::printf(" "): 0), WT(*begin++); }
template<typename C> void WTV(const C& c) {WTV(std::begin(c), std::end(c));}
template<typename It> void WTVL(It begin, It end) { WTV(begin, end); std::printf("\n"); }
template<typename C> void WTVL(const C& c) {WTVL(std::begin(c), std::end(c));}



namespace XX
{   
    template<template<typename> class Compare, typename T>
    inline
    T& UP(T& x, const T& y)
    {   
        Compare<T>()(y, x) && (x = y);
        return x;
    }
    template<typename Compare, typename T>
    inline
    T& UP(T& x, const T& y, Compare comp)
    {   
        comp(y, x) && (x = y);
        return x;
    }

    template<typename T> inline T& GT(T& x, const T& y){return UP<std::greater>(x, y);}
    template<typename T> inline T& LS(T& x, const T& y){return UP<std::less>(x, y);}

    template<typename T, int S>
    struct ReferenceArray
    {
        struct It {typename std::array<T*, S>::iterator it; T& operator*(){return **it;} void operator++(){it++;} bool operator!=(const It& other){return it != other.it;} };
        int size()const{return _ptr.size();}
        It begin()const{return {_ptr.begin()};}
        It end()const{return {_ptr.end()};}
        T& operator[](int idx)const{return *_ptr[idx];}
        mutable std::array<T*, S> _ptr;
    };
    template<typename T, typename... Args> 
    ReferenceArray<T, sizeof...(Args) + 1> MAKEV(T& arg1, Args&... args) {return {&arg1, &args...};}

    struct Range
    {   
        struct It {   int num, step; int operator*(){return num;} void operator++(){num += step;} bool operator!=(const It& other){return num != other.num;} };
        Range(int ee):b(0),e(ee){}
        Range(int bb, int ee):b(bb), e(ee){}
        It begin(){return {b, (b < e? 1: -1)};}
        It end(){return {e, 0};}
        int b, e;
    };

}



//alias
//RD[L],RDV[L],WT[L],WTV[L] for i/o
template<typename T> T& UMAX(T& x, T y){return XX::UP<std::greater>(x, y);}
template<typename T> T& UMIN(T& x, T y){return XX::UP<std::less>(x, y);}
using XX::UP; //(x,y) comp
using RG = XX::Range;
using XX::MAKEV;
//template
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;


string in[2];
char buf[32];

long long table[32][2];
int table2[32][2];
long long radix[18];

long long int dp(int pos, int big)
{
    if(pos >= (int)in[0].size())
        return 1;
    else if(table2[pos][big])
        return table2[pos][big] - 1;
    else
    {
        char a = in[0][pos], b = in[1][pos];
        for(char d1 = '0'; d1 <= '9'; d1++)
            for(char d2 = '0'; d2 <= '9'; d2++)
                if(a == '?' || a == d1)
                    if(b == '?' || b == d2)
                        if(big || d1 >= d2)
                        {
                            auto res = dp(pos + 1, big || d1 > d2);
                            if(res)
                            {
                                auto diff = (d1 - d2) * radix[in[0].size() - 1 - pos] + table[pos + 1][big || d1 > d2];
                                if(!table2[pos][big])
                                {
                                    table2[pos][big] = 1;
                                    table[pos][big] = diff;
                                }
                                else 
                                    UMIN(table[pos][big], diff);
                            }
                        }

        return table2[pos][big]++;
    }
}


tuple<int,long long, string, string> solve(string in1, string in2, bool s)
{
    in[0] = in1;
    in[1] = in2;

    radix[0] = 1;
    for(int i = 1; i < 18; i++)
        radix[i] = radix[i - 1] * 10;
    memset(table2, 0, sizeof(table2));
    memset(table, 0, sizeof(table));
    auto res = dp(0, 0);
    if(!res)
        return {1};
    bool big = false;
    long long int now = 0, dif = table[0][0];
    string r1, r2;
    for(unsigned i = 0; i < in1.size(); i++)
    {
        int a = in1[i], b = in2[i];
        for(int x1: RG(10))
            for(int x2: RG(10))
            {
                int d1 = x1, d2= x2;
                if(!s)
                    swap(d1, d2);

                if(a == '?' || a == d1 + '0')
                    if(b == '?' || b == d2 + '0')
                    {
                        if((big || d1 >= d2) && dp(i + 1, big || d1 > d2) && now + (d1 - d2) * radix[in1.size() - 1 - i] + table[i + 1][big || d1 > d2] == dif)
                        {
                            r1 += '0' + d1;
                            r2 += '0' + d2;
                            big = big || d1 > d2;
                            now += (d1 - d2) * radix[in1.size() - 1 - i];
                            goto loop;
                        }
                    }
            }
loop:;
    }
    if(s)
    return {0, dif, r1, r2};
    else
        return {0, dif, r2, r1};
}

void solve()
{
    char buf1[32], buf2[32];
   RD(buf1);
   RD(buf2);
   auto res1 = solve(buf1, buf2, true);
   auto res2 = solve(buf2, buf1, false);

   if(res2 < res1)
       swap(res1, res2);

   WTL(get<2>(res1).c_str(), get<3>(res1).c_str());

}

int main()
{
    int T;
    RD(T);
    for(int tn: RG(1, T + 1))
    {
        printf("Case #%d: ", tn);
        solve();
    }
}


