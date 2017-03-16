#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

int main(){
	int Test,cnt;
	int flag[2510];
	ifstream in("B-small-attempt0.in");
	ofstream out("B-small-attempt0.out");
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		for (int i=0;i<=2500;i++)
			flag[i]=0;
		int n;
		in>>n;
		for (int i=0;i<2*n-1;i++){
			for (int j=0;j<n;j++){
				int x;
				in>>x;
				flag[x]=(flag[x]+1) % 2;
			}
		}
		int ans[100];
		int now=0;
		for (int i=0;i<=2500;i++){
			if (flag[i]){
				ans[now]=i;
				now++;
			}
		}
		out<<"Case #"<<cnt<<": ";
		for (int i=0;i<n-1;i++){
			out<<ans[i]<<" ";
		}
		out<<ans[n-1]<<endl;
	}
	in.close();
	out.close();
}
