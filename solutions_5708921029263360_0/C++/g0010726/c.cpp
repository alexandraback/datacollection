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
	}
	return 0;
}


void exe()
{
	int ab[10][10]={0};
	int bc[10][10]={0};
	int ac[10][10]={0};
	
	int a,b,c,k;
	cin >>a>>b>>c>>k;
	string s;
	int sum=0;
	for(int i=1;i<=a;++i){
		for(int j=1;j<=b;++j){
			for(int h=1;h<=c;++h){
				if(ab[i][j]<k && bc[j][h]<k && ac[i][h]<k){
					s += to_string(i) +' '+to_string(j)+' '+to_string(h)+'\n';
					++bc[j][h]; ++ac[i][h]; ++ab[i][j];
					++sum;
				}
			}
		}
	}
	cout << sum << '\n' << s;
}
