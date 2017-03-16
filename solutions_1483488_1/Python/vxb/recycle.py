from collections import deque

num_lines = int(raw_input(''))
lines = list()
for i in range(num_lines):
    lines.append(raw_input(''))

def num_pairs(pairs, l, u):
    num = 0
    for x, y in pairs:
        xt = min((x, y))
        yt = max((x, y))
        if l <= xt and yt <= u:
            num += 1
    return num

# Large case: memoisation!
lower = 1
upper = 2000000

pairs = set()
for item in range(lower, upper+1):
    rep = deque(str(item))
    # should rotate less than lg n times
    for j in range(len(rep)-1):
        rep.rotate(1)
        new = int("".join(rep))
        # don't want to match ourselves
        if item == new:
            continue
        if item < new:
            pair = (item, new)
        else:
            pair = (new, item)
        if pair not in pairs and lower <= new and new <= upper:
            pairs.add(pair)

for case, line in enumerate(lines):
    lower, upper = map(int, line.split())
    print "Case #{0}: {1}".format(case+1, num_pairs(pairs, lower, upper))

