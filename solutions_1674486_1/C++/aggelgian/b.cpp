#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<sstream>
#include<iostream>
#define BSIZE 1<<15

char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

typedef struct edge {
	long to;
	struct edge *next;
}edge;

typedef struct edge **graph;

long addEdgeToGraph(graph g, int fromV, long toV) {

	struct edge *newedge;

	newedge = (struct edge *)malloc(sizeof(struct edge));

	newedge->to = toV;
	newedge->next = g[fromV];
	g[fromV] = newedge;

	return 0;
}

typedef struct job {
	long v;
	struct job *next;
}job;

typedef struct queue_info {
	struct job *head;
	struct job *tail;
}queue_info;

typedef struct queue_info *queue;

long enqueue(queue q, long vert) {

	struct job *p;

	p = (struct job *)malloc(sizeof(struct job));
	p->v = vert;
	p->next = NULL;

	if (q->head == NULL) {
		q->head = p;
		q->tail = p;
	}
	else {
		q->tail->next = p;
		q->tail = p;
		p = NULL;
	}
	p = NULL;

	return 0;
}

long dequeue(queue q) {

	long vertex;
	struct job *p;

	p = q->head;
	vertex = p->v;

	if (q->head == q->tail)
		q->head = q->tail = NULL;
	else 
		q->head = p->next;

	free(p);

	return vertex;
}

long readLong () {
   long d = 0L, x = 0L;
   char c;

   while (1)  {
      if (bpos >= bsize) {
         bpos = 0;
         if (feof(stdin)) return x;
         bsize = fread(buffer, 1, BSIZE, stdin);
      }
      c = buffer[bpos++];
      if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
      else if (d == 1) return x;
   }
   return -1;
}



int main () {

   long T,ii, N, i, j, num, tt, *S, *parent, v, flag,x, k;
   graph g;
   queue joblist;
   edge *q;
   
   T = readLong();

   
   for(ii=1; ii<=T; ii++) {
   
      N = readLong();
      flag=0;
      S = (long *)malloc(N*sizeof(long));
      parent = (long *)malloc(N*sizeof(long));
      g = (graph )malloc(N*sizeof(edge *));
      for(i=0; i<N; i++) {
         g[i] = NULL;
         S[i] = 0;
         parent[i] = LONG_MAX;
         num = readLong();
         for(j=0; j< num; j++) {
            tt = readLong();
            addEdgeToGraph(g, i, tt-1);
         }
            
      }

 for (k=0; k<N; k++) {
      i = k;
		joblist = NULL;
		joblist = (queue)malloc(sizeof(queue_info));
		joblist->head = joblist->tail = NULL;
		enqueue(joblist, (long)i);
		S[i] = 1;
		parent[i] = 0;
		while(joblist->head != NULL) {

			x = dequeue(joblist);
			S[x] = 2;
			q = g[x];
			while (q!=NULL) {
			   v = q->to;
			   
			   if (S[v] == 0) {
			      enqueue(joblist, v);
			      S[v] = 1;
			      parent[v] = x;
			   }
			   else if (S[v] < 3)
			      flag = 1;
			   
			   q = q->next;
			}
		}
		
		for (i=0; i<N; i++) {
		  S[i] = 0;
         parent[i] = LONG_MAX;
		}
}
     
      /* calc result */
      if (flag)
      printf("Case #%ld: Yes\n", ii);
      else
            printf("Case #%ld: No\n", ii);
      
      
      free(S);
      for(i=0; i<N; i++) free(g[i]);
      free(g);
      free(joblist);
   }
   

   return 0;
}
