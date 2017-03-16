#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

string shift(string a){
	string b; 
	for (int i=1;i<a.size();i++) b.push_back(a[i]);
	b.push_back(a[0]);
	return b; 
}

long shiftset(long aa,long low , long up){
	stringstream ss; 
	ss<<aa;
	string a; 
	ss>>a;

	vector<long> v; 
	string y;
	y= a; 
	do{
		y= shift(y);
		stringstream ss; 
		ss<<y;
		long yy;
		ss>>yy;
		if ( y[0]!='0' &&  yy>=low && yy<=up ) v.push_back(yy);
	}while (a.compare(y)!=0);
	sort(v.begin(), v.end());
  if (v.front()==aa) return v.size(); 
  
	return 0; 
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	
	long T, A, B;

	cin>>T; 
	for (int iT=0 ;iT<T;iT++){
	  cin>>A>>B; 
	  long sum =0;
	  for (long i= A; i<=B;i++) {
	    long num = shiftset(i, A, B); 
	    sum+=num*(num-1)/2;
	  }
	  cout<<"Case #"<<iT+1<<": "<<sum<<endl;
	}
	
}
