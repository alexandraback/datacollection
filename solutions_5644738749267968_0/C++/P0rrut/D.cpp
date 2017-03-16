#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;
vector<double> tod1,tod2;
vector<bool> us1,us2;
int T,N;
void leer(vector<double> &ref){
	for(int i=0;i<N;i++){
		double t1;
		scanf("%lf",&t1);
		ref.push_back(t1);
	}
	sort(ref.begin(),ref.end());
}
int main(){
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		cout << "Case #" << i+1 << ": ";
		tod1.clear();
		tod2.clear();
		us1 = vector<bool>(N+2,false);

		us2 = vector<bool>(N+2,false);
		scanf("%d",&N);
		leer(tod1);
		leer(tod2);
		int s1=0;
		int s2 =0;	
		for(int i=N-1;i>=0;i--){
			int j;
			for(j=0;j<N;j++){
				if(!us2[j] && tod2[j]>tod1[i]) break;
			}
			if(j==N){
				for(int k=0;k<N;k++){
					if(!us2[k]){
						us2[k]=true;
						break;
					}
				}
				s1++;
			}
			else
				us2[j]=true;
			
		}
		us1 = vector<bool>(N+2,false);

		us2 = vector<bool>(N+2,false);

		for(int i=N-1;i>=0;i--){
			int j;
			for(j=0;j<N;j++){
				if(!us1[j] && tod1[j]>tod2[i]) break;
			}
			if(j==N){
				for(int k=0;k<N;k++){
					if(!us1[k]){
						us1[k]=true;
						break;
					}
				}
				
			}
			else
				us1[j]=true,s2++;
			
		}


		cout << s2 << " " << s1 << endl;
	//	for(int j=0;j<N;j++) cout << tod1[j] << " ";
	//	cout << endl;
	//	for(int j=0;j<N;j++) cout << tod2[j] << " ";
	//	cout << endl;

	}

	return 0;
}
