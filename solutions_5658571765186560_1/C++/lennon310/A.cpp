#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
string shy;
int smax;
int main(){
    //freopen("input1.txt","r",stdin);
    //freopen("A-small-attempt0.in","r",stdin);
   freopen("A-large.in","r",stdin);
    freopen("output1.txt","w",stdout);
    
    int t;
    cin >> t;
    
    for(int ti=1;ti<=t;ti++){
		cout << "Case #"<<ti<<": ";
        cin>>smax;
		cin>>shy;
		if (smax==0){
			cout << "0\n";
			continue;
		}
		int tot = 0;
		int inv = 0;
        for(int i=1;i<=smax;i++){
			tot += shy[i-1]-'0';
			if (tot>=i) continue;
			else if (shy[i]-'0'==0) continue;
			else{
				inv += i-tot;
				tot += (i-tot);
			}
		}
        cout << inv << "\n";   
        
    }
    return 0;
}
