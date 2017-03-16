#include <iostream>
using namespace std;
#define N 1000001
bool check(char c)
{
	if(c == 'a' || c == 'o' || c == 'u' || c== 'i' || c == 'e')
		return false;
	return true;
}
int main(){
	//freopen("A-small-practice.in","r",stdin);
	//freopen("A-small-practice.out","w",stdout);
	int t,i,j,l,x,n;
	__int64 ans;
	char name[N];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%s%d",&name,&n);
		ans = 0;
		for(j=0,l=-1,x=0;name[j]!='\0';j++)
		{
			if(check(name[j])){
				x ++;
			}
			else x = 0;
			if(x >= n){
				ans += j+2-n;
				l = j+1-n;
			}
			else
				ans += l+1;
		}
		printf("Case #%d: %I64d\n",i,ans);

	}
	return 0;
}