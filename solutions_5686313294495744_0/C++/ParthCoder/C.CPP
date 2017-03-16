#include<bits/stdc++.h>
#define mod 1000000007
#define SIZE 1000007
#define ll long long
#define INF LLONG_MAX
#define fr(i,a,b) for(i=a;i<=b;i++)
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<string,string> ss;
typedef vector<ss> vss;

vss::iterator itr,itr1;

int main() {
    freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
    //ios::sync_with_stdio(0);
    int tc,i,n,fake;
    string str,str1;
	ll ans;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        cin>>n;
        vss topics;
        for(i=0;i<n;i++){
            cin>>str>>str1;
            topics.push_back(ss(str,str1));
        }
        fake = 0;
        for(itr=topics.begin();itr!=topics.end();itr++){
            str = (*itr).first;
            str1 = (*itr).second;
            for(itr1=topics.begin();itr1!=topics.end();itr1++)
            if(itr!=itr1){
                if((*itr1).first==str)
                    break;
            }
            if(itr1!=topics.end()){
                for(itr1=topics.begin();itr1!=topics.end();itr1++)
                if(itr!=itr1){
                    if((*itr1).second==str1)
                        break;
                }
                if(itr1!=topics.end())
                    fake++;
            }
        }
		cout<<"Case #"<<t<<": "<<fake<<"\n";
	}
	return 0;
}

