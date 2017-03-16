#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
		int N, S, p;
		cin >> N >> S >> p;

		int count=0;
		int count_sur=0;
		for (int j=0; j<N; j++) {
			int score;
			cin >> score;
			if (score >= p*3-2)
				count++;
			else if (p>=2 && score >= p*3-4)
				count_sur++;
		}

		cout << "Case #" << i+1 << ": " << count+min(S,count_sur) << endl;
	}
}



