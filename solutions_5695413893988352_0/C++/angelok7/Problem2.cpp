#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string l,r;
string sum;
string res;
int mm = 10000;
int abs(int a){
	if(a < 0)
		return -a;
	return a;
}

void check(int now)
{
	if(now == sum.size()){
		string a,b;
		a = sum.substr(0,l.size());
		b = sum.substr(l.size(),l.size());
		int aa,bb;
		aa = bb =0;
		for(int i=0;i<a.size();i++){
			aa += (a[i]-'0'); 
			aa *= 10;
		}
		for(int i=0;i<a.size();i++){
			bb += (b[i]-'0'); 
			bb *= 10;
		}
		aa /= 10;
		bb /= 10;
		if(mm > abs(aa - bb)){
			mm = abs(aa - bb);
			res = a + " " + b;
		}
		return;
	}
	if(sum[now] == '?'){
		for(int i=0;i<10;i++){
			sum[now] = '0' + i;
			check(now+1);
			sum[now] = '?';
		}
	}
	else
		check(now+1);
}

int main()
{
	int t,T;
	ifstream fin("B-small-attempt1.in");
	//ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>T;

	for(t=0;t<T;t++){
		
		fin>>l>>r;
		sum = l+r;
		mm = 10000;
		check(0);
		fout<<"Case #"<<t+1<<": "<<res<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);