

def line_to_int_list(file):
    return [int(x) for x in file.readline().strip().split()]

def case(file):
    # hello
    [a, n] = line_to_int_list(file)
    motes0 = line_to_int_list(file)
    if a == 1:
        return n
    motes0.sort()
    best = float('inf')
    for i in range(n + 1):
        motes = motes0[:n - i]
        current = a
        count = 0
        for mote in motes:
            while current <= mote:
                current *= 2
                current -= 1
                count += 1
            current += mote
        best = min(best, count + i)
        index = i
    return str(best)



def cases(in_name, func=None, out_name=None):
    if func is None:
        func = case
    if out_name is None:
        ext = in_name.rindex('.')
        out_name = in_name[:ext] + ".out"
    with open(in_name, 'r') as fin:
        with open(out_name, 'w') as fout:
            ntests = int(fin.readline())
            for i in range(1, ntests + 1):
                fout.write("Case #%i: %s\n" % (i, func(fin)))

Q = 'A'
def run(op, n=0):
    if op == 0:
        cases(Q + "-test.in")
    elif op == 1:
        cases(Q + "-small-attempt" + str(n) + ".in")
    elif op == 2:
        cases(Q + "-large.in")

if __name__ == "__main__":
    print("beginning")
    run(2)