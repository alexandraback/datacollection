//Template

// By Anudeep :)
//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

//M lazy ;)
typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vs;
typedef pair< int ,int > pii;
typedef vector <ll> vll;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

int arr[10];

bool check2(int a,int b,int k) {
	rep(i,k) if(!(arr[i]==1 || a==arr[i] || b==arr[i] || a*b==arr[i])) return false;
	return true;
}
bool check3(int a,int b,int c,int k) {
	rep(i,k)
	if(!(arr[i]==1 || a==arr[i] || b==arr[i] || c==arr[i] || a*b == arr[i] || b*c==arr[i] || a*c==arr[i] || a*b*c == arr[i])) return false;
	return true;
}
	
int main() {
	int r,n,m,k,x,a1,a2,a3;
	scanf("%d%d",&r,&r);
	scanf("%d%d%d",&n,&m,&k);
	printf("Case #1:\n");
	int bad=0;
	rep(i,n) bad = bad*10 + 2;
	rep(das,r) {
		rep(i,k) scanf("%d",arr+i);
		int flag = 1;
		if(n==1) {
			rep(i,k) if(i>0 && arr[i] != arr[0]) flag=0;
			if(flag==0) break;
			a1 = arr[0];
		}
		else if(n==2) {
			a1 = -1;
			for(int a=2; a<=m; a++)
				for(int b=2; b<=m; b++) if(check2(a,b,k)) { a1 = a; a2 = b; break; }
			if(a1==-1) flag = 0;
		}
		else if(n==3) {
			a1 = -1;
			for(int a=2; a<=m; a++)
				for(int b=2; b<=m; b++)
					for(int c=2; c<=m; c++) if(check3(a,b,c,k)) { a1 = a; a2 = b; a3 = c; break; }
			if(a1==-1) flag = 0;
		}
		// printf("%d %d\n",flag,check3(3,4,3,4));
		if(flag==0) printf("%d\n",bad);
		else {
			printf("%d",a1);
			if(n>1) printf("%d",a2);
			if(n>2) printf("%d",a3);
			printf("\n");
		}
	}
	return 0;
}