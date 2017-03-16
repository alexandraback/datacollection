/*
 * MagicTrick.c
 *
 *  Created on: 2014. 4. 12.
 *      Author: Administrator
 */



#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct reader
{
	char buf[512];
	int idx;
	int size;
};

typedef struct reader* READER;


READER reader_init(void)
{
	READER rdr = calloc(1, sizeof(struct reader));

	return rdr;
}


int reader_refresh(READER rdr)
{
	rdr->size = fread(rdr->buf, 1, 512, stdin);
	if(rdr->size<0)
	{
		fprintf(stderr, "failed to fread. %s\n", strerror(errno));
		return -1;
	}
	rdr->idx = 0;
	return rdr->size;
}


char reader_next(READER rdr)
{
	if(rdr->size <= rdr->idx)
	{
		reader_refresh(rdr);
	}

	return rdr->buf[rdr->idx++];
}


char* nextStr(READER rdr)
{
	int idx = 0;
	int size = 32;
	char* buf = NULL;

	while(1)
	{
		char ch = reader_next(rdr);
		if(isspace(ch))
		{
			if(buf==NULL) {
				continue;
			} else {
				buf[idx] = '\0';
				return buf;
			}
		}

		if(buf==NULL) buf = malloc(size);
		if(idx==size)
		{
			size *= 2;
			buf = realloc(buf, size);
		}

		buf[idx++] = ch;
	}

	return NULL;
}


int nextInt(READER rdr)
{
	int started = 0;
	int res = 0;

	while(1)
	{
		char ch = reader_next(rdr);
		if(isspace(ch))
		{
			if(!started) continue;
			else return res;
		}

		if(isdigit(ch))
		{
			started = 1;
			res *= 10;
			res += ch - '0';
		}

	}

	return -1;
}


double nextDbl(READER rdr)
{
	char* word = nextStr(rdr);
	double res = atof(word);
	free(word);
	return res;
}


void solve(READER rdr, int T)
{
	double C = nextDbl(rdr);
	double F = nextDbl(rdr);
	double X = nextDbl(rdr);

	double rate = 2.0;
	double offset = 0.0;
	double ans = X/rate + offset;

	do {
		offset += (C/rate);
		rate += F;
		double pred = X/rate + offset;
		if(pred>ans) break;
		ans = pred;

	} while(1);

	fprintf(stdout, "Case #%d: %.7f\n", T, ans);

	return;
}


int main(int argc, char** argv)
{
	READER rdr = reader_init();

	int T = nextInt(rdr);
	fprintf(stderr, "%d cases\n", T);
	int i;
	for(i=1; i<=T; i++)
	{
		solve(rdr, i);
	}

	return 0;
}
