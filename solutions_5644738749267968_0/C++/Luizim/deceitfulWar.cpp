#include <iostream>
#include <set>


using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n, n1=0, n2=0;
		cin>>n;

		set<double> set1, set2;

		for(int j=0;j<n;j++){
			double aux;
			cin>>aux;
			set1.insert(aux);
		}

		for(int j=0;j<n;j++){
			double aux;
			cin>>aux;
			set2.insert(aux);
		}


		set<double>::iterator it1 = set1.begin(), it2 = set2.begin();

		for(int i=0;i<n;i++){
			if(*it1>*it2){
				n1++;
				it2++;
			}
			it1++;
		}

		set<double>::reverse_iterator rit1, rit2;

		rit1 = set1.rbegin();
		rit2 = set2.rbegin();

		for(int i=0;i<n;i++){
			if(*rit1>*rit2)
				n2++;
			else 
				rit2++;
			rit1++;
		}

		cout<<"Case #"<<i+1<<": "<<n1<<' '<<n2<<endl;
	}
}