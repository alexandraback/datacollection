#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<utility>
#include<string>
#include<sstream>
#include<cmath>
#include<list>
#include<new>

using namespace std;

#define tr(c, it) \
        for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

#define all(c) (c).begin(),(c).end()

typedef long long int LLI;

int main()
{	
	int N;
	cin >> N;

	for(int i = 0; i < N; i++){

		LLI r,t;
		cin >> r >> t;

		LLI num = 0;
		LLI val = 1;
		while(1){

			LLI area = pow(r+val,2)-pow(r+val-1,2);

			if(area <= t){
				t = t - area;
				num += 1;
			}
			else{
				break;
			}

			val += 2; 

		}
	
		cout << "Case #" << i+1 << ": " << num << endl;

	}

	return 0;
}
