#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

void foo(vector<int> &nums, map<char,int> &m, int x, string snum, char cz) {
	int z = m[cz]; 
	nums[x]+=z;
	for(size_t i=0;i<snum.size();i++) 
		m[snum[i]]-=z;
}

int main(int argc, char *argv[]) {
//	string fname = "A-sample";
	string fname = "A-small-attempt1";
//	string fname = "A-large";
	ifstream fin(fname+".in");
	ofstream fout(fname+".out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		vector<int> nums(10,0);
		map<char,int> m;
		for(char x='A';x<='Z';++x) m[x]=0;
		string s;
		fin>>s;
		for(size_t i=0;i<s.size();i++) m[s[i]]++;
		
		foo(nums,m,0,"ZERO",'Z');
		foo(nums,m,2,"TWO",'W');
		foo(nums,m,6,"SIX",'X');
		foo(nums,m,8,"EIGHT",'G');
		foo(nums,m,3,"THREE",'H');
		foo(nums,m,4,"FOUR",'U');
		foo(nums,m,5,"FIVE",'F');
		foo(nums,m,1,"ONE",'O');
		foo(nums,m,7,"SEVEN",'V');
		m['N']/=2;
		foo(nums,m,9,"NINE",'N');
//		cout<<"Case #"<<I+1<<endl;
//		for(char x='A';x<='Z';++x) 
//			if(m[x]!=0) cout <<x<<"  " << m[x];
		
		fout<<"Case #"<<I+1<<": ";
		for(int i=0;i<10;i++) { 
			for(int j=0;j<nums[i];j++) { 
				fout << i;
			}
		}
		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

