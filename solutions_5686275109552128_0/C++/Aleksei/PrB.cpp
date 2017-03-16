#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n;
		cin>>n;
		int a[1010];
		for(int i=0; i<n; i++) cin>>a[i];
		int maxD = *max_element(&a[0],&a[n]);
		int rez = maxD;
		for(int maxL = 1; maxL<maxD; maxL++){
			int additional = 0;
			for(int i=0; i<n; i++){
				if(a[i]>maxL){
					int num = a[i]/maxL;
					if(a[i]%maxL==0){
						num--;
					}
					additional+=num;
				}
			}
			rez = min(rez, maxL+additional);
		}
		cout<<"Case #"<<testnum+1<<": "<<rez<<endl;
	}
	return 0;
}
