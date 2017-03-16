/*
ID: rohamhe1
PROB: proximity
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<iomanip>	
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<set>
#include<complex>
#include<queue>
#include<utility>

using namespace std;

//typedef complex<long double> point;
#define pb push_back
#define mk make_pair
#define x first
#define y second
#define error(x) cout << #x << " : " << (x) << endl;
typedef long long LL;
typedef long double LD;
//#define cin fin
//#define cout fout 

int n , m , k;
const int maxn = 1000*1000+100;
int array[maxn];


int main()
{
	int t;
	int T = 1;
	cin >> t;
	while(t--)
	{
		//cout << "CASE " << T << " : " << endl;
		int fv;
		cin >> fv >> n;
		for(int i=0 ; i<n ; i++)
			cin >> array[i];
		sort(array , array+n);
		//for(int i=0 ; i<n ; i++)
		//	cout << array[i] << " " ;
		//cout << endl;
		int ans = maxn;
		int a = 0;
		for(int i=0 ; i<n ; i++)
		{
			ans = min(ans , a+(n-i));
			if(array[i] < fv)
				fv+=array[i];
			else
			{
				if(fv==1)
				{
					a = n;
					break;
				}
				while(fv <= array[i])
				{
					fv+=(fv-1);
					a++;
				}
				fv+=array[i];
				//error(a);
			}
		}
		//error(a);
		ans = min(a , ans);
		cout << "Case #" << T << ": " << ans << endl; 
		T++;
	}
}

