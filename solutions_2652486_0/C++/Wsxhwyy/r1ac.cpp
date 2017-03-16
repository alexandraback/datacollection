#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout

int x[10];
int k[10];
vector<int> ans;
int a[10];

int main()
{
	cin>>x[0]>>x[1]>>x[2]>>x[3]>>x[4];
	cout<<"Case #1:"<<endl;
	for(int xx=0;xx<100;xx++){
		for(int i=0;i<7;i++) cin>>k[i];
		a[2]=a[3]=a[4]=a[5]=0;
		for(int i=0;i<7;i++){
			if(k[i]%3==0){
				a[3]=max(a[3],1);
				if(k[i]%9==0){
					a[3]=max(a[3],2);
					if(k[i]%27==0)
						a[3]=max(a[3],3);
				}
			}
			if(k[i]%5==0){
				a[5]=max(a[5],1);
				if(k[i]%25==0){
					a[5]=max(a[5],2);
					if(k[i]%125==0)
						a[5]=max(a[5],3);
				}
			}
			if(k[i]%16==0){
				a[4]=max(a[5],2);
			}
		}
		ans.clear();
		for(int i=0;i<a[3];i++) ans.push_back(3);
		for(int i=0;i<a[4];i++) ans.push_back(4);
		for(int i=0;i<a[5];i++) ans.push_back(5);
		if(ans.size()<3){
			for(int i=0;i<7;i++){
				if(k[i]%8==0 && ans.size()>0){
					ans.push_back(4);
					ans.push_back(2);
					break;
				}
			}
		}
		if(ans.size()<3){
			for(int i=0;i<7;i++){
				if(k[i]%4==0 && ans.size()==1){
					ans.push_back(2);
					ans.push_back(2);
					break;
				}else if(k[i]%4==0 && ans.size()==2){
					ans.push_back(4);
					break;
				}
			}
		}
		while(ans.size()<3){
			ans.push_back(2);
		}
		cout<<ans[0]<<ans[1]<<ans[2]<<endl;
	}
}