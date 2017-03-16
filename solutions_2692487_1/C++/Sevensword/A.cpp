#include<stdio.h>
#include<math.h>
#include<iostream>
#include<mem.h>
//-------------------------------------------------------
typedef long long DType;
int cmp(DType d1, DType d2);
char *toString(char *buf, DType d);
//-------------------------------------------------------
int cmp(long long d1, long long d2) {
    if (d1 == d2) return 0;
return (d1 < d2) ? -1 : 1;
}
char *toString(char *buf, long long d) {
    sprintf(buf, "%lld", d);
    return buf;
}
//-------------------------------------------------------
struct SBHeap {
    DType *data;
    int length;
    int size;
};
typedef struct SBHeap *BHeap;

BHeap newBHeap(int length) {
    BHeap h = (BHeap) malloc(sizeof(struct SBHeap));
    h->data = (DType *) malloc(length * sizeof(DType));
    h->length = length;
    h->size = 0;
    return h;
}
void freeBHeap(BHeap h) {
    free(h->data);
    free(h);
}
//-------------------------------------------------------
int sizeOfBHeap(BHeap h) {
    return h->size;
}
int isEmptyBHeap(BHeap h) {
    return h->size == 0;
}
void printBHeap(BHeap h) {
    printf("heap:[ ");
    int i;
    char buf[100];
    for (i=0; i<h->size; i++) {
        printf("%s ", toString(buf, h->data[i]));
    }
    printf("]\n");
}
//-------------------------------------------------------
void swap(DType*a, DType*b) {
    DType t = *a; *a = *b; *b = t;
}
void heapify(DType d[], int n, int p) {
    int c;
    while ( (c = 2*p+1) < n) {
        if (c+1 < n && cmp(d[c+1], d[c]) < 0) c++;
        if (cmp(d[c],d[p]) >= 0) break;
        swap(&d[c], &d[p]);
        p = c;
    }
}
//-----------------------------------------------------
BHeap buildBHeap(DType d[], int n) {
    BHeap h = newBHeap(n);
    int i;
    for(i=0; i<n; i++) {
        h->data[i] = d[i];
    }
    h->length = n;
    h->size = n;
    for(i=n-1; i>=0; i--) {
        heapify(h->data, h->size, i);
    }
    return h;
}
//-------------------------------------------------------
//----------------------------------------------------
void addBHeap(BHeap h, DType x) {  // min heap
    if (h->size == h->length) {
        int newlength = 2*h->length;
        DType *a = (DType *)
            malloc(newlength * sizeof(DType));
        memcpy(a, h->data, sizeof(DType)*h->size);
        free(h->data);
        h->data = a;
        h->length = newlength;
    }
    int c = h->size;
    h->data[c] = x;
    while( c > 0 ) {
        int p = (c-1)/2;
        if (cmp(h->data[p],h->data[c]) <= 0) break;
        swap(&(h->data[p]), &(h->data[c]));
        c = p;
    }
    h->size++;
}
DType removeMinBHeap(BHeap h) {  // min heap
    if (isEmptyBHeap(h)) {
        exit(11);
    }
    DType min = h->data[0];
    h->data[0] = h->data[--(h->size)];
    heapify(h->data, h->size, 0);
    return min;
}

int main()
{
    int i,j,k,n,t,r,v;
    long long now,temp;
    int min,time;
    scanf("%d",&t);
    //scanf("%c",&fre);
    for(k=1;k<=t;k++)
    {

        scanf("%lld %d",&now,&n);
        BHeap h=newBHeap(n);
        for(i=1;i<=n;i++) { scanf("%lld",&temp); addBHeap(h,temp); }
        min=1000; time=0;
        while(!isEmptyBHeap(h))
        {
            temp = removeMinBHeap(h);
            if(now>temp) now+=temp;
            else
            {
                if(time+sizeOfBHeap(h)+1<min) min = time+sizeOfBHeap(h)+1;
                while(now<=temp) {
                    if(now==1) {time=1001; break;}
                    now+=now-1; time++;
                }
                now+=temp;
            }
        }
        if(time<min) min=time;
        printf("Case #%d: %d\n",k,min);
        freeBHeap(h);
    }

    return 0;
}
