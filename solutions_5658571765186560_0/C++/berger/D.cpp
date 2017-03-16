#include <cstdio>
#include <algorithm>

using namespace std;

bool canBlock(int x, int r, int c) {
    if (x >= 7)
        return true;
    if (r < x && c < x)
        return true;
    if (r*c % x != 0)
        return true;
    if (r >= x && c >= x)
        return false;
    
    //the steps check
    int levels = (x+1)/2;
    if (levels > r)
        return true;
    if (levels < r)
        return false;
    int cols = (x+2)/2;
    
    int spaces = levels*cols - x;
    int i, j;
    for (i = 1; i < spaces; i++) {
        bool found = false;
        for (j = 0; j <= c-cols; j++)
            if ((j*r + i) % x == 0)
                found = true;
        if (!found)
            return true;
    }
    return false;       
}

int main() {
	int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        
        int x, r, c;
        scanf("%d%d%d", &x, &r, &c);
        if (c < r) {
            swap(r, c);
        }
        
        if (canBlock(x, r, c))
            printf("RICHARD\n");
        else
            printf("GABRIEL\n");
        
    }
}