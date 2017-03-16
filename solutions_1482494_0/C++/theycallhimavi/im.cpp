#include <iostream>
using namespace std;
int main (){
	int to;
	int arr[1000][2];
	int T;
	int N;
	int m[1000][2];
	int s;
	int total;
	int max;
	int i;
	int j;
	cin>>T;
	for (i=1;i<=T;i++){
		cin>>N;
		for (j=0;j<N;j++){
			cin>>m[j][0]>>m[j][1];
			arr[j][0]=0;
			arr[j][1]=0;
		}
		s=0;
		total=0;
		int temp;
		while (s!=2*N){
			to=0;
			for (j=0;j<N;j++){
				if (arr[j][1]==0 && s>=m[j][1]){
					if (arr[j][0]==1){
						s++;
					} else {
						s+=2;
					}	
					arr[j][0]=1;
					arr[j][1]=1;
					to=1;
					total++;
				}
			}
			if (to==0){
				max=-1;
				for (j=0;j<N;j++){
					if (arr[j][0]==0 && s>=m[j][0]){
						if (m[j][1]>max){
							max=m[j][1];
								temp=j;
						}
						to=1;
					}
				}
				if (to==1){
				s++;
				total++;
				arr[temp][0]=1;
				}
			}
			if (to==0){
			total=-1;
			s=2*N;
			}
		}
		if (total==-1){
			cout<<"Case #"<<i<<": "<<"Too Bad"<<endl;
		} else {
			cout<<"Case #"<<i<<": "<<total<<endl;
		}
	}
	return 0;
}
