#/usr/bin/env python

def cal_num(i):
    i = i + 1
    raw = raw_input()
    raw = raw.split()
    raw = [int(x) for x in raw]
    num = raw[0]
    count = raw[1]
    max_p = raw[2]
    raw = raw[3:]
    result = 0
    for r in raw:
        if (r + 2) / 3 >= max_p:
            result += 1
        elif count > 0 and r >= 2 and (r + 4) / 3 >= max_p:
            result += 1
            count -= 1
    print "Case #%d: %d" % (i, result) 

if __name__ == '__main__':
    i = int(raw_input())
    for x in range(i):
        cal_num(x)

