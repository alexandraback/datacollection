#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<cassert>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<utility>
#include<numeric>
#include<iterator>
using namespace std;

#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define memo(a,b) memset(a,b,sizeof(a))

#define all(a) a.begin(),a.end()
#define pb push_back
#define mpp(a,b,c) make_pair(make_pair(a,b),c)

#define inf (1<<29)
#define i64 long long
#define pi (2.0*acos(0.0))
#define eps (1e-9)

typedef pair< int , int >  pii;

string calc(int n,int sng, char a,char b,int &i){
    if(sng)
        swap(a,b);
    string ret = "";
    int m = 0;
    while(m!=n){
        if(m+i>n){
            ret+=b;
            m-=i;
        }
        else {
            ret+=a;
            m+=i;
        }
        i++;
    }

    return ret;
}
int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small.ans","w",stdout);
    int t,cs = 1,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        int i = 1;
        string ret = calc(abs(x),x<0,'E','W',i);
      //  cout<<i<<endl;
        ret+=calc(abs(y),y<0,'N','S',i);
        assert(ret.size()<=500);
        cout<<"Case #"<<cs++<<": "<<ret<<endl;
    }
	return 0;
}
