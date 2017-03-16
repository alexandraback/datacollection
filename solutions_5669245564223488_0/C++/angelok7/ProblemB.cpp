#include <iostream>
#include <fstream>
#include <string>
#define MOD 1000000007
using namespace std;

string arr[100];

int ma[10][10];
int count[10];
__int64 pre[11];
int num;

int pp[10];

__int64 check(int p,int next){
	int i,j;
	if(p==num){
		if(next == 0)
			return 1;
		else
			return 0;

	}
	__int64 res = 0;
	for(i=0;i<num;i++){
		for(j=0;j<p;j++)
			if(i == pp[j])
				break;
		if(j!= p)
			continue;
		if(ma[pp[p-1]][i]){
			pp[p] = i;
			res += check(p+1,0);
			res = res%MOD;
		}else if(next == 0){
			pp[p] = i;
			res += check(p+1,1);
			res = res%MOD;
		}
	}
	return res%MOD;
}


int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;
	pre[0] = 1;
	for(int i=1;i<11;i++)
		pre[i] = pre[i-1]*i;

	for(n=0;n<N;n++){
		int i,j;
		__int64 res = 0;
		fin>>num;
		memset(ma,0x00,sizeof(ma));
		memset(count,0x00,sizeof(count));
		for(i=0;i<num;i++)
			fin>>arr[i];

		for(i=0;i<num;i++){
			for(j=0;j<num;j++){
				if(i==j)
					continue;
				if(arr[i][arr[i].size()-1] == arr[j][0]){
					ma[i][j] = 1;
					count[i]++;
				}
			}
		}
		
		for(i=0;i<num;i++){
			pp[0] = i;
			res+=check(1,1);
		}

		res %= MOD;

		
		fout<<"Case #"<<n+1<<": "<<res<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);