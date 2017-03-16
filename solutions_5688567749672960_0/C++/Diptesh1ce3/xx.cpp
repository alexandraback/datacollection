#include<bits/stdc++.h>
#define MOD 1000000007
#define F first
#define S second
#define pb(x) push_back(x);
#define mp(x,y) make_pair(x,y)
#define sc(x) scanf("%d",&x)
#define Fill(x,y) memset(x,y,sizeof(x))
#define REP(i,x,y) for(int i=x ; i<=y ; i++)
#define DREP(i,x,y) for(int i=x ; i>=y ; i--)

using namespace std;
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int,int> ipair;
llong xx;
llong getR(){
    char arr[50];
    int length=0;
    while(xx){
        arr[length++]=(xx%10ll)+48;
        xx=xx/10ll;
    }
    llong po=0,val=0;
    for(int i=length-1 ; i>=0  ; i--){
        val+=(llong)(arr[i]-'0')*(llong)pow(10ll,po);
        po++;
    }
    return val;
}
int values[1000099];
int main()
{
	int testCases;
	freopen("ASmall.in","r",stdin);
	freopen("OutputSmallA.out","w",stdout);
	cin>>testCases;
	llong n;
	int counter=0;
	llong i,rev;
	for(int k=1 ; k<=testCases ; k++){
	    cout<<"Case #"<<k<<": ";
        cin>>n;
        counter=0;
        for(int index=0 ; index<=n ; index++){
            values[index]=MOD;
        }
        values[1]=1;
        for(i=1 ; i<=n ; i++){
            xx=(llong)i;
            rev=getR();
            if(rev>i && rev<=n){
                values[rev]=min(values[i]+1,values[rev]);
            }
            values[i+1]=min(values[i+1],values[i]+1);
        }
        cout<<values[n]<<endl;
	}
	return 0;
}
