#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

int T;
string s, ret = "";
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    cin>>T;
    for(int t = 1; t <= T; ++t){
        cin>>s;
        int i = 0;
        int n = s.length();

        ret = "";
        while(i < n){
            if(s[i] >= ret[0] || ret == ""){
                ret = s[i] + ret;
            }else{
                ret = ret + s[i];
            }
            ++i;
        }
        cout<<"Case #"<<t<<": "<<ret<<endl;
    }
	return 0;
}
