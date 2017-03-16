/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

int solve(int cc){
    string str;

    cin>>str;
    int len = str.length();
    string sol;
    for(int i=0;i<len;i++){
        if(i==0||str[i]<sol[0]){
            sol+=str[i];
        }else{
            sol=str[i]+sol;
        }
    }
    cout<<"Case #"<<cc<<": "<<sol<<endl;

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }

	return 0;
}
