
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;

typedef long double LD;

int N;
int main(){

    int TC,c,d,a,b;

    scanf("%d",&TC);
    int casenum =1 ;
    
    while(TC--){

        cin >> N;
        vector<double> naomi, ken;
        ken.clear();
        double tmp;
        for(int i = 0; i < N; i++){
            cin >> tmp;
            
            naomi.push_back(tmp);
        }
     
        for(int i = 0; i < N; i++){
            cin >> tmp;
            
            ken.push_back(tmp);
        }

        sort(ken.begin(), ken.end());
        sort(naomi.begin(), naomi.end());
        /*for(int i = 0; i < N; i++){
            cout << naomi[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < N; i++){
            cout << ken[i] << " ";
        }
        cout << endl;*/
        int nindex=0, kindex = 0;
        int count = 0;
        while(nindex < N && kindex < N){
            
            while(ken[kindex] < naomi[nindex] && kindex < N){
                kindex++;
            }
            kindex++;
            nindex++;
            
        }


	int n = N-1;
	int nk = N-1;
	int matches = 0;
	while(n >= 0 && nk >= 0){
		while(ken[nk] > naomi[n] && nk >= 0){
			nk--;
		}
		// match found
		if(nk >= 0 && ken[nk] < naomi[n]){
			 matches++;
			//cout << nk << ": " << ken[nk] << " " << n << ": " << naomi[n] << endl;
		}
		n--;
		nk--;
	}
          
        cout << "Case #" << casenum++ << ": " << matches << " " << kindex-nindex  << endl;
    }
    
}
