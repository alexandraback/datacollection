#include <iostream>
#include <string>

int toInt(const std::string &S) {
    int res = 0;
    for (int i = 0; i < (int)S.size(); ++ i) {
        res *= 10;
        res += S[i] - '0';
    }
    return res;
}



std::string A, B;


std::string jeden() {
    std::string res;

    if (A[0] == '?' && B[0] == '?')
        return "0 0";
    if (A[0] == '?' && B[0] != '?') {
        res = B[0];
        res += " ";
        res += B[0];
    }
    if (A[0] != '?' && B[0] == '?') {
        res = A[0];
        res += " ";
        res += A[0];
    }
    if (A[0] != '?' && B[0] != '?') {
        res = A[0];
        res += " ";
        res += B[0];
    }
    return res;
}

std::string dwa() {
    std::string r, q;
    std::string ra, rb;
    int y, u;
    for (int a = 0; a < 10; ++ a) {
        for (int b = 0; b < 10; ++ b) {
            for (int c = 0; c < 10; ++ c) {
                for (int d = 0; d < 10; ++ d) {
                    r = A;
                    q = B;
                    if (r[0] == '?') r[0] = a + '0';
                    if (r[1] == '?') r[1] = b + '0';
                    if (q[0] == '?') q[0] = c + '0';
                    if (q[1] == '?') q[1] = d + '0';
                    if (a == 0 && b == 0 && c == 0 && d == 0) {
                        y = toInt(r);
                        u = toInt(q);
                        ra = r;
                        rb = q;
                    } else {
                        int z = toInt(r);
                        int x = toInt(q);
                        if (std::abs(y - u) < std::abs(z - x)) continue;

                        if (std::abs(y - u) > std::abs(z - x)) {
                            y = z;
                            u = x;
                            ra = r;
                            rb = q;
                            continue;
                        }

                        if (z < y) {
                            y = z;
                            u = x;
                            ra = r;
                            rb = q;
                        } else if (z == y && x < u) {
                            y = z;
                            u = x;
                            ra = r;
                            rb = q;
                        }
                    }
                }
            }
        }
    }

    return ra + " " + rb;
}

std::string trzy() {
    std::string r, q;
    std::string ra, rb;
    int y, u;

    for (int a = 0; a < 10; ++ a) {
        for (int b = 0; b < 10; ++ b) {
            for (int c = 0; c < 10; ++ c) {
                for (int d = 0; d < 10; ++ d) {
                    for (int e = 0; e < 10; ++ e) {
                        for (int f = 0; f < 10; ++ f) {

                            r = A;
                            q = B;
                            if (r[0] == '?') r[0] = a + '0';
                            if (r[1] == '?') r[1] = b + '0';
                            if (r[2] == '?') r[2] = c + '0';
                            if (q[0] == '?') q[0] = d + '0';
                            if (q[1] == '?') q[1] = e + '0';
                            if (q[2] == '?') q[2] = f + '0';

                            if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
                                y = toInt(r);
                                u = toInt(q);
                                ra = r;
                                rb = q;
                            } else {
                                int z = toInt(r);
                                int x = toInt(q);
                                if (std::abs(y - u) < std::abs(z - x)) continue;

                                if (std::abs(y - u) > std::abs(z - x)) {
                                    y = z;
                                    u = x;
                                    ra = r;
                                    rb = q;
                                    continue;
                                }

                                if (z < y) {
                                    y = z;
                                    u = x;
                                    ra = r;
                                    rb = q;
                                } else if (z == y && x < u) {
                                    y = z;
                                    u = x;
                                    ra = r;
                                    rb = q;
                                }

                            }
                        }
                    }
                }
            }
        }
    }

    return ra + " " + rb;
}


std::string solve() {
    std::string res;

    std::cin>> A >> B;

    if (A.size() == 1) res = jeden();
    if (A.size() == 2) res = dwa();
    if (A.size() == 3) res = trzy();

    return res;
}



int main() {
    int tests;
    std::cin >> tests;

    for (int i = 1; i <= tests; ++ i) {
        std::cout << "Case #" << i << ": " << solve() << "\n";
    }

    return 0;
}
