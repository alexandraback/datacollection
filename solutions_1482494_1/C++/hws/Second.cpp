#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void sort(int *a,int *b,int n){
	for(int i=0;i<n;i++){
		int temp=b[i];
		int minIndex=i;
		for(int j=i+1;j<n;j++){
			if(b[j]<temp){
				temp=b[j];
				minIndex=j;
			}else if(b[j]==temp){
				if(a[j]<a[minIndex]){
					temp=b[j];
					minIndex=j;
				}
			}
		}
		if(minIndex!=i){
			int minA=a[minIndex];
			a[minIndex]=a[i];
			b[minIndex]=b[i];
			a[i]=minA;
			b[i]=temp;
		}
	}
}


int main(){

	ifstream cin("B-large.in");
	ofstream cout("B-large.out");

	int t,n;
	int result;
	int star;
	int a[2012],b[2012];
	bool flag[2012][2];
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		for(int j=0;j<n;j++){
			cin >> a[j] >> b[j];
		}
		for(int j=0;j<n;j++){
			flag[j][0]=flag[j][1]=false;
		}
		result=0;
		star=0;
		sort(a,b,n);
		int j=0;
		for(j=0;j<n;j++){
			if(b[j]<=star){
				if(flag[j][0]) star+=1;
				else star+=2;
				result+=1;
				flag[j][0]=flag[j][1]=true;
			}else{
				int k=n-1;
				for(;k>=0;k--){
					if(a[k]<=star && !flag[k][0]){
						result+=1;
						star+=1;
						flag[k][0]=true;
						j--;
						break;
					}
				}
				if(k<0){
					break;
				}
			}
		}


		if(j<n){
			cout << "Case #" << i+1 << ": Too Bad"<< endl;
		}else{
			cout << "Case #" << i+1 << ": "<< result << endl;
		}


	}

	return 0;
}