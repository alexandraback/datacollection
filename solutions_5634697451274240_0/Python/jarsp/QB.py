inp = open("B-small-attempt0.in", "r")
out = open("B-small.out", "w")

def flips(s):
    curr = s[0]
    f = 0
    for c in s[1:]:
        if c != curr:
            curr = c
            f += 1
    if curr == "-": f += 1
    return f

inp.readline()
count = 1
for l in inp:
    out.write("Case #{}: ".format(count) + str(flips(l.strip())) + "\n")
    count += 1
