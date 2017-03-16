/*
 * DeceitfulWar.c
 *
 *  Created on: 2014. 4. 12.
 *      Author: Administrator
 */




#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

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


void sort(int* arr, int size)
{
	int i, j, t;
	for(i=0; i<size-1; i++) {
		for(j=i+1; j<size; j++) {
			if(arr[i]>arr[j]) {
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}


void solve(READER rdr, int T)
{
	int N = nextInt(rdr);
	int i, j;

	int* naomi = malloc(N* sizeof(int));
	int* ken = malloc(N* sizeof(int));

	for(i=0; i<N; i++)
		naomi[i] = (int) (nextDbl(rdr) * 100000);
	for(i=0; i<N; i++)
		ken[i] = (int) (nextDbl(rdr) * 100000);

	sort(naomi, N);
	sort(ken, N);

	int* naomiD = malloc(N* sizeof(int));
	memcpy(naomiD, naomi, N* sizeof(int));
	int* kenD = malloc(N* sizeof(int));
	memcpy(kenD, ken, N* sizeof(int));

	int vd = 0;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(kenD[j]!=-1 && kenD[j]<naomiD[i]) {
				naomiD[i] = -1;
				kenD[j] = -1;
				vd++;
				break;
			}
		}
	}

	int v = 0;
	for(i=N-1; i>=0; i--) {
		for(j=N-1; j>=0; j--) {
			if(naomi[j]!=-1 && naomi[j]<ken[i]) {
				naomi[j]=-1;
				ken[i]=-1;
				v++;
				break;
			}
		}
	}

	fprintf(stdout, "Case #%d: %d %d\n", T, vd, N-v);

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
