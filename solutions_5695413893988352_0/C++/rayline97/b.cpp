#include <cstdio>
#include <cstring>
#include <string>
using std::string;
long long n,ans;
string ansa,ansb;

long long tonum(string s){
	long long a = 0;
	for(int i=0;i<s.size();i++){
		a*=10;
		a+=s[i]-'0';
	}
	return a;
}

long long abs(long long a){
	if(a>0) return a;else return -a;
}

void calc(string aa, string bb, int i, int state){
	//printf("%s %s %d %d\n", aa.c_str(),bb.c_str(),i,state);
	if(i==n){
		long long a = tonum(aa);
		long long b = tonum(bb);
		if(abs(a-b)<ans||abs(a-b)==ans&&tonum(aa)<tonum(ansa)||abs(a-b)==ans&&tonum(aa)==tonum(ansa)&&tonum(bb)<tonum(ansb)){
			ans = abs(a-b);
			ansa = aa;
			ansb = bb;
		}
		return;
	}
	string a=aa;
	string b=bb;
	if(state==0){
		if(aa[i]=='?'&&bb[i]=='?'){
			a=aa;
			b=bb;
			a[i]='0';
			b[i]='0';
			calc(a,b,i+1,0);
			a = aa;
			b = bb;
			a[i]='1';
			b[i]='0';
			calc(a,b,i+1,1);
			a=aa;
			b=bb;
			a[i]='0';
			b[i]='1';
			calc(a,b,i+1,-1);
			a=aa;
			b=bb;
		}else
		if(aa[i]=='?'){
			a=aa;
			b=bb;
			a[i] = b[i];
			calc(a,b,i+1,0);
			b = bb;
			if(b[i]!='0'){
				a[i] = b[i]-1;
				calc(a,b,i+1,-1);
				a = aa;
			}
			if(b[i]!='9'){
				a[i] = b[i]+1;
				calc(a,b,i+1,1);
				b = bb;
			}
		}else
		if(bb[i]=='?'){
			a=aa;
			b=bb;
			b[i] = a[i];
			calc(a,b,i+1,0);
			b = bb;
			if(a[i]!='0'){
				b[i] = a[i]-1;
				calc(a,b,i+1,1);
				b = bb;
			}
			if(a[i]!='9'){
				b[i] = a[i]+1;
				calc(a,b,i+1,-1);
				b=bb;
			}
		}else{
			if(aa[i]==bb[i])calc(aa,bb,i+1,0);
			if(aa[i]>bb[i]) calc(aa,bb,i+1,1);
			if(aa[i]<bb[i]) calc(aa,bb,i+1,-1);
		}
	}else{
		if(state==1){
			if(a[i]=='?'){
				a[i] = '0';
			}
			if(b[i]=='?'){
				b[i] = '9';
			}
			calc(a,b,i+1,state);
		}
		if(state==-1){
			if(a[i]=='?'){
				a[i] = '9';
			}
			if(b[i]=='?'){
				b[i] = '0';
			}
			calc(a,b,i+1,state);
		}
	}
}

int main(){
	char a[20],b[20];
	int T;
	scanf("%d",&T);
	for(int Case = 1;Case<=T;Case++){
		scanf("%s%s",a,b);
		n = strlen(a);
		ans = 9223372036854775807;
		calc(string(a),string(b),0,0);
		printf("Case #%d: %s %s\n",Case, ansa.c_str(), ansb.c_str());
	}
}
