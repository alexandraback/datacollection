import sys

lines = sys.stdin.readlines()[1:]

for nrs, l in enumerate(lines):
    k, c, s = map(int, l.strip().split())
    div_r_up = k / c + (1 if k % c > 0 else 0)
    if s < div_r_up:
        ans = 'IMPOSSIBLE'
    else:
        poses = []
        digit = 0
        for nr in range(div_r_up):
            p = 0
            for pos in range(c):
                p *= k
                p += digit
                if digit < k-1:
                    digit += 1
            poses.append(p)
        ans = ' '.join(str(p+1) for p in poses)
    print 'Case #%d: %s' % (nrs + 1, ans)
