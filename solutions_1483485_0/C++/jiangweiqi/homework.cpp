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
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <string.h>

using namespace std; 
#define N 100001
#define MOD 1000000007
typedef long long ll;


/*bool arr[N];
void prim()
{
arr[0]=1;
arr[1]=1;
int i;
ll j;
for(i=2;i<N;i++)
{
if(arr[i]==0)
{
for(j=i,j=j*i;j<N;j+=i)
{
arr[j]=1;
}
}
}
}*/
/*int gcd(int m, int n) {
while (true) {
if ((m = m % n) == 0) return n;
if ((n = n % m) == 0) return m;
}
}*/

/*yhesocvxduiglbkrztnwjpfmaq
a-y
b-h
c-e
d-s
e-o
f-c
g-v
h-x
i-d
j-u
k-i
l-g
m-l
n-b
o-k
p-r
q-z
r-t
s-n
t-w
u-j
v-p
w-f
x-m
y-a
z-q
*/
int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	char cstr[30]="yhesocvxduiglbkrztnwjpfmaq";
	int T,cas,i;
	char s[2];
	scanf("%d",&T);
	gets(s);
	for(cas=1;cas<=T;cas++)
	{
		char str[105]={0};
		gets(str);
		for(i=0;str[i];i++)
		{
			if(str[i]==' ')continue;
			str[i]=cstr[ str[i]-'a' ];
		}
		printf("Case #%d: %s\n",cas,str);
	}
	return 0;
}