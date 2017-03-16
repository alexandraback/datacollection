#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
        
    const double EPS = 0.0000001;
    FILE *f = fopen("D-small-attempt0.in", "r");
    FILE *out = fopen("out.txt", "w");

    int numberOfCases;
    fscanf(f, "%d\n", &numberOfCases);

    for (int caseNum = 1; caseNum <= numberOfCases; ++caseNum) {
        int height, width, D;
        fscanf(f, "%d %d %d\n", &height, &width, &D);

        double youX, youY;
        int result = 0;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                char c;
                c = fgetc(f);
                if (c == 'X') {
                    youY = i + 0.5;
                    youX = j + 0.5;
                }
            }
            char endLine = fgetc(f);
        }

        int realHeight = height - 2;
        int realWidth = width - 2;

        double x = youX - 1;
        double y = youY - 1;
        
        set<int> angles;

        const double PI = 3.14159265;
        /*
        for (double x1 = x - realWidth * (D/realWidth +1); x1 <= D + x + EPS; x1 += realWidth) {
            for (double y1 = y - realHeight * (D/realHeight +1); y1 < D + y + EPS; y1 += realHeight) {
                double dist = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
                if (dist <= D + EPS && dist >= EPS) {
                    angles.insert(atan2(x - x1, y - y1) / PI * 180);
                }
            }
        }
        */
        double x1 = x - realWidth * (D/realWidth +1);
        while (x1 <= D + x + EPS) {
            double y1 = y - realHeight * (D/realHeight +1);
            bool even = true;
            while (y1 <= D + y +EPS) {
                double dist = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
                if (dist <= D + EPS && dist >= EPS) {
                    angles.insert(atan2(x - x1, y - y1) / PI * 90);
                }
                if (even) {
                    y1 += 2*(realHeight - y);
                } else {
                    y1 += 2*y;
                }
                even = !even;
            }

            x1 += 2 *(realWidth - x);
            y1 = y - realHeight * (D/realHeight +1);
            even = true;
            while (y1 <= D + y +EPS) {
                double dist = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
                if (dist <= D + EPS && dist >= EPS) {
                    angles.insert(atan2(x - x1, y - y1) / PI * 90);
                }
                if (even) {
                    y1 += 2*(realHeight - y);
                } else {
                    y1 += 2*y;
                }
                even = !even;
            }
            x1 += 2*x;
        }
        
        
        result = angles.size();
        fprintf(out, "Case #%d: %d\n", caseNum, result);
    }

    fclose(f);
    fclose(out);

}
