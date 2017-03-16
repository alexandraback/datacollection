/*
 * b.cpp
 *
 *  Created on: May 10, 2015
 *      Author: dimalit
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;

namespace B{

int S;			// string length
int L;			// word length
int K;			// key count
string keys;
string word;

int key_repeats[256];
double word_prob;

void fill_key_repeats(){
	for(int i=0; i<266; i++)
		key_repeats[i] = 0;

	assert(keys.length() == K);
	for(int i=0; i<K; i++)
		key_repeats[keys[i]]++;
}

void fill_word_prob(){
	if(S < L){
		word_prob = 0.0;
		return;
	}

	word_prob = 1.0;

	assert(word.length() == L);
	for(int i=0; i<L; i++)
		word_prob *= key_repeats[word[i]] / (double)K;
}

int count_common_chars(const string& a, const string& b){
	int i = 0;
	while(i<a.length() && i<b.length() && a[i]==b[i])
		i++;
	return i;
}

int get_ceiling(){
	int max_shift = S - L;
	if(max_shift < 0)
		return 0;

	int found = 0;
	int last_begin = 0;
	for(int i=0; i<=max_shift; i++){
		int common = count_common_chars(word.substr(i-last_begin), word);
		if(common == word.length()-(i-last_begin)){
			found++;
			last_begin=i;
		}
	}
	return found;
}

bool have_all_keys(){
	for(int i=0; i<L; i++)
		if(key_repeats[word[i]]==0)
			return false;
	return true;
}

void test_ceiling(){
	word = "aaa";
	L = word.length();
	S = 2;
	int c = get_ceiling();
	cout << c;
}

double one_test(){
	cin >> K >> L >> S;
	cin >> keys >> word;

	fill_key_repeats();
	fill_word_prob();

	int max_shift = S - L;
	double mean = word_prob*(max_shift+1);
	int ceiling = get_ceiling();
	if(!have_all_keys())
		ceiling = 0;
	return ceiling - mean;
}

int main(){
	int T;
	cin >> T;

	cout.precision(7);
	cout.setf(ios::fixed);
	for(int t=0; t<T; t++){
		cout << "Case #" << (t+1) << ": " << one_test() << endl;
	}

	return 0;
}// main

}

int main(){
	freopen("a_small.in", "rb", stdin);
	freopen("a_small.out", "wb", stdout);
	return B::main();
	//B::test_ceiling();
	return 0;
}
