//============================================================================
// Author      : Prateek Agarwal
// Institution : NITJ
//============================================================================

#include <bits/stdc++.h>

#define ll long long

#define TEST int t;scan(t);while(t--)
#define scan(n) scanf("%d",&n)
#define set(x,y) memset(x,y,sizeof(x))
#define loop(i,l,r,x) for (int i=l;i<=r;i+=x)
#define printl(n) printf("%d\n",n)
#define print(n) printf("%d ",n)
#define pb push_back

#define INF 1000000000
#define M 1000000007
#define MAX 500001
#define LIM 10

using namespace std;

char a[20],b[20];

int init(){
	int cs=1;
	TEST{

		cin>>a>>b;

		int big=0;	//-1 for a....1 for b

		for (int i=0;i<strlen(a);i++){
			if (big==0){
				if (a[i]=='?' && b[i]=='?') a[i]=b[i]='0';
				else if (a[i]=='?') a[i]=b[i];
				else if (b[i]=='?') b[i]=a[i];
				else{
					if (a[i]>b[i]) big=-1;
					else big=1;
				}
			}
			else if (big==-1){
				if (a[i]=='?') a[i]='0';
				if (b[i]=='?') b[i]='9';
			}
			else{
				if (a[i]=='?') a[i]='9';
				if (b[i]=='?') b[i]='0';
			}
		}

		cout << "Case #" << cs++ << ": " ;
		cout << a << " " << b;
		cout << endl;
	}
	return 0;
}

int main(){
	//clock_t start = clock();
	init();
	//printf("%.6f\n",double(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}

