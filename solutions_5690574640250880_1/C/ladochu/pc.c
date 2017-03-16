#include <stdio.h>
#include <string.h>

char map[50][50];

void change_array_value(int x, int y, int height, int width, int array[][50], int dx){
    if(x < 0 || x >= height || y < 0 || y >= width){
        return;
    }
    array[x][y] += dx;
}

void fill_dot(int height, int width){
    int i, j;
    for(i = 0;i < height;++i){
        for(j = 0;j < width;++j){
            map[i][j] = '.';
        }
    }
}

void dfs(int x, int y, int visited[][50], int height, int width, int sum[][50]){
    if(x < 0 || y < 0 || x >= height || y >= width){
        return;
    }
    if(visited[x][y]){
        return;
    }
    visited[x][y] = 1;
    if(sum[x][y]){
        return;
    }
    int i, j;
    for(i = -1;i <= 1;++i){
        for(j = -1;j <= 1;++j){
            dfs(x + i, y + j, visited, height, width, sum);
        }
    }
}

int check(int height, int width, int sum[][50]){
    int x, y;
    int dfsed = 0;
    int visited[50][50] = {};
    int min_x = 0, min_y = 0;
    for(x = 0;x < height;++x){
        for(y = 0;y < width;++y){
            if(sum[x][y] < sum[min_x][min_y]){
                min_x = x;
                min_y = y;
            }
        }
    }
    dfs(min_x, min_y, visited, height, width, sum);
    for(x = 0;x < height;++x){
        for(y = 0;y < width;++y){
            if(map[x][y] != '*' && visited[x][y] == 0){
                return 0;
            }
        }
    }
    return 1;
}

void affect_neighbor(int x, int y, int height, int width, int array[][50], int dx){
    int i, j;
    for(i = -1;i <= 1;++i){
        for(j = -1;j <= 1;++j){
            change_array_value(x + i, y + j, height, width, array, dx);
        }
    }
}

int search(int x, int y, int height, int width, int mine, int sum[][50]){
    if(check(height, width, sum) == 0){
        return 0;
    }
    if(mine == 0){
        int x, y;
        int min_x = 0, min_y = 0;
        for(x = 0;x < height;++x){
            for(y = 0;y < width;++y){
                if(sum[x][y] < sum[min_x][min_y]){
                    min_x = x;
                    min_y = y;
                }
            }
        }
        map[min_x][min_y] = 'c';
        return 1;
    }
    if(y == width){
        y = 0;
        ++x;
    }
    if(x == height){
        return 0;
    }
    map[x][y] = '*';
    affect_neighbor(x, y, height, width, sum, 1);
    if(search(x, y + 1, height, width, mine - 1, sum)){
        return 1;
    }
    affect_neighbor(x, y, height, width, sum, -1);
    map[x][y] = '.';
    return search(x, y + 1, height, width, mine, sum);
}

int fill(int height, int width, int mine, int bot, int right){
    int i, j;
    if(mine >= height && bot == 0){
        if(fill(height, width - 1, mine - height, bot, 1)){
            return 1;
        }
    }
    if(mine >= width){
        if(fill(height - 1, width, mine - width, 1, right)){
            return 1;
        }
    }
    if(mine >= height || mine >= width){
        return 0;
    }
    int sum[50][50] = {};
    if(bot){
        for(i = 0;i < width;++i){
            sum[height - 1][i] = 3;
        }
        sum[height - 1][0] = 2;
    }
    if(right){
        for(i = 0;i < height;++i){
            sum[i][width - 1] = 3;
        }
        sum[0][width - 1] = 2;
    }
    if(bot && right){
        sum[height - 1][width - 1] = 5;
    }
    fill_dot(height, width);
    if(search(0, 0, height, width, mine, sum)){
        return 1;
    }
    memset(&map[0][0], '*', 50 * 50 * sizeof(char));
    return 0;
}

int main(){
    int T, t;
    scanf("%d", &T);
    for(t = 1;t <= T;++t){
        memset(&map[0][0], '*', 50 * 50 * sizeof(char));
        int width, height, mine;
        scanf("%d%d%d", &height, &width, &mine);
        printf("Case #%d:\n", t);
        if(fill(height, width, mine, 0, 0)){
            int i, j;
            for(i = 0;i < height;++i){
                for(j = 0;j < width;++j){
                    putchar(map[i][j]);
                }
                putchar('\n');
            }
        }else{
            printf("Impossible\n");
        }
    }
}
