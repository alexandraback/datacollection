#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define uint unsigned int

typedef pair<int,int> pii;
#define x first
#define y second

#define read(n) scanf("%d",&n)
#define readll(n) scanf("%lld",&n)
#define read2(n,m) scanf("%d%d",&n,&m)
#define read3(n,m,l) scanf("%d%d%d",&n,&m,&l)

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,a,b)   for(int i=a;i<b;i++)
#define rf(i,n)     for(int i=n-1;i>=0;i--)

#define init(mem,v) memset(mem,v,sizeof(mem))

#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#define DB4(a, b, c, d)    cout<<__LINE__<<" :: "<<#a<< ": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;

#define mod 1000000007

int n;
string car[101];
bool occ[101][26];

bool internal_proper(int i){
    int last[26];
    fr(j,26) last[j]=car[i].length();

    fr(j,car[i].length()){
        if(last[car[i][j]-'a'] < j-1 and car[i][j-1]!=car[i][j]) return false;
        else last[car[i][j]-'a']=j;
    }
    return true;
}

bool valid(vector<int>& perm){
    bool seen[26]={};
    char last=car[perm[0]][0];
    seen[car[perm[0]][0]-'a']=true;

    fr(i,n){
        char curr=car[perm[i]][0];
        if(last!=curr and seen[curr-'a']) return false;
        seen[curr-'a']=true;
        last=curr;

        fr(j,26) if(occ[perm[i]][j]){
            curr='a'+j;
            if(last!=curr and seen[curr-'a']) return false;
            seen[curr-'a']=true;
            last=curr;
        }
        curr=car[perm[i]][car[perm[i]].length()-1];
        if(last!=curr and seen[curr-'a']) return false;
        seen[curr-'a']=true;
        last=curr;
    }
    return true;
}

ll solve(){
    fr(i,n) if(!internal_proper(i)) return 0;
    fr(i,n){
        int start=0;
        while((start<car[i].length()) and  (start==0 or car[i][start]==car[i][start-1])) start++;
        int end=car[i].length()-1;
        while((end>=0) and (end==car[i].length()-1 or car[i][end]==car[i][end+1])) end--;

        for(int j=start;j<=end;j++){
            occ[i][car[i][j]-'a']=true;
        }
    }

    vector<int> perm;
    fr(i,n) perm.push_back(i);

    int ans=0;
    if(valid(perm)) ans++;

    while(next_permutation(perm.begin(),perm.end()))
        if(valid(perm)) ans++;
    return ans;
}

int main(){
    int t;
    read(t);
    for(int ii=1;ii<=t;ii++){
        init(occ,0);
        read(n);
        fr(i,n) cin>>car[i];
        printf("Case #%d: %lld\n",ii,solve());
    }
}
