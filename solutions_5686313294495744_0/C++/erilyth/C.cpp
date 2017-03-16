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
    string str1,str2;
    cin >> t;
    for(i=0;i<t;i++){
        msi mymapl, mymapr;
        map<int, string> mymapl1, mymapr1;
        cin >> n;
        for(j=0;j<n;j++){
            cin >> str1 >> str2;
            mymapl[str1]+=1;
            mymapr[str2]+=1;
            mymapl1[j]=str1;
            mymapr1[j]=str2;
        }
        ll cnt=0;
        ll ans = 0;
        for(j=1;j<(1<<n);j++){
            msi mymaplcopy = mymapl;
            msi mymaprcopy = mymapr;
            cnt=0;
            ll notpossible = 0;
            ll t1 = j;
            while(t1){
                if(t1%2==1){
                    if(mymaplcopy[mymapl1[cnt]]>=2 && mymaprcopy[mymapr1[cnt]]>=2){
                        mymaplcopy[mymapl1[cnt]]-=1;
                        mymaprcopy[mymapr1[cnt]]-=1;
                    }
                    else{
                        notpossible = 1;
                    }
                }
                t1/=2;
                cnt+=1;
            }
            if(notpossible == 0){
                ll tt = 0;
                ll cur = j;
                while(cur){
                    if(cur%2==1)
                        tt+=1;
                    cur/=2;
                }
                ans = max(ans,tt);
            }
        }
        cout << "Case #" << (i+1) << ": " << ans << endl;
    }
	return 0;
}
