#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string calc(string s){
	string ret="";
	bool used[1020]={0,};
	int l=s.length();
	int curmaxptr=0,usedmax=0,usedlastloc=l;

	while(true){
		curmaxptr=0;
		for(int i=1;i<usedlastloc;i++)
		if(!used[i])
		if(s[i]>=s[curmaxptr])
			curmaxptr=i;
		if(curmaxptr==0)break;
		usedmax=s[curmaxptr];
		ret=ret+s[curmaxptr];
		used[curmaxptr]=1;
		usedlastloc=curmaxptr;
	}
	for(int i=0;i<l;i++)
		if(!used[i])
			ret+=s[i];
	return ret;

}

int main()
{
	int T,N;
	string s;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		printf("Case #%d: ",tt);
		cin>>s;
		cout<<calc(s)<<endl;
	}
}
