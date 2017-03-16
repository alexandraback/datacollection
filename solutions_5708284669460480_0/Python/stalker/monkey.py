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

def comp_pref(t,l):
    for i in range(l-1,-1,-1):
        if t.endswith(t[:i]):
            return i

def compute_max(t,l,s):
    x = comp_pref(t,l) 
    return 1 + ( (s - l) // (l - x) )


def app(s,c):
    return map(lambda x: x+c,s)


def ext(s,alpha):
    result = []
    for c in alpha:
        result.extend(app(s,c))
    return result


def expand(alpha,s):
    result = ['']
    for i in range(s):
        result = ext(result,alpha)
    return result;

def count(row,target):
    result = 0
    beg = 0
    while True:
        f = row.find(target,beg)
        if f == -1:
            return result;
        result += 1
        beg = f+1


def solve(k,l,s,alpha,t):
    if set(t).difference(set(alpha)):
        return 0

    table = expand(alpha,s)

    n = len(table)
    exp = sum([count(row,t) for row in table]) / n

    m = compute_max(t,l,s)
    return m - exp


if __name__ == "__main__":
    T = read_int()
    for c in range(T):
        K,L,S = read_ints()
        alphabet = input()
        target = input()

        assert(len(alphabet) == K)
        assert(len(target) == L)
        
        R = solve(K,L,S,alphabet,target)
        print("Case #{}: {}".format(c+1,R))
