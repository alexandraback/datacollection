#include <iostream>
#include <vector>
using namespace std;
int n;
int star[1000][2];
int lev[1000];
int main(){
	int tnum,tcou=0;
	cin>>tnum;
	while (tnum--){
		cin>>n;
		for (int i=0;i<n;++i){
			cin>>star[i][0]>>star[i][1];
			lev[i]=0;
		}
		int s=0;
		int extra=0;
		while (true){
			int ind=-1;
			for (int i=0;i<n;++i)
				if (lev[i]!=2 && s>=star[i][1]){
					s+=2-lev[i];
					lev[i]=2;
					goto next;
				}
			for (int i=0;i<n;++i){
				if (lev[i]==0 && s>=star[i][0]){
					if (ind==-1 || star[i][1]>star[ind][1])
						ind=i;
				}
			}
			if (ind==-1)
				break;
			else{
				++s;
				lev[ind]=1;
				++extra;
			}
			next:;
		}
		cout<<"Case #"<<++tcou<<": ";
		if (s!=n+n){
			cout<<"Too Bad"<<endl;
		}
		else{
			cout<<n+extra<<endl;
		}
	}
	return 0;
}
