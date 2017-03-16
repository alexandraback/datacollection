#include<stdio.h>
#include<math.h>
#include<iostream>
#include<mem.h>
#include<string.h>
//-------------------------------------------------------
typedef int DType;
int   cmp(DType d1, DType d2);
char *toString(char *buf, DType d);
//-------------------------------------------------------
int cmp(int d1, int d2) {
    if(d1==d2) return 0;
    else return d1>d2? 1:-1;
}
char *toString(char *buf, int d) {
    sprintf(buf, "%d", d);
    return buf;
}
//-------------------------------------------------------
struct SACollection {
    DType *data;
    int length;
    int size;
};
typedef struct SACollection *ACollection;

ACollection newACollection(int length) {
    ACollection col = (ACollection)
                malloc(sizeof(struct SACollection));
    col->data = (DType *)malloc(length * sizeof(DType));
    col->length = length;
    col->size = 0;
    return col;
}
void freeACollection(ACollection col) {
    free(col->data);
    free(col);
}
//-------------------------------------------------------
int sizeOfACollection(ACollection col) {
    return col->size;
}
int isEmptyACollection(ACollection col) {
    return col->size == 0;
}
void printACollection (ACollection col) {
    int i;
    char buf[100];
    printf("ACollection:[ ");
    for (i=0; i<col->size; i++) {
        printf("%s ", toString(buf,col->data[i]));
    }
    printf("]\n");
}
//-------------------------------------------------------

void addACollection(ACollection col, DType x) {
    if (col->size == col->length) {
        int newlength = 2*col->length;
        DType *a = (DType *)
                    malloc(newlength * sizeof(DType));
        int i;
        for (i=0; i<col->size; i++) {
            a[i] = col->data[i];
        }
        free(col->data);
        col->data = a;
        col->length = newlength;
    }
    col->data[col->size] = x;
    col->size++;
}
int indexOfACollection(ACollection col, DType x) {
    int i;
    for (i=0; i<col->size; i++) {
        if (cmp(col->data[i],x)==0) return i;
    }
    return -1;  // not found
}
int isInACollection(ACollection col, DType x) {
    int i = indexOfACollection(col, x);
return i >= 0 ? 1 : 0;
}
int removeACollection(ACollection col, DType x) {
    int i = indexOfACollection(col, x);
    if (i < 0) return 0;
    col->data[i] = col->data[col->size-1];
    col->size--;
    return 1;
}
//-----------------------------------------------------
bool isConsonant(char a)
{
    if(a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u') return true;
    else return false;
}
int main()
{
    int i,j,k,n,t,r,kk,v;
    long long now,temp,count;
    int min,time;
    char word[1000004];
    scanf("%d",&t);
    //scanf("%c",&fre);
    for(k=1;k<=t;k++)
    {
        count = 0;
        ACollection acol = newACollection(105);
        scanf("%s",word);
        scanf("%d",&n);
        //printf("%s\n",word);
        r = strlen(word);
        for(i=0;i<=r-n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(!isConsonant(word[i+j-1])) break;
            }
            if(j>n) addACollection(acol,i);
        }
        //printACollection(acol);
        v = sizeOfACollection(acol);
        for(i=r;i>=n;i--)
        {
            for(j=0;j<=r-i;j++)
            {

                for(kk=0;kk<v;kk++)
                {
                    if(acol->data[kk]>=j && acol->data[kk]+n-1<=j+i-1) break;
                }
                if(kk<v) count++;
            }
        }
        printf("Case #%d: %lld\n",k,count);
        freeACollection(acol);

    }

    return 0;
}
