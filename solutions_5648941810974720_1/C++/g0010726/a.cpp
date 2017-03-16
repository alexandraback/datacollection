#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void exe();
int main(void)
{	
	int T;	cin >> T;
	for(int caseNum=1; caseNum<=T ; ++caseNum){
		cout << "Case #" << caseNum << ": ";
		exe();
		cout << endl;	
	}
	return 0;
}

constexpr int t(char c){
	return c-'A';
}


void exe()
{
	int alp[26]={0};
	string str;
	cin >> str;
	for(auto ch : str) ++alp[t(ch)];
	int d[10]={0};
	while(alp[t('Z')]--){
		++d[0]; --alp[t('R')];--alp[t('O')];--alp[t('E')];
	}
	while(alp[t('X')]--){
		++d[6]; --alp[t('S')];--alp[t('I')];
	}
	while(alp[t('W')]--){
		++d[2]; --alp[t('T')];--alp[t('O')];
	}
	while(alp[t('U')]--){
		++d[4]; --alp[t('R')];--alp[t('O')];--alp[t('F')];
	}
	while(alp[t('G')]--){
		++d[8]; --alp[t('E')];--alp[t('I')];--alp[t('H')];--alp[t('T')];
	}
	while(alp[t('S')]--){
		++d[7]; -- --alp[t('E')];--alp[t('V')];--alp[t('N')];
	}
	while(alp[t('R')]--){
		++d[3]; --alp[t('T')];--alp[t('H')];-- --alp[t('E')];
	}
	while(alp[t('O')]--){
		++d[1]; --alp[t('N')];--alp[t('E')];
	}
	while(alp[t('V')]--){
		++d[5]; --alp[t('E')];--alp[t('I')];--alp[t('F')];
	}
	while(alp[t('N')]--){
		++d[9]; --alp[t('I')];--alp[t('E')];--alp[t('N')];
	}
	for(int i=0;i<10;++i)
		while(d[i]--)	cout << i;
}
