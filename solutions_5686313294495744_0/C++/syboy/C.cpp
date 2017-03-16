#include<iostream>

using namespace std;

const int MN=1000;
string st[MN][2];
int mark[MN];
int main(){

	int tt;
	cin>>tt;
	for(int ii=0;ii<tt;ii++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>st[i][0]>>st[i][1];
		}
		int Max=0;
		for(int mk=0;mk<(1<<n);mk++){
			for(int i=0;i<n;i++){
				mark[i]=(mk>>(i))%2;
			}
			
			int con=0;
			for(int i=0;i<n;i++){
				if(mark[i]==0){
					int f=0,s=0;
					for(int j=0;j<n;j++){
						if(mark[j]==1){
							if(st[i][0]==st[j][0]){
								f=1;
							}
							if(st[i][1]==st[j][1]){
								s=1;
							}
						}
					}
					if(s&&f){
						con++;
					}
				}
			}
			Max=max(con,Max);
		}
		cout<<"Case #"<<ii+1<<": "<<Max<<endl;
	}
	return 0;
}

