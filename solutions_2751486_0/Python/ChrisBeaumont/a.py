
def has_n_consec(s, n):
    ct = 0
    vowels = set('aeiou')
    if n == 0:
        return True

    for ss in s:
        if ss not in vowels:
            ct += 1
            if ct >= n:
                return True
        else:
            ct = 0
    return False

def solve_bruteforce(s, n):
    result = 0
    for i in range(len(s)):
        for j in range(i, len(s)):
            sub = s[i:j + 1]
            if has_n_consec(sub, n):
                result += 1
    return result


def solve(s, n):
    consec = []
    for i in range(len(s) - n + 1):
        print s[i : i + n]
        if len(set(s[i: i + n]) & set('aeiou')) == 0:
            consec.append(i)

    result = len(s) * (len(s) + 1) / 2
    if n == 0:
        return result

    for i in range(len(consec)):
        lo = 0 if i == 0 else consec[i - 1] + 1
        hi = min(consec[i] + n - 2, len(s) - 1)
        print lo, hi
        num = hi - lo + 1
        result -= num * (num + 1) / 2

    lo = consec[-1] + 1
    hi = len(s) - 1
    print lo, hi
    num = hi - lo + 1
    result -= num * (num + 1) / 2

    print result, solve_bruteforce(s, n)
    assert solve_bruteforce(s, n) == result
    return result




import sys
data = open(sys.argv[1] + '.in').readlines()
outfile = open(sys.argv[1] + '.out', 'w')

for i, d in enumerate(data[1:]):
    s, n = d.strip().split()
    n = int(n)
    result = 'Case #%i: %i\n' % (i + 1, solve_bruteforce(s, n))
    print result
    outfile.write(result)
