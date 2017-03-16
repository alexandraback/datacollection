#include <iostream>
#include <fstream>

using namespace std;

__int64 p[50];

__int64 gong(__int64 a, __int64 b){
	__int64 temp;
	if(a < b){
		temp = a;
		a = b;
		b = temp;
	}

	while(1){
		if(a%b == 0)
			return b;
		a = a%b;
		if(b%a == 0)
			return a;
		b = b%a;
	}
	return 1;
}

int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;
	p[0] = 1;
	for(int i=1;i<50;i++)
		p[i] = p[i-1] *2;

	for(n=0;n<N;n++){
		__int64 P,Q;
		char temp;
		fin>>P>>temp>>Q;
		__int64 k = gong(P,Q);
		int i,j;
		P = P/k;
		Q = Q/k;

		for(i=0;i<50;i++){
			if(p[i] == Q)
				break;
		}
		if(i!=50){
			int count = 0;
			for(j=i;j>0;j--){
				count++;
				if(P > p[j-1]){
					break;
				}
			}
			fout<<"Case #"<<n+1<<": "<<count<<endl;

		}else{
			fout<<"Case #"<<n+1<<": impossible"<<endl;
		}		
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);