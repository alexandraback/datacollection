#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        char a[100] = "", b[100] = "";
        char oa[100] = "", ob[100] = "";
        cin >> a >> b;
        int bigger = 0;
        int len = strlen(a);
        for (int i = 0; i < len; i++) {
            if (a[i] == b[i]) {
                if (a[i] == '?') {
                    if (a[i+1] == b[i+1]) {
                        if (a[i+1] == '?') {
                            oa[i] = '0';
                            ob[i] = '0';
                        } else {
                            oa[i] = a[i];
                            ob[i] = b[i];
                        }
                    } else {
                        if (a[i+1] == '?') {
                            oa[i] = '0';
                            ob[i] = '0';
                        } else if (b[i+1] == '?') {
                            oa[i] = '0';
                            ob[i] = '0';
                        } else if (a[i+1] > b[i+1]) {
                            if (a[i+1] - b[i+1] > 5) {
                                oa[i] = '0';
                                ob[i] = '1';
                            } else {
                                oa[i] = '0';
                                ob[i] = '0';
                            }
                        } else {
                            if (b[i+1] - a[i+1] > 5) {
                                oa[i] = '1';
                                ob[i] = '0';
                            } else {
                                oa[i] = '0';
                                ob[i] = '0';
                            }
                        }
                    }
                } else {
                    oa[i] = a[i];
                    ob[i] = b[i];
                }
            } else {
                if (a[i] == '?') {
                    if (a[i+1] == b[i+1]) {
                        oa[i] = b[i];
                        ob[i] = b[i];
                    } else {
                        if (a[i+1] == '?') {
                            oa[i] = b[i];
                            ob[i] = b[i];
                        } else if (b[i+1] == '?') {
                            oa[i] = b[i];
                            ob[i] = b[i];
                        } else if (a[i+1] > b[i+1]) {
                            if (a[i+1] - b[i+1] > 5) {
                                if (b[i] == '0')
                                    oa[i] = '0';
                                else
                                    oa[i] = b[i]-1;
                                ob[i] = b[i];
                            } else {
                                oa[i] = b[i];
                                ob[i] = b[i];
                            }
                        } else {
                            if (b[i+1] - a[i+1] > 5) {
                                if (b[i] == '9')
                                    oa[i] = '9';
                                else
                                    oa[i] = b[i]+1;
                                ob[i] = b[i];
                            } else {
                                oa[i] = b[i];
                                ob[i] = b[i];
                            }
                        }
                    }
                } else if (b[i] == '?') {
                    if (a[i+1] == b[i+1]) {
                        oa[i] = a[i];
                        ob[i] = a[i];
                    } else {
                        if (a[i+1] == '?') {
                            oa[i] = a[i];
                            ob[i] = a[i];
                        } else if (b[i+1] == '?') {
                            oa[i] = a[i];
                            ob[i] = a[i];
                        } else if (a[i+1] > b[i+1]) {
                            if (a[i+1] - b[i+1] > 5) {
                                if (a[i] == '9')
                                    ob[i] = '9';
                                else
                                    ob[i] = a[i]+1;
                                oa[i] = a[i];
                            } else {
                                oa[i] = a[i];
                                ob[i] = a[i];
                            }
                        } else {
                            if (b[i+1] - a[i+1] > 5) {
                                if (a[i] == '0')
                                    ob[i] = '0';
                                else
                                    ob[i] = a[i]-1;
                                oa[i] = a[i];
                            } else {
                                oa[i] = a[i];
                                ob[i] = a[i];
                            }
                        }
                    }
                } else if (a[i] > b[i]) {
                    oa[i] = a[i];
                    ob[i] = b[i];
                } else {
                    oa[i] = a[i];
                    ob[i] = b[i];
                }
            }
        }
        cout << "Case #" << t << ": " << oa << " " << ob << endl;
    }
    return 0;
}
