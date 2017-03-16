#include <cstdlib>
#include <cstdio>
#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>

using namespace std;  

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;

#define PB push_back
#define MP make_pair

using namespace std ;
const int base = 1000 ;
struct node
{
    int x , y , f ;
	int sum ;
} ;
int f[4][2] ;
char d[4] ;
int mark[2001][2001] ;
int X,Y ;
node q[5000000] ;
int s,t ;
bool check(int x,int y)
{
	return (x>=0&&y>=0&&x<=2000&&y<=2000) ;
}

void out_r(int tt)
{
	node rr[1001] ;
	int cnt = 0 ;
	while (t!=-1){
		rr[cnt++] = q[t] ;
		t = q[t].f ;
	}
	for (int i=0;i<cnt/2;i++){
		swap(rr[i],rr[cnt-1-i]) ;
	}
	string out = "" ;
	for (int i=0;i<cnt-1;i++){		
		for (int j=0;j<4;j++){
			if (rr[i+1].x-rr[i].x==(i+1)*f[j][0]&&rr[i+1].y-rr[i].y==(i+1)*f[j][1]){
				out = out + char(d[j]) ;
			}
		}
	}
	cout<<"Case #"<<tt<<": "<<out<<endl ;	
}

int main()
{
	int cs ;
	cin>>cs ;
	d[0] = 'N' ;d[1] = 'S' ; d[2] = 'E' ; d[3] = 'W' ;
	f[0][0] = 0 ; f[0][1] = 1 ; 
	f[1][0] = 0 ; f[1][1] = -1 ;
	f[2][0] = 1 ; f[2][1] = 0 ;
	f[3][0] = -1 ;f[3][1] = 0 ;
	vector<node> res ;
	for (int tt=1;tt<=cs;tt++){
		cin>>X>>Y ;
		X += base ;
		Y += base ;
		memset(mark,0,sizeof(mark)) ;
		node start ;
		start.x = base ; start.y = base ; start.sum = 0 ; start.f = -1 ;
		mark[base][base] = 1 ;
		s = t = 1 ;
		q[s] = start ;
		bool flag = 0 ;
		while (s<=t){
			node curr = q[s] ;
			int l = curr.sum + 1 ;
			for (int i=0;i<4;i++){
				int nx = curr.x + l * f[i][0] ;
				int ny = curr.y + l * f[i][1] ;
				if (check(nx,ny)&&!mark[nx][ny]){
					node next ;
					next.x = nx ; next.y = ny ; next.sum = l ;next.f = s ;
					q[++t] = next ;
					mark[nx][ny] = 1 ;
					if (next.x==X&&next.y==Y){
						out_r(tt) ;
						flag = 1 ;
						break ;
					}
				}
			}
			if (flag==1) break ;
			s++ ;
		}
	}
}
// ----------  end of function main  ---------- 
