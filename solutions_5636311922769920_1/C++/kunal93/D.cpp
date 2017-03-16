#include<bits/stdc++.h>
using namespace std;

long long pw(long long a,long long b){
	if(b==1)
		return a;
	long long c=pw(a,b/2);
	c*=c;
	if(b%2)
		c*=a;
	return c;
}

void eval(){
	int s,c,k;
	cin>>k>>c>>s;
	if(c==1){
		if(s==k)
		{
			for(int i=1;i<=s;i++)
				cout<<i<<" ";
			cout<<endl;
		}
		else
				cout<<"IMPOSSIBLE"<<endl;
		return ;
	}
	vector<long long> soln;
	set<int> st;
	for(int i=1;i<=k;i++){
		st.insert(i);
	}
	for(int i=1;i<=s && st.empty()==false ;i++){
		int elementNo = *(st.begin());
		st.erase(elementNo);
		int chunkNo = 1;
		if(st.empty()==false )
			{
				chunkNo = *(st.begin()); 
				st.erase(chunkNo);
				long long pos = (chunkNo-1)*pw(k,c-1)+elementNo;
				soln.push_back(pos);
			}
		else
			soln.push_back(elementNo);			
	}
	if(st.empty())
		{
			for(int i=0;i<soln.size();i++)
				cout<<soln[i]<<" ";
			cout<<endl;
		}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	for(int te=1;te<=t;te++){
		cout<<"Case #"<<te<<": ";
		eval();
	}
}
