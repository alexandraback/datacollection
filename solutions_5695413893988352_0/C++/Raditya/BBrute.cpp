#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
int t;
int Aans, Bans;
string tempA, tempB;
int len;
void bruteB(string S, string SS, int lenB){
	//printf("DEBUG B %s %s\n", S.c_str(), SS.c_str());
	if(lenB == len){
		int Atemp = stoi(S);
		int Btemp = stoi(SS);
		int abssisa = abs(Atemp - Btemp);
		int absmin = abs(Aans - Bans);
		if(Aans == -1){
			Aans = Atemp;
			Bans = Btemp;
			tempA = S;
			tempB = SS;
		}
		else if(abssisa < absmin){
			Aans = Atemp;
			Bans = Btemp;
			tempA = S;
			tempB = SS;
		}
		else if(abssisa == absmin){
			if(Atemp < Aans){
				Aans = Atemp;
				Bans = Btemp;
				tempA = S;
				tempB = SS;
			}
			else if(Atemp == Aans && Btemp < Bans){
				Aans = Atemp;
				Bans = Btemp;
				tempA = S;
				tempB = SS;
			}
		}
	}
	else{
		if(SS[lenB] == '?'){
			for(int i = 0;i <= 9; ++i){
				string tempSS = SS;
				tempSS[lenB] = i+ '0';
				bruteB(S, tempSS, lenB+1);
			}
		}
		else{
			bruteB(S,SS,lenB+1);
		}
	}
}
void bruteA(string S, string SS, int lenA){
	//printf("DEBUG A %s %s\n", S.c_str(), SS.c_str());
	if(lenA == len){
		bruteB(S,SS,0);
	}
	else{
		if(S[lenA] == '?'){
			for(int i = 0;i <= 9; ++i){
				string tempS = S;
				tempS[lenA] = i + '0';
				bruteA(tempS, SS, lenA+1);
			}
		}
		else{
			bruteA(S,SS,lenA+1);
		}
	}
}
int main(){

	scanf("%d", &t);
	for(int tc = 1; tc <= t; ++tc){
		string A,B;
		cin>>A>>B;
		Aans = -1, Bans = -1;
		len = A.size();
		bruteA(A,B,0);
		printf("Case #%d: %s %s\n", tc,tempA.c_str(), tempB.c_str());
	}
	return 0;
}