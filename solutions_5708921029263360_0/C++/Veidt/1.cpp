#include <bits/stdc++.h>
using namespace std;

int tt;

int j,p,s,k;

int jp[11][11],ps[11][11],sj[11][11];

vector<int> v1,v2,v3;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> tt;
    for(int ii=1;ii<=tt;ii++){
	cin >> j >> p >> s >> k;
	memset(jp,0,sizeof(jp[0][0])*11*11),memset(ps,0,sizeof(ps[0][0])*11*11),memset(sj,0,sizeof(sj[0][0])*11*11);
	v1.clear(),v2.clear(),v3.clear();
	for(int i1=1;i1<=j;i1++){
	    for(int i2=1;i2<=p;i2++){
		for(int i3=1;i3<=s;i3++){
		    if(jp[i1][i2] == k || ps[i2][i3] == k || sj[i3][i2] == k) continue;
		    jp[i1][i2] ++,ps[i2][i3] ++,sj[i3][i2] ++;
		    v1.push_back(i1),v2.push_back(i2),v3.push_back(i3);
		}
	    }
	}
	cout << "Case #" << ii << ": "<< v1.size() << endl;
	for(int i=0;i<v1.size();i++){
	    cout << v1[i] << " " << v2[i] << " " << v3[i] << endl;
	}
	
    }
    return 0;
}
