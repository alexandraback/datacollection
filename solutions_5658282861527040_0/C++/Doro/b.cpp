#include <cstdio>
using namespace std;

// -------------------------------
// -------- DEBUG include --------
#include <cassert>
#include <cstring> // strcmp
bool DEBUG = false;
// -------------------------------
// -------------------------------

void test_case(){
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);

    int res = 0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            res += ((i&j) < k);
        }
    }
    printf("%d\n", res);
}

// ----------------------------------------
// -------------- MAIN DRAFT --------------
// ----------------------------------------

const bool LINE_AFTER_CASE = false;
int main(int argc, char *argv[]) {
    // recognise running mode
    if(argc >= 2 && !strcmp(argv[1],"DEBUG")){
        printf("switch DEBUG ON!\n");
        DEBUG = true;
    }
    // -------------------
    int z;
    scanf("%d", &z);
    for(int t=1;t<=z;++t){
        printf("Case #%d:%s", t, LINE_AFTER_CASE ? "\n" : " ");
        test_case();
    }
    return 0;
}
