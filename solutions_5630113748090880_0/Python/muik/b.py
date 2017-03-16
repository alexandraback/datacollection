import fileinput
f = fileinput.input()
T = int(f.readline())

def solve(N):
    map = {}
    for i in range(2*N-1):
        line = f.readline().strip()
        cols = line.split(' ')
        for col in cols:
            if map.has_key(col):
                map[col] += 1
            else:
                map[col] = 1

    nums = []
    for key, count in map.items():
        if count % 2 != 0:
            nums.append(int(key))
    return ' '.join(str(n) for n in sorted(nums))

for case in range(1,T+1):
    N = int(f.readline().strip())
    print "Case #%d: %s" % (case, solve(N))
