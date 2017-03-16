#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-4
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
#define ALL(n) n.begin(),n.end()
#define pb push_back
#define iFor(i,n) for(typeof(n.begin()) i=n.begin();i!=n.end();i++)

int main(){
	int ca;
	freopen("C-small-2-attempt2.in","r",stdin);
	//freopen("C-small-2-attempt2.out","w",stdout);
	scanf("%d",&ca);
	while(ca--){
	    int r,n,m,k;
	    scanf("%d %d %d %d",&r,&n,&m,&k);
        cout<<"Case #1:"<<endl;
	    while(r--){
	        int thr=0,fv=0,two=0;
	        int sev=0;
            For(p,k){
                int num; scanf("%d",&num);
                int three=0,five=0,t=0,seven=0;
                while(num%3==0) num/=3,three++;
                while(num%5==0) num/=5,five++;
                while(num%2==0) num/=2,t++;
                while(num%7==0) num/=7,seven++;
                thr=max(thr,three);
                fv=max(fv,five);
                two=max(two,t);
                sev=max(sev,seven);
            }
            int pos = n - fv-thr-sev;
            For(i,fv) cout<<"5";
            For(i,thr/2) cout<<"6";
            For(i,thr-thr/2) cout<<"3";
            two-=thr/2;
            For(i,sev) cout<<"7";
            int eight = max(0, two-pos*2);
            pos -= eight;
            two -= eight*3;
            For(i,eight) cout<<"8";
            int t = (n-pos)*2/5;
            t = min(pos,t);
            For(i,t/2) cout<<"2";
            For(i,t-t/2) cout<<"4";
            pos -= t;

            while(pos-->0){
                char c = '2' + (rand() % 7);
                cout<<c;
            }
            cout<<endl;
	    }
	}
	return 0;
}
