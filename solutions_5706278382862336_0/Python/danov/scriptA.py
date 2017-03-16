import sys
from fractions import gcd

if len(sys.argv) != 3:
    print("Usage: python scriptA.py <input_file> <output_file>")
    exit()

input_file = sys.argv[1]
output_file = sys.argv[2]


def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)

def generations(P, Q, cnt):
    if cnt > 40: return -1;
    G = gcd(P, Q)
    NP = P // G
    NQ = Q // G
    NP = NP * 2
    if NP >= NQ:
        if is_power2(NQ):
            return cnt
        else:
            return -1
    else:
        return generations(NP, NQ, cnt + 1)

results = []
with open(input_file, 'r') as f:
    T = int(f.readline())
    for t in range(T):
        line = f.readline()
        P, Q = tuple(map(int, line.split('/')))
        res = generations(P, Q, 1)
        if res == -1: res = 'impossible'
        results.append('Case #%d: %s\n' % (t+1, res))

with open(output_file, 'w') as f:
    f.writelines(results)