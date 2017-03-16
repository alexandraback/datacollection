
#include <stdio.h>
#include <stdlib.h>

#define WMAX 55
#define HMAX 55

#define W_BY_H_MAX 27

int W,H;


int *good[HMAX+1][WMAX+1];

int mine[HMAX][WMAX];
int neighbours[HMAX][WMAX];
int clicked[HMAX][WMAX];
int blankcount;
int blankfound;

int boardnum;

#define DBG_BRD 0

int min(int a, int b) { return a<b ? a : b;}
int max(int a, int b) { return a>b ? a : b;}

void printboard(int w, int h, int blank);


void countneighbours(void) {
    int x,y,n,xx,yy;
    for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            n=0;
            //if (boardnum==DBG_BRD)
            //    printf("cn %d %d (m%d)\n",x,y,mine[y][x]);
            if (mine[y][x]) {neighbours[y][x]=-1; continue; }
            for (yy=max(0,y-1);yy<=min(H-1,y+1);yy++)
                for (xx=max(0,x-1);xx<=min(W-1,x+1);xx++) {
                    //if (boardnum==DBG_BRD)
                    //    printf("  %d %d\n",xx,yy);
                    n+=mine[yy][xx];
                }
            neighbours[y][x]=n;
        }
    }
}

void clearclicked(void) {
    int x,y;
    blankcount=0;
    for (y=0;y<H;y++) { 
        for (x=0;x<W;x++) { 
            clicked[y][x]=0;
            if (mine[y][x]==0) blankcount++;
        }
    }
}

int findzero(int *xx, int *yy) {
    int x,y,bx=-1,by=-1;
    for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            if (neighbours[y][x]==0) {
                *xx=x;
                *yy=y;
                return 1;
            }
            if (!mine[y][x]) {bx=x;by=y;}
        }
    }
    if (bx>=0) {
        *xx=bx;*yy=by;
        return 1;
    }
    return 0;
}

void click(int x, int y) {
    int xx,yy;
    if (x<0 || x>=W) return;
    if (y<0 || y>=H) return;
    if (mine[y][x] || clicked[y][x]) return;
    blankfound++;
    clicked[y][x]=1;
    if (neighbours[y][x]!=0) return;
    for (yy=y-1;yy<=y+1;yy++)
        for (xx=x-1;xx<=x+1;xx++)
            click(xx,yy);
}

int increment(void) {
   int x,y;
   boardnum++;
   for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            if (mine[y][x]) mine[y][x]=0;
            else {mine[y][x]=1; return 1; }
        }
    }
    return 0;
}

void clearboard(void) {
    int x,y;
    boardnum=0;
    for (y=0;y<H;y++) 
        for (x=0;x<W;x++)
            mine[y][x]=0;
}

void cleargood(void) {
    int i;
    int *g=malloc((W*H+1)*sizeof(int));
    for (i=0;i<=W*H;i++) g[i]=-1;
    good[H][W]=g;
}

void boardsize(int ww, int hh) {
    int sx,sy,i;
    W=ww;
    H=hh;
    clearboard();
    cleargood();
    do {
        blankfound=0;
        countneighbours();
        clearclicked();
        if (good[H][W][blankcount]!=-1) continue;
        if (findzero(&sx,&sy)) {
            click(sx,sy);
            if (blankfound==blankcount) {
                good[H][W][blankcount]=boardnum;
            }
        }
    } while (increment());
    
    
    printf("%d X %d\n",W,H);
    for (i=0;i<=H*W;i++) {
        if (good[H][W][i]>=0) printf("%d %x\n",i,good[H][W][i]);
    }
    printf("\n");
    //return 0;
    
}

void drawboard(void) {
    int x,y;
    char *m="c.*";
    for (y=0;y<H;y++) { 
        for (x=0;x<W;x++) {
            putchar(m[mine[y][x]+1]);
        }
        putchar('\n');
    }
}

void drawtransposed(void) {
    int x,y;
    char *m="c.*";
    for (x=0;x<W;x++) {
        for (y=0;y<H;y++) { 
            putchar(m[mine[y][x]+1]);
        }
        putchar('\n');
    }
}

void fillin(int bits) {
    int y,x;
    for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            mine[y][x]=bits & 1;
            bits>>=1;
        }
    }
}



int mainX(int argc, char **argv) {
    int ww,hh,mines,blanks;
    int tc,casenum;
    for (ww=1;ww<=WMAX;ww++) {
        for (hh=1;hh<=ww;hh++) {
            if (ww*hh<=W_BY_H_MAX)
                boardsize(ww,hh);
        }
    }
    scanf("%d",&tc);
    for (casenum=1;casenum<=tc;casenum++) {
        printf("Case #%d:\n",casenum);
        scanf("%d %d %d",&hh, &ww, &mines);
        blanks=ww*hh-mines;
        printboard(ww,hh,blanks);
    }
    return 0;
}

void makethreeA(int blank);


void makeone(int blank) {
    int x;
    for (x=0;x<W;x++) {
        if (x<blank) mine[0][x]=0;
        else mine[0][x]=1;
    }
}

void maketwo(int blank) {
    int x;
    if (blank==1) {makethreeA(blank);return;}
    blank=blank/2;
    for (x=0;x<W;x++) {
        if (x<blank) mine[0][x]=0;
        else mine[0][x]=1;
        mine[1][x]=mine[0][x];
    }    
}

void allmines(void) {
    int x,y;
    for (y=0;y<H;y++) {
        for (x=0;x<W;x++) {
            mine[y][x]=1;
        }
    }
}

void deminerow(int y, int n) {
    int x;
    for (x=0;x<n;x++) mine[y][x]=0;
} 

void makethreeA(int blank) {
    allmines();
    if (blank>=1) mine[0][0]=0;
    if (blank>=4) {
        mine[0][1]=
        mine[1][0]=
        mine[1][1]=0;
    }
    if (blank>=6) {
        mine[0][2]=
        mine[1][2]=0;
    }
    if (blank>=8) {
        mine[2][0]=
        mine[2][1]=0;
    }
}

void makethree(int blank) {
    int p2,p1,p0,r,w,i;
    if (blank<9) {makethreeA(blank); return; }
    w=W;
again:
    r=blank/w;
    p2=w;
    p1=w;
    p0=blank % w;
    if (p0) r++;
    else p0=w;
    if (r<3) {
        w=blank/3;
        if (blank % 3) w++;
        goto again; 
    }
    if (p0 == 1) {
        if (r==3) {
            p0+=2;
            p1--;
            p2--;
        } else {
            p0++;
            p1--;
        }
    }
    allmines();
    for (i=0;i<r-3;i++) {
        deminerow(i,w);
    }
    deminerow(r-3,p2);
    deminerow(r-2,p1);
    deminerow(r-1,p0);
}

void testblank(int blank) {
    blankfound=0;
    countneighbours();
    clearclicked();
    click(0,0);
    if (blankfound!=blank) {
        printf("FAIL %d X %d\n",W,H);
        printf("   %d %d\n",blank,blankfound);
        drawboard();
        printf("\n");
    } else {
        //printf("%d X %d [%d]\n",W,H,blank);
        //drawboard();
        //printf("\n");
    }
}



int mainY(int argc, char **argv) {
    //size 1 boards
    int blank;
    H=1;
    for (W=1;W<=WMAX;W++) {
        for (blank=1;blank<=W;blank++) {
            makeone(blank);
            testblank(blank);
        }
    } 
    //size 2 boards
    H=2;
    for (W=4;W<=WMAX;W++) {
        for (blank=4;blank<=2*W;blank+=2) {
            maketwo(blank);
            testblank(blank);
        }
    }
    
    printf("size 3\n");
    //size3 + boards
    for (H=3;H<=HMAX;H++) {
        for (W=3;W<=WMAX;W++) {
            for (blank=4;blank<=W*H;blank++) {
                if ((blank & 1) && blank<9) continue;
                makethree(blank);
                testblank(blank);
            }
        }
    }
    
    return 0;
}

void printboard(int w, int h, int blank) {
    int transpose=0,t;
    int sx,sy;
    int imposs=0;
    if (w<h) {transpose=1;t=w;w=h;h=t;}
    W=w;H=h;
    if (h==1) {
        makeone(blank);
    } else if (h==2) {
        imposs=((blank & 1) || blank==2);
        if (blank==1) imposs=0;
        if (!imposs) maketwo(blank);
    } else if (h>=3) {
        imposs=((blank<9 && (blank & 1) || blank==2));
        if (blank==1) imposs=0;
        if (!imposs) makethree(blank);
    }
    mine[0][0]=-1;
    if (imposs) printf("Impossible\n");
    else if (transpose) drawtransposed();
    else drawboard();
}


int main(int argc, char **argv) {
    int tc,casenum,hh,ww,mines,blanks;
    scanf("%d",&tc);
    for (casenum=1;casenum<=tc;casenum++) {
        printf("Case #%d:\n",casenum);
        scanf("%d %d %d",&hh, &ww, &mines);
        blanks=ww*hh-mines;
        printboard(ww,hh,blanks);
    }
    return 0;
}

