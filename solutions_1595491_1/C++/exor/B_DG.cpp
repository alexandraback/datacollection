#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<fstream>

using namespace std;

int main()
{
	int N;
	int n,s,p,x,a,k=1,ans;
	scanf("%d",&N);
	fstream fi("out2.txt",ios::out);
	while(N--){
		ans=0;
		scanf("%d %d %d ",&n,&s,&p);
		while(n--){
			scanf("%d",&x);
			if(x >= 3*p-2)ans++;
			else if(x>=3*p-4 && x >=p && s >0){ans++;s--;}
		}
		printf("%d\n",ans);
		fi << "Case #"<<k++<<": " << ans << "\n";
	}
	return 0;
}
