import sys
import math
import string

def main():
    #infile = open('in')
    #infile = open('A-large.in')
    infile = open('A-small-attempt0.in')
    #infile = open('A-small-practice.in')
    #infile = open('A-large-practice.in')
    outfile = open('out', 'w')
    T = long(infile.readline())
    for i in xrange(T):
        outfile.write('Case #'+str(i+1)+': ' + solve(infile.readline()) + '\n')

def solve(content):
    alph = string.ascii_lowercase
    vov = 'aeiou'
    s, n = content.split()
    n = int(n)
    def check(l, r):
        cnt = 0
        for c in s[l:r]:
            if c not in vov:
                cnt += 1
                if cnt >= n:
                    return True
            else:
                cnt = 0
        return False
    res = 0
    for l in range(len(s) - n + 1):
        r = l + n
        while r <= len(s):
            res += 1 if check(l, r) else 0
            r += 1
    return str(res)

if __name__=='__main__':
    main()
