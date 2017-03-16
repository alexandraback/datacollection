import sys


def r():
    return sys.stdin.readline()

def main(n):
    if n == 0:
        return 'INSOMNIA'

    ret = 0
    state = 0
    not_seen = {str(k): False for k in range(10)}

    while not all(not_seen.values()):
        ret += 1
        state += n

        for s in {k for k, v in not_seen.items() if not v}:
            if str(state).count(s) > 0:
                not_seen[s] = True

    return state

t = int(r())

for i in range(t):
    print('Case #{}: {}'.format(i + 1, main(int(r()))))

