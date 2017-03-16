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

int init(){
	int cs=1;
	TEST{
		int ra,rb;
		int mn=100000;
		char c[10],jj[10];
		cin>>c>>jj;
		int l = strlen(c);
		int k;
		if (l==1) k=10;
		else if (l==2) k=100;
		else k=1000;
		for (int i=0;i<k;i++){


			int f=0;
			char p[10];
			p[0] = p[1] = p[2] = '0';
			int temp = i;
			int tt = l-1;
			while(temp){
				p[tt--] = (temp%10)+48;
				temp/=10;
			}
			for (int q=0;q<l;q++){
				if (c[q]!='?' && c[q]!=p[q]){
					f=1;
					break;
				}
			}
			if (f==1) continue;


			for (int j=0;j<k;j++){
				int f=0;
							char p[10];
							p[0] = p[1] = p[2] = '0';
							int temp = j;
							int tt = l-1;
							while(temp){
								p[tt--] = (temp%10)+48;
								temp/=10;
							}

							for (int q=0;q<l;q++){
								if (jj[q]!='?' && jj[q]!=p[q]){
									f=1;
									break;
								}
							}
							if (f==1) continue;

							if (abs(i-j)<mn){
								mn = abs(i-j);
								ra=i;
								rb=j;
							}

			}
		}

		int dig = 0;
		int temp = ra;
		if (ra==0) dig++;
		while(temp){
			temp/=10;
			dig++;
		}
		cout << "Case #" << cs++ << ": " ;
		for (int i=0;i<l-dig;i++) cout << 0;
		cout << ra << " ";

		dig = 0;
		temp = rb;
		if (rb==0) dig++;
		while(temp){
			temp/=10;
			dig++;
		}
		for (int i=0;i<l-dig;i++) cout << 0;
		cout << rb;
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

