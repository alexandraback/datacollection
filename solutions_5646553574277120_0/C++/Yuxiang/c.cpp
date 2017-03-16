#include <bits/stdc++.h>
#include <fstream>
using namespace std;
bool va[50];

int main(){
	ifstream in("C-small-attempt3.in");
	ofstream out("C.out");
	int T;
	in >> T;
	for (int z = 1 ; z <= T ; z++)
	{
		int C, D, V;
		in >> C >> D >> V;
		int k;
		bool test[V + 1];
		for(int i =0; i <= V; i++){
			va[i] = false;
			test[i] = false;
		}
		va[0] = true;
		for(int i = 0; i < D; i++){
			in >> k;
			test[k] = true;
			for(int j = V; j >=k; j--){
				if (va[j-k])
				      va[j] = true;
			}
		}
		int i = 1;
		k = 0;
		while(va[i] && i <= V){
			i++;
		}
		while(i != V+1){
			k++;
			test[i] = true;
			for(int j = V; j >=i; j--){
				if(va[j-i])
					va[j] = true;
			}
			i++;
			while(va[i] && i<=V){
				i++;
			}
		}
		cout << z << ':' << V << ':';
		for (int i = 1 ; i <= V ; i++)
		{
			if (test[i])
				cout << i << ' ';
		}
		cout << endl;
		out << "Case #"<<z<<": "<<k<<endl;
	}
	in.close();
	out.close();
	return 0;
}
