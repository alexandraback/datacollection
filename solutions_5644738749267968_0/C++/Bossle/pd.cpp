#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef long double num;
typedef unsigned long long int nat;

void print(num n){cout << n << " ";}
void print(int n){cout << n << " ";}
template<class T> void print(vector<T> v){for(int i=0;i<v.size();++i) print(v[i]);cout << endl;}

int main()
{
	int t;
	cin >> t;
	for(int tc=1;tc<=t;++tc)
	{
		cout << "Case #" << tc << ": ";
		int n;
		cin >> n;
		vector<num> inpa(n);
		vector<num> inpb(n);
		for(int i=0;i<n;++i)
			cin >> inpa[i];
		for(int i=0;i<n;++i)
			cin >> inpb[i];

		vector<num> a(inpa),b(inpb);
		int pointsdec=0;
		int mina=0,maxa=n,minb=0,maxb=n;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		while(mina<maxa)
		{
			if(a[mina]>b[minb])
			{
				mina++;
				minb++;
				pointsdec++;
			}
			else
			{
				mina++;
				maxb--;
			}
		}
		
		a=vector<num>(inpa);
		b=vector<num>(inpb);
		int points=0;
		mina=0,maxa=n,minb=0,maxb=n;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		while(mina<maxa)
		{
			if(a[maxa-1]<b[maxb-1])
			{
				maxb--;
				maxa--;
			}
			else
			{
				maxa--;
				minb++;
				points++;
			}
		}
		
		cout << pointsdec << " " << points << endl;
	}
}
