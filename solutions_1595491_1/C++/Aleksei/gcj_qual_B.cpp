#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n, s, p;
		cin>>n>>s>>p;
		vector<int> t(n);
		vector<int> rez(n,0), rezs(n,0);
		for(int i=0; i<n; i++) cin>>t[i];
		sort(t.begin(),t.end());
		for(int a=0; a<=10; a++){
			for(int b=a; b<=a+2; b++){
				for(int c=a; c<=a+2; c++){
					int sum = a+b+c;
					int poz = upper_bound(t.begin(),t.end(),sum)-t.begin();
					if(poz<=0) continue;
					poz--;
					int r = max(a,max(b,c));
					while(poz>=0 && t[poz]==sum){
						if(abs(a-b)>=2 || abs(b-c)>=2 || abs(a-c)>=2){
							rezs[poz] = max(rezs[poz],r);
						}else{
							rez[poz] = max(rez[poz],r);
						}
						poz--;
					}
				}
			}
		}
		int all = 0;
		for(int i=0; i<n; i++){
			if(rez[i]>=p) all++;
			else if(rezs[i]>=p && s>0){ all++; s--; }
		}
		cout<<"Case #"<<testnum+1<<": "<<all<<endl;
	}
	return 0;
}
