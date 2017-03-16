#include <bits/stdc++.h>
using namespace std;

int t,la,lb,ta,tb,ct,da[5],db[5],ansa,ansb,p[]={1,10,100,1000},no;
string a,b;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("clomat.out","w",stdout);
	cin >> t;
	for (int tc=1;tc<=t;tc++){
		cout << "Case #" << tc << ": ";
		cin >> a >> b; la=a.length(); lb=b.length();
		ansa=2000000000; ansb=1000000000;
		for (int i=0;i<p[la];i++){
			for (int j=0;j<p[lb];j++){
				for (int k=0;k<3;k++) da[k]=db[k]=0;
				ta=i; tb=j;
				ct=0;
				while (ta){
					da[ct]=ta%10; ta/=10; ct++;
				}
				ct=0;
				while (tb){
					db[ct]=tb%10; tb/=10; ct++;
				}
				no=0;
				for (int k=0;k<la;k++)
				if (a[k]!='?'&&a[k]-'0'!=da[la-1-k]) no=1;
				for (int k=0;k<lb;k++)
				if (b[k]!='?'&&b[k]-'0'!=db[lb-1-k]) no=1;
				if (no) continue;
				if (abs(i-j)<abs(ansa-ansb)||
				abs(i-j)==abs(ansa-ansb)&&i<ansa||
				abs(i-j)==abs(ansa-ansb)&&i==ansa&&j<ansb){
					ansa=i; ansb=j;
				}
			}
		}
		for (int i=1;i<la;i++) if (ansa<p[i]) cout << 0;
		cout << ansa << " ";
		for (int i=1;i<lb;i++) if (ansb<p[i]) cout << 0;
		cout << ansb << "\n";
	}
}
