#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<numeric>
using namespace std;
const int maxn=2000001;
typedef long long LL;
int hash[maxn],cnt=0,s[32],top;
LL cal(int n,int A,int B){
	if(hash[n]==cnt)return 0;
	//cout<<"x="<<n<<endl;
	top=0;
	int base=1;
	for(int x=n;x;x/=10)s[top++]=x%10,base*=10;
	base/=10;
	LL c=1;
	hash[n]=cnt;
	int pre=n;
	for(int i=0;i<top-1;i++){
		pre=pre/10+s[i]*base;
		//cout<<"pre="<<pre<<endl;
		if(s[i]!=0&&pre>=A&&pre<=B&&hash[pre]!=cnt){hash[pre]=cnt;c++;}
		}
	//cout<<"c="<<c<<endl;system("pause");
	return c*(c-1)/2;
	}
int main(){
	int T,A,B;
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(int ca=1;ca<=T;ca++){
		cnt++;
		cin>>A>>B;
		LL ans=0;
		for(int i=A;i<=B;i++)ans+=cal(i,A,B);
		cout<<"Case #"<<ca<<": "<<ans<<endl;
		}
    return 0;
	}
