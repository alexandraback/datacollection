def process(s):
    proofs = []
    for k in range(2, 11):
        x = int(s, k)
        for i in range(2, 1000):
            if (x % i == 0):
                # print(x, i)
                proofs += [i]
                break
        # print(len(proofs))
        if (len(proofs) != k - 1):
            return None
    return (s, proofs)

cnt = 0
def gen(n, res):
    global cnt
    if (n == 30):
        x = process(''.join(['1'] + res + ['1']))
        if x is not None:
            print(x[0], ' '.join(map(str, x[1])))
            cnt += 1
        if (cnt == 500):
            exit(0)
        return
    gen(n + 1, res + ['0'])
    gen(n + 1, res + ['1'])

print("Case #1:")
gen(0, [])
