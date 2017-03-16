#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

vector<int> knihy;

bool jeSpol(char c){
	if((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u')){
		return false;
	}
	else return true;
}

vector<string> slova;

vector<vector<int> > nakolko;

int main(){
	long long n;
	scanf("%lld",&n);
	long long cas=0;
	while(n--){
		cas++;
		
		char a[1000000];
		scanf("%s",a);
		long long kolko;
		scanf("%lld",&kolko);
		string slovo=a;
		
		long long spoluhlasok=0;
		long long minule=0;
		long long vysledok=0;

		for(int i=0; i<kolko-1; i++){
			if(jeSpol(slovo[i])) spoluhlasok++;
		}
		for(int i=kolko-1; i<slovo.size(); i++){
			if(jeSpol(slovo[i])) spoluhlasok++;
			if((i-kolko>=0)&&(jeSpol(slovo[i-kolko]))) spoluhlasok--;

			if(spoluhlasok==kolko){
				//cout<<i<<endl;
				vysledok+=(slovo.size()-i)*((i-kolko+2)-minule);		
				minule=(i-kolko)+2;
			}
			
		}

		printf("Case #%lld: %lld\n",cas,vysledok);
	}
		return 0;
}

