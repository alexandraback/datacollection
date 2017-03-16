#include <iostream>
#include <string>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

// 1 = 1, i = 2, j = 3, k = 4


int s[34567];
int l;
int x;

int multt[4][4] = {
	{1, 2, 3, 4},
	{2, -1, 4, -3},
	{3, -4, -1, 2},
	{4, 3, -2, -1}
};

int mult(int a, int b){
	int un = 1;
	if(a < 0){
		a*=-1; un*=-1;
	}
	if(b < 0){
		b*=-1; un*=-1;
	}
	return un*multt[a-1][b-1];
}

int trans(char c){
	return c == 'i' ? 2 : c == 'j' ? 3 : 4;
}

bool look_for(int needle, int &i){ //našel / nenašel
	int r = 1;
	if(i == l)return false;
	while(r!=needle && i < l){
		r = mult(r, s[i]);
		i++;
		//cout << needle << " " << r << " " << i << endl;
	}
	return r == needle;
}

void go_on(int testNum, bool ok, string str=""){
	cout << "Case #" << testNum+1 <<": " << (ok ? "YES" : "NO") << endl;
}

int main(){
	int tests;
	cin >> tests;
	REP(t, tests){
		string ss;
		cin >> l >> x;
		cin >> ss;
		REP(j, x)REP(i, l){
			s[l*j + i] = trans(ss[i]);
		}
		l*=x;

		int i = 0;
		
		if(!look_for(2, i) || !look_for(3, i) || !look_for(4, i)){
			go_on(t, false, "prvni");
			continue;
		}
		
		int r = 1;
		for(;i<l;i++)r = mult(r, s[i]);


		if(r!=1){
			go_on(t, false, "druhy");
			continue;
		}else{
			go_on(t, true);
		}


	}

	return 0;

}
