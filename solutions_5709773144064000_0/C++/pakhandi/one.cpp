//Author : pakhandi
//
using namespace std;

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iterator>
#include<sstream>
#include<fstream>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)
#define scan(n) scanf("%d", &n)
#define scans(s) scanf("%s", s)
#define scanc(c) scanf("%c", &c)
#define scanp(f) scanf("%f", &f)
#define scanll(l) scanf("%lld", &l)
#define print(n) printf("%d\n", n)
#define prints(s) printf("%s\n", s)
#define printc(c) printf("%c\n", c)
#define printp(f) printf("%f\n", f)
#define printll(l) printf("%lld\n", l)
#define nline printf("\n")
#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define MOD 1000000007
#define ll long long int

double ansarr[1000000], arr[1000000];

int main()
{
	freopen("C:\\Users\\DELL\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\DELL\\Desktop\\output.txt","w",stdout);
	int i, j, cases, k=1;
	double c, f, x, temp, min; 
	scan(cases);
	wl(cases)
	{
		scanf("%lf%lf%lf", &c, &f, &x);
		//printf("hello");
		ansarr[0]=x/2;
		//cout<<ansarr[0];
		min=ansarr[0];
		arr[0]=0;
		temp=2.0000000;
		fl(i,1,1000000)
		{
			arr[i]=arr[i-1]+(c/temp);
			temp=temp+f;
			ansarr[i]=arr[i]+(x/temp);
			//printf("%lf\n", ansarr[i]);
			if(ansarr[i]<min)
			{
				min=ansarr[i];
			}
		}
		printf("Case #%d: ", k);
		k++;
		printf("%0.7lf", min);
		nline;
	}
	return 0;
}

