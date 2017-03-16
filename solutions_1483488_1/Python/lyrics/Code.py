import sys

def main():
    T = int(raw_input())
    for c in xrange(T):
        f = [0 for i in xrange(2000010)]
        [A, B] = map(int, raw_input().split())
        for i in xrange(A+1, B+1):
            f[i] = f[i-1]+calc(A, str(i))
        print "Case #%d: %d" % (c+1, f[B]-f[A-1])

def calc(A, s):
    st = set()
    st.add(int(s))
    for i in xrange(1, len(s)):
        tmp = s[i:]+s[0:i]
        if tmp[0]!='0' and A<=int(tmp)<int(s):
            st.add(int(tmp))
    return len(st)-1

if __name__ == '__main__':
    f1 = open('c.in', 'r')
    f2 = open('c.out', 'w')
    sys.stdin = f1
    sys.stdout = f2
    main()
    f1.close()
    f2.close()
