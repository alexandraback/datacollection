#!/usr/bin/env python


def read():
    return map(int, raw_input().split())


def work(cases, (N, M)):
    if M > (1 << (N - 2)):
        print "Case #%d: IMPOSSIBLE" % cases
        return

    ans = '0'
    for bit in range(N - 3, -1, -1):
        if M >= (1 << bit):
            ans += '1'
            M -= 1 << bit
        else:
            ans += '0'
    
    if M > 0:
        ans += '1'
        M -= 1
    else:
        ans += '0'
    
    print "Case #%d: POSSIBLE" % cases
    
    print ans
    for i in range(1, N):
        print ("0" * (i + 1)) + ("1" * (N - i - 1))
    

if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
