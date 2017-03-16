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

vector<vector<vector<bool> > > bol;

vector<vector<string> > odpovede;

int CONST=100;

void rekurzia(int x, int y, int krok, string tahy){
	bol[x+CONST][y+CONST][krok]=true;

	if(odpovede[x+CONST][y+CONST]==""){
		odpovede[x+CONST][y+CONST]=tahy;
	}

	if(krok>=501) return;
	
	if((x-krok>=-CONST)&&(bol[x-krok+CONST][y+CONST][krok+1]==false)) {
		tahy.push_back('W');
		rekurzia(x-krok,y,krok+1,tahy);
		tahy.erase(tahy.size()-1,1);
	}
	if((x+krok<=CONST)&&(bol[x+krok+CONST][y+CONST][krok+1]==false)) {
		tahy.push_back('E');
		rekurzia(x+krok,y,krok+1,tahy);
		tahy.erase(tahy.size()-1,1);
	}
	if((y+krok<=CONST)&&(bol[x+CONST][y+krok+CONST][krok+1]==false)) {
		tahy.push_back('N');
		rekurzia(x,y+krok,krok+1,tahy);
		tahy.erase(tahy.size()-1,1);
	}	
	if((y-krok>=-CONST)&&(bol[x+CONST][y-krok+CONST][krok+1]==false)) {
		tahy.push_back('S');
		rekurzia(x,y-krok,krok+1,tahy);
		tahy.erase(tahy.size()-1,1);
	}
}

int main(){
	long long n;
	scanf("%lld",&n);
	long long cas=0;
	string nic="";

	odpovede.resize(1200,vector<string> (1200,""));
	bol.resize(1250,vector<vector<bool> > (1250, vector<bool> (510, false)));
	rekurzia(0,0,1,nic);

	while(n--){
		cas++;
		long long x,y;
		scanf("%lld%lld",&x,&y);
		
		
		
		cout<<"Case #"<<cas<<": "<<odpovede[x+CONST][y+CONST]<<endl;
		//printf("Case #%lld: %lld\n",cas,vysledok);
	}
		return 0;
}

