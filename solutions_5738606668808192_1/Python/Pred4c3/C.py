import sys, itertools

def get_primes(max):
    sieve = [True] * max
    sieve[0] = False
    sieve[1] = False
    for i in range(int(max ** 0.5)):
        if sieve[i]:
            for composite in range(i*i, max, i):
                sieve[composite] = False
    return [index for index, is_prime in enumerate(sieve) if is_prime]

primes = get_primes(10**6)

def get_nt_div(n):
    max_divisor = int(n ** 0.5)
    for divisor in primes:
        if divisor > max_divisor:
            raise Exception('Prime')
        if n % divisor == 0:
            return divisor
    raise Exception('Finding better')

T=int(input())
for case_id in range(1,T+1):
    N,J = map(int,input().split())
    def solve():
        res,j = '\n',0
        for p in itertools.product(range(2), repeat=N-2):
            s = '1'+''.join(str(b) for b in p)+'1'
            nums = [int(s,i) for i in range(2,11)]
            try:
                res += ' '.join([s] + [str(get_nt_div(n)) for n in nums]) + '\n'
                j += 1
                print(j,s,nums, file=sys.stderr)
                if J==j: return res
            except:
                pass

    ans = solve()
    print('Case #%d: %s' % (case_id, ans))
    print('Case #%d: %s' % (case_id, ans), file=sys.stderr)
