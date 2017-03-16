#include <iostream>
#include <fstream>
#include <string>

using namespace std;

__int64 rev(__int64 a){
	__int64 res = 0;

	while(a){
		res *= 10;
		res += a%10;		
		a /= 10;
	}
	return res;
}

int aa(__int64 a){
	int c = 0;
	while(a){
		++c;
		a /= 10;
	}
	return c;
}

int ab(__int64 a){
	while (a >= 10){
		a/=10;
	}
	return a;
}

__int64 pw(int a){
	__int64 res = 1;
	for(int i=0;i<a;i++)
		res *= 10;
	return res;
}

__int64 arr[20];

int main()
{
	int n,N;
	ifstream fin("A-small-attempt3.in");
	//ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;
	
	arr[0] = arr[1] = 0;
	arr[2] = 10;
	
	for(int i=3;i<15;i++){
		__int64 num = pw(i-1);
		__int64 now = pw(i-2);
		__int64 res = arr[i-1];

		int size = i%2 + i/2;
		size = pw(size);
		__int64 min = num - now;

		for(int j=9;j<size;j=j*10+9){
			__int64 tmp = rev(now+j);
			if(tmp<=num){
				if(num-tmp+j+1 < min)
					min = num-tmp+j+1;
			}
		}
		arr[i] = min+res;
	}

	for(n=0;n<N;n++){
		__int64 num;
		fin>>num;
		if(aa(num) < 2){
			fout<<"Case #"<<n+1<<": "<<num<<endl;
			continue;
		}
		int size = aa(num);
		__int64 res = arr[size];
		__int64 now = pw(size-1);
		__int64 min = num-now;
		int k = size/2 + size%2;
		k = pw(k);
		for(int i=0;i<k;i++){
			__int64 tmp = rev(now+i);
			if(tmp <= num){
				if(num-tmp+i+1 < min)
					min = num-tmp+i+1;
			}
		}
			
		
		/*res += ab(num);
		if(ab(num) != 1)
			res++;
		res += num - (pw(aa(num)-1)*ab(num) + 1);*/
		
		fout<<"Case #"<<n+1<<": "<<res+min<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);