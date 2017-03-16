import sys
import itertools
import re

def solve():
    k,l,s = [int(i) for i in sys.stdin.readline().split(' ')]
    kstr = sys.stdin.readline()[:-1]
    lstr = sys.stdin.readline()[:-1]
    max = 0
    total = 0
    num = 0
    for st in itertools.product(kstr, repeat=s):
        num += 1
        target_str = ''.join(st)
        match_num = 0
        pos = 0
        while True:
            p = target_str.find(lstr, pos)
            if p == -1:
                break
            pos = p+1
            match_num += 1

        if max < match_num:
            max = match_num
        total += match_num
    return max - total/num

def main():
    t = int(sys.stdin.readline())
    for i in range(t):
        s = solve()
        frm  = '{0:.7g}'.format(s)
        if len(re.findall(r'\.', frm)) == 0:
            frm += ".0"
        print("Case #{0}: {1}".format(i+1, frm))

if __name__ == '__main__':
    main()
