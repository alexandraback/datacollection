#include <array>
#include <iterator>
#include <functional>
#include <cstdio>
#include <vector>

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

char buf[2048];

void solve()
{
    RD(buf);

    map<char, int> table;
    for(int i = 0; buf[i]; i++)
        table[buf[i]]++;
    
    char key[] = "GWZXHRFOSN";
    const char* digit[] = {"EIGHT", "TWO", "ZERO", "SIX", "THREE", "FOUR", "FIVE", "ONE", "SEVEN", "NINE"
    };
    int num[] = {8,2,0,6,3,4,5,1,7,9};


    int alc[10] = {};
    for(int i = 0; i < 10; i++)
        while(table[key[i]] > 0)
        {
            alc[num[i]]++;
            for(int j = 0; digit[i][j]; j++)
                table[digit[i][j]]--;
        }

    printf(" ");
    for(int i = 0; i < 10; i++)
        while(alc[i]--)
            printf("%d", i);
    printf("\n");
}

int main()
{
    int T;
    RD(T);
    for(int tn: RG(1, T + 1))
    {
        printf("Case #%d:", tn);
        solve();
    }

}


