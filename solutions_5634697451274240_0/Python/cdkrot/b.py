#!/usr/bin/python3

def solve(line):
    ans = 0
    for i in range(len(line) - 1, -1, -1):
        if line[i] == "-":
            ans += 1
            for j in range(0, i + 1):
                if (line[j] == '-'):
                    line[j] = '+'
                else:
                    line[j] = '-'
    # print(line)
    return ans

def main():
    T = int(input())
    for i in range(1, T + 1):
        print("Case #{}: {}".format(i, solve(list(input().strip()))))
    

main()
