#!/usr/bin/env python3

"""
Google Code Jam
Round 1B 2016
Problem A
"""

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

class TestCase:
    def __init__(self, b, m):
        self.b = b
        self.m = m
    def solve(self):
        result = []
        if 2**(self.b - 1) < self.m:
             result.append("IMPOSSIBLE")
             return result
        result.append("POSSIBLE")
        flag = False
        if self.m == 2**(self.b - 2):
            self.m -= 1
            flag = True
        bi = bin(self.m)[2:]
        if flag:
            bi = bi.zfill(self.b)
        else:
            bi = bi.zfill(self.b + 1)
        for i in range(1, self.b + 1):
            line = ""
            for j in range(1, self.b + 1):
                if i == j:
                    line += "0 "
                elif i == self.b:
                    line += "0 "
                elif i > 1:
                    line += "1 "
                elif j == self.b:
                    if flag:
                        line += "1 "
                    else:
                        line += "0 "
                elif bi[j] == '1':
                    line += "1 "
                else:
                    line += "0 "
            line.strip()
            result.append(line)
        return result

def read_data(filename):
    with open(filename) as f:
        test_cases = []
        num_test_cases = int(f.readline())
        for _ in range(num_test_cases):
            b, m = [int(x) for x in next(f).split()]
            test_case = TestCase(b, m)
            test_cases.append(test_case)
    return num_test_cases, test_cases

if __name__ == "__main__":
    num_test_cases, test_cases = read_data("B-small-attempt7.in")
    for it in range(num_test_cases):
        test_case = test_cases[it]
        print("Case #{}: ".format(it + 1), end='')
        for line in test_case.solve():
            print(line)