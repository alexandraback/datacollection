#include <iostream>
#include <cstdio>
#include "Chelper.h"
using namespace std;

pair<bool, string> bs;
pair<string, string> ss;

map<ss, bs> table;

table[ss('1', '1')] = bs(false, '1');
table[ss('1', 'i')] = bs(false, 'i');
table[ss('1', 'j')] = bs(false, 'j');
table[ss('1', 'k')] = bs(false, 'k');

table[ss('i', '1')] = bs(false, 'i');
table[ss('i', 'i')] = bs(true, '1');
table[ss('i', 'j')] = bs(true, 'k');
table[ss('i', 'k')] = bs(true, 'j');

table[ss('j', '1')] = bs(false, 'j');
table[ss('j', 'i')] = bs(false, 'k');
table[ss('j', 'j')] = bs(true, '1');
table[ss('j', 'k')] = bs(true, 'i');

table[ss('k', '1')] = bs(false, 'k');
table[ss('k', 'i')] = bs(true, 'j');
table[ss('k', 'j')] = bs(false, 'i');
table[ss('k', 'k')] = bs(true, '1');

bool ifJ(char* str, int si, int ei){
	table sum;
	if (str[si] == 'i'){
		sum = i;
	}
	if (str[si] == 'j'){
		sum = j;
	}
	if (str[si] == 'k'){
		sum = k;
	}
	int man = si + 1;
	/* while (man <= ei){

		if (str[man] == 'i'){
			sum = operate(sum, i);
		}
		if (str[man] == 'j'){
			sum = operate(sum, j);
		}
		if (str[man] == 'k'){
			sum = operate(sum, k);
		}
		
		man++;
	} */
	if (sum == j){
		return true;
	}
	return false;	
}

bool mulcheck(int strt, int end, string character)
{
	int negativity = 0;
	string value = '1';

	for(int i = strt;i <= end;i++)
	{
		// TODO: value*S[i];
		bs tmp = table[ss(value, S[i])];
		if(tmp.first)
			negativity++;
		value = tmp.second;
	}
	
	if(negativity % 2 == 0 && character[0] == value[0])
		return true;
	return false;
}

bool bigl(char* str, Node* check){
	vector<int> I;
	vector<int> K;

	bool find = false;
	bool rfind = false;
	bool result = false;
	int x = strlen(str);
	table sum;

	for (int i = 0; i < x; i++){

		char ch = str[i];
		if (i == 0){
			if (ch == 'i'){
				check[i].i = true;
				sum = table::i;
			}
			if (ch == 'j'){
				sum = table::j;
			}
			if (ch == 'k'){
				sum = table::k;
			}
		} else {
			if (ch == 'i'){
				sum = operate(sum, table::i);
			}
			if (ch == 'j'){
				sum = operate(sum, table::j);
			}
			if (ch == 'k'){
				sum = operate(sum, table::k);
			}

			if (sum == table::i){
				check[i].i = true;
			}
			if (sum == table::k){
				check[i].k = true;
			}

			if (i == x - 1 && sum != table::minus_one){
				return false;
			}
		}
		
	}

	for (int i = x - 1; i >= 0; i--){

		char ch = str[i];
		if (i == x-1){
			if (ch == 'i'){
				sum = table::i;
			}
			if (ch == 'j'){
				sum = table::j;
			}
			if (ch == 'k'){
				check[i].reverse_k = true;
				sum = table::k;
				if (i - 1 >= 0 && check[i - 1].k == true && check[i].reverse_k == true){
					K.push_back(i - 1);
				}
			}
		}
	}
	return result;
}

int main(void)
{
	int t, l, x;
	scanf("%d", &t);
	for(int rep =1;rep <= t;rep++)
	{
		scanf("%d%d", &l, &x);
		cin >> dij;
		bool res = bigl(dij, 0);
		if(res)
			printf("Case #%d: YES\n", rep);
		else
			printf("Case #%d: NO\n", rep);
	}
}