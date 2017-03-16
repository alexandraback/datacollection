#include <cstdio>
#include <cassert>

void print_char(int num, char (*sign)()){
    while(num--)
        printf("%c", sign());
}
void print_row(int r_len, char (*sign)()){
    print_char(r_len, sign);
    printf("\n");
}
void print_mixed_row(int first, char (*f_sign)(), int second, char (*s_sign)()){
    print_char(first, f_sign); print_row(second, s_sign);
}
void print_rows(int r_num, int r_len, char (*sign)()){
    while(r_num--)
        print_row(r_len, sign);
}
void print_impossible(){
    printf("Impossible\n");
}

const char CELL = '.';
const char CLICK = 'c';
const char MINE = '*';

bool clicked;
char get_cell(){
    if(clicked){
        return CELL;
    }
    clicked = true;
    return CLICK;
}
char get_mine(){
    return MINE;
}

void test_case(){
    clicked = false;
    int height, width, mines;
    scanf("%d%d%d", &height, &width, &mines);
    int r = height * width - mines;
    //printf("REMAINS -> %d\n", r);
    assert(r>0);
    if(r==1){
        // all mines, except one
        print_mixed_row(1, get_cell, width-1, get_mine);
        print_rows(height-1, width, get_mine);
    } else if(width == 1){
        print_rows(r, 1, get_cell);
        print_rows(height-r, 1, get_mine);
    } else if(height == 1){
        print_mixed_row(r, get_cell, width-r, get_mine);
    } else if(width == 2 || height == 2){
        if(r&1 || r==2){
            print_impossible();
        } else if(width == 2){
            print_rows(r/2, width, get_cell);
            print_rows(height - r/2, width, get_mine);
        } else { // height == 2
            print_mixed_row(r/2, get_cell, width-r/2, get_mine);
            print_mixed_row(r/2, get_cell, width-r/2, get_mine);
        }
    } else {
        if(r == 2 || (r<9 && r&1)){
            print_impossible();
        } else {
            if(r==4){
                print_mixed_row(2, get_cell, width-2, get_mine);
                print_mixed_row(2, get_cell, width-2, get_mine);
                print_rows(height-2, width, get_mine);
            } else if (r <= 2*width+1){
                if(r&1){
                    int tmp = (r-3)/2;
                    if(tmp < 3){ print_mixed_row(3, get_cell, width-3, get_mine); }
                    print_mixed_row(tmp, get_cell, width-tmp, get_mine);
                    print_mixed_row(tmp, get_cell, width-tmp, get_mine);
                    if(tmp >= 3){ print_mixed_row(3, get_cell, width-3, get_mine); }
                    print_rows(height-3, width, get_mine);
                } else {
                    print_mixed_row(r/2, get_cell, width-r/2, get_mine);
                    print_mixed_row(r/2, get_cell, width-r/2, get_mine);
                    print_rows(height-2, width, get_mine);
                }
            } else { // r > 2*width+1
                while(r > 2 * width + 1){
                    print_rows(2, width, get_cell);
                    r -= 2*width;
                    height -= 2;
                }
                // after loop --> r in [2...2*width+1]
                if(r <= width){
                    print_mixed_row(r, get_cell, width-r, get_mine);
                    print_rows(height-1, width, get_mine);
                } else if (r == width+1){
                    print_mixed_row(width-1, get_cell, 1, get_mine);
                    print_mixed_row(2, get_cell, width-2, get_mine);
                    print_rows(height-2, width, get_mine);
                } else if (r == 2*width+1){
                    if(width-1 < 3) print_mixed_row(3, get_cell, width-3, get_mine);
                    print_mixed_row(width-1, get_cell, 1, get_mine);
                    print_mixed_row(width-1, get_cell, 1, get_mine);
                    if(width-1 >= 3) print_mixed_row(3, get_cell, width-3, get_mine);
                    print_rows(height-3, width, get_mine);
                } else { // r in [width+2...2*width]
                    print_row(width, get_cell);
                    print_mixed_row(r-width, get_cell, 2*width - r, get_mine);
                    print_rows(height-2, width, get_mine);
                }
            }
        }
    }
}

const bool LINE_AFTER_CASE = true;
int main(){
    int z;
    scanf("%d", &z);
    for(int t=1;t<=z;++t){
        printf("Case #%d:%s", t, LINE_AFTER_CASE ? "\n" : " ");
        test_case();
    }
    return 0;
}
