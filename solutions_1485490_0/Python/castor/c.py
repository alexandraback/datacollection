#!/usr/bin/python

import sys

def calc(b, t):
    if not len(b) or not len(t):
        return 0

    count=0
    if b[1]==t[1]:
        count=min(b[0], t[0])
        if b[0]>=t[0]:
            b[0]-=count
            t=t[2:]
        else:
            t[0]-=count
            b=b[2:]

    return count+max(calc(b[2:], t), calc(b, t[2:]))

if __name__ == '__main__':
    with open(sys.argv[2], 'w') as out:
        with open(sys.argv[1]) as f:
            for i in range(int(f.readline())): # Case
                types=tuple(map(int, f.readline().split()))
                boxes=list(map(int, f.readline().split()))
                toys=list(map(int, f.readline().split()))
                #result=calc(types, boxes, toys)
                result=calc(boxes, toys)
                print('Case #{}: {}'.format(i+1,result), file=out)
