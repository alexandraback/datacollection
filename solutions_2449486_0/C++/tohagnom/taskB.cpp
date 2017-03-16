#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <memory.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>

int main()
{
	int T;
	cin >> T;
	int a[200][200];
	for(int step=1; step<=T; ++step)
	{
		int N,M;
		cin >> N >> M;
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				cin >> a[i][j];
		bool can=true;
		for(int i=0; i<N && can; ++i)
			for(int j=0; j<M && can; ++j)
			{
				bool ok=true;
				for(int l=0; l<N; ++l)
					if(a[l][j]>a[i][j])
						ok=false;
				if(!ok){
					ok=true;
					for(int l=0; l<M; ++l)
						if(a[i][l]>a[i][j])
							ok=false;
					if(!ok)
						can=false;
				}
			}
		
		cout << "Case #"<<step<<": ";
		if(can)
			cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
