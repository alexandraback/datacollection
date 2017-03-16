import sys
import re

def read_int(fp=sys.stdin):
    return int(fp.readline().strip())

def read_ints(fp=sys.stdin):
    return map(int, fp.readline().strip().split())

def n_value(name, n):
    cons = re.compile("[bcdfghjklmnpqrstvwxyz]{%d,}" % n)
    value = 0
    for i in range(len(name)):
        for j in range(i + 1, len(name)+1):
            substring = name[i:j]
            if cons.search(substring):
                value += 1
    return value

if __name__ == "__main__":
    T = read_int()
    for t in range(1, T+1):
        name, n = sys.stdin.readline().strip().split()
        n = int(n)
        print "Case #%d: %s" % (t, n_value(name, n))
