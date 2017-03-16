#include <iostream>
using namespace std;
int nd=1;
int a,b;
inline int shift(int x){
	return x/10 + x%10 * nd;
}
inline bool valid(int x){
	return x/nd>0 && x>=a && x<=b;
}
int main()
{
	int tt;
	cin >> tt;
	int k;
	for(k=0;k<tt;k++){
		cout << "Case #" << k+1 << ": ";
		cin >> a >> b;
		int tmp=a;
		nd=1;
		while(tmp>=10){tmp/=10,nd*=10;}	
		int j,tol=0;
		for(j=a;j<=b;j++){
			tmp=shift(j);
			while(tmp!=j){
				if(tmp<j && valid(tmp)){
					//cout << tmp << ' ' << j << endl;
					tol++;
				}
				tmp=shift(tmp);
			}
		}
		cout << tol << endl;
	}

}
