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

ll counts[27];
ll res[27];

int main()
{
	STDSYNC;
	ll t,a,b,c,i,j,k,n,m;
    cin >> t;
    string str;
    for(i=0;i<t;i++){
        cin >> str;
        for(j=0;j<27;j++){
            counts[j] = 0;
            res[j] = 0;
        }
        for(j=0;j<str.length();j++){
            counts[str[j]-'A'] += 1;
        }
        if(counts['Z'-'A']!=0){
            res[0] += counts['Z'-'A'];
            counts['E'-'A']-=counts['Z'-'A'];
            counts['R'-'A']-=counts['Z'-'A'];
            counts['O'-'A']-=counts['Z'-'A'];
            counts['Z'-'A']=0;
        }
        if(counts['W'-'A']!=0){
            res[2] += counts['W'-'A'];
            counts['T'-'A']-=counts['W'-'A'];
            counts['O'-'A']-=counts['W'-'A'];
            counts['W'-'A']=0;
        }
        if(counts['X'-'A']!=0){
            res[6] += counts['X'-'A'];
            counts['S'-'A']-=counts['X'-'A'];
            counts['I'-'A']-=counts['X'-'A'];
            counts['X'-'A']=0;
        } 
        if(counts['U'-'A']!=0){
            res[4] += counts['U'-'A'];
            counts['F'-'A']-=counts['U'-'A'];
            counts['O'-'A']-=counts['U'-'A'];
            counts['R'-'A']-=counts['U'-'A'];
            counts['U'-'A']=0;
        }
        if(counts['G'-'A']!=0){
            res[8] += counts['G'-'A'];
            counts['E'-'A']-=counts['G'-'A'];
            counts['I'-'A']-=counts['G'-'A'];
            counts['H'-'A']-=counts['G'-'A'];
            counts['T'-'A']-=counts['G'-'A'];
            counts['G'-'A']=0;
        }
        if(counts['T'-'A']!=0){
            res[3] += counts['T'-'A'];
            counts['H'-'A']-=counts['T'-'A'];
            counts['R'-'A']-=counts['T'-'A'];
            counts['E'-'A']-=counts['T'-'A'];
            counts['E'-'A']-=counts['T'-'A'];
            counts['T'-'A']=0;
        }
        if(counts['F'-'A']!=0){
            res[5] += counts['F'-'A'];
            counts['I'-'A']-=counts['F'-'A'];
            counts['V'-'A']-=counts['F'-'A'];
            counts['E'-'A']-=counts['F'-'A'];
            counts['F'-'A']=0;
        }
        if(counts['V'-'A']!=0){
            res[7] += counts['V'-'A'];
            counts['S'-'A']-=counts['V'-'A'];
            counts['E'-'A']-=counts['V'-'A'];
            counts['E'-'A']-=counts['V'-'A'];
            counts['N'-'A']-=counts['V'-'A'];
            counts['V'-'A']=0;
        }
        res[1] = counts['O'-'A'];
        res[9] = counts['E'-'A']-counts['O'-'A'];
        cout << "Case #" << (i+1) << ": ";
        for(j=0;j<=9;j++){
            for(k=0;k<res[j];k++){
                cout << j;
            }
        }
        cout << endl;
    }
	return 0;
}
