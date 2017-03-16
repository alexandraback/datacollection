#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define dprintf //printf



unsigned int K, L, S;
char keys[100];
char word[100];
int kcnt[256];


int word_substr_len() {	
	for (int i = 1; i < L; i++) {
		bool found = true;
		for (int j = 0; i + j < L; j++) {
			if (word[i + j] != word[j]) {
				found = false;
				break;
			};
		};
		if (found)
			return i;
	};
	return 0; // no luck
};


bool could_the_word_be_typed(){
	for (int i = 0; i < L; i++) 
		if (!kcnt[word[i]])
			return false;
	return true;
};


int get_max_cnt() {
	// is the word accessible with this keyboard?
	bool accessible = could_the_word_be_typed();
	if (!accessible) 
		return 0;
	// can it overlap?
	int substr_len = word_substr_len();
	if (!substr_len)
		return S / L;
//	dprintf("INFO: superposition from idx %d\n", substr_len);
	int rez = 0, tmp_S = S;
	while (tmp_S >= L) {
		rez++;
		tmp_S -= substr_len;
	};
	return rez;
};


double get_direct_word_type_probability() {
	double prob = 1.0d;
	for (int i = 0; i < L; i++) {
		prob *= (double)kcnt[word[i]];
		prob /= (double)K;
	};
	return prob;
};


double get_estimated_cnt() {
	// the most probable number of words we'll get
	return get_direct_word_type_probability();
};


int solve(int ctry){
	scanf("%u %u %u", &K, &L, &S);
	char t;
	scanf("%c", &t);
	for (int i = 0; i < K; i++)
		scanf("%c", keys + i);
	scanf("%c", &t);
	for (int i = 0; i < L; i++)
		scanf("%c", word + i);
	keys[K] = word[L] = 0;
	
	// better structure for checking the probabilities or presence
	memset(kcnt, 0, sizeof(kcnt));	
	for (int i = 0; i < K; i++)
		kcnt[keys[i]]++;
	
	dprintf("INFO: L = %d, S = %d, overlap: %d, word |%s|, keys: |%s|\n", L, S, word_substr_len(), word, keys);
	// first, how many times the string could fit?
	double rez = get_max_cnt();
	// and how probable is it?
	rez -= rez * get_estimated_cnt();
	printf("Case #%d: %0.12f\n", ctry, rez);
};


int main(){

	if (freopen("test.in", "rt", stdin)){
//		freopen("A-large-practice.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	if (freopen("B-small-attempt1.in", "rt", stdin)){
		freopen("B-small-attempt1.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	if (freopen("A-large-practice.in", "rt", stdin)){
		freopen("A-large-practice.out", "wt", stdout);
		int tries = 0;
		scanf("%d", &tries);
		for (int ctry = 1; ctry <= tries; ctry++){
			solve(ctry);
		};
	};
	return 0;
};