import sys

def solve(b, m):
    if m > 2 ** (b - 1):
        print "IMP", b,m
        return "IMPOSSIBLE"
    res = [['0'] * (b + 1) for i in xrange(b + 1)]
    if m == 0:
        print "####"
        return res
    if m == 1:
        for j in xrange(b):
            res[j][j + 1] = '1'
        return res

    if m % 2 == 0:
        half = solve(b - 1, m / 2)
        res = [[a for a in half[0]]]
        res.extend(half)
        res[0][0] = '1'
        new_res = []
        for s in res:
            t = ['0']
            for a in s:
                t.append(a)
            new_res.append(t)
        res = new_res

    else: # m % 2 = 1
        half = solve(b - 1, (m / 2) + 1)
        res = [[a for a in half[0]]]
        res.extend(half)
        res[0][0] = '1'
        flg = False
        for i in xrange(len(res[0]) - 1, -1, -1):
            if flg:
                break
            for j in xrange(len(res[0]) - 1, i, -1):
                if res[j][i] == '1':
                    res[j][i] = '0'
                    flg = True
                    break
        new_res = []
        for s in res:
            t = ['0']
            for a in s:
                t.append(a)
            new_res.append(t)
        res = new_res

    return res

input_file = open(sys.argv[1], "r")
output_file = open(sys.argv[2], "w")

T = int(input_file.readline().strip())
strings = input_file.readlines()
results = []
for s in strings:
    (b, m) = s.strip().split(' ')
    if int(m) > 2 ** (int(b) - 2):
        results.append("IMPOSSIBLE")
    else:
        res1 = solve(int(b) - 1, int(m))
        if res1 != "IMPOSSIBLE":
            a = []
            for l in res1:
                a.append("".join(l))
            results.append("POSSIBLE\n" + "\n".join(a))
        else:
            print "IMP111"
            results.append("IMPOSSIBLE")

for i in xrange(T):
    output_file.write("Case #{0}: {1}\n".format(i+1, results[i]))

input_file.close()
output_file.close()