import sys

def war(naomi, ken):
    i = len(naomi) - 1
    j = i
    naomiScore = 0
    while 0 <= i and 0 <= j:
        if ken[i] < naomi[j]:
            naomiScore += 1
            j -= 1
        else:
            i -= 1
            j -= 1
    return naomiScore

def deceitfulWar(naomi, ken):
    i = len(naomi) - 1
    j = i
    naomiScore = 0
    while 0 <= i and 0 <= j:
        if ken[i] < naomi[j]:
            naomiScore += 1
            i -= 1
            j -= 1
        else:
            i -= 1
    return naomiScore


def solve():
    sys.stdin.readline()
    naomi = list(map(float, sys.stdin.readline().split()))
    naomi.sort()
    ken = list(map(float, sys.stdin.readline().split()))
    ken.sort()
    return '%d %d' % (deceitfulWar(naomi, ken), war(naomi, ken))

if __name__ == '__main__':
    cases = int(sys.stdin.readline().split()[0])
    for i in range(cases):
        print('Case #%d: %s' % (i + 1, solve()))
