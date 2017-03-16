#!/usr/bin/env python3

################################################################################

def read_int():
    return int(input())

def read_words():
    return input().split()

def read_ints():
    return list(map(int,read_words()))

def read_floats():
    return list(map(float,read_words()))

################################################################################

def solve(D):
    D.sort(reverse=True)
    best = D[0]
    acc = 0
    while acc < best:
        if D[0] < 3:
            return min(best, acc + D[0])

        half = D[0] // 2
        D[0] -= half
        D.append(half)
        D.sort(reverse=True)
        acc += 1

        if acc + D[0] < best:
            best = acc + D[0]

    return best

if __name__ == "__main__":
    T = read_int()
    for c in range(T):
        D = read_int()
        Ds = read_ints()
        R = solve(Ds)
        print("Case #{}: {}".format(c+1,R))
