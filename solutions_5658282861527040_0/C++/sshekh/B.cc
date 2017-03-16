// Round 1B 2014 problem B
// Saurav Shekhar
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-7
#define INF 2000000000
#define P 1000000009
typedef unsigned int ui;
typedef unsigned long long llu; //I64d
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const ui LIM = 100005; 



int main()
{
  ui T,qq;
  int A, B, K;
  for(cin>>T, qq=1; qq<=T; qq++) {
	printf("Case #%u: ",qq);
	cin >> A >> B >> K;
	int count = 0;
	for(int i=0; i<A; i++) 
		for(int j=0; j<B; j++)
			if((i & j) < K) count++;

	cout << count << "\n";

  }
	
  return 0;
}
