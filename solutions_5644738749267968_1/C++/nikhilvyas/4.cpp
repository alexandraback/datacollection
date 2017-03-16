#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gg(double y,vector<double> b){
	int i=b.size()-1;
	while(true){
		if(i==0) break;
		if(b[i-1]<y) return i;
		i--;
	}
	return i;
}

void fgf(int &sum,vector<double> &a,vector<double> &b){
	//cout<<"a"<<endl;
	if(a.size()==0) return;
	if(b[b.size()-1]>a[a.size()-1]){
		int i=gg(a[a.size()-1],b);
		a.erase(a.begin());
		b.erase(b.begin()+i);
		fgf(sum,a,b);
		return;
	}
	else{
		int i=gg(b[0],a);
		a.erase(a.begin()+i);
		b.erase(b.begin());
		sum++;
		fgf(sum,a,b);
		return;
	}
}
	

int main(){
	int t;
	cin>>t;
	for(int yy=0;yy<t;yy++){
		int z;
		cin>>z;
		vector<double> a(z,0);
		vector<double> b(z,0);
		for(int i=0;i<z;i++){
			cin>>a[i];
		}
		for(int i=0;i<z;i++){
			cin>>b[i];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int i=0,j=0;
		int sum2=0,sum1=0;
		while(true){
			if(j==b.size()) break;
			if(b[j]>a[i]){
				j++;
				i++;
				sum2++;
				continue;
			}
			j++;
		}
		sum2=z-sum2;
		double h=a[a.size()-1];
		int ff=0;
		for(int i=b.size()-1;i>-1;i--){
			//cout<<i<<endl;
			if(b[i]>h) ff++;
			else break;
		}
		double l=b[0];
		int gg=0;
		for(int i=0;i<a.size();i++){
			if(a[i]<l) gg++;
			else break;
		}
		//cout<<gg<<"  "<<ff<<endl;
		if(gg>=ff) sum1=gg;
		else sum1=ff; 
		sum1=0;
		//cout<<"L"<<endl;
		fgf(sum1,a,b);
		cout<<"Case #"<<yy+1<<": "<<sum1<<" "<<sum2<<endl;
	}
}
			
