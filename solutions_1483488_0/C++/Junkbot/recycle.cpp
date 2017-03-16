#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

int T;

set< pair<int,int> > s;

int pow10(int num) {
    int p = 1;
    for(int i=0;i<num;i++) {
        p *= 10;
    }
    return p;
}

int main() {
    scanf("%d",&T);

    for(int t=1;t<=T;t++) {
        s.clear();
        int A,B;
        scanf("%d %d",&A,&B);

        int numDig = 0;
        int ta = A;
        while(ta > 0) {
            ta /= 10;
            numDig++;
        }

        //printf("numDig = %d\n",numDig);

        for(int i=A;i<=B;i++) {
            //printf("i=%d\n",i);
            for(int j=0;j<numDig && pow10(j) < i;j++) {
                int nextNum = (i%pow10(j))*pow10(numDig-j) + (i/pow10(j));
              //  printf("nextNum = %d (mod by %d, mult by %d)\n",nextNum,j,numDig-j);
                if(nextNum > i && nextNum <= B) {
//                    printf("(%d,%d)\n",i,nextNum);
                    s.insert(make_pair(i,nextNum));
                }
            }
        }

        printf("Case #%d: %d\n",t,s.size());
    }
    return 0;
}
