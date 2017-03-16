from multiprocessing import Pool


def solve(line):
    res = ""
    for ch in line.strip():
        if ch + res > res + ch:
            res = ch + res
        else:
            res = res + ch
    return res


p = Pool(8)
with open("in.txt", "r") as fin:
    results = p.map(solve, fin.readlines()[1:])
    with open("out.txt", "w") as fout:
        i = 0
        for res in results:
            i += 1
            fout.write("Case #%d: %s\n" % (i, str(res)))
