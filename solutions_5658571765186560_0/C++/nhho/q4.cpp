#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>

using namespace std;

int t,x,n,m;
bool ok;

int main(){
	scanf("%d",&t);
	for(int a=1;a<=t;a++){
		scanf("%d%d%d",&x,&n,&m);
		if(x==1){
			ok=false;
		}else if(x==2){
			if((n*m)%2==0)ok=false;
			else ok=true;
		}else if(x==3){
			if(n*m!=3&&(n*m)%3==0)ok=false;
			else ok=true;
		}else{
			if(n<4&&m<4)ok=true;
			else if(n*m==4||n*m==8)ok=true;
			else ok=false;
		}
		if(ok)printf("Case #%d: RICHARD\n",a);
		else printf("Case #%d: GABRIEL\n",a);
	}
	//system("pause");
	return 0;
}
