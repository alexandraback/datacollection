#include<iostream>
#include<vector>

using namespace std;

char mult(char a,char b,int &asign) {
	if(a=='1') return b;
	if(a=='i') {
		if(b=='i') {asign*=-1;return '1';}
		if(b=='j') {return 'k';}
		if(b=='k') {asign*=-1;return 'j';}
	}
	if(a=='j') {
		if(b=='j') {asign*=-1;return '1';}
		if(b=='k') {return 'i';}
		if(b=='i') {asign*=-1;return 'k';}
	}
	if(a=='k') {
		if(b=='k') {asign*=-1;return '1';}
		if(b=='i') {return 'j';}
		if(b=='j') {asign*=-1;return 'i';}
	}
}

int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=1; n<=nCases; n++) {
		cout<<"Case #"<<n<<": ";
		int L,X;
		cin>>L>>X;
		char sum='1';
		int sign=1;
		bool hasi=false;
		bool hasj=false;
		char a;
		vector<char> b(L);
		for(int j=0;j<X;j++) {
			for(int i=0;i<L;i++) {
				if(j==0) {
					cin>>a;
					b[i]=a;
				}
				sum=mult(sum,b[i],sign);
				if(!hasi) {
					if(sum=='i' && sign==1) hasi=true;
				} 
				else if(!hasj) {
					if(sum=='k' && sign==1) hasj=true;
				}
			}		
		}
		if(sum=='1' && sign==-1 && hasi && hasj) cout<<"YES\n";
		else cout<<"NO\n";		
	}

	return 0;
}
