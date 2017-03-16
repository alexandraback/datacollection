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

int R, C, M;
int size;


char* init(const char* board) {
	char* b = malloc(size);
	if(b==NULL)
		fprintf(stderr, "failed to malloc.\n");
	if(board)
		memcpy(b, board, size);
	else
		memset(b, '*', size);

	return b;
}


char get(const char* board, int x, int y) {
	return board[y*C + x];
}


void setIf(char* board, int x, int y, char v, char cond) {
	if(x<0 || x>=C) return;
	if(y<0 || y>=R) return;
	if(board[y*C + x]!=cond) return;
	board[y*C + x] = v;
	return;
}

void set(char* board, int x, int y, char v) {
	if(x<0 || x>=C) return;
	if(y<0 || y>=R) return;
	board[y*C + x] = v;
	return;
}

int count(char* board, char v) {
	int cnt = 0;
	int x, y;
	for(y=0; y<R; y++) {
		for(x=0; x<C; x++) {
			if(board[y*C + x]==v)
				cnt++;
		}
	}
	return cnt;
}

void print(char* board, int debug) {
	int x, y, clicked = 0;
	for(y=0; y<R; y++) {
		for(x=0; x<C; x++) {
			if(!debug && board[y*C+x]=='c') {
				if(clicked)
					board[y*C+x] = '.';
				else
					clicked = 1;
			}
			fprintf(stdout, "%c", board[y*C+x]);
		}
		fprintf(stdout, "\n");
	}

	return;
}


char* click(const char* board, int cx, int cy) {
	if(cx<0 || cx>=C) return NULL;
	if(cy<0 || cy>=R) return NULL;
	if(get(board, cx, cy)=='c') return NULL;

	char* b = init(board);
	set(b, cx, cy, 'c');

	setIf(b, cx-1, cy-1, '.', '*');
	setIf(b, cx  , cy-1, '.', '*');
	setIf(b, cx+1, cy-1, '.', '*');

	setIf(b, cx-1, cy  , '.', '*');
	setIf(b, cx+1, cy  , '.', '*');

	setIf(b, cx-1, cy+1, '.', '*');
	setIf(b, cx  , cy+1, '.', '*');
	setIf(b, cx+1, cy+1, '.', '*');

//	print(b, 1);
//	usleep(100 * 1000);
	int c = count(b, '*');

	if(c==M) return b;
	if(c<M) {
		free(b);
		return NULL;
	}

	char* cb;
	if((cb = click(b, cx-1, cy-1))!=NULL) { free(b); return cb; }
	if((cb = click(b, cx-1, cy  ))!=NULL) { free(b); return cb; }
	if((cb = click(b, cx-1, cy+1))!=NULL) { free(b); return cb; }

	if((cb = click(b, cx  , cy-1))!=NULL) { free(b); return cb; }
	if((cb = click(b, cx  , cy+1))!=NULL) { free(b); return cb; }

	if((cb = click(b, cx+1, cy-1))!=NULL) { free(b); return cb; }
	if((cb = click(b, cx+1, cy  ))!=NULL) { free(b); return cb; }
	if((cb = click(b, cx+1, cy+1))!=NULL) { free(b); return cb; }

	free(b);
	return NULL;
}


void solve(READER rdr, int T)
{
	R = nextInt(rdr);
	C = nextInt(rdr);
	M = nextInt(rdr);
	size = R * C * sizeof(char);

	char* board = init(NULL);
	char* rb = NULL;

	if(R * C - 1 == M) {
		rb = init(board);
		set(rb, 0, 0, 'c');
	} else {
		rb = click(board, 0, 0);
	}

	fprintf(stdout, "Case #%d:\n", T);
	if(rb==NULL) {
		fprintf(stdout, "Impossible\n");
	} else {
		print(rb, 0);
		free(rb);
	}

	free(board);

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
