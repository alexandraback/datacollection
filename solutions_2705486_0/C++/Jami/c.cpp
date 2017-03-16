#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<cassert>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)


#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid,s,e
#define clrgt rgt,mid+1,ed,s,e
#define inf (1<<20)
#define i64 long long
#define MX 600002

typedef pair<int,int> pii;

int dp[5005][20],n;
string a[MX],s;

int minch(int pos,int idx,int pre,int &npre){
    if(pos+a[idx].size()>s.size())return inf;
    int i,ret=0;
    for(i=0;i<a[idx].size();i++){
        if(a[idx][i]==s[pos+i])continue;
        else if((i-pre)<5){
            npre=0;
            return inf;
        }
        else {
            ret++;
            pre=i;
        }
    }
    npre=a[idx].size()-pre;
    assert(npre>=0);
    return ret;
}

int func(int pos,int pre){
    assert(pre>=0);
    if(pos==s.size())return 0;
    int &ret=dp[pos][pre];
    if(ret!=-1)return ret;
    ret=inf;
    int tmp,x,idx,npre;
    for(idx=0;idx<n;idx++){
        x=minch(pos,idx,-pre,npre);
        if(x>=inf)continue;
        assert(npre>=0);
        tmp=x+func(pos+a[idx].size(),npre);
        ret=min(ret,tmp);
    }
    return ret;
}

int main(){
    //freopen("in.txt","r",stdin);
	freopen("C-small-attempt2.in","r",stdin);
	freopen("out.txt","w",stdout);
	FILE *fp=fopen("garbled_email_dictionary.txt","r");
	char str[100];
	while(fscanf(fp,"%s",str)==1){
	    a[n++]=str;
	}
	int cs,t=1;
	cin>>cs;
	while(cs--){
	    cin>>s;
	    SET(dp);
	    printf("Case #%d: %d\n",t++,func(0,5));
	}
	return 0;
}


