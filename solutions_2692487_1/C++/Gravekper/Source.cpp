#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;

	in>>T;
	
	for(int q=1;q<=T;q++){
		int A,N;
		int min;
		vector<int> v;

		in>>A>>N;

		for(int i=0;i<N;i++){
			int t;
			in>>t;
			v.push_back(t);
		}
		sort(v.rbegin(),v.rend());

		if(A==1){
			out<<"Case #"<<q<<": "<<N<<endl;
			continue;
		}

		min=N;
		for(int ab=0;v.size()>0;ab++){
			if(ab>0)A+=A-1;
			for(int i=v.size()-1;i>=0 && A>v[i];i--){
				A+=v[i];
				v.pop_back();
			}
			if(v.size()+ab<min) min=v.size()+ab;
		}
		
		out<<"Case #"<<q<<": "<<min<<endl;

	}

	return 0;
}