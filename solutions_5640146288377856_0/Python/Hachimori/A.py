#!/usr/bin/env python


def read():
    return map(int, raw_input().split())


def work(cases, (R, C, W)):
    ans = 0
    ans += C / W * (R - 1)

    if C % W == 0:
        ans += C / W
        ans += W - 1
    else:
        ans += C / W
        ans += W
    
    print "Case #%d: %d" % (cases, ans)


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
