
#include <cstdlib>
#include <cstdio>

int rows, cols;
int fail;
int lawn[100][100];

void check() {
    int _fail;
    fail = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            _fail = 0;
            for (int cc = 0; cc < cols; cc++) {
                if (lawn[row][cc] > lawn[row][col]) {
                    _fail++;
                    break;
                }
            }
            for (int rr = 0; rr < rows; rr++) {
                if (lawn[rr][col] > lawn[row][col]) {
                    _fail++;
                    break;
                }
            }
            if (_fail > 1) {
                fail = 1;
                return;
            }
        }
    }
    
    
}

int main(int argc, const char * argv[])
{
    int cn;
    
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    
    scanf("%d\n", &cn);
    for (int ci = 1; ci <= cn; ci++) {
        scanf("%d %d", &rows, &cols);
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                scanf("%d", &lawn[row][col]);
            }
        }
        check();
        
        if (fail) {
            printf("Case #%d: NO\n", ci);
        }
        else {
            printf("Case #%d: YES\n", ci);
        }
    }
    return 0;
}

