
/*

Google Code Jam 2015
Qualification Round
Problem C
Dijkstra

Instructions:
	gcc -std=gnu99 -o process process.c
	./process <input_file >output_file

Notes:
	* decided to code the input before I think about this one, because I so often get to the input and suddenly find I'm tripped up by some unexpected aspect of it that changes the nature of the problem
	* associativity means we can combine the result of arbitrary sequences to get the result of concatenating those sequences
	* this allows us to eg. build up a table of results for all possible substrings, quite efficiently
		* 1 quaternion multiplication per cell, to be exact
		* and it turns out you don't need associativity to do that
	* of course for the large dataset, such a table would be prohibitively huge, based on the full L*X string
	* even for the small dataset, I wouldn't want to do that (100,000,000 cells)
	* is it possible to work out a "division" operation of some kind, to remove a factor from either the beginning or the end of a segment, and calculate the new result from the old result?
		* I think it is...
		* x / y = z
		* what, when multiplied by y, gives x?
		* look in the y column for the vaue x, and take the label of that row, adjusting for sign
		* this always gives a unique answer
		* no reason we can't just work out the division tables manually and program them in
		* we may have 2 division tables, depending on which side we wish to remove a letter
		* this will allow us to shift the division point between 2 substrings by a character and calculate the updated results in O(1) time
		* I think it will be easiest to think about if we produce functions with names like push, pop, shift, unshift, which have a well-established meaning for me
		* note that this implies 2 kinds of multiplication operations also, although it's just a matter of swapping the argument order to get one from the other
		* being able to incrementally calculate the products like this will hopefully remove any need to build large tables
	* so with our division operation, the problem reduces down to shifting 2 division points to any position in the string
	* that's (n**2)/2 combinations, I believe (since the 2nd division is always positioned after the first) - of course that's O(n)
	* but if we simply work with the expanded strings, n is L*X which is huge
	* initially, I'll solve it for the small dataset
	* notes for the large dataset:
		* any string longer than L is going to consist of a start, end and a repeat of no more than X instances of the L string in the middle
		* associativity allows us to take the product of 1 repetition, the repeat count, and instantly get the result, then tack the ends on with just a couple more multiplications
	
	
	* solving for the small dataset:
		* first thing: what's my data representation?
		* a value can be i,j,k,1, plus it has a sign
		* I could simply use a single character each - ijk1IJK2 or something
		* I'll probably autogenerate the 3 other tables from the initial multiplication table
		* I'll use a dict mapping from pairs to single values as the tables
		* maybe even don't bother with a function for it
		* okay, let's simply use 'i', 'j', 'k', '-i', '-j', '-k' and 1, -1
		* with our tables, we'll basically be treating them as atomic values, anyway
		* I was hoping it would just scrape under, but it didn't quite make it
			* it took 264 seconds, after I set the worker threads to 8
			* what's worse, many of these are high L low X, meaning any optimisation to use the repetition won't help with them
			* the large dataset may very well have many cases with L near 10000
	
	* taking advantage of repetition:
		* 
	
	* other optimisation:
		* can we avoid iterating over every possible substring (even for X=1)?
		* 
	
	* I'm just going to write it in C - same algorithm for now
	* this will handle the small dataset, but not the large


*/

#include <stdio.h>

int debug = 0;

char values[] = "1ijk-IJK";

char table_base[4][4] = {
	"1ijk",
	"i1kj",
	"jk1i",
	"kji1"
};

char table_sign[4][4] = {
	"....",
	".x.x",
	".xx.",
	"..xx"
};

char push[8][8];
char shift[8][8];
char rvalues[0x100];


void dump(char (*table)[8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			fprintf(stderr, "%c", values[table[i][j]]);
		}
		fprintf(stderr, "\n");
	}
}

char build(char base, char sign) {
	return ((sign < 0 ? 1 : 0) << 2) | base;
}

void init(void) {
	// init rvalues from values
	for (int i = 0; i < 0x100; i++) rvalues[i] = 0;
	for (int i = 0; i < 8; i++) rvalues[values[i]] = i;
	
	// init push/shift frmo table_sign and table_base
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int isign = (i >> 2) ? -1 : 1;
			int jsign = (j >> 2) ? -1 : 1;
			int ibase = i & 3;
			int jbase = j & 3;
			
			char sign = isign * jsign * ((table_sign[ibase][jbase] == 'x') ? -1 : 1);
			char base = rvalues[table_base[ibase][jbase]];
			
			char a = build(ibase, isign);
			char b = build(jbase, jsign);
			char c = build(base, sign);
			
			push[a][b] = c;
			shift[c][a] = b;
		}
	}
	
	if (debug) {
		fprintf(stderr, "\npush table\n");
		dump(push);
		fprintf(stderr, "\nshift table\n");
		dump(shift);
	}
}

int solve(int L, int X, char *line) {
	// build the expanded string (won't cut it in the large dataset)
	int LX = L * X;
	char seq[LX + 1];
	for (int i = 0; i < L; i++) {
		char ch = rvalues[line[i]];
		for (int j = 0; j < X; j++) seq[j * L +i] = ch;
	}
	seq[LX] = 0;
	
	if (debug) fprintf(stderr, "L: %d, X: %d, line: %s\n", L, X, line);
	
	char pi0 = 0;  // 0 => '1' => identity value
	char pj0 = 0;
	char pk0 = 0;
	for (int i = 0; i < LX; i++) {
		if (debug) fprintf(stderr, "%c ", values[pk0]);
		pk0 = push[pk0][seq[i]];
		if (debug) fprintf(stderr, "* %c = %c\n", values[seq[i]], values[pk0]);
	}
	
	for (int i = 0; i < LX; i++) {
		char pi1 = pi0;
		char pj1 = pj0;
		char pk1 = pk0;
		
		for (int j = i; j < LX; j++) {
			
			if (debug) {
				fprintf(stderr, "sizes: %d %d %d\n", i, j - i, LX - j);
				fprintf(stderr, "characters: %c%c%c\n", values[pi1], values[pj1], values[pk1]);
				fprintf(stderr, "values: %d %d %d\n", pi1, pj1, pk1);
			}
			
			if (pi1 == 1 && pj1 == 2 && pk1 == 3) return 1;
			
			// shift off k string onto j string
			pk1 = shift[pk1][seq[j]];
			pj1 = push[pj1][seq[j]];
		}
		
		// shift off k string, through 0-width j string, onto i string
		pk0 = shift[pk0][seq[i]];
		pi0 = push[pi0][seq[i]];
	}
	
	return 0;
}

int main(int argc, char *argv) {
	init();
	
	int T;
	scanf("%d\n", &T);
	
	for (int testcase = 1; testcase <= T; testcase++) {
		int L, X;
		scanf("%d %d\n", &L, &X);
		char line[10003];
		fgets(line, 10003, stdin);
		
		printf("Case #%d: %s\n", testcase, solve(L, X, line) ? "YES" : "NO");
	}
	
	return 0;
}


