#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100;
FILE * fin, * fout;
int main(){
	freopen_s(&fin, "osmos.in", "r", stdin);
	freopen_s(&fout, "osmos.out", "w", stdout);
	int run, count, fewest, added, temp; long long curr, mote[N];
	cin >> run;
	for (int a = 1; a <= run; ++a){
		cin >> curr >> count;
		for (int x = 0; x < count; ++x)
			cin >> mote[x];
		sort(mote, mote+count);

		cout << "Case #" << a << ": ";
		if (curr == 1){
			cout << count << endl;
			continue;
		}
		fewest = count; added = 0;
		for (int x = 0; x < count; ++x){
			while (curr <= mote[x]){
				curr += (curr-1);
				++added;
			}
			curr += mote[x];
			if ((temp = added + count-(x+1)) < fewest)
				fewest = temp;
		}
		cout << fewest << endl;
	}
	return 0;
}
