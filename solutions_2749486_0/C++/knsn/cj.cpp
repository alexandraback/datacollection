#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define cin(n) scanf("%d",&n)
#define gc getchar_unlocked
typedef vector<int> VI;
int main(){
	int x,y,tests;
	cin>>tests;
	for(int T = 1;T<=tests;T++){
		cin>>x>>y; 
		cout<<"Case #"<<T<<": ";
		if (x>0){
			while (x>0) {
				x--;
				cout<<"WE";
			}
		}
		else if (x<0){
			while (x<0) {
				x++;
				cout<<"EW";
			}
		}
		if (y>0){
			while (y>0) {
				y--;
				cout<<"SN";
			}
		}
		else if (y<0){
			while (y<0) {
				y++;
				cout<<"NS";
			}
		}
		cout<<endl;
	}
}