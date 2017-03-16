#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;



int main()
{
    freopen("a1.in", "r", stdin);
    freopen("a1.out", "w", stdout);
int no,x,y;
	cin >>no;
	for(int i=0;i<no;i++){
	
	cout<<"Case #"<<i+1<<": ";
	cin>>x>>y;
	if(x>0){
		if(y>0){for(int j=0;j<x;j++)cout<<"WE";	for(int j=0;j<y;j++)cout<<"SN";}
		else  {y=-y;for(int j=0;j<x;j++)cout<<"WE";	for(int j=0;j<y;j++)cout<<"NS";}}
	else{x=-x;
		if(y>0){for(int j=0;j<x;j++)cout<<"EW";	for(int j=0;j<y;j++)cout<<"SN";}
		else  {y=-y;for(int j=0;j<x;j++)cout<<"EW";	for(int j=0;j<y;j++)cout<<"NS";}}
		
		cout<<endl;
	}
    
    return 0;
}
