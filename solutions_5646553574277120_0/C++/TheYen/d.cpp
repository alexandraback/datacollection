#include <algorithm>
#include<bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
 #include<stdio.h>

using namespace std;

int dpn[31][100], dpa[31][100];

int arr[9]={0,1,1,0,1,0,0,0,1};
int arr2[5]={1,2,4,8,16};


int main() {
	 freopen("C-small-attempt0.in","r",stdin);
    freopen("kkkn.out","w",stdout);

	int test,p=0;
	cin >> test;
	while(test--)
	{

	int c,d,v,i=0;
	cin>>c>>d>>v;
	int dd[d];
	  printf("Case #%d: ",++p);
	for(i=0;i<d;i++)
	cin>>dd[i];
	vector<int> vec;
	vector<int> :: iterator  it;
		int s=0;

	for(i=1;i<=v;i++)
	{
		if(s<v)
		{
			s+=i;
			vec.push_back(i);
		}
		else
		break;
	}
	int n=i;
	 s=0;
	for(i=0;;i++)
	{
		if(s<v)
		s+=arr2[i];

		else
		break;
	}

	int a=i;


	for(i=0;i<d;i++)
	{
		it=find(vec.begin(),vec.end(),dd[i]);
		if(it!=vec.end()){
			--n;
		}
		if(arr[dd[i]])
			--a;

	}


	if(a<n)
	cout<<a<<endl;
	else
	cout<<n<<endl;

	}
return 0;
}
