#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int T;
long long pal[100];

int main() {
	int t;
	long long tot=0, i=0, a, b, cont;

	ifstream f1("temp2");
	do {
		f1>>pal[tot];
		tot++;
	} while(!f1.eof());
	f1.close();

	//for(i=0; i<tot; i++) cout<<pal[i]<<endl;
	
    cin>>T;
    for(t=0; t<T; t++) {
		cout<<"Case #"<<t+1<<": ";
		cin>>a>>b;
		cont=0;
		for(i=0; i<tot; i++) if(pal[i]>=a && pal[i]<=b) cont++;
		cout<<cont<<endl;
	}

	return 0;
}
