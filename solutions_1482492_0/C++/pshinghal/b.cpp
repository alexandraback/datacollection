#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<iomanip>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

#define For(i,a,b) for(i=a;i<b;i++)

const int MAXN = 2000 + 20;
const long double tinyerror = 0.00000000001F;

long double t[MAXN], x[MAXN];
long double lastv, lastx, currtime, timegap, currv, currx, D, acc, otherv;//, lasttime;

int N, A;

int main ()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(10);
	int TC, I, J, M, K, curr;
	cin>>TC;
	for(I = 0; I < TC; I++){
		cin>>D>>N>>A;
		for(J = 0; J < N; J++){
			cin>>t[J]>>x[J];
		}
		cout<<"Case #"<<I+1<<":\n";
		//!!!!!!!!!A is different from acc!!!!!!!!
		for(J = 0; J < A; J++){
			cin>>acc;
			currv = 0;
			currx = 0;
			currtime = 0;
			for(K = 0; K < N; K++){
				lastv = currv;
				lastx = currx;
				//lasttime = currtime;
				timegap = t[K] - currtime;
				currx = (long double)lastx + ((long double)lastv * timegap) + ((long double)((long double) acc * timegap * timegap)/2.0);
				if(currx < ((long double) D - tinyerror) && currx < ((long double) x[K] - tinyerror)){
					currtime = t[K];
					currv = (long double) lastv + ((long double)acc * timegap);
				}
				if(currx > ((long double) x[K] - tinyerror)){
					if(K == 0)
						currv = 0;
					else
						currv = (long double) ((long double) x[K] - x[K - 1])/timegap;
					currx = x[K];
					currtime = t[K];
				}
				else if(currx > (D - tinyerror)){
					currtime += (long double)((long double) sqrt((long double) ((long double) 2 * acc * ((long double) D - lastx)) + ((long double) lastv * lastv)) - lastv)/acc;
					break;
				}
			}
			if(currx <= (D - tinyerror))
				currtime += (long double)((long double) sqrt((long double) ((long double) 2 * acc * ((long double) D - currx)) + ((long double) currv * currv)) - currv)/acc;
			cout<<currtime<<endl;
		}
	}
	return 0;
}
