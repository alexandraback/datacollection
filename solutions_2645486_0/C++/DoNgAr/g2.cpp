#define CO(x) std::cout << #x" = " << x << std::endl
#define fori(i,start,sharpEnd) for(int i = start; i < sharpEnd; i++)
#define fora(i,start,End) for(int i = start; i >= End; i--)
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <climits>
#include <map>
#include <vector>
#include <cassert>
#include <limits>
#include <iomanip>


using namespace std;


#define mm(type,value) memset(type,value,sizeof(type))
#define mat(matrix,h,w) fori(i,0,h){fori(j,0,w)std::cout<<matrix[i][j]<<" ";std::cout<<std::endl;}
#define sw(matrix,h,w,value) fori(i,0,h)fori(j,0,w)matrix[i][j]=value
#define mt(matrix,s) fori(i,0,s)std::cout<<matrix[i]<<" ";std::cout<<std::endl;
#define EPS 10e-8




int act[1000];
int maxi;
int n,r,e;
void bc(int gain, int en, int c){
	if(c == n){
		maxi = max(maxi,gain);
		return;
	}
	if(en == 0)
		return;
		
	fori(i,0,en)
		bc(gain + act[c]* i, min(max(en - i + r,0), e), c + 1);
}

int main()
 {
	//freopen("t.in","r",stdin);
  	// freopen("t.out","w",stdout);
	int ts;
	cin >> ts;
	int cs = 1;
	while(ts--){
		cout << "Case #"<<cs++<<": ";
		
		maxi = 0;
		cin >> e >> r >> n;
		fori(i,0,n){
			cin >> act[i];	
		}
		
		e++;
		fori(i,0,e)
			bc(act[0]* i, min(max(e - i + r,0), e), 1);
		
		cout << maxi << endl;
		
		
	}



 //system("PAUSE");
 return 0;
 }




