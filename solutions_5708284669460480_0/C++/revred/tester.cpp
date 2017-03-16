#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define mod 1000000007
#define inf 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define lim 200007

string a,str;
string st[900000];
int k,s,l;

double gen()
{
	int tot = pow(k,s),tmp,tmp1;
	double ans = 0,max = 0;
	for(int i=0;i<tot;i++){
		tmp = i;
		tmp1 = 0;
		st[i] = "";
		for(int j=0;j<s;j++){
			st[i] += a[tmp%k];
			tmp /= k;
		}
		for(int k1,j=0;j<=s-l;j++){
			for(k1=0;k1<l;k1++){
				if(st[i][j+k1] != str[k1]){
					break;
				}
			}
			if(k1==l){
				tmp1++;
			}
		}
		if(tmp1>max){
			max = tmp1;
		}
		ans += tmp1;
	}
	//cout<<max<<" "<<ans<<" "<<tot<<" ";
	return max-(ans/double(tot));
}

int main(){
	freopen("file.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=1,tst = 1;
	cin>>t;
	while(t--){
		cin>>k>>l>>s;
		cin>>a;
		cin>>str;
		printf("Case #%d: %.7f\n",tst++,gen());
		gen();
	}
	return 0;
}
