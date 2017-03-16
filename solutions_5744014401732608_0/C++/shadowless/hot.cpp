#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define si(X) scanf("%d", &(X))
#define sll(X) scanf("%lld",&(X))
#define INFL 0x3f3f3f3f3f3f3f3fLL
ll gcd(ll a,ll b){
	if(b==0)
	return a;
	return gcd(b,a%b);
}
string toBin(ll a) {
	string res = "";
	while (a) {
		res += char((a & 1) + '0');
		a >>= 1;
	}
	reverse(res.begin(), res.end());
	return res;
}
const int mod = 1e9+7;
ll expo(ll base,ll pow){
    ll ans = 1;
    while(pow!=0){
        if(pow&1==1){
            ans = ans*base;
            ans = ans%mod;
        }
        base *= base;
        base%=mod;
        pow/=2;
    }
    return ans;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
/* -------Template ends here-------- */

const int M = 100001;

int main(){

	int t;
	si(t);

	for(int alp = 1;alp<=t;alp++){
            cout<<"Case #"<<alp<<": ";
		int ans = 0;
		int n;
		si(n);
		ull m;
        cin>>m;
		if((m&(m-1))==0){
            int arr[n+1][n+1];
            memset(arr,0,sizeof(arr));
            if(m==1){
                arr[1][n] = 1;
            }
            else{
                int po = 0;
                while(m>1){
                    m/=2;
                    po++;
                }
                int req = 2+po;
                if(n<req){
                    cout<<"IMPOSSIBLE"<<endl;;
                    continue;
                }
                arr[1][n] = 1;
                int st = 2;
                while(true){
                    if(po==0)
                        break;
                    po--;
                    for(int i = st-1;i>0;i--){
                        arr[i][st] = 1;
                    }
                    arr[st][n] = 1;
                    st++;
                }

            }
            cout<<"POSSIBLE"<<endl;
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    cout<<arr[i][j];
                }
                cout<<endl;
            }
		}
		else{
            cout<<"IMPOSSIBLE"<<endl;;
		}






		//cout<<endl;




		//cout<<"Case #"<<alp<<": "<<ans<<endl;

	}











}























