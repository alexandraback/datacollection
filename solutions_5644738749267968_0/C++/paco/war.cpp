#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int dwar(vector<float> Naomi,vector<float> Ken,int N) {
	
	int first=0;
	int last=N-1;
	
	int count=0;
	for(int i=0;i<N;i++) {
		if(Naomi[i]<Ken[first]) 
			last--;
		else {
			first++;
			count++;
		}
	}
	
	return count;
}

int playwar(vector<float> Naomi,vector<float> Ken,int N) {
	int points=0;
	int first=0;
	int last=N-1;
	for(int i=0;i<N;i++) {
		while(Ken[first]==0) first++;
		while(Ken[last]==0) last--;
		if(Naomi[i]>Ken[last]) {
			Ken[first]=0;
			points++;
		} else {
			int j=first;
			while(Ken[j]<Naomi[i]) j++;
			Ken[j]=0;
		}
	}
	return points;
}

int war(vector<float> Naomi,vector<float> Ken,int N) {

	int points=0;
	do {
		int p=playwar(Naomi,Ken,N);
		points=p>points?p:points;
	} while( next_permutation(Naomi.begin(),Naomi.end()));

	return points;
}


int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=0; n<nCases; n++) {
		
		cout<<"Case #"<<n+1<<": ";
		
		int N;
		cin>>N;
		vector<float> Naomi(N,0);
		vector<float> Ken(N,0);
		for(int i=0;i<N;i++) 
			cin>>Naomi[i];
		for(int i=0;i<N;i++) 
			cin>>Ken[i];
		sort(Naomi.begin(),Naomi.end());
		sort(Ken.begin(),Ken.end());
		cout<<dwar(Naomi,Ken,N);
		cout<<" ";
		cout<<war(Naomi,Ken,N);
		cout<<endl;
	}

	return 0;
}
