#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;




int DP[20][2000000];

int getnumber (int A[], int n, int i, int t)
{
	if (i==n)
		return 0;
	if (t<0)
		return 0;
	if (t==0){
		DP[i][t]=1;
		return 1;
	}

	int val1 = getnumber(A,n,i+1,t-A[i]);
	int val2 = getnumber(A,n,i+1,t);

	DP[i][t]=val1+val2;
	return val1+val2;
}

void print1 (int A[],int n, int i, int t, ofstream &cout)
{
	if (i==n)
		return;
	if (t==0)
		return;
	if (t<0)
		return;

	if (DP[i+1][t-A[i]]>=1){
		cout<<A[i]<<' ';
		print1(A,n,i+1,t-A[i],cout);
	}
	else
		if (DP[i+1][t]>=1)
			print1(A,n,i+1,t,cout);

	return;
}

void print2(int A[],int n, int i, int t, ofstream &cout)
{
	if (i==n)
		return;
	if (t==0)
		return;
	if (t<0)
		return;

	if (DP[i+1][t]>=1)
			print2(A,n,i+1,t,cout);
	else
		if (DP[i+1][t-A[i]]>=1){
			cout<<A[i]<<' ';
			print2(A,n,i+1,t-A[i],cout);
		}

	return;
}

int main ()
{
	ifstream cin;
	cin.open("C-small-attempt2.in");
	ofstream cout;
	cout.open("equal_small.out");

	int T, N, A[600];

	cin>>T;

	for (int t=1; t<=T; t++)
	{
		cin>>N;
		int S=0;
		for (int i=0; i<N; i++){
			cin>>A[i];
			S+=A[i];
		}

		fill(&DP[0][0],&DP[0][0]+20*(S+10),-1);

		int num, tar;
		for (int target=0; target<S; target++){	
			 num = getnumber(A,N,0,target);
			 if (num>=2){
				 tar=target;
				 break;
			 }
		}
		cout<<"Case #"<<t<<":"<<endl;
		print1(A,N,0,tar,cout);
		cout<<endl;
		print2(A,N,0,tar,cout);
		cout<<endl;
	}


	return 0;
}