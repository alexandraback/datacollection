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

double arr1[1005], arr2[1005];

int main()
{
	freopen("C:\\Users\\DELL\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\DELL\\Desktop\\output.txt","w",stdout);
	int i, j, cases;
	int start1, start2, end1, end2, temp;
	scan(cases);
	int n, score, scored, k=1, l=1;
	wl(cases)
	{
		scan(n);
		printf("Case #%d: ", l);
		l++;
		score=0;
		scored=0;
		start2=0;
		end2=n-1;
		fl(i,0,n)
			scanf("%lf", &arr1[i]);
		fl(i,0,n)
			scanf("%lf", &arr2[i]);
			
		std::sort(arr1, arr1+n, std::greater<double>());
		std::sort(arr2, arr2+n, std::greater<double>());
		/*nline;
		fl(i,0,n)
			printf("%lf ", arr1[i]);
		nline;
		fl(j,0,n)
			printf("%lf ", arr2[j]);
		nline;*/
		
		fl(i,0,n)
		{
			if(arr1[i]>arr2[start2])
			{
				if(arr1[i]>arr2[end2])
				{
					score++;
					//cout<<arr1[i];
				}
				end2--;
			}
			else
			{
				start2++;
			}
		}
		
		std::sort(arr1, arr1+n, std::less<double>());
		std::sort(arr2, arr2+n, std::less<double>());
		
		/*nline;
		fl(i,0,n)
			printf("%lf ", arr1[i]);
		nline;
		fl(j,0,n)
			printf("%lf ", arr2[j]);
		nline;*/
		
		start1=0;  temp=0;
		for(i=0; i<n; i++)
		{
			//cout<<"*";
			if(arr1[i]<arr2[0])
			{
				//cout<<"here";
				arr2[n-1-i]=0;
				arr1[i]=0;
			}
			else
				break;
		}
		//nline;
		/*fl(i,0,n)
			printf("%lf ", arr1[i]);
		nline;
		fl(j,0,n)
			printf("%lf ", arr2[j]);
		nline;*/
		//cout<<i;
		//nline;
		for(j=i; j<n; j++)
		{
			fl(k,0,n)
			{
				if(arr1[k]>arr2[n-1-j])
				{
					scored++;
					arr1[k]=0;
					arr2[n-1-j]=0;
					break;
				}	
			}
		}
		printf("%d %d", scored, score);
		nline;
	}
	return 0;
}


