#include <stdio.h>
#include <cmath>
using namespace std;
#define MAX_HW 30
#define PI 3.1415926535897932
#define INF 1E-10
typedef enum {
    Null = 0, Mirror, Myself
} Status;

typedef enum {
    LeftUp, LeftDown, RightUp, RightDown
} Direction;

typedef struct {
    double x;
    double y;
} Position;

Status g_Hall[MAX_HW][MAX_HW] = { { Null } };
double g_Slope; //斜率绝对值

bool TestInt(double x) {
    if (abs(floor(x + 0.5) - x) < INF) {
        return true;
    }
    return false;
}

/* 功能：返回正整数m和n的最大公约数*/
int gcd(int m, int n) {
    if (m % n == 0)
        return n;
    return gcd(n, m % n);
}

Position AddPos(Position Pos, double add_x, double add_y) {
    Pos.x += add_x;
    Pos.y += add_y;
    return Pos;
}

int Trans(Position Pos, Direction Direct, double ReDepth) {
    if (ReDepth < 0) {
        return 0;
    }
    int Row, Column;
    if (TestInt(Pos.x) && TestInt(Pos.y)) {
        switch (Direct) {
        case LeftUp:
            Row = Pos.y - INF;
            Column = Pos.x - INF;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(0.5) > -INF) && (abs(g_Slope - 1) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope < 1) {
                    ReDepth -= sqrt(1 + g_Slope * g_Slope);
                    return Trans(AddPos(Pos, -1, -g_Slope), LeftUp, ReDepth);
                } else {
                    ReDepth -= sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(AddPos(Pos, -1 / g_Slope, -1), LeftUp, ReDepth);
                }
            case Mirror:
                if ((Mirror == g_Hall[Row][Column + 1])
                        && (Mirror == g_Hall[Row + 1][Column])) {
                    return Trans(Pos, RightDown, ReDepth);
                } else if (Mirror == g_Hall[Row][Column + 1]) {
                    return Trans(Pos, LeftDown, ReDepth);
                } else if (Mirror == g_Hall[Row + 1][Column]) {
                    return Trans(Pos, RightUp, ReDepth);
                } else {
                    return 0;
                }
            }
            break;
        case RightUp:
            Row = Pos.y - INF;
            Column = Pos.x + INF;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(0.5) > -INF) && (abs(g_Slope - 1) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope < 1) {
                    ReDepth -= sqrt(1 + g_Slope * g_Slope);
                    return Trans(AddPos(Pos, 1, -g_Slope), RightUp, ReDepth);
                } else {
                    ReDepth -= sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(AddPos(Pos, 1 / g_Slope, -1), RightUp, ReDepth);
                }
            case Mirror:
                if ((Mirror == g_Hall[Row][Column - 1])
                        && (Mirror == g_Hall[Row + 1][Column])) {
                    return Trans(Pos, LeftDown, ReDepth);
                } else if (Mirror == g_Hall[Row][Column - 1]) {
                    return Trans(Pos, RightDown, ReDepth);
                } else if (Mirror == g_Hall[Row + 1][Column]) {
                    return Trans(Pos, LeftUp, ReDepth);
                } else {
                    return 0;
                }
            }
            break;
        case RightDown:
            Row = Pos.y + INF;
            Column = Pos.x + INF;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(0.5) > -INF) && (abs(g_Slope - 1) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope < 1) {
                    ReDepth -= sqrt(1 + g_Slope * g_Slope);
                    return Trans(AddPos(Pos, 1, g_Slope), RightDown, ReDepth);
                } else {
                    ReDepth -= sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(AddPos(Pos, 1 / g_Slope, 1), RightDown,
                            ReDepth);
                }
            case Mirror:
                if ((Mirror == g_Hall[Row][Column - 1])
                        && (Mirror == g_Hall[Row - 1][Column])) {
                    return Trans(Pos, LeftUp, ReDepth);
                } else if (Mirror == g_Hall[Row][Column - 1]) {
                    return Trans(Pos, RightUp, ReDepth);
                } else if (Mirror == g_Hall[Row - 1][Column]) {
                    return Trans(Pos, LeftDown, ReDepth);
                } else {
                    return 0;
                }
            }
            break;
        case LeftDown:
            Row = Pos.y + INF;
            Column = Pos.x - INF;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(0.5) > -INF) && (abs(g_Slope - 1) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope < 1) {
                    ReDepth -= sqrt(1 + g_Slope * g_Slope);
                    return Trans(AddPos(Pos, -1, g_Slope), LeftDown, ReDepth);
                } else {
                    ReDepth -= sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(AddPos(Pos, -1 / g_Slope, 1), LeftDown,
                            ReDepth);
                }
            case Mirror:
                if ((Mirror == g_Hall[Row][Column + 1])
                        && (Mirror == g_Hall[Row - 1][Column])) {
                    return Trans(Pos, RightUp, ReDepth);
                } else if (Mirror == g_Hall[Row][Column + 1]) {
                    return Trans(Pos, LeftUp, ReDepth);
                } else if (Mirror == g_Hall[Row - 1][Column]) {
                    return Trans(Pos, RightDown, ReDepth);
                } else {
                    return 0;
                }
            }
            break;
        }
    }
    if (TestInt(Pos.x)) {
        switch (Direct) {
        case LeftUp:
            Row = Pos.y;
            Column = Pos.x - INF;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(1 + g_Slope * g_Slope) / 2 > -INF)
                        && (abs(Row + 0.5 + g_Slope / 2 - Pos.y) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope < Pos.y - Row) {
                    ReDepth -= sqrt(1 + g_Slope * g_Slope);
                    return Trans(AddPos(Pos, -1, -g_Slope), LeftUp, ReDepth);
                } else {
                    ReDepth -= (Pos.y - Row)
                            * sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(
                            AddPos(Pos, -(Pos.y - Row) / g_Slope,
                                    -(Pos.y - Row)), LeftUp, ReDepth);
                }
            case Mirror:
                return Trans(Pos, RightUp, ReDepth);
            }
            break;
        case RightUp:
            Row = Pos.y;
            Column = Pos.x + INF;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(1 + g_Slope * g_Slope) / 2 > -INF)
                        && (abs(Row + 0.5 + g_Slope / 2 - Pos.y) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope < Pos.y - Row) {
                    ReDepth -= sqrt(1 + g_Slope * g_Slope);
                    return Trans(AddPos(Pos, 1, -g_Slope), RightUp, ReDepth);
                } else {
                    ReDepth -= (Pos.y - Row)
                            * sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(
                            AddPos(Pos, (Pos.y - Row) / g_Slope,
                                    -(Pos.y - Row)), RightUp, ReDepth);
                }
            case Mirror:
                return Trans(Pos, LeftUp, ReDepth);
            }
            break;
        case RightDown:
            Row = Pos.y;
            Column = Pos.x + INF;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(1 + g_Slope * g_Slope) / 2 > -INF)
                        && (abs(Row + 0.5 - g_Slope / 2 - Pos.y) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope < Row + 1 - Pos.y) {
                    ReDepth -= sqrt(1 + g_Slope * g_Slope);
                    return Trans(AddPos(Pos, 1, g_Slope), RightDown, ReDepth);
                } else {
                    ReDepth -= (Row + 1 - Pos.y)
                            * sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(
                            AddPos(Pos, (Row + 1 - Pos.y) / g_Slope,
                                    (Row + 1 - Pos.y)), RightDown, ReDepth);
                }
            case Mirror:
                return Trans(Pos, LeftDown, ReDepth);
            }
            break;
        case LeftDown:
            Row = Pos.y;
            Column = Pos.x - INF;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(1 + g_Slope * g_Slope) / 2 > -INF)
                        && (abs(Row + 0.5 - g_Slope / 2 - Pos.y) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope < Row + 1 - Pos.y) {
                    ReDepth -= sqrt(1 + g_Slope * g_Slope);
                    return Trans(AddPos(Pos, -1, g_Slope), LeftDown, ReDepth);
                } else {
                    ReDepth -= (Row + 1 - Pos.y)
                            * sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(
                            AddPos(Pos, -(Row + 1 - Pos.y) / g_Slope,
                                    (Row + 1 - Pos.y)), LeftDown, ReDepth);
                }
            case Mirror:
                return Trans(Pos, RightDown, ReDepth);
            }
            break;
        }
    }
    if (TestInt(Pos.y)) {
        switch (Direct) {
        case LeftUp:
            Row = Pos.y - INF;
            Column = Pos.x;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(1 + 1 / (g_Slope * g_Slope)) / 2 > -INF)
                        && (abs(Column + 0.5 + 0.5 / g_Slope - Pos.x) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope > 1/(Pos.x - Column)) {
                    ReDepth -= sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(AddPos(Pos, -1 / g_Slope, -1), LeftUp, ReDepth);
                } else {
                    ReDepth -= (Pos.x - Column)
                            * sqrt(1 + g_Slope * g_Slope);
                    return Trans(
                            AddPos(Pos, -(Pos.x - Column),
                                    -(Pos.x - Column) * g_Slope), LeftUp,
                            ReDepth);
                }
            case Mirror:
                return Trans(Pos, LeftDown, ReDepth);
            }
            break;
        case RightUp:
            Row = Pos.y - INF;
            Column = Pos.x;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(1 + 1 / (g_Slope * g_Slope)) / 2 > -INF)
                        && (abs(Column + 0.5 - 0.5 / g_Slope - Pos.x) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope > 1/(Column + 1 - Pos.x)) {
                    ReDepth -= sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(AddPos(Pos, 1 / g_Slope, -1), RightUp, ReDepth);
                } else {
                    ReDepth -= (Column + 1 -Pos.x)
                            * sqrt(1 + g_Slope * g_Slope);
                    return Trans(
                            AddPos(Pos, (Column + 1 - Pos.x),
                                    -(Column + 1 - Pos.x) * g_Slope), RightUp,
                            ReDepth);
                }
            case Mirror:
                return Trans(Pos, RightDown, ReDepth);
            }
            break;
        case RightDown:
            Row = Pos.y + INF;
            Column = Pos.x;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(1 + 1 / (g_Slope * g_Slope)) / 2 > -INF)
                        && (abs(Column + 0.5 - 0.5 / g_Slope - Pos.x) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope > 1/(Column + 1 - Pos.x)) {
                    ReDepth -= sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(AddPos(Pos, 1 / g_Slope, 1), RightDown,
                            ReDepth);
                } else {
                    ReDepth -= (Column + 1 -Pos.x)
                            * sqrt(1 + g_Slope * g_Slope);
                    return Trans(
                            AddPos(Pos, (Column + 1 - Pos.x),
                                    (Column + 1 - Pos.x) * g_Slope), RightDown,
                            ReDepth);
                }
            case Mirror:
                return Trans(Pos, RightUp, ReDepth);
            }
            break;
        case LeftDown:
            Row = Pos.y + INF;
            Column = Pos.x;
            switch (g_Hall[Row][Column]) {
            case Myself:
                if ((ReDepth - sqrt(1 + 1 / (g_Slope * g_Slope)) / 2 > -INF)
                        && (abs(Column + 0.5 + 0.5 / g_Slope - Pos.x) < INF)) {
                    return 1;
                }
                /* no break */
            case Null:
                if (g_Slope > 1/(Pos.x - Column)) {
                    ReDepth -= sqrt(1 + 1 / (g_Slope * g_Slope));
                    return Trans(AddPos(Pos, -1 / g_Slope, 1), LeftDown,
                            ReDepth);
                } else {
                    ReDepth -= (Pos.x - Column)
                            * sqrt(1 + g_Slope * g_Slope);
                    return Trans(
                            AddPos(Pos, -(Pos.x - Column),
                                    (Pos.x - Column) * g_Slope), LeftDown,
                            ReDepth);
                }
            case Mirror:
                return Trans(Pos, LeftUp, ReDepth);
            }
            break;
        }
    }
    return 0;
}

int TryTrans(Position Pos, double MaxDepth) {
    int Cnt = 0;
    if (g_Slope < 1) {
        double ReDepth = MaxDepth - 0.5 * sqrt(1 + g_Slope * g_Slope);
        Cnt += Trans(AddPos(Pos, -0.5, -0.5 * g_Slope), LeftUp, ReDepth);
        Cnt += Trans(AddPos(Pos, 0.5, -0.5 * g_Slope), RightUp, ReDepth);
        Cnt += Trans(AddPos(Pos, 0.5, 0.5 * g_Slope), RightDown, ReDepth);
        Cnt += Trans(AddPos(Pos, -0.5, 0.5 * g_Slope), LeftDown, ReDepth);
    } else {
        double ReDepth = MaxDepth - 0.5 * sqrt(1 + 1 / (g_Slope * g_Slope));
        Cnt += Trans(AddPos(Pos, -0.5 / g_Slope, -0.5), LeftUp, ReDepth);
        Cnt += Trans(AddPos(Pos, 0.5 / g_Slope, -0.5), RightUp, ReDepth);
        Cnt += Trans(AddPos(Pos, 0.5 / g_Slope, 0.5), RightDown, ReDepth);
        Cnt += Trans(AddPos(Pos, -0.5 / g_Slope, 0.5), LeftDown, ReDepth);
    }
    return Cnt;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int H, W, D;
        Position MyPos;
        int Answer = 0;
        scanf("%d %d %d\n", &H, &W, &D);
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                int c = getchar();
                switch (c) {
                case '.':
                    g_Hall[j][k] = Null;
                    break;
                case '#':
                    g_Hall[j][k] = Mirror;
                    break;
                case 'X':
                    g_Hall[j][k] = Myself;
                    MyPos.x = k + 0.5;
                    MyPos.y = j + 0.5;
                    break;
                default:
                    return 1;
                    break;
                }
            }
            getchar();
        }

        g_Slope = 0;
        Answer += Trans(AddPos(MyPos, -0.5, 0), LeftUp, D - 0.5);
        Answer += Trans(AddPos(MyPos, 0.5, 0), RightUp, D - 0.5);
        g_Slope = 1E100;
        Answer += Trans(AddPos(MyPos, 0, -0.5), LeftUp, D - 0.5);
        Answer += Trans(AddPos(MyPos, 0, 0.5), LeftDown, D - 0.5);
        for (int j = 1; j <= D; ++j) {
            for (int k = 1; k <= D; k++) {
                if (1 == gcd(j, k)) {
                    g_Slope = (double) j / k;
                    Answer += TryTrans(MyPos, (double) D);
                }
            }
        }
        printf("Case #%d: %d\n", i, Answer);
    }
    return 0;
}

