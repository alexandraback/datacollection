#include<bits/stdc++.h>
using namespace std;

#define     ll             long long
#define     si(x) 	scanf("%d",&x)
#define 	sc(ch)	 scanf(" %c",&ch);
#define 	sl(x) 	scanf("%I64d",&x)
#define 	pi(x) 	cout << x <<" "
#define 	nl 	 cout << '\n'
#define 	mp	   make_pair
#define     pb 	  push_back
#define 	f 	  first
#define 	se 	   second
#define 	pii 	   pair<int,int>
#define 	RESET(a)   	 memset(a,-1,sizeof(a))
#define 	CLEAR(a) 		memset(a,0,sizeof(a))
#define 	all(v)   		v.begin(),v.end()
#define 	trv(it,v) 		for(it=v.begin();it!=v.end();it++)
#define 	rep(i,a,b) 		for(int i=a;i<b;i++)

#define mod 	1000000007
#define MIN 	INT_MIN
#define MAX 	INT_MAX
#define INF 	1e9
vector<int> a,b;
void recur(int i, string s, int n, int x, int t)
{
    if(i==n){
        //pi(i), pi(n);
        if(t==0)
            a.pb(x);
        else
            b.pb(x);
        return ;
        }
    if(s[i]!='?'){
       // cout <<"fdgd";
        int y = x*10 + s[i]-'0';
        recur(i+1,s,n,y,t);
    }
    else{
       // cout << "dsgdgd";
        for(int k=0; k<=9; k++){
            int y = x*10 + k;
            recur(i+1,s,n,y,t);
        }
    }
}
string get(int x)
{
    string a;
    while(x){
        a += x%10+'0';
        x/=10;
    }
    reverse(all(a));
    return a;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("6.in", "r", stdin);
        freopen("_6.in", "w", stdout);
    #endif


    int t=1, T;
    si(T);

    while(t<=T){

            string s1,s2;
            cin >> s1 >> s2;
            a.clear();
            b.clear();
            int n = s1.size();
            recur(0,s1,n,0,0);
            recur(0,s2,n,0,1);
            int d = INF;
            int x=INF,y=INF;
//            for(auto x : a)
//                pi(x);
//            nl;
//            for(auto x : b)
//                pi(x);
//            nl;
            for(int i=0; i<a.size(); i++){
                for(int j=0; j<b.size(); j++){
                    int dd = abs(a[i]-b[j]);
                   // pi(dd);
                    if(dd<d){
                        d=dd;
                        x=a[i];
                        y=b[j];
                    }
                    else if(dd==d){
                        if(a[i]<x){
                            x=a[i];
                            y=b[j];
                        }
                        else if(a[i]==x && b[j]<y){
                            x=a[i];
                            y=b[j];
                        }
                    }
                }
            }
            cout <<"Case #"<<t<<": ";
            string t1,t2;
            t1 = get(x);
            t2 = get(y);
            int n1=t1.size();
            for(int i=0; i<n-n1;i++)
                cout <<"0";
            cout << t1;
            cout <<" ";
            int n2=t2.size();
            for(int i=0; i<n-n2; i++)
                cout<<"0";
            cout <<t2;
          nl;
        t++;
    }

   return 0;
}

