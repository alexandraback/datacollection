#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
typedef vi::iterator vit;
typedef set<ll> si;
typedef si::iterator sit;
typedef vector<pii> vpi;

#define sq(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
//#define LL "%I64d"
#define RLL(x) scanf(LL,&(x))

int n;

string mas[101];
bool was[256];

bool valid()
{
    cl(was);
    char cur = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j+1 < mas[i].size(); ++j)
        {
            if(cur != mas[i][j])
            {
                if(was[mas[i][j]])
                    return false;
                cur = mas[i][j];
                was[cur] = 1;
            }
        }
    return true;
}

void test(int T)
{
    cin>>n;
    for(int i=0; i <n ;++i)
    {
        cin>>mas[i];
        mas[i].push_back((char)('z'+1+i));
    }
    sort(mas, mas+n);
    int answ = 0;
    do
    {
        if(valid())
            ++answ;
//        for(int i = 0; i <n; ++i)
//            cout<<mas[i]<<" ";
//        cout<<endl;
    }while (next_permutation(mas, mas+n));
    printf("Case #%d: %d\n", T, answ);
}

int main(int argc, const char * argv[])
{
    
    freopen("/Users/olpet/Downloads/GCJ/b.in", "r", stdin);
    freopen("/Users/olpet/Downloads/GCJ/b.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}