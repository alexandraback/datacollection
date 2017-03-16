// codejam.cpp : 定义控制台应用程序的入口点。
//



#include<iostream>
#include<string>
#include<fstream>
using namespace std;


int main(){
	ifstream in;
	in.open("in");
	ofstream out;
	out.open("out");
	int t;
	in>>t;
	for(int j=0;j<t;j++){
		int n,s,p,a,count=0;
		in>>n>>s>>p;
		for(int i=0;i<n;i++){
			in>>a;
			int temp=a/3;
			if(temp>=p) count++;
			else{
				int left=a-p-temp;
				if(left<0) continue;
				if(left==p||left==p-1) count++;
				if(left==p-2&&s>0){
					count++;
					s--;
				}
			}
		}
		out<<"Case #"<<j+1<<": "<<count<<endl;
	}
	in.close();
	out.close();
	return 0;
}