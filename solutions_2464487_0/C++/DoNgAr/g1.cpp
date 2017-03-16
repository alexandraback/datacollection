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






int main()
 {
	//freopen("t.in","r",stdin);
  	// freopen("t.out","w",stdout);
	int ts;
	cin >> ts;
	int cs = 1;
	double a,b;
	while(ts--){
		cout << "Case #"<<cs++<<": ";
		
		cin >> a >> b;
		int sum = 0;
		long long int c = (a+1)*(a+1) - a*a;
		int g = 0;
		while(c <= b){
			sum++;
			g+=2;
			c += (a+g+1)*(a+g+1) - (a+g)*(a+g);
		}
		cout << sum << endl;
		
		
		
		
	}



// system("PAUSE");
 return 0;
 }




