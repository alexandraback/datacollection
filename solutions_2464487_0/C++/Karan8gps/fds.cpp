#include <cstdio>
#include <cstring>
#include<cstdlib>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
#define ll long long
#define MOD 1000000007
FILE *on=fopen("on.txt","w");
using namespace std;
int main(){
int t;
cin>>t;int y=0;
 while(t--){y++;
	 long long r,t;
	 cin>>r>>t;
	 long long sco=0,count=0;
	for(int i=0;;i++){
	sco+=((r+i+1)*(r+i+1) -((r+i)*(r+i)));cout<<sco<<endl;
	if(sco>t){break;}count++;
	i++; }
	 fprintf(on,"Case #%d: %d\n",y,count);
	 }
	 fclose(on);
	 return 0;
	}
	
