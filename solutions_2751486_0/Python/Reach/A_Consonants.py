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

    count = 0
    for i in xrange(len(s)):
        for j in xrange(1, len(s)+1):
            if isValid(s[i:j], n):
                count += 1

    print 'Case #%d:'%t, count

def main():
    sys.stdin = open('A-small.in')
    f = file('A-small.out', 'w')
    f.close()
    sys.stdout = open('A-small.out', 'w')

    T = input()
    for t in xrange(1, T+1):
        solve(t)


if __name__ == '__main__':
    main()

