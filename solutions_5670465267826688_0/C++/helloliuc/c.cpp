#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

struct NODE
{
    int flag;
    char c;
    NODE() {
        this->flag = 1;
        this->c = '1';
    }
    NODE(int flag, char c) {
        this->flag = flag;
        this->c = c;
    }
    NODE mul(NODE x) {
        NODE ret;
        ret.flag = 1;
        if(c == '1') {
            ret.c = x.c;
        }
        else if(x.c == '1') {
            ret.c = c;
        }
        else if(c == x.c) {
            ret.c = '1';
            if(c != '1') {
                ret.flag = -1;
            }
        }
        else if(c == 'i') {
            if(x.c == 'j') {
                ret.c = 'k';
            }
            else if(x.c == 'k') {
                ret.c = 'j';
                ret.flag = -1;
            }
        }
        else if(c == 'j') {
            if(x.c == 'i') {
                ret.c = 'k';
                ret.flag = -1;
            }
            else if(x.c == 'k') {
                ret.c = 'i';
            }
        }
        else if(c == 'k') {
            if(x.c == 'i') {
                ret.c = 'j';
            }
            else if(x.c == 'j') {
                ret.c = 'i';
                ret.flag = -1;
            }
        }
        ret.flag *= flag * x.flag;
        return ret;
    }
    NODE divide(NODE x) {
        NODE ret;
        ret.flag = 1;
        if(c == '1') {
            ret.c = x.c;
            if(x.c != '1') {
                ret.flag = -1;
            }
        }
        else if(x.c == '1') {
            ret.c = c;
        }
        else if(c == x.c) {
            ret.c = '1';
            //ret.flag = -1;
        }
        else if(c == 'i') {
            if(x.c == 'j') {
                ret.c = 'k';
                ret.flag = -1;
            }
            else if(x.c == 'k') {
                ret.c = 'j';
            }
        }
        else if(c == 'j') {
            if(x.c == 'i') {
                ret.c = 'k';
            }
            else if(x.c == 'k') {
                ret.c = 'i';
                ret.flag = -1;
            }
        }
        else if(c == 'k') {
            if(x.c == 'i') {
                ret.c = 'j';
                ret.flag = -1;
            }
            else if(x.c == 'j') {
                ret.c = 'i';
            }
        }
        ret.flag *= flag * x.flag;
        return ret;
    }
};

char s[11000];
NODE num[200000];
NODE first[200000];
NODE last[200000];
NODE allmul[5];
int L;
ll X;


bool search(int i, int j, int k, int l) {
    //printf("%d %d %d %d\n", i, j,k,l);
    NODE ret;

    if(i != k) {
        int det_block = (k - i - 1) % 4 ;
        ret = ret.mul(allmul[det_block]);
        if(j != L-1) {
            ret = last[j+1].mul(ret);
        }
        if(l != 0) {
            ret = ret.mul(first[l-1]);
        }
    }
    else {
        //ret = first[l-1].divide(first[j]);
        ret = last[j+1].divide(last[l]);
    }

    //printf("ret: %c %d\n", ret.c, ret.flag);
    if(ret.c == 'j' && ret.flag == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++) {
        cin>>L>>X;
        scanf("%s", s);
        for(int i=0;i<L;i++) {
            num[i].flag = 1;
            num[i].c = s[i];
            if(i == 0) {
                first[i] = num[i];
            }
            else {
                first[i] = first[i-1].mul(num[i]);
            }
        }
        for(int i=L-1;i>=0;i--) {
            if(i == L-1) {
                last[i] = num[i];
            }
            else {
                last[i] = num[i].mul(last[i+1]);
            }
        }

        allmul[0].c = '1';
        allmul[0].flag = 1;
        int loop_num = 0;
        for(int i=1;i<=4;i++) {
            allmul[i] = allmul[i-1].mul(first[L-1]);
            //printf("i:%d flag:%d c:%c\n", i, allmul[i].flag, allmul[i].c);
        }


        bool found = false;
        NODE head;
        int det = X % 4;
        int all_length = X > 12 + det ? 12 + det: X;
        for(int i=0;i<4  && i < all_length && !found ;i++) {
            for(int j=0;j<L && !found;j++) {
                head= head.mul(num[j]);
                //printf("head: %c %d\n", head.c, head.flag);
                if(head.c == 'i' && head.flag == 1) {

                    NODE tail;
                    for(int k=all_length - 1; k>=i && all_length - k <= 4 && !found; k--) {
                        for(int l = L-1; l>=0 && !found; l--) {
                        //printf("tail: %c %d\n", tail.c, tail.flag);
                            if(i == k && j >= l - 1) break;
                            tail = num[l].mul(tail);
                            if(tail.c == 'k' && tail.flag == 1) {
                                found = search(i, j, k, l);
                            }
                        }
                    }
                }
            }
        }

        if(found) {
            printf("Case #%d: YES\n", cas);
        }
        else {
            printf("Case #%d: NO\n", cas);
        }
        /*
        for(int i=0;i<L;i++) {
            if(first[i].flag==-1) printf("-");
            printf("%c ", first[i].c);
        }
        printf("\n");
        */
    }

    return 0;
}
