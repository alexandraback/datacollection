from sys import stdin

def read_ints():
    return map(int, stdin.readline().rstrip().split(' '))

def mirror(s, double):
    return int(s + s[::-1] if double else s[:-1] + s[::-1])
    
def next_palindrome(n):
    s = str(n)
    lens = len(s)
    half = s[:(lens - 1) / 2 + 1]
    double = True if lens % 2 == 0 else False
    np = mirror(half, double)
    if np <= n:
        lenhalf = len(half)
        np = str(int(half) + 1)
        if lenhalf == len(np):
            np = mirror(np, double)
        else:
            if not double:
                np = np[:-1]
            np = mirror(np, not double)
    return np
        
def is_palin(n):
    s = str(n)
    return s == s[::-1]
    
def find(n, fas):
    for i in xrange(len(fas)):
        if fas[i] >= n:
            return i
    return len(fas)
    
def gen_fas(max):
    fas = [1, 4, 9]
    fasappend = fas.append
    base, square = 11, 121
    while square < max:
        if is_palin(square):
            #print base, square, len(str(square))
            fasappend(square)
        base = next_palindrome(base)
        #sb = str(base)
        #if '3' == sb[0]:
        #    base = next_palindrome(int('9' * len(sb)))
        square = base * base
    return fas
    
def main():
    MAX = 10 ** 14
    fas = gen_fas(MAX)
    
    T = int(stdin.readline())
    for Ti in xrange(T):
        A, B = read_ints()
        answer = find(B + 1, fas) - find(A, fas)
        print 'Case #{}: {}'.format(Ti + 1, answer)

main()
