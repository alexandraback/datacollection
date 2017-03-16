#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 10000000

using namespace std;

typedef long long ll;

vector<ll> palindromes;
char temp[100],temp2[100],temp3[100],temp4[100];

bool isIntPalindrome(ll x)
{
    sprintf(temp4,"%I64d",x);
    int len = strlen(temp4);
    int left = 0,right = len-1;
    FOR(i,0,len-1)
    {
        if(left >= right) break;
        if(temp4[left] != temp4[right]) return false;
        left++;
        right--;
    }
    //cerr << temp4 << endl;
    //getchar();
    return true;
}

void generateOddPalindrome(ll x)
{
    ll res;
    sprintf(temp,"%d",x);
    strcpy(temp2,temp);
    reverse(temp2,temp2 + strlen(temp2));
    FOR(i,0,9)
    {
        if(temp[0] != '0')sprintf(temp3,"%s%d%s",temp,i,temp2);
        else sprintf(temp3,"%d",i);
        sscanf(temp3,"%I64d",&res);
        //cerr << res << endl;
        //getchar();
        if(isIntPalindrome(res*res)) palindromes.push_back(res * res);
    }
}

void generateEvenPalindrome(ll x)
{
    ll res;
    sprintf(temp,"%I64d",x);
    strcpy(temp2,temp);
    reverse(temp2,temp2 + strlen(temp2));
    sprintf(temp3,"%s%s",temp,temp2);
    sscanf(temp3,"%I64d",&res);
    if(isIntPalindrome(res * res)) palindromes.push_back(res*res);
}

int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    //freopen("C-err.txt","w",stderr);
    FOR(i,0,999)
    {       
        generateEvenPalindrome(i);
        generateOddPalindrome(i);
    }
    sort(palindromes.begin(),palindromes.end());
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        ll a,b;
        scanf("%I64d %I64d",&a,&b);
        int pos = lower_bound(palindromes.begin(),palindromes.end(),a) - palindromes.begin();
        int pos2 = upper_bound(palindromes.begin(),palindromes.end(),b) - palindromes.begin();
        //if(pos2 < pos) cerr << pos2 << " " << pos << " " << a << " " << b << endl;
        //getchar();
        printf("Case #%d: %d\n",ca,pos2-pos);
    }
    return 0;
}
