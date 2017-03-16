#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define mod 1000000007
#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lim 100007

map<char,map<char,char> > ch;
map<char,map<char,int> > sn;

lli l,x;
string s;

bool out(string tmp)
{
	lli i,j,cn;
	bool dk = 0;
	char t1 = tmp[0];
	lli t2 = 1, si = tmp.size();
	for(j=0;j<si;j++){
		if(j!=0){
			t2 *= sn[t1][tmp[j]];
			t1 = ch[t1][tmp[j]];
		}
		if(t1=='i'&&t2==1){
			break;
		}
	}
	if(j+1>=x*l){
		return 0;
	}
	j++;
	t1 = tmp[j];
	t2 = 1;
	for(cn = 0;j<si;j++, cn++){
		if(cn != 0){
			t2 *= sn[t1][tmp[j]];
			t1 = ch[t1][tmp[j]];
		}
		if(t1=='j'&&t2==1){
			break;
		}
	}
	if(j+1>=si){
		return 0;
	}
	j++;
	t1 = tmp[j];
	t2 = 1;
	for(cn = 0;j<si;j++, cn++){
		if(cn != 0){
			t2 *= sn[t1][tmp[j]];
			t1 = ch[t1][tmp[j]];
		}
	}
	if(t1=='k'&&t2==1){
		return 1;
	}
	return 0;
}

int solve(){
	lli i;
	string tmp="";
	for(i = 1; i <= min(x, 100LL); i++)
	{
		tmp += s;
		if( (x - i) % 4 != 0) continue;
		if(out(tmp)) return 1;
	}
	return 0;
	
}

int main(){
	freopen("file.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=1,tst = 1;
	cin>>t;
	ch['1']['1'] = '1';
	ch['1']['i'] = 'i';
	ch['1']['j'] = 'j';
	ch['1']['k'] = 'k';
	
	ch['i']['1'] = 'i';
	ch['i']['i'] = '1';
	ch['i']['j'] = 'k';
	ch['i']['k'] = 'j';
	
	ch['j']['1'] = 'j';
	ch['j']['i'] = 'k';
	ch['j']['j'] = '1';
	ch['j']['k'] = 'i';
	
	ch['k']['1'] = 'k';
	ch['k']['i'] = 'j';
	ch['k']['j'] = 'i';
	ch['k']['k'] = '1';
	
	sn['1']['1'] = 1;
	sn['1']['i'] = 1;
	sn['1']['j'] = 1;
	sn['1']['k'] = 1;
	
	sn['i']['1'] = 1;
	sn['i']['i'] = -1;
	sn['i']['j'] = 1;
	sn['i']['k'] = -1;
	
	sn['j']['1'] = 1;
	sn['j']['i'] = -1;
	sn['j']['j'] = -1;
	sn['j']['k'] = 1;
	
	sn['k']['1'] = 1;
	sn['k']['i'] = 1;
	sn['k']['j'] = -1;
	sn['k']['k'] = -1;

	while(t--){
		cin>>l>>x;
		cin>>s;
		printf("Case #%d: ",tst++);
		if(solve()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
