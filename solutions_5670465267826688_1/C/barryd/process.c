
/*

Google Code Jam 2015
Qualification Round
Problem C
Dijkstra

Instructions:
	gcc -std=gnu99 -O3 -o process process.c
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
	
	* I'm just going to write it in C - same algorithm for now
	* this will handle the small dataset, but not the large
	
	
	* taking advantage of repetition:
		* WARNING: performing a modulus operation on each string lookup doubled the run time of the program on the small-0 dataset (from 4 to 8 seconds)
			* I can only imagine that this will be offset by the increases in speed once we start taking advantage of X.
			* Even if it slows down the small datasets, it should definitely improve the large.
		* any sequence can be collapsed into a single value by multiplying it
		* the resulting value can then be used to multiply another value by the sequence in 1 operation
		* if the resulting value is 1 (the identity), the sequence can be "appended" any integral number of times with no effect to the result
		* but in the general case, the product of our repating sequence will not be 1
		* any substring of length L will contain the repeating sequence, though possibly rotated by some amount
		* does the rotation affect the resulting product?
			* a rotation by 1 character shifts that character off the beginning and pushes that same character onto the end
			* if we consider a sequence of 2 characters, a rotation would be equivalent to switching the order of the arguments
			* since we have been told the operation is not commutative, we know this kind of switch is not in general going to preserve the result
			* so no, the product is not preserved through rotation
		* so my current thought is that we retain basically the same loops, but add some code to adjust the loop variables to skip over redundant sections
			* the risk is that we make a mistake in identifying the redundant sections, and miss a solution, getting a false negative
			* clearly in the inner loop, we just have to skip over anything that will result in values we've already seen for the j and k products
		* j and k change in sync in the inner loop - a character is shifted off k and into j
			* so is there some correspondence between the two that is preserved by this shift/push operation?
			* if so, we could do a quick analysis to determine that it's impossible to ever get both j and k, and don't bother to do the inner loop at all
			* and if it's possible, we could determine (statically) that it will happen within the first eg. 16 duplicates of the L string
				* but 10000 * 16 is still a lot of characters to check - though it's the worst case
				* perhaps 
			* I *think* we can get the full set of "equivalences" to jk by taking jk and applying this operation to it once for each of the 8 values
				* there are only 3 values in the string, but when combined in sequences, these can be equivalent to any of the 8 different values, and no others
				* furthermore, at the beginning of the inner loop, the j product is always 1, so there will probably be a specific value that k has to be for it to be possible to get ijk...
				* well... if there *is* just a single value, it would be the product "jk", which is i
				* and thinking about this has made me realise the obvious: we shouldn't do the inner loop if the i product is not i
				* with these realisations, the python version will probably be fine
				* it worked - I got the same results on the small dataset, in less than a second
				* and the python version now does the small datasets in under 10 seconds (9 seconds for small-0, 6 for small-1)
					* that's with 1 worker thread - I moved to work and my multithreading template doesn't work with the python installation here (no time to debug it)
					* it seems to be mainly delayed on some specific test cases, probably designed to break this particular optimisation
			* we can apply a similar filter to the outer loop, not executing it unless we can achieve ii, which means we must begin with... 1-
			* so... it's not possible unless the entire product of the string is -1?  I should have realised this earlier
		* these latest optimisations are very promising, but unfortunately they doesn't improve the worst case, so we'd be gambling to take on the large dataset at this time
		* my python program still builds the full string explicitly, which slows it down before the new optimisations can take effect
		* the worst case is perhaps...
			* i, followed by some repeating pattern with an overall product of i, but which never evaluates to the jk value we're looking for, somehow dodging around it despite the repetition
			* is this possible, or does the repetition make this impossible?
			* can we simply say something like "if pk1 is i and X > 16, skip the inner loop and return True immediately, because they're going to hit it"?
			* probably not, becuase the product of the repeated sequence could, for example, be 1
			* and in fact depending on the product of the repeated sequence, the cycle size varies, and we're certainly not guaranteed to cover every possible value
		* if I can't make any improvements in handling repetition by 30 minutes before the end of the round, I'll just try the current C program on the large dataset
		* I have a suspicion that we might be able to just truncate X to 16 or something?
			* not quite... because each repetition changes the total product, and 16 might not be the same as the whole thing
			* what are the size of the cycles, when multiplying by the same value repeatedly?
			* I added some code to dump the cycles:
				cycles:
				    1 1 1
				    1 i i-I1
				    1 j j-J1
				    1 k k-K1
				    1 - -1
				    1 I I-i1
				    1 J J-j1
				    ...
			* 4 is the maximum cycle size
			* this means that after 4 repetitions of any sequence, we are just encountering the same combinations of j and k products that we have already seen
			* any sequence of length L*4 or greater begins outputting the same products
			* so after 4*L iterations of the inner loop, we can abort
			* what about the outer loop? this is a little more complex...
			* in the inner loop, we're trying to achieve a pair of jk
			* in the outer loop, we're trying to achieve a pair of ii
			* does it matter where we achieve the pair of ii?
				* if the final i is just build frmo a single value i, it's impossible to get jk out of it
				* but is it possible for a sequence ending in i to give a value of k?
				* I don't have a lot of time to spend to verify this... I should perhaps just implement the max 4 repetitions rule on the inner loop right now
			* okay, implemented, and it doesn't break the small datasets - going to try the large dataset
		
	* it occurs to me that we could process pairs at a time, treating combinations of the j and k product as a single value
		* there would be 8*8 = 64 values, addressable in 12 bits
		* we'd use a lookup table of 3 * 64 values to get a 12-bit (packed in 16 bits) result
		* not sure this would give us any worthwhile benefit though - we're looking for big-O improvements right now, not inner-loop optimisations
			
	
	


*/

#include <stdio.h>

int debug0 = 0;
int debug1 = 0;

char values[] = "1ijk-IJK";

char qmul_base[4][4] = {
	"1ijk",
	"i-kJ",
	"jK-i",
	"kjI-"
};

char push[8][8];
char shift[8][8];
char rvalues[0x100];

void dump(void) {
	void dump_op(char *label, char (*table)[8]) {
		fprintf(stderr, "%s table:\n", label);
		for (int i = 0; i < 8; i++) {
			fprintf(stderr, "    ");
			for (int j = 0; j < 8; j++) {
				fprintf(stderr, "%c", values[table[i][j]]);
			}
			fprintf(stderr, "\n");
		}
		fprintf(stderr, "\n");
	}
	
	void dump_cycles(void) {
		fprintf(stderr, "cycles:\n");
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				fprintf(stderr, "    %c %c ", values[i], values[j]);
				for (int k = push[i][j]; k != i; k = push[k][j]) {
					fprintf(stderr, "%c", values[k]);
				}
				fprintf(stderr, "%c\n", values[i]);
			}
		}
	}
	
	dump_op("push", push);
	dump_op("shift", shift);
	dump_cycles();
}

void init(void) {
	// init rvalues from values
	for (int i = 0; i < 0x100; i++) rvalues[i] = 0;
	for (int i = 0; i < 8; i++) rvalues[values[i]] = i;
	
	char build(char base, char sign) {
		return ((sign < 0 ? 1 : 0) << 2) | base;
	}
	char breakup(char value, char *base, char *sign) {
		*base = value & 3;
		*sign = (value >> 2) ? -1 : 1;
	}
	
	// init push/shift from the qmul_base table
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			char asign, bsign, abase, bbase;
			breakup(a, &abase, &asign);
			breakup(b, &bbase, &bsign);
			
			char cbase, csign;
			breakup(rvalues[qmul_base[abase][bbase]], &cbase, &csign);
			csign *= asign * bsign;
			char c = build(cbase, csign);
			
			push[a][b] = c;
			shift[c][a] = b;
			// unshift[b][a] = c;
			// pop[c][b] = a;
		}
	}
	
	if (debug0) dump();
}

int solve(int L, int X, char *line) {
	if (debug1) fprintf(stderr, "L: %d, X: %d, line: %s", L, X, line);
	
	char _seq[L];
	for (int i = 0; i < L; i++) _seq[i] = rvalues[line[i]];
	// note: with -O3 this is no slower than manually inlining the lookup
	char seq(int i) { return _seq[i % L]; }
	
	int LX = L * X;
	
	char pi0 = 0;  // 0 => '1' => identity value
	char pj0 = 0;
	char pk0 = 0;
	int limit0 = (4 * L) < LX ? (4 * L) : LX;
	for (int i = 0; i < limit0; i++) pk0 = push[pk0][seq(i)];
	if (pk0 == 4) for (int i = 0; i < limit0; i++) {
		char pi1 = pi0;
		char pj1 = pj0;
		char pk1 = pk0;
		
		int limit1 = ((i + 4 * L) < LX) ? (i + 4 * L) : LX;
		if ((pi1 == 1) && (pk1 == 1)) for (int j = i; j < limit1; j++) {
			
			if (debug1) {
				fprintf(stderr, "     sizes: %d %d %d\n", i, j - i, LX - j);
				fprintf(stderr, "characters: %c%c%c\n", values[pi1], values[pj1], values[pk1]);
				fprintf(stderr, "    values: %d %d %d\n", pi1, pj1, pk1);
			}
			
			if (pi1 == 1 && pj1 == 2 && pk1 == 3) return 1;
			
			// shift off k string onto j string
			pk1 = shift[pk1][seq(j)];
			pj1 = push[pj1][seq(j)];
		}
		
		// shift off k string, through 0-width j string, onto i string
		pk0 = shift[pk0][seq(i)];
		pi0 = push[pi0][seq(i)];
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


