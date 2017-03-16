from sys import stdin

def read_str(): return stdin.readline().rstrip('\n')
def read_int(): return int(stdin.readline())
def read_ints(): return map(int, stdin.readline().split())

def main():
    vovels = set(['a', 'e', 'i', 'o', 'u'])
            
    cases = read_int()
    for case in xrange(1, cases + 1):
        word, n = stdin.readline().split()
        n = int(n)
        
        lenword = len(word)
        ans = 0
        consecutive = 0
        begin = -1
        for i in xrange(lenword):
            c = word[i]
            if not c in vovels:
                consecutive += 1
            else:
                consecutive = 0
            if consecutive >= n:
                begin = i - n + 1
                ans += i - n + 2
            elif begin != -1:
                ans += begin + 1
        
        print('Case #{}: {}'.format(case, ans))
        
main()
