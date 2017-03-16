#include<iostream>
#include<fstream>
using namespace std;
int arr[10000006];
long int rev(long int n){
	long int ans;
	bool flag=false;
	while(n>0){
		if(n%10==0)
			n/=10;
		else  break;
	}
	ans=0;
	while(n>0){
		ans*=10;
		ans+=n%10;
		n/=10;
	}
	return ans;
}
int main(){
	int t;
	ofstream fout("out.out");
	ifstream fin("a.in");
	fin>>t;
	arr[1]=1;
	int tmp,cas;
	for(long int i=2;i<1000006;i++){
/*		tmp=rev(i);
		if(i<=rev(i))
		arr[i]=arr[i-1]+1;
		else
		arr[i]=min(arr[rev(i)],arr[i-1])+1;
		fout<<i<<":"<<arr[i]<<"\n";
		*/
		if(arr[i]==0){
			arr[i]=arr[i-1]+1;
			if(rev(i)>i)
				arr[rev(i)]=arr[i]+1;
		}
		else arr[i]=min(arr[i],arr[i-1]+1);
		
	}
	cas=0;
	while(t--){
		cas++;
		long long n,ans;
		fin>>n;
		fout<<"Case #"<<cas<<": "<<arr[n]<<"\n";
	}
}
