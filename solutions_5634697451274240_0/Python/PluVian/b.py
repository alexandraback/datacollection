import sys


def r():
    return sys.stdin.readline()

def main(strIn):
    if strIn.count('-') == 0:
        return 0

    st = [True if c == '+' else False for c in strIn]
    idx = len(st) - 1
    ret = 0

    def flip(n):
        nonlocal ret, st
        ret += 1

        for i in range(n + 1):
            st[i] = not st[i]

        for i in range((n + 1) // 2):
            st[i], st[n - i] = st[n - i], st[i]

    while idx != -1:
        if st[idx] is False:
            if st[0] is True:
                idx_next = idx - 1

                while idx_next > 0:
                    if st[idx_next]:
                        break
                    idx_next -= 1
                flip(idx_next)
                flip(idx)
            else:
                flip(idx)
        idx -= 1

    return ret

t = int(r())

for i in range(t):
    print('Case #{}: {}'.format(i + 1, main(r()[:-1])))

