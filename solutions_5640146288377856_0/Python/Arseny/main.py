#!/usr/bin/python

def solve(r, c, w):
    result = 0
    result+= (r - 1) * (c / w)
    result+= (c / w - 1)
    result+= w
    if (c % w):
        result+= 1
    return result 


if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        r, c, w = map(int, raw_input().split())
        answer = solve(r, c, w)
        print "Case #{0}: {1}".format(t + 1, answer)
