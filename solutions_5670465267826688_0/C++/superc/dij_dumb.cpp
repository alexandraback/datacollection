#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int gmul(int i,int j){
	bool positive = i*j>0;
	i = abs(i);
	j = abs(j);
	int res;
	if(i==j&&i!=4){
		res = -4;
	} else if(i!=4&&j!=4){
		res = 6-i-j;
	} else {
		res = i+j-4;
	}
	if(!positive){
		res = -res;
	}
	if(i!=4&&j!=4&&(i==j+1||j==i+2)){
		res = -res;
	}
	return res;
}


bool check(int l, int x, string s){
	int xx = x;
	x = x % 4;
	if(x==0)
		return false;
	else {
		bool kafteri = false;
		bool iappear = false;
		bool kappear = false;
		bool feasible = false;
		int prod = 0;
		if(xx>4){
			xx=x+4;
		}
		for(int i=0;i<l*xx;i++){
			int temp = s[i%l]-'i'+1;
			if(i==0){
				prod = temp;
			} else {
				prod = gmul(prod,temp);
			}
			if(prod == 1){
				iappear=true;
			} else if(prod==3){
				kappear = true;
				if(iappear){
					kafteri = true;
				}
			}
		}
		return prod==-4&&kafteri;
	}
}

int main(int argc, char** argv){
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	int n;
	fin>> n;
	for(int i=0;i<n;i++){
		int l;
		int x;
		string str;
		fin>>l>>x;
		fin>>str;
		cout<<(i+1)<<":\t"<<x<<":\t";
		bool r = check(l,x,str);
		string rr = r?"YES":"NO";
		cout<<rr<<endl;
		fout<<"Case #"<<(i+1)<<": "<<rr<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

