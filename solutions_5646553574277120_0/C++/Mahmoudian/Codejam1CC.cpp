//In the name of God
#include <bits/stdc++.h>
using namespace std;
ofstream fout("codejam.out");
#define cout fout
const int Maxn = 1e3 + 9;
int mark[Maxn];
int coin[Maxn];
int main(){
	int tc;
	cin >> tc;
	int ts = 0;
	while(tc--){
		cout << "Case #" << ++ts << ": ";
		int c,d,v;
		cin >> c >> d >> v;
		for(int i = 0; i < d;i++) cin >> coin[i];
		int last = d;
		while(1){
			for(int i = 0; i < (1 << d);i++){
				int x = 0;
				for(int j = 0; j < d;j++){
					if(i & (1 << j))
						x += coin[j];
				}
				mark[x] = 1;
			}
			int add = -1;
			for(int i = 0; i <= v;i++)
				if(!mark[i])
					add = i;
			if(add == -1) break;
			coin[d++] = add;
		}
		cout << d - last << endl;
	}
}
