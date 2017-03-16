import sys


def get_tiles(k, c, s):
    return "IMPOSSIBLE"


name = sys.argv[1]

lines = []
with open(name) as f:
    lines = f.readlines()

lines = lines[1:]

case = 0;
for line in lines:
    case += 1
    p = "Case #"+str(case)+": "
    (k, c, s) = line.split()
    k = int(k)
    c = int(c)
    s = int(s)
    if k==s:
        p += ' '.join(str(x) for x in range(1,k+1))
    else:
        p += get_tiles(k, c, s)
    print(p)

