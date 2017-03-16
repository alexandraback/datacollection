#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

char guStr1[8];
char guStr2[8];
void moveStr(char *str,int len)
{
	char temp=str[0];
	int i;
	for(i=0;i<len-1;i++)
		str[i]=str[i+1];
	str[i]=temp;
}

int main()
{
	freopen("C-small-practice.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int i,j,k,j2;
	int t,a,b;
	int len=0;
	int numPair;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		numPair=0;
		scanf("%d %d",&a,&b);
		for(j=a;j<b;j++)
		{
			itoa(j,guStr1,10);
			itoa(j,guStr2,10);
			len=strlen(guStr1);
			for(k=1;k<=len-1;k++)
			{
				moveStr(guStr1,len);
				j2=atoi(guStr1);
				if(j2>j && j2<=b)
					numPair++;
			}
		}
		printf("Case #%d: %d\n", i,numPair);
	}
	return 0;
}


















