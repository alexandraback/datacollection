#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        int map[100][100];
        std::cin >> n >> m;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                std::cin >> map[j][k];

        bool possible = true;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                bool valid = true;
                for (int l = 0; l < m; l++) {
                    if (map[j][l] > map[j][k]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    continue;
                }
                valid = true;
                for (int l = 0; l < n; l++) {
                    if (map[l][k] > map[j][k]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    possible = false;
                    break;
                }
            }
            if (!possible)
                break;
        }
        std::cout << "Case #" << i + 1 << ": "
                  << (possible ? "YES" : "NO") << std::endl;
    }
    
    return 0;
}
