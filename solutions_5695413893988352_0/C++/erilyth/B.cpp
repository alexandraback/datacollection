#include <bits/stdc++.h>
using namespace std;

#define whatis(x) cout << #x << " is " << x << endl;

#define MAX 1000001
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265359

#define STDSYNC std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define swap(VAR1,VAR2) VAR1=VAR1^VAR2;VAR2=VAR1^VAR2;VAR1=VAR1^VAR2

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef priority_queue < ll , vector < ll > , greater < ll > > minheap;
typedef priority_queue < ll , vector < ll > , less < ll > > maxheap;

int main()
{
	STDSYNC;
	ll t,a,b,c,i,j,k,n,m;
    cin >> t;
    ll ans1 = 0, ans2 =0;
    string str1,str2;
    for(i=0;i<t;i++){
        ans1=1000000000;
        ans2=100;
        cin >> str1 >> str2;
        ll str1len = str1.length();
        ll str2len = str2.length();
        for(j=0;j<=999;j++){
            for(k=0;k<=999;k++){
                if(j>=10 && str1len<2)
                    continue;
                if(j>=100 && str1len<3)
                    continue;
                if(k>=10 && str2len<2)
                    continue;
                if(k>=100 && str2len<3)
                    continue;
                if(str1[str1len-1]!='?' && str1[str1len-1]-'0'!=j%10)
                    continue;
                if(str1len>=2 && str1[str1len-2]!='?' && str1[str1len-2]-'0'!=(j/10)%10)
                    continue;
                if(str1len>=3 && str1[str1len-3]!='?' && str1[str1len-3]-'0'!=(j/100)%10)
                    continue;
                if(str2[str2len-1]!='?' && str2[str2len-1]-'0'!=k%10)
                    continue;
                if(str2len>=2 && str2[str2len-2]!='?' && str2[str2len-2]-'0'!=(k/10)%10)
                    continue;
                if(str2len>=3 && str2[str2len-3]!='?' && str2[str2len-3]-'0'!=(k/100)%10)
                    continue;
                if(abs(j-k)<abs(ans1-ans2)){
                    ans1=j;
                    ans2=k;
                }
                if(abs(j-k)==abs(ans1-ans2)){
                    if(j<ans1){
                        ans1=j;
                        ans2=k;
                    }
                    else if(k<ans2){
                        ans1=j;
                        ans2=k;
                    }
                }
            }
        }
        ll ans1len = 0;
        ll ans2len = 0;
        if(ans1/10!=0){
            ans1len+=1;
            if(ans1/100!=0)
                ans1len+=1;
        }
        if(ans2/10!=0){
            ans2len+=1;
            if(ans2/100!=0)
                ans2len+=1;
        }
        cout << "Case #" << (i+1) << ": ";
        for(j=0;j<str1.length()-ans1len-1;j++)
            cout << "0";
        cout << ans1 << " ";
        for(j=0;j<str2.length()-ans2len-1;j++)
            cout << "0";
        cout << ans2;
        cout << endl;
    }
	return 0;
}
