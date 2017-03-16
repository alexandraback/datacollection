#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;

typedef long long ll;

const int MAXN = 1000010;
char str[MAXN];
ll c[MAXN];
    
inline int isVowels(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || 
    	ch == 'o' || ch == 'u';
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int T, n, len;
    cin>>T;
    for(int tt = 1; tt <= T; ++tt){
    	cin>>&str[1]>>n;
		ll ans = 0;
		int sumConsonants = 1;
		memset(c, 0, sizeof(c));
		int len;
  		for(len = 1; str[len]; ++len);
  		for(int i = len - 1; i > 0; --i){
   			if(isVowels(str[i]))
   				c[i] = 0;
			else 
				c[i] = c[i + 1] + 1;
		}
	//	cout<<"len = "<<len<<endl;
		ll prepos = -1;
		for(int i = 1; i < len; ++i){
			//cout<<"i="<<i<<' '<<c[i]<<' ';
   			if(prepos == -1 && c[i] < n)continue;
			if(c[i] >= n){
				ll m = c[i] - n + 1;
				ans += m * (m + 1) / 2 + m * (i - 1);
				if(prepos != -1){
					ans += prepos * (n - 1);
    			}
    			prepos = i + c[i] - n;
				i += c[i] - 1;
   			}else {
   			    ans += prepos;
   			}
   	//		cout<<"i="<<i<<' '<<ans<<endl;   
  		}
  	//	cout<<endl;
		cout<<"Case #"<<tt<<": "<<ans<<endl;
    }    
    return 0;
//	system("pause");
}    

