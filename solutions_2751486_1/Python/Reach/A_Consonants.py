import sys

vowels = list('aeiou')

def isValid(s, n):
    l = 0
    for a in s:
        if a:
            l += 1
            if l >= n:
                return True
        else:
            l = 0
    return False

def solve(t):
    si = raw_input()
    s, n = si.split()
    s = list(s)
    n = int(n)

    for i in xrange(len(s)):
        if s[i] in vowels:
            s[i] = 0
        else:
            s[i] = 1

    l = 0
    count = 0
    last = 0
    for i in xrange(len(s)):
        if s[i]:
            l += 1
        else:
            l = 0
        if l >= n:
            last = i-n+2
        count += last

    print 'Case #%d:'%t, count

def main():
    sys.stdin = open('A-large.in')
    f = file('A-large.out', 'w')
    f.close()
    sys.stdout = open('A-large.out', 'w')

    T = input()
    for t in xrange(1, T+1):
        solve(t)


if __name__ == '__main__':
    main()

