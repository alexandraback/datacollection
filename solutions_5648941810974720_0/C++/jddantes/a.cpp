#include <bits/stdc++.h>

using namespace std;

vector<int> letters_left(26, 0);

string input;
int N;

vector<int> dump;

vector<string> dict(10);

bool can(int num){
	string word = dict[num];

	for(int i = 0; word[i]; i++){
		if(!letters_left[word[i]-'A']){
			return false;
		}
	}

	return true;

}

bool used_up(){
	for(int i = 0; i<26; i++){
		if(letters_left[i]){
			return false;
		}
	}

	return true;
}

void use_num(int num){
	string word = dict[num];
	for(int i = 0; word[i]; i++){
		letters_left[word[i]-'A']--;
	}
}
void revert_num(int num){
	string word = dict[num];
	for(int i = 0; word[i]; i++){
		letters_left[word[i]-'A']++;
	}
}

int f(int ub){

	// printf("ENtered %d\n", ub);

	if(used_up()){
		// printf("Used up\n");
		for(auto num : dump){
			printf("%d", num);
		}
		printf("\n");
		return 1;
	}

	if(ub == 10){
		// printf("lower bounds\n");
		return 0;
	}

	for(int num = ub; num<=9; num++){
		if(can(num)){
			use_num(num);
			dump.push_back(num);
			// printf("Trying out num %d\n", num);
			int ret = f(num);
			dump.pop_back();
			revert_num(num);

			if(ret) return 1;
		}	
	}

	return 0;
}

int main(){
	dict[9] = "NINE";
	dict[8] = "EIGHT";
	dict[7] = "SEVEN";
	dict[6] = "SIX";
	dict[5] = "FIVE";
	dict[4] = "FOUR";
	dict[3] = "THREE";
	dict[2] = "TWO";
	dict[1] = "ONE";
	dict[0] = "ZERO";


	int cases;

	scanf("%d", &cases);

	for(int e = 0; e<cases; e++){
		printf("Case #%d: ", e+1);

		cin >> input;
		N = input.size();

		letters_left.assign(26, 0);

		for(int i = 0; i<N; i++){
			char c = input[i];
			letters_left[c-'A']++;
		}

		f(0);

	}

	return 0;
}