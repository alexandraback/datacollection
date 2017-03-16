#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

const int maxH = 2501;
int T, n;
int a, b[maxH];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>T;
	for(int t = 1; t <= T; ++t){
        cin>>n;
        memset(b, 0, 4*maxH);
        for(int i = 0; i < 2*n - 1; ++i){
            for(int j = 0; j < n; ++j){
                cin>>a;
                b[a]++;
            }
        }
        cout<<"Case #"<<t<<": ";
        for(int i = 1; i <= maxH; ++i){
            if(b[i] % 2){
                cout<<i<<" ";
            }
        }
        cout<<endl;
	}

	return 0;
}
