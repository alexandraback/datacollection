#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	int t,te;
	int i,j,l;
	int a,b,k;
	cin>>t;
	for(te=1;te<=t;te++){
		int ans=0;
		cin>>a>>b>>k;
		for(i=0;i<k;i++)
			for(j=0;j<a;j++)
				for(l=0;l<b;l++)
					if((l&j)==i)
						ans++;

		cout<<"Case #"<<te<<": "<<ans<<endl;

	}
	return 0;
}