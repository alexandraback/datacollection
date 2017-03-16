#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
using namespace std;
int table [4][4]={{1,57,58,59},{57,-1,59,-58},{58,-59,-1,57},{59,58,-57,-1}};
int mult(int e,int f)
{
int a=abs(e);
int b=abs(f);
int c,d;
if(a==1){c=0;}
else if(a>3){c=a-56;}
if(b==1){d=0;}
else if(b>3){d=b-56;}
if(e*f>=0)return table[c][d];
else return -1*table[c][d];
}
int multiply(string a)
{
int ans=a[0]-'0';
for(int i=1;i<a.size();i++)
{
ans=mult(ans,a[i]-'0');

}
return ans;
}
int che(string a)
{
int check1=0;int check2=0;
int i=0;
int j=a.size()-1;
for(i=0;i<a.size();i++){string b;
b.clear();
b.append(a.begin(),a.begin()+i+1);
if(multiply(b)==57){check1=1;break;}
}
for(j=a.size()-1;j>=0;j--){
string b;
b.clear();
b.append(a.begin()+j,a.end());
if(multiply(b)==59){check2=1;break;}}
if(check1*check2==1&&i<j){return 1;}
return 0;

}


int main()
{
    ifstream input;
    input.open("C-small-attempt0.in");
    ofstream output;
    output.open("output.txt");
    int cse=1;
    int t;
    input>>t;

    while(cse<=t)
    {
	int ans=0;
	int poss=1;
	int x,l;
	string a;
	input>>l>>x>>a;
	int b=multiply(a);
	if(l*x<3||x%4==0||b==1){poss=0;}
	else if(b==-1&&x%2==0){poss=0;}
	if(x%2==1&&b>1){poss=0;}
	if(x%2==1&&b<-1){poss=0;}
	if(poss==1)
	{
	if(x<10){

string b;
for(int i=0;i<x;i++){b.append(a.begin(),a.end());}cout<<b<<endl;
if(che(b)==0){poss=0;}
	}
    else if(x>=10){

string b;
for(int i=0;i<10;i++){b.append(a.begin(),a.end());}cout<<b<<endl;
if(che(b)==0){poss=0;}
	}




	}


if(poss==0){        output<<"Case #"<<cse<<": NO"<<endl;
        cout<<"Case #"<<cse<<": NO"<<endl;}
        else{        output<<"Case #"<<cse<<": YES"<<endl;
        cout<<"Case #"<<cse<<": YES"<<endl;}
        cse++;
    }

    return 0;
}
