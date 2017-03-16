#include <iostream>
#include <cstdio>
#include <string>
#include <utility>

using namespace std;

bool compare(long long x1, long long x2, long long y1, long long y2) {
    long long x_abs = (x2 - x1 > 0) ? x2 - x1 : x1 - x2;
    long long y_abs = (y2 - y1 > 0) ? y2 - y1 : y1 - y2;

    return (x_abs < y_abs || (x_abs == y_abs && x1 < y1) || (x_abs == y_abs && x1 == y1 && x2 <= y2));
}

pair<string, string> minpair(pair<string, string> x, pair<string, string> y) {
    string x1str = get<0>(x);
    string x2str = get<1>(x);
    long long x1 = stoll(x1str);
    long long x2 = stoll(x2str);

    string y1str = get<0>(y);
    string y2str = get<1>(y);
    long long y1 = stoll(y1str);
    long long y2 = stoll(y2str);

    if (compare(x1,x2,y1,y2)) return x;
    else return y;
}

pair<string, string> minpair(pair<string, string> x, pair<string, string> y, pair<string, string> z) {
    return minpair(minpair(x,y),z);
}

// Compare is -1 if C < J, 1 if C > J, or 0 if C = J so far
pair<string,string> find_min(int current, pair<string, string> paired, int compare) {
    string C = get<0>(paired);
    string J = get<1>(paired);
    //cout << current << " " <<  C << " " << J << endl;

    if (current >= C.length()) {
        pair<string, string> end_pair (C,J);
        return end_pair;
    }

    // We don't need to edit numbers
    if (C[current] != '?' && J[current] != '?') {
        int new_compare = compare;
        if (compare == 0) {
            if (C[current] < J[current]) new_compare = -1;
            if (C[current] == J[current]) new_compare = 0;
            if (C[current] > J[current]) new_compare = 1;
        }

        return find_min(current+1, paired, new_compare);
    }

    // We need to decide how we edit question marks
    else if (C[current] == '?' && J[current] == '?') {
        if (compare < 0) {
            C[current] = '9';
            J[current] = '0';
            return find_min(current+1, make_pair(C,J), compare);
        }

        else if (compare > 0) {
            C[current] = '0';
            J[current] = '9';
            return find_min(current+1, make_pair(C,J), compare);
        }

        else {
            // Try all possibilities
            string C_copy = C;
            string J_copy = J;
            C_copy[current] = '0';
            J_copy[current] = '1';
            pair<string, string> less_case = find_min(current+1, make_pair(C_copy, J_copy), -1);

            C_copy[current] = '0';
            J_copy[current] = '0';
            pair<string, string> equal_case = find_min(current+1, make_pair(C_copy, J_copy), compare);

            C_copy[current] = '1';
            J_copy[current] = '0';
            pair<string, string> greater_case = find_min(current+1, make_pair(C_copy, J_copy), 1);

            return minpair(less_case, greater_case, equal_case);
        }
    }

    else if (C[current] == '?') {
        if (compare < 0) {
            C[current] = '9';
            return find_min(current+1, make_pair(C,J), compare);
        }

        else if (compare > 0) {
            C[current] = '0';
            return find_min(current+1, make_pair(C,J), compare);
        }

        else {
            // Try all possibilities
            string C_copy = C;
            string J_copy = J;

            // Cannot test smaller
            if (J[current] == '0') {
                C_copy[current] = '1';
                pair<string, string> greater_case = find_min(current+1, make_pair(C_copy, J_copy), 1);

                C_copy[current] = '0';
                pair<string, string> equal_case = find_min(current+1, make_pair(C_copy, J_copy), compare);

                return minpair(greater_case, equal_case);
            }

            else if (J[current] == '9') {
                C_copy[current] = '8';
                pair<string, string> less_case = find_min(current+1, make_pair(C_copy, J_copy), -1);

                C_copy[current] = '9';
                pair<string, string> equal_case = find_min(current+1, make_pair(C_copy, J_copy), compare);

                return minpair(less_case, equal_case);
            }

            else {
                C_copy[current] = J[current] + 1;
                pair<string, string> greater_case = find_min(current+1, make_pair(C_copy, J_copy), 1);

                C_copy[current] = J[current];
                pair<string, string> equal_case = find_min(current+1, make_pair(C_copy, J_copy), compare);

                C_copy[current] = J[current] - 1;
                pair<string, string> less_case = find_min(current+1, make_pair(C_copy, J_copy), -1);

                return minpair(greater_case, equal_case, less_case);
            }
        }
    }

    else if (J[current] == '?') {
        if (compare < 0) {
            J[current] = '0';
            return find_min(current+1, make_pair(C,J), compare);
        }

        else if (compare > 0) {
            J[current] = '9';
            return find_min(current+1, make_pair(C,J), compare);
        }

        else {
            // Try all possibilities
            string C_copy = C;
            string J_copy = J;

            // Cannot test smaller
            if (C[current] == '0') {
                J_copy[current] = '1';
                pair<string, string> greater_case = find_min(current+1, make_pair(C_copy, J_copy), -1);

                J_copy[current] = '0';
                pair<string, string> equal_case = find_min(current+1, make_pair(C_copy, J_copy), compare);

                return minpair(greater_case, equal_case);
            }

            else if (C[current] == '9') {
                J_copy[current] = '8';
                pair<string, string> less_case = find_min(current+1, make_pair(C_copy, J_copy), 1);

                J_copy[current] = '9';
                pair<string, string> equal_case = find_min(current+1, make_pair(C_copy, J_copy), compare);

                return minpair(less_case, equal_case);
            }

            else {
                J_copy[current] = C[current] + 1;
                pair<string, string> greater_case = find_min(current+1, make_pair(C_copy, J_copy), -1);

                J_copy[current] = C[current];
                pair<string, string> equal_case = find_min(current+1, make_pair(C_copy, J_copy), compare);

                J_copy[current] = C[current] - 1;
                pair<string, string> less_case = find_min(current+1, make_pair(C_copy, J_copy), 1);

                return minpair(greater_case, equal_case, less_case);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        string C, J;
        cin >> C >> J;
        pair<string, string> answer = find_min(0, make_pair(C,J), 0);
        cout << "Case #" << t << ": " << get<0>(answer) << " " << get<1>(answer) << endl;
    }
}