N = 32
J = 500

# ----------------

N -= 2
s = ['0' for i in xrange(N)]

counter = 0
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]

def fact(n):
    global primes
    for i in primes:
        if n % i == 0:
            return i

def dfs(depth):
    global N, J, s, counter
    if depth == N:
        tmp = '1' + ''.join(s) + '1'
        lst = []
        for i in xrange(2, 11):
            tstNum = int(tmp, i)
            res = fact(tstNum)
            if res is None: return
            lst.append(res)
        if res is not None:
            counter += 1
            dump = tmp
            for i in lst:
                dump += ' ' + str(i)
            print dump
            if counter == J: exit()
        return
    for i in ['0', '1']:
        s[depth] = i
        dfs(depth+1)
        
print 'Case #1:'
dfs(0)