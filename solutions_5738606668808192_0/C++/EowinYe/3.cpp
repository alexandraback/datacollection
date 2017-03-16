#include <iostream>
#include <fstream>

using namespace std;

int N,J;
int ans[16];

ifstream in("C-small-attempt0.in");
ofstream out("C-small-attempt0.out");

void printans(){
	out<<11;
	if (N%2==1)
		out<<0;
	for (int i=0;i<N/2-2;i++){
		if (ans[i]){
			out<<"11";
		}else{
			out<<"00";
		}
	}
	out<<11<<" ";
	out<<"3 2 5 2 7 2 3 2 11"<<endl;
	J--;
}

void dfs(int dep){
	if (dep==N/2-2){
		printans();
		return;
	}
	ans[dep]=0;
	if (J) dfs(dep+1);
	ans[dep]=1;
	if (J) dfs(dep+1);
}

int main(){
	int Test,cnt;
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		in>>N;
		in>>J;
		out<<"Case #"<<cnt<<":"<<endl;
		dfs(0);
	}
	in.close();
	out.close();
}
