#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char donemap[3000][3000] = {0};

typedef struct _leaf{
    char way[500];
    int nowx;
    int nowy;
    int te;
    struct _leaf *next;
} leaf;

int hyouka(leaf* theleaf,int gx,int gy){
    return - (abs(theleaf->nowx - gx) + abs(theleaf->nowy - gy) + theleaf->te* 2);
}

void clearone(leaf*tmp){
    free(tmp);
}

void clearall(leaf* theleaf){
    leaf* nxt,*tmp = theleaf;
    while((nxt = tmp->next) != NULL){
        free(tmp);
        tmp = nxt;
    }
}

void addleaf(leaf* theleaf,leaf* toadd,int gx,int gy){
    leaf* tmp = theleaf;
    leaf* latmp;
    int tmpval = hyouka(toadd,gx,gy);
// is it already
    if(abs(toadd->nowx) > 1000 || abs(toadd->nowy) > 1000 || donemap[toadd->nowx+1000][toadd->nowy + 1000]){
        return;
    }
    donemap[toadd->nowx+1000][toadd->nowy + 1000] = 1;

    if(tmp->next == NULL){
        tmp->next = toadd;
    }else{
//        while((tmp->next != NULL) && (hyouka(tmp->next,gx,gy) > tmpval)){
        while((tmp->next != NULL)){
            tmp = tmp->next;
        }
        latmp = tmp->next;
        tmp->next = toadd;
        toadd->next = latmp;
    }
}

int tocut(int tmpx,int tmpy,int gx,int gy,int te){
    int dist = abs(tmpx - gx) + abs(tmpy - gy);
    if(dist > 300){
        return 1;
    }
    return 0;
}

char *searchgoal(leaf* searchleaf,int gx,int gy){
    int i;
    leaf *newl,*lastleaf,*tmpleaf;
    tmpleaf = searchleaf;
    while(1){
        if(tmpleaf == NULL || tmpleaf->te > 490){
            printf("cut cut cut \n");
            exit(0);
        }
//        printf("%d:%d,%d\n",tmpleaf->te,tmpleaf->nowx,tmpleaf->nowy);
        if(tmpleaf->nowx == gx && tmpleaf->nowy == gy){            
            clearall(tmpleaf->next);
            return tmpleaf->way;
        }
        if(tocut(tmpleaf->nowx,tmpleaf->nowy,gx,gy,tmpleaf->te)){
//            printf("cut\n");
            goto noadd;
        }
        for(i=0;i<4;i++){
            newl = malloc(sizeof(leaf));
            newl->next = NULL;
            newl->te = tmpleaf->te + 1;
            strncpy(newl->way,tmpleaf->way,tmpleaf->te);
            newl->way[newl->te] = '\0';
            switch(i){
            case 0:
                newl->nowx = tmpleaf->nowx + newl->te;
                newl->nowy = tmpleaf->nowy;
                newl->way[newl->te - 1] = 'E';
                break;
            case 1:
                newl->nowx = tmpleaf->nowx - newl->te;
                newl->nowy = tmpleaf->nowy;
                newl->way[newl->te - 1] = 'W';
                break;
            case 2:
                newl->nowx = tmpleaf->nowx;
                newl->nowy = tmpleaf->nowy + newl->te;
                newl->way[newl->te - 1] = 'N';
                break;
            case 3:
                newl->nowx = tmpleaf->nowx;
                newl->nowy = tmpleaf->nowy - newl->te;
                newl->way[newl->te - 1] = 'S';
                break;
            }
            addleaf(tmpleaf,newl,gx,gy);
        }
    noadd:
        lastleaf = tmpleaf;
        tmpleaf = tmpleaf->next;
        clearone(lastleaf);
    }    
}

int main(){
    int T;
    int p;
    int destx,desty;
    leaf* initpoint;
    char *ret;
    scanf("%d\n",&T);
    for(p=0;p<T;p++){
        memset(donemap,0,9000000);
        scanf("%d %d\n",&destx,&desty);
        initpoint = malloc(sizeof(leaf));
        initpoint->nowx = 0;
        initpoint->nowy = 0;
        initpoint->te = 0;
        initpoint->next = NULL;
        ret = searchgoal(initpoint,destx,desty);
        printf("Case #%d: %s\n",p+1,ret);
    }
}
